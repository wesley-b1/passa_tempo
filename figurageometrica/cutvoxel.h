#ifndef CUTVOXEL_H
#define CUTVOXEL_H
#include "figurageometrica.h"
#include "sculptor.h"


class CutVoxel : public FiguraGeometrica
{
private:

    int x0, y0, z0;

public:

    CutVoxel(int _x, int _y, int _z);


    ~CutVoxel();

    void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
