#include "../include/BmOS.h"

// constructor
BmOS::BmOS() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            frame[i][j] = bg_color;
        }
    }
}

// iterating frames
void BmOS::changeFrame(int x, int y, int color) {
    frame[y][x] = color;
}

void BmOS::render() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cout << "\e[48;5;" << frame[i][j] << "m \e[0m";
        }
        cout << endl;
    }
}

void BmOS::play(bool loop) {
    ifstream file("frameSets/" + set + ".txt" );

    if(!file.is_open()) {
        cerr << "Error opening file" << endl;
    }

    string temp_frame; 
    string raw_pixel;
    string raw_value;
    vector<int> temp_pixel;
    vector<vector<int>> clearing_array;

    //one frame
    while(getline(file, temp_frame)) {
        stringstream pixels(temp_frame);

        //one pixel
        while(getline(pixels, raw_pixel, '|')) {
            stringstream values(raw_pixel);
            temp_pixel.clear();

            //one value of that pixel coordinate and color
            while(getline(values, raw_value, ',')) {
                temp_pixel.push_back(stoi(raw_value));
            }
            changeFrame(temp_pixel[0], temp_pixel[1], temp_pixel[2]);
            clearing_array.push_back(temp_pixel);
        }
        render();
        usleep(60000);

        while(!clearing_array.empty()) {
            changeFrame(clearing_array[0][0], clearing_array[0][1], bg_color);
            clearing_array.erase(clearing_array.begin());
        }
    }
    file.close();
}