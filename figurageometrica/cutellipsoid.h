#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "figurageometrica.h"
#include "sculptor.h"


class CutEllipsoid : public FiguraGeometrica
{
private:
    int xcentro,ycentro,zcentro,rx,ry,rz;

public:


    CutEllipsoid(int _xcentro, int _ycentro, int _zcentro, int _rx, int _ry, int _rz);


    ~CutEllipsoid();


    void draw(Sculptor &t);
};

#endif // CUTELLIPSOID_H
