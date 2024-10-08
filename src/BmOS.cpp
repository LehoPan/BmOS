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
    frame[x][y] = color;
}

// changes animation file
void BmOS::changeFile(string newFile) {
    set = newFile;
}

void BmOS::render() {
    ofstream console1("/dev/tty1");
    ofstream console2("/dev/tty2");

    //string line = "\033c";
    string line = "\n";
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            line += "\e[48;5;" + to_string(frame[i][j]) + "m \e[0m";
        }
        //line += "\n";
    }
    consoleFrame = (++consoleFrame) % 2;
    if(consoleFrame) {
    	cout.rdbuf(console2.rdbuf());
	system("chvt 1");
    } else {
	cout.rdbuf(console1.rdbuf());
	system("chvt 2");
    }
    cout << line << flush;
    console1.close();
    console2.close();
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
       	usleep(50000); 

        while(!clearing_array.empty()) {
            changeFrame(clearing_array[0][0], clearing_array[0][1], bg_color);
            clearing_array.erase(clearing_array.begin());
        }
        usleep(600000);
    }
    file.close();
}
