#include "sculptor.h"
#include "voxel.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
//*!
// *Atribuicao das cores nos voxels mediante RGB
//*\param alpha transparencia
// */
void Sculptor:: setColor(float r, float g, float b, float alpha){
    this->r=r;//primeiro R da sculptor e o segundo R variavel local
    this->g=g;
    this->b=b;
    a = alpha;
}
void Sculptor::putVoxel(int x, int y, int z){
    //entre [0, 1]
    //se a cor esta dentro do do espaco alocado para os Voxels
    if(x>=0 && x<nx && y>=0 && y<ny && z>=0 && z<nz){
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
        v[x][y][z].isOn = true;
    }
}
void Sculptor::cutVoxel(int x, int y, int z){
    if(x>=0 && x<nx && y>=0 && y<ny && z>=0 && z<nz){
        v[x][y][z].isOn = false;
    }
}

//*!
// * Ativa os voxels no intervalo [x0,x1], [y0,y1], [z0,z1] e atribui as cores
// */
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
   for(int k = 0; k<nz; k++){
        for(int j = 0; j<ny; j++){
           for(int i = 0; i<nx; i++){
               if(i>=x0 && i<=x1 && j>=y0 && j<=y1 && k>=z0 && k<=z1){
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                    v[i][j][k].isOn = true;
                }
            }
        }
    }
}

//*!
// * Desativa os voxels no intervalo [x0,x1], [y0,y1],[z0,z1]
// */
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int k = 0; k<nz; k++){
        for(int j = 0; j<ny; j++){
          for(int i = 0; i<nx; i++){
                if(i>=x0 && i<=x1 && j>=y0 && j<=y1 && k>=z0 && k<=z1){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }
}

//*!
// * Ativa os voxels da esfera e os atribui uma cor
// */
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int k = 0; k<nz; k++){
        for(int j = 0; j<ny; j++){
             for(int i = 0; i<nx; i++){
                if(((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter)) <= radius*radius){
                    v[i][j][k].isOn = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
               }
            }
       }
    }
}

//*!
// * Desativa os voxels da esfera
// */
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for(int k = 0; k<nz; k++){
        for(int j = 0; j<ny; j++){
             for(int i = 0; i<nx; i++){
                 if( ((i - xcenter)*(i - xcenter) + (j - ycenter)*(j - ycenter) + (k - zcenter)*(k - zcenter)) <= radius*radius ){
                    v[i][j][k].isOn = false;
                 }
           }
       }
    }
}

//*!
 //* Construtor da classe para geração da matriz tridimensional alocada dinamicamente.
 //*/
Sculptor::Sculptor(int _nx, int _ny, int _nz){
    //int i,j=0,k=0;
    nx=_nx;
    ny=_ny;
    nz =_nz;
    v = new Voxel**[nx];//numero de linhas
    if(v == nullptr){//retorna um zero
        cout<<"Error na alocacao! Nao ha valor.";
        exit(0);

    }
    v[0] = new Voxel*[nx*ny];

    if(v[0] == nullptr){
        cout<<"Erro na alocacao!";
        exit(0);
    }
    v[0][0] = new Voxel[nx*ny*nz];


    if(v[0] == nullptr){
        cout<<"Erro na alocacao!";
        exit(0);
    }

}

/*!
 * Destrutor
 */
Sculptor::~Sculptor(){
    //se nao existir valor nas dimensoes a funcao sera encerrada
    if(nx < 0 || ny < 0 || nz < 0){
        return;
    }
    //liberacao da matriz
    delete[] v[0][0];
    delete [] v[0];
    delete [] v;

}
