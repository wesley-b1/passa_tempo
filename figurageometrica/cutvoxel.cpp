#include "cutvoxel.h"
#include "sculptor.h"


CutVoxel::CutVoxel(int _x, int _y, int _z)
{
    x0 = _x;
    y0 = _y;
    z0 = _z;
}

CutVoxel::~CutVoxel()
{

}

void CutVoxel:: draw(Sculptor &t){
    t.cutVoxel(x0, y0, z0);
}
