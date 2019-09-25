#include <iostream>
#include <fstream>
#include <sstream>
#include "sculptor.h"
#include "voxel.h"
using namespace std;

int main()
{
    Sculptor forma(20,20,20);
        forma.setColor(0.4,0.1,0.5,1);
        forma.putVoxel(0,0,0);
        forma.cutVoxel(0,0,0);
        forma.putBox(0,0,0,0,0,0);
        forma.cutBox(0,0,0,0,0,0);

        return 0;
}
