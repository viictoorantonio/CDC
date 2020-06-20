#ifndef ROBO_H
#define ROBO_H

#include "mapa.h"

class Robo{
public:
    void mover_direita();
    void mover_esquerda();
    void mover_cima();
    void mover_baixo();

    int getlinha();
    int getcoluna();

    Robo(Mapa *mapinha);

    Mapa mapinha;

private:
    int cordLinha;
    int cordColuna;
};

#endif // ROBO_H
