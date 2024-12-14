#include <iostream>
#include "sculptor.h"
#include "sculptor.cpp"
#include "writeOFF.cpp"

int main(){
    Sculptor teste(50, 50, 50);
    
    teste.setColor(0.72, 0, 0, 1.0);
    teste.putSphere(25,25,25,25);

    //teste.setColor(0.72, 0, 1.0, 1.0);
    //teste.putEllipsoid(50,100,100,25,36,9);
    /*cogumelo
    teste.putEllipsoid(100, 100, 100, 21, 16, 21);
    teste.cutEllipsoid(100, 95, 100, 15, 16, 15);
    teste.cutBox(0, 199, 0, 90, 0, 199);

    teste.setColor(0.79, 0.67, 0.55, 1.0);
    teste.putSphere(100, 95, 100, 225);
    
    teste.setColor(1.0, 1.0, 1.0, 1.0);
    teste.putSphere(180, 100, 180, 10);
   */
    teste.writeOFF("teste.off");
}