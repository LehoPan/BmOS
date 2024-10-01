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
        int width = 100;
        int height = 30;
        int frame[30][100]; // for speed at compile time you need to put y, x here
	
	int consoleFrame = 0;
	
	//ofstream console1("/dev/tty1");
	//ofstream console2("/dev/tty2");

	//filebuf *console1 = new filebuf();
	//console1->open("/dev/tty1");
	
	//filebuf *console2 = new filebuf();
	//console2->open("/dev/tty2");
		
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
