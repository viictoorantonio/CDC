#include <iostream>
#include "robo.h"
#include "mapa.h"

int main(){

    Mapa mapa;
    Robo robozinho(&mapa);

    int valor;

    std::cout << "\nSeu robo nasceu na posicao: " << robozinho.getlinha() << " e " << robozinho.getcoluna() << "\n";

    for(int i=0; i<mapa.getLins(); i++){
        for(int j=0; j<mapa.getCols(); j++){
            if(robozinho.getlinha() == i && robozinho.getcoluna() == j && mapa.acessivel(i,j)){
                std::cout << "@";
            }else if(mapa.parede(i,j)){
                std::cout << "#";
            } else if(mapa.saida(i,j)){
                std::cout << "$";
            } else if(mapa.acessivel(i,j) && mapa.saida(i,j)==false){
                std::cout << "-";
            }
        }
        std::cout << "\n";
    }

    std::cout << "\nDigite 1 - CIMA \n" << "Digite 2 - DIREITA \n" << "Digite 3 - ESQUERDA \n" << "Digite 4 - BAIXO \n";

    std::cin >> valor;

    bool terminou = false;

    while(valor != 0){

        if(valor == 1){
          robozinho.mover_cima();
        } else if(valor == 2){
            robozinho.mover_direita();
        }else if(valor == 3){
            robozinho.mover_esquerda();
        }else if(valor == 4){
            robozinho.mover_baixo();
        }

        terminou = mapa.saida(robozinho.getlinha(), robozinho.getcoluna());

          if(terminou == false){

            system("cls");

            for(int i=0; i<mapa.getLins(); i++){
                for(int j=0; j<mapa.getCols(); j++){
                    if(robozinho.getlinha() == i && robozinho.getcoluna() == j && mapa.acessivel(i,j)){
                        std::cout << "@";
                    }else if(mapa.parede(i,j)){
                        std::cout << "#";
                    } else if(mapa.saida(i,j)){
                        std::cout << "$";
                    } else if(mapa.acessivel(i,j) && mapa.saida(i,j)==false){
                        std::cout << "-";
                    }
                }
                std::cout << "\n";
            }

            std::cout << "\nDigite 1 - CIMA \n" << "Digite 2 - DIREITA \n" << "Digite 3 - ESQUERDA \n" << "Digite 4 - BAIXO \n" << "Digite 0 PARA ACABAR \n";
            std::cin >> valor;
        } else {
            valor = 0;
            system("cls");

            std::cout << "\tVoce GANHOUUUU!!\n\n";
        }
    }
}
