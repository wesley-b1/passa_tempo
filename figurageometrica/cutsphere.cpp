#include "cutsphere.h"
#include "sculptor.h"
#include "math.h"


CutSphere::CutSphere(int _xcentro, int _ycentro, int _zcentro, int _raio)
{
    xcentro = _xcentro;
    ycentro = _ycentro;
    zcentro = _zcentro;
    raio = _raio;
}

CutSphere::~CutSphere()
{

}

void CutSphere::draw(Sculptor &t)
{

    double dist;
    for(int k=zcentro - raio; k<=zcentro + raio; k++){
        for (int i=xcentro - raio; i<=xcentro + raio; i++) {
            for (int j=ycentro - raio; j<=ycentro + raio; j++){
               dist = pow(i-xcentro,2) + pow(j-ycentro,2) + pow(k-zcentro,2);
               if (dist <= pow(raio,2)){
                   t.cutVoxel(i,j,k);
               }
            }

        }
    }
}
