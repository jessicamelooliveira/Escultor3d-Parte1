#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include "sculptor.h"

// Grava a escultura no formato OFF no arquivo filename
void Sculptor::writeOFF(const char *filename){
    std::ofstream fout(filename);
        if (!fout.is_open()) {
            std::cout << "ERRO: Não abriu o arquivo!" << std::endl;
            return;
        }
    fout << "OFF" << std::endl;
    
    // Contagem do numero de voxels
    int nvoxels = 0;
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].show == true){
                    nvoxels++;
                }
            }
        }
    }
    
    fout << nvoxels * 8 << " " << nvoxels * 6 << " 0" << std::endl;

    // Escrever os vértices
    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            for (int z = 0; z < nz; z++) {
                if (v[x][y][z].show) {
                    fout << x - 0.5 << " " << y - 0.5 << " " << z - 0.5 << std::endl;
                    fout << x + 0.5 << " " << y - 0.5 << " " << z - 0.5 << std::endl;
                    fout << x + 0.5 << " " << y + 0.5 << " " << z - 0.5 << std::endl;
                    fout << x - 0.5 << " " << y + 0.5 << " " << z - 0.5 << std::endl;
                    fout << x - 0.5 << " " << y - 0.5 << " " << z + 0.5 << std::endl;
                    fout << x + 0.5 << " " << y - 0.5 << " " << z + 0.5 << std::endl;
                    fout << x + 0.5 << " " << y + 0.5 << " " << z + 0.5 << std::endl;
                    fout << x - 0.5 << " " << y + 0.5 << " " << z + 0.5 << std::endl;
                }
            }
        }
    }

    // Escrever as faces
    int voxelFaces = 0;
    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            for (int z = 0; z < nz; z++) {
                if (v[x][y][z].show) {
                    // Definir faces para um cubo (voxel)
                    fout << "4 " << voxelFaces * 8 + 0 << " " << voxelFaces * 8 + 1 << " " << voxelFaces * 8 + 2 << " " << voxelFaces * 8 + 3 << " "
                         << std::fixed << std::setprecision(1) << v[x][y][z].r << " " 
                         << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl; // Face inferior
                    fout << "4 " << voxelFaces * 8 + 4 << " " << voxelFaces * 8 + 5 << " " << voxelFaces * 8 + 6 << " " << voxelFaces * 8 + 7 << " "
                         << std::fixed << std::setprecision(1) << v[x][y][z].r << " " 
                         << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl; // Face superior
                    fout << "4 " << voxelFaces * 8 + 0 << " " << voxelFaces * 8 + 1 << " " << voxelFaces * 8 + 5 << " " << voxelFaces * 8 + 4 << " "
                         << std::fixed << std::setprecision(1) << v[x][y][z].r << " " 
                         << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl; // Face lateral 1
                    fout << "4 " << voxelFaces * 8 + 1 << " " << voxelFaces * 8 + 2 << " " << voxelFaces * 8 + 6 << " " << voxelFaces * 8 + 5 << " "
                         << std::fixed << std::setprecision(1) << v[x][y][z].r << " " 
                         << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl; // Face lateral 2
                    fout << "4 " << voxelFaces * 8 + 2 << " " << voxelFaces * 8 + 3 << " " << voxelFaces * 8 + 7 << " " << voxelFaces * 8 + 6 << " "
                         << std::fixed << std::setprecision(1) << v[x][y][z].r << " " 
                         << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl; // Face lateral 3
                    fout << "4 " << voxelFaces * 8 + 3 << " " << voxelFaces * 8 + 0 << " " << voxelFaces * 8 + 4 << " " << voxelFaces * 8 + 7 << " "
                         << std::fixed << std::setprecision(1) << v[x][y][z].r << " " 
                         << v[x][y][z].g << " " << v[x][y][z].b << " " << v[x][y][z].a << std::endl; // Face lateral 4
                voxelFaces++;
                }
            }
        }
    }
    fout.close();
}