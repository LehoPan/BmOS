#include "../include/include.h"

int main(){
    BmOS hiii;

    hiii.render();
    system("ffplay -t '5' -autoexit ./sfx/LocalForecast-Elevator.wav &");

    while(true){
        hiii.play();
        usleep(700000);
    }
    
}