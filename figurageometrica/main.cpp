#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "sculptor.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "figurageometrica.h"
//biblitoteca que permite utilizar o setprecision
//#include <iomanip>
/*
 * float x = 2.4514;
 * cout<<"x="<<setprecison(3)<<x<<endl;
 *
 * SAIDA: x = 2.45
 * UTIL PARA UTILIZAR O SETCOLOR MASHLAB
 * ESTE PROGRAMA ACEITA AS CORES (RGB-A) 1.0 0.0 0.0 1.0
 */
using namespace std;

int main(){
  /*
//TESTE
  f.push_back(new Reta(1, 2 , 3, 0.1, 0.1, 0.1, 1));
  f.push_back(new Circulo);
  f.push_back(new Retangulo);
  for (int i=0; i<f.size(); i++) {
    v[i]->draw(*s);
  }
  cout << "\n";
  for (int i=0; i<f.size; i++) {
    delete f[i];
  }
*/


    Sculptor *sculptor;
       vector<FiguraGeometrica*> figs;
       fstream fin;
       string s, filename;
       stringstream ss;

       filename = "arquivo";

       fin.open("./"+filename+".txt");
       if(!fin.is_open()){
           cout<<"Arquivo nao encontrado."<<endl;
           exit(0);
       }
       while(fin.good()){
           getline(fin, s);
           ss.clear();
           ss.str(s);
           ss>>s;

           if(s.compare("dim")==0){
               int dx, dy, dz;
               ss>>dx>>dy>>dz;
               sculptor = new Sculptor(dx, dy, dz);
           }
           else if(s.compare("putvoxel")==0){
               int x, y, z;
               float r, g, b, a;
               ss>>x>>y>>z>>r>>g>>b>>a;
               figs.push_back(new PutVoxel(x, y, z, r, g, b, a));
           }
           else if(s.compare("cutvoxel")==0){
               int x, y, z;
               ss>>x>>y>>z;
               figs.push_back(new CutVoxel(x, y, z));
           }
           else if(s.compare("putbox")==0){
               int x0, x1, y0, y1, z0, z1;
               float r, g, b, a;
               ss>>x0>>x1>>y0>>y1>>z0>>z1>>r>>g>>b>>a;
               figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
           }
           else if(s.compare("cutbox")==0){
               int x0, x1, y0, y1, z0, z1;
               ss>>x0>>x1>>y0>>y1>>z0>>z1;
               figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
           }
           else if(s.compare("putsphere")==0){
               int xcenter, ycenter, zcenter, radius;
               float r, g, b, a;
               ss>>xcenter>>ycenter>>zcenter>>radius>>r>>g>>b>>a;
               figs.push_back(new PutSphere(xcenter, ycenter, zcenter, radius, r, g, b, a));
           }
           else if(s.compare("cutsphere")==0){
               int xcenter, ycenter, zcenter, radius;
               ss>>xcenter>>ycenter>>zcenter>>radius;
               figs.push_back(new CutSphere(xcenter, ycenter, zcenter, radius));
           }
           else if(s.compare("putellipsoid")==0){
               int xcenter, ycenter, zcenter, rx, ry, rz;
               float r, g, b, a;
               ss>>xcenter>>ycenter>>zcenter>>rx>>ry>>rz>>r>>g>>b>>a;
               figs.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
           }
           else if(s.compare("cutellipsoid")==0){
               int xcenter, ycenter,  zcenter,  rx,  ry, rz;
               ss>>xcenter>>ycenter>>zcenter>>rx>>ry>>rz;
               figs.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
           }

       }

       for(int i = 0; i< figs.size(); i++){
           figs[i]->draw(*sculptor);
       }


       //(*sculptor).writeOFF("OFF_file");


  return 0;
}



