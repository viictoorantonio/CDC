#include "robo.h"
#include "mapa.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Robo::getlinha(){
    return cordLinha;
}

int Robo::getcoluna(){
    return cordColuna;
}

Robo::Robo(Mapa *mapinha){
    this->mapinha = *mapinha;

    int x;
    int y;
    bool aprovado = false;

    while(aprovado == false){

        srand(time(nullptr));
        for (int i=0; i<100; i++){
            x = (rand()%50);
        }

        srand(time(nullptr));
        for (int i=0; i<100; i++){
            y = (rand()%50);
        }

        aprovado = mapinha->acessivel(x,y);
    }

    if(aprovado){
        this->cordLinha = x;
        this->cordColuna = y;
    }
}

void Robo::mover_cima(){
    if(this->mapinha.acessivel(this->cordLinha-1, this->cordColuna)){
        this->cordLinha = this->cordLinha - 1;
    } else if(this->mapinha.saida(this->cordLinha-1, this->cordColuna)) {
    } else {
         printf("Voce nao pode subir mais!");
    }
}

void Robo::mover_baixo(){
   if(this->mapinha.acessivel(this->cordLinha+1, this->cordColuna)){
       this->cordLinha = this->cordLinha + 1;
   } else if(this->mapinha.saida(this->cordLinha+1, this->cordColuna)) {
   } else {
        printf("Voce nao pode abaixar mais!");
   }
}

void Robo::mover_direita(){
    if(this->mapinha.acessivel(this->cordLinha, this->cordColuna+1)){
        this->cordColuna = this->cordColuna + 1;
    } else if(this->mapinha.saida(this->cordLinha, this->cordColuna+1)) {
    } else {
         printf("Voce nao pode ir mais para direita!");
    }
}

void Robo::mover_esquerda(){
    if(this->mapinha.acessivel(this->cordLinha, this->cordColuna-1)){
        this->cordColuna = this->cordColuna - 1;
    } else if(this->mapinha.saida(this->cordLinha, this->cordColuna-1)) {
    } else {
         printf("Voce nao pode ir mais para esquerda!");
    }
}
