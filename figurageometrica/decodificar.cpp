#include <iostream>
#include "sculptor.h"
#include <string>
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include "figurageometrica.h"
#include "decodificar.h"
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;



Sculptor decodificar (string &filename){

    Sculptor *s;
    // Vetor que armazena os ponteiros para acessar as diversar figuras geometricas
    vector<FiguraGeometrica *> fgs;

    // Leitura e tratamento do arquivo
    ifstream file;
    string line, first;
    //stringstream sline;


    file.open(filename);
    cout << filename << endl;
    if(file.is_open()){
        cout << "Arquivo .txt aberto com sucesso" << endl;
    }
    else{
        cout << "O arquivo .txt nao pode ser aberto" << endl;
        exit(0);
    }

    while(file.good()){
        // Leitura de cada linha
        getline(file,line);
        stringstream sline;
        sline.clear();
        sline.str(line);
        sline >> first;

        if (first.compare("dim") == 0){
             int nx=0, ny=0, nz=0;
             sline >> nx >> ny >> nz;
             s = new Sculptor(nx, ny, nz);

        }

        else if (first.compare("putvoxel") == 0){
            int v_x0, v_y0, v_z0;
            float v_r,v_g,v_b,v_a;
            sline >> v_x0 >> v_y0 >> v_z0 >> v_r >> v_g >> v_b >>v_a ;
            fgs.push_back(new PutVoxel(v_x0,v_y0,v_z0,v_r,v_g,v_b,v_a));
        }

        else if (first.compare("cutvoxel") == 0){
            int vc_x0, vc_y0, vc_z0;
            sline >> vc_x0 >> vc_y0 >> vc_z0;
            fgs.push_back(new CutVoxel(vc_x0,vc_y0,vc_z0));
        }

        else if (first.compare("putbox") == 0) {
            int b_x0, b_x1, b_y0, b_y1, b_z0, b_z1;
            float b_r, b_g, b_b, b_a;
            sline >> b_x0 >> b_x1 >> b_y0 >> b_y1 >> b_z0 >> b_z1 >> b_r >> b_g >> b_b >> b_a;
            fgs.push_back(new PutBox(b_x0,b_x1,b_y0,b_y1,b_z0,b_z1,b_r,b_g,b_b,b_a));

        }

        else if (first.compare("cutbox") == 0) {
            int bc_x0, bc_x1, bc_y0, bc_y1, bc_z0, bc_z1;
            sline >> bc_x0 >> bc_x1 >> bc_y0 >> bc_y1 >> bc_z0 >> bc_z1;
            fgs.push_back(new CutBox(bc_x0,bc_x1,bc_y0,bc_y1,bc_z0,bc_z1));

        }

        else if (first.compare("putsphere") == 0) {
            int s_xcenter, s_ycenter, s_zcenter, s_radius;
            float s_r, s_g, s_b, s_a;
            sline >> s_xcenter >> s_ycenter>> s_zcenter >> s_radius >> s_r >> s_g >> s_b >> s_a;
            fgs.push_back(new PutSphere(s_xcenter, s_ycenter,s_zcenter,s_radius,s_r,s_g,s_b,s_a));

        }

        else if (first.compare("cutsphere") == 0) {
            int s_xcenter, s_ycenter, s_zcenter, s_radius;
            sline >> s_xcenter >> s_ycenter>> s_zcenter >> s_radius;
            fgs.push_back(new CutSphere(s_xcenter, s_ycenter,s_zcenter,s_radius));

        }

        else if (first.compare("putellipsoid") == 0) {
            int e_xcenter, e_ycenter, e_zcenter, e_rx, e_ry, e_rz;
            float e_r, e_g, e_b, e_a;
            sline >> e_xcenter >> e_ycenter>> e_zcenter >> e_rx >> e_ry >> e_rz >> e_r >> e_g >> e_b >> e_a;
            fgs.push_back(new PutEllipsoid(e_xcenter, e_ycenter, e_zcenter, e_rx, e_ry, e_rz, e_r, e_g, e_b, e_a));

        }

        else if (first.compare("cutellipsoid") == 0) {
            int e_xcenter, e_ycenter, e_zcenter, e_rx, e_ry, e_rz;
            sline >> e_xcenter >> e_ycenter>> e_zcenter >> e_rx >> e_ry >> e_rz;
            fgs.push_back(new CutEllipsoid(e_xcenter, e_ycenter, e_zcenter, e_rx, e_ry, e_rz));

        }
    }

    // Sculptor s(nx,ny,nz);

     vector<FiguraGeometrica*>::iterator it;

     // Desenhando as figuras geometricas
     for(it = fgs.begin();it != fgs.end();it++){
         (*it)->draw(*s);
     }

     // Limpando a memoria
     for (it = fgs.begin(); it != fgs.end();it++) {
         delete *it;
     }

     // Fechar o arquivo
     file.close();

     return *s;

}
