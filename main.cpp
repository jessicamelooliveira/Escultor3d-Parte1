#include <iostream>
#include "sculptor.h"
#include "sculptor.cpp"
#include "writeOFF.cpp"

int main(){
    Sculptor kirby(100, 100, 100);
    
    // Corpo
    kirby.setColor(0.97, 0.65, 0.72, 1.0);
    kirby.putSphere(45, 45, 25, 25);
    kirby.putSphere(20, 40, 25, 10);
    kirby.putSphere(70, 40, 25, 10);

    // Pes
    kirby.setColor(0.86, 0, 0.34, 1.0);
    kirby.putEllipsoid(28, 20, 25, 15, 5, 12);
    kirby.putEllipsoid(62, 20, 25, 15, 5, 12);
    kirby.cutBox(0, 99, 0, 16, 0, 99);

    // Olhos
    kirby.setColor(0, 0.33, 0.57, 1.0);
    //for(int i=45; j<50; j++){
        //for(int j=5; k<10; k++){
            //kirby.cutVoxel(35, 45, 45);
            kirby.putVoxel(35, 45, 47);
        //}
    //}

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
    kirby.writeOFF("kirby.off");
}