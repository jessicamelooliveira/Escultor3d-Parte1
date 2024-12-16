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
    kirby.setColor(0, 0, 0, 1.0);
    for(int i=38; i<53; i++){
        if(i>=40 && i<=50) continue;
        for(int j=45; j<55; j++){
        kirby.cutVoxel(i, j, 49);
        }
    }
    for(int i=37; i<54; i++){
        if(i>=40 && i<=50) continue;
        for(int j=45; j<55; j++){
            kirby.putVoxel(i, j, 48);
        }
    }

    // Boca
    for(int i=44; i<47; i++){
        kirby.putVoxel(i, 41, 49);
    }
    kirby.putVoxel(43, 42, 49);
    kirby.putVoxel(47, 42, 49);
    kirby.putVoxel(42, 43, 49);
    kirby.putVoxel(48, 43, 49);

    // Brilho
    kirby.setColor(1.0, 1.0, 1.0, 1.0);
    for(int i=38; i<54; i++){
        if(i>=40 && i<=51) continue;
        for(int j=53; j<55; j++){
            kirby.putVoxel(i, j, 48);
        }
    }

    kirby.writeOFF("kirby.off");
}