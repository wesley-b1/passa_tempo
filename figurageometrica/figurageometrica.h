#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "sculptor.h"

class FiguraGeometrica{
public:
  FiguraGeometrica();
  // declara-se o metodo draw
  // como um funcao-membro virtual PURA
  // colocando "=0" apos o seu prototipo
  // antes do ";"
  virtual void draw(Sculptor &t)=0;
  // destrutores virtuais devem
  // OBRIGATORIAMENTE ser implementados
  // em classes que servirão de base
  // para outras classes
  virtual ~FiguraGeometrica();
};

#endif // FIGURAGEOMETRICA_H









