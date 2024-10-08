#include "../include/include.h"

int main(){
    BmOS hiii;

    hiii.render();
    system("ffplay -t '5' -autoexit ./sfx/LocalForecast-Elevator.wav &");

    while(true){
        hiii.changeFile("blink");
        hiii.play();
        usleep(3000000);

        hiii.changeFile("lookMidToTopRight");
        hiii.play();
        usleep(3000000);

        hiii.changeFile("lookTopRightToMid");
        hiii.play();
        usleep(3000000);

        hiii.changeFile("blink");
        hiii.play();
        usleep(700000);
    }
    
}
