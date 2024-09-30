#ifndef BMOS_H
#define BMOS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unistd.h>

using namespace std;

// class to have a BmOS visualizer
class BmOS {
    // frame is stored here
    private:
        int width = 80;
        int height = 20;
        int frame[20][80]; // for speed at compile time you need to put y, x here

        int bg_color = 6;
        string set = "loading";

    public:
        // construcor defines frame size
        BmOS();

        // change the frame
        void changeFrame(int x, int y, int color);

        // render the frame onto console
        void render();

        // play the animation
        void play(bool loop = false);
};

#endif // BMOS_H