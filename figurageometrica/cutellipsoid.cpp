#include "cutellipsoid.h"
#include "sculptor.h"
#include "math.h"

CutEllipsoid::CutEllipsoid(int _xcentro, int _ycentro, int _zcentro, int _rx, int _ry, int _rz)
{
    xcentro = _xcentro;
    ycentro = _ycentro;
    zcentro = _zcentro;
    rx = _rx;
    ry = _ry;
    rz = _rz;
}

CutEllipsoid::~CutEllipsoid()
{

}

void CutEllipsoid::draw(Sculptor &t)
{
    double dist;

    if (rx ==0){
        for (int k=zcentro - rz;k<=zcentro + rz;k++) {
            for (int j=ycentro - ry;j<=ycentro + ry;j++) {
                dist =  pow(j-ycentro,2)/pow(ry,2) + pow(k-zcentro,2)/pow(rz,2);
                if(dist<=1){
                    t.cutVoxel(xcentro,j,k);
              }
            }
        }
    }
    else if(ry==0){
        for (int k=zcentro - rz;k<=zcentro + rz;k++) {
            for (int i=xcentro - rx;i<=xcentro + rx;i++) {
                dist =  pow(i-xcentro,2)/pow(rx,2) + pow(k-zcentro,2)/pow(rz,2);
                if(dist<=1){
                    t.cutVoxel(i,ycentro,k);
              }
            }
        }
    }
    else if (rz==0) {
        for (int i=xcentro - rx;i<=xcentro + rx;i++) {
            for (int j=ycentro - ry;j<=ycentro + ry;j++) {
                dist =  pow(i-xcentro,2)/pow(rx,2) + pow(j-ycentro,2)/pow(ry,2);
                if(dist<=1){
                    t.cutVoxel(i,j,zcentro);
              }
            }
        }
    }
    else{
    for (int k=zcentro - rz;k<=zcentro + rz;k++) {
        for (int i=xcentro - rx;i<xcentro + rx;i++) {
            for (int j=ycentro - ry;j<=ycentro + ry;j++) {
                  dist = pow(i-xcentro,2)/pow(rx,2) + pow(j-ycentro,2)/pow(ry,2) + pow(k-zcentro,2)/pow(rz,2);
                if(dist<=1){
                    t.cutVoxel(i,j,k);
                }

            }

        }
    }
    }

}
