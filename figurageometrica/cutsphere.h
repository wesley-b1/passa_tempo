#ifndef CUTSPHERE_H
#define CUTSPHERE_H
#include "figurageometrica.h"
#include "sculptor.h"


class CutSphere : public FiguraGeometrica
{
private:

    int xcentro, ycentro, zcentro, raio;
public:


    CutSphere(int _xcentro, int _ycentro, int _zcentro, int _raio);

    ~CutSphere();


    void draw (Sculptor &t);
};

#endif // CUTSPHERE_H
