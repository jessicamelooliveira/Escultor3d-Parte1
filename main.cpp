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

    // Pés
    kirby.setColor(0.86, 0, 0.34, 1.0);
    kirby.putEllipsoid(28, 21, 25, 15, 5, 12);
    kirby.putEllipsoid(62, 21, 25, 15, 5, 12);
    kirby.cutBox(0, 99, 0, 16, 0, 99);

    // Olhos
    kirby.setColor(0, 0, 0, 1.0);
    kirby.cutBox(38, 39, 45, 54, 49, 49);
    kirby.cutBox(51, 52, 45, 54, 49, 49);
    kirby.putBox(38, 39, 45, 54, 48, 48);
    kirby.putBox(51, 52, 45, 54, 48, 48);

    // Boca
    kirby.putBox(44, 46, 41, 41, 49, 49);
    kirby.putVoxel(43, 42, 49);
    kirby.putVoxel(47, 42, 49);
    kirby.putVoxel(42, 43, 49);
    kirby.putVoxel(48, 43, 49);

    // Brilho
    kirby.setColor(1.0, 1.0, 1.0, 1.0);
    kirby.putBox(39, 39, 53, 54, 48, 48);
    kirby.putBox(52, 52, 53, 54, 48, 48);

    // Bochechas
    kirby.setColor(0.95, 0.44, 0.52, 1.0);
    kirby.cutBox(36, 36, 42, 43, 49, 49);
    kirby.cutBox(53, 53, 42, 43, 49, 49);
    kirby.putBox(34, 36, 42, 43, 48, 48);
    kirby.putBox(53, 55, 42, 43, 48, 48);

    // Aparando o que não é necessário
    kirby.cutBox(0, 99, 0, 99, 50, 50);

    // Escrevendo o arquivo OFF
    kirby.writeOFF("kirby.off");
}