#include <iostream>
#include <time.h>
#include "classes.h"

int main()
{

    char valor = '1';
    std::string letraChute;
    std::string palavraChute;
    std::string nome;

    bool check_letra = true;
    bool check_palavra = true;
    bool check_proseguir = true;
    bool check_play = true;

    Jogo all;

    std::cout << "\n- Antes de comecar digite seu nome: ";
    std::cin >> nome;


    Jogador jogador(nome);

    time_t tempoInicio = time (0);

    while(check_play){

        system("cls");

        check_proseguir = all.check_prosseguir(jogador.get_tentativas());

        if(check_proseguir){
            //std::cout << all.get_palavra_atual() << std::endl;

            std::cout << "------------------------------------"<< std::endl;
            std::cout << "| Seu nome: " << jogador.get_nome() << " | Tentativas: " << jogador.get_tentativas() << " |" << std::endl;
            std::cout << "------------------------------------"<< std::endl;

            all.get_forca(jogador.get_tentativas());

            std::cout << "\n\t" << all.get_palavra_resolvida() << std::endl;

            std::cout << "\n Digite: \n 1 - CHUTAR LETRA \n 2 - CHUTAR PALAVRA \n 3 - SORTEAR NOVA PALAVRA \n\n- ";
            std::cin >> valor;

            if(valor == '1'){
                std::cout << "\nDigite uma Letra: ";
                std::cin >> letraChute;

                check_letra = all.checkar_letra(letraChute);
                if(check_letra == false){
                    jogador.set_tentativas(jogador.get_tentativas()-1);
                }
            } else if(valor == '2'){
                check_play = false;

                std::cout << "\nChute uma palavra: ";
                std::cin >> palavraChute;

                check_palavra = all.checkar_palavra(palavraChute);
            } else if(valor == '3'){
                all.sorter_palavra();
                jogador.set_tentativas(5);
            }

        } else {

            check_play = false;

            std::cout << "\nSuas chances acabaram tente uma palavra: ";
            std::cin >> palavraChute;

            check_palavra = all.checkar_palavra(palavraChute);
        }

        if(all.get_palavra_atual() == all.get_palavra_resolvida()){
            check_play = false;
        }
    }

    time_t tempoFim = time (0);

    if(check_palavra){
        system("cls");
        std::cout << "=========================================";
        std::cout << "\n|\t\tVoce Ganhou!\t\t|\n";
        std::cout << "\n\t    Palavra era: " << all.get_palavra_atual() << "\n";
        std::cout << "=========================================\n";

        jogador.set_tempo(tempoInicio, tempoFim);
        all.set_record(jogador.get_nome(), jogador.get_tempo());
    } else {
        system("cls");
        std::cout << "=========================================";
        std::cout << "\n|\t\tVoce Perde.\t\t|\n";
        std::cout << "\n\t    Palavra era: " << all.get_palavra_atual() << "\n";
        std::cout << "=========================================\n";  
    }

    all.get_ranked();

    return 0;
}
