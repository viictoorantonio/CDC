#include "classes.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <string>

//Functions Principais
std::string to_upper_case(std::string palavra){
    std::string palavraUPER = "";
    for( int i=0; i<(int)palavra.size(); i++ )
        palavraUPER+= ( palavra[i] >= 'a' && palavra[i] <= 'z')? ( palavra[i] -'a'+'A' ): palavra[i];
    return palavraUPER;
}

std::string replaceAll (std::string palavra, std::string a, std::string b)
{
    std::string nova_palavra = "";
    for(int i = 0 ; i <= palavra.length(); i++)
    {
        for(int j = 0 ; j <= palavra.length()-i; j++)
        {
            nova_palavra = nova_palavra + palavra[j];
            if(nova_palavra == a)
            {
                for(int h = 0 ; h <= j ; h++)
                {
                    palavra[h] = b[h];
                }
            }
        }
    }
    return palavra;
}

//Metodos JOGADOR
Jogador::Jogador(std::string nome){
    set_nome(nome);
    set_tentativas(5);
}

std::string Jogador::get_nome(){
    return this->nome;
}

void Jogador::set_tempo(time_t tempo1, time_t tempo2){
    time_t tempoPartida = tempo1 - tempo2;

    if(tempoPartida < -9){
        tempoPartida = tempoPartida*(-1);
    }

    this->tempo = tempoPartida;
}

int Jogador::get_tempo(){
    return this->tempo;
}

void Jogador::set_tentativas(int n){
    this->tentativas = n;
}

void Jogador::set_nome(std::string nome){
    this->nome = nome;
}

int Jogador::get_tentativas(){
    return this->tentativas;
}

// Metodos JOGO
Jogo::Jogo(){
    set_palavras();
    sorter_palavra();
}

void Jogo::set_palavras(){
        std::string palavra;
        std::ifstream arqAbertura("palavrasaleatorias.txt");

        int cont = 0;

        if (arqAbertura.is_open()){
            while (arqAbertura >> palavra){

                this->Palavras[cont] = palavra;
                cont++;
            }
        }
        arqAbertura.close();
}

void Jogo::get_ranked(){
    std::string linha;
    std::string nome[100];
    std::string tempo_segundos[100];

    int posicao1,posicao2,posicao3;

    std::ifstream arqAberto("recordes.txt");

    int cont = 0;
    if (arqAberto.is_open()){
        while(arqAberto >> linha){
            if(cont% 2 != 0){
                tempo_segundos[cont] = linha;
            } else {
                nome[cont] = linha;
            }
            cont++;
        }
    }

    std::string ranked_1 = "";
    std::string ranked_2 = "";
    std::string ranked_3 = "";

    for(int i=0; i<100; i++){
        //std::cout << "Linha: " << i << " " << tempo_segundos[i] << " " << nome[i] << std::endl;

        if(tempo_segundos[i] != ""){

            if(tempo_segundos[i] < ranked_1 or ranked_1 == ""){

                ranked_3 = ranked_2;
                ranked_2 = ranked_1;
                ranked_1 = tempo_segundos[i];

                posicao3 = posicao2;
                posicao2 = posicao1;
                posicao1 = i-1;

            } else if(tempo_segundos[i] < ranked_2 or ranked_2 == ""){
                posicao3 = posicao2;
                posicao2= i-1;

                ranked_3 = ranked_2;
                ranked_2 = tempo_segundos[i];
            } else if(tempo_segundos[i] < ranked_3 or ranked_3 == "") {
                posicao3 = i-1;
                ranked_3 = tempo_segundos[i];
            }
        }
    }

    arqAberto.close();

    ranked_1 = replaceAll(ranked_1, "-", "");
    ranked_2 = replaceAll(ranked_2, "-", "");
    ranked_3 = replaceAll(ranked_3, "-", "");

    if(ranked_1 == ""){
        std::cout << "\nSem ranqueamento ainda!\n\n";
    } else if(ranked_2 == ""){
        std::cout << "\t\tPrimeiro lugar: \n\t\t  " << nome[posicao1] << " | " << ranked_1 << std::endl;
    } else if(ranked_3 == ""){
        std::cout << "\t\tPrimeiro lugar: \n\t\t  " << nome[posicao1] << " | "  << ranked_1 << std::endl;
        std::cout << "\t\tSegundo lugar: \n\t\t  " << nome[posicao2] << " | " << ranked_2 << std::endl;

    } else {
        std::cout << "\t\tPrimeiro lugar: \n\t\t  " << nome[posicao1] << " | " << ranked_1 << std::endl;
        std::cout << "\t\tPrimeiro lugar: \n\t\t  " << nome[posicao2] << " | "  << ranked_2 << std::endl;
        std::cout << "\t\tTerceiro lugar: \n\t\t  " << nome[posicao3] << " | " << ranked_3 << std::endl;
    }
}

void Jogo::set_record(std::string nome, int tempo){

    std::string linha;
    std::string texto[100];

    std::ifstream arqAberto("recordes.txt");

    int cont = 0;
    if (arqAberto.is_open()){

        while(arqAberto >> linha){
            texto[cont] = linha;
            cont++;
        }
    }

    arqAberto.close();
    remove("recordes.txt");

    std::ofstream arqFechado("recordes.txt");

    if(arqFechado.is_open()){
        for(int i=0; i<=cont; i++){
            if(texto[i] != ""){
                 arqFechado << texto[i] << "\n";
            }
        }

        arqFechado << nome << std::endl;
        arqFechado << tempo;
    }
    arqFechado.close();
}

int Jogo::get_n_letras(){
    return this->nLetras;
}

void Jogo::sorter_palavra(){

    int n;

    srand(time(NULL));
    for (int i=0; i<50; i++){
      n = (rand()%50);
    }

    this->nLetras = Palavras[n].length();

    this->Palavra_Atual = this->Palavras[n];
    this->posicao_Palavra = n;

    this->Palavra_Resolvida = "";

    for(int i=0; i<this->nLetras; i++){
        this->Palavra_Resolvida += "-";
    }
}

bool Jogo::checkar_letra(std::string l){
        std::string letra_resolvida_verificar = Palavra_Resolvida;

        std::string letra;
        std::string letra_Resolvida;

        std::string posicao_Letra[get_n_letras()];

        bool check_existente = false;

        for(int i=0; i<get_n_letras();i++)
        {
            letra = Palavras[this->posicao_Palavra].at(i);
            letra_Resolvida = Palavra_Resolvida.at(i);

            if(l == letra or to_upper_case(l) == letra){
                check_existente = true;
            }

            if(letra == l or letra == to_upper_case(l)){
                posicao_Letra[i] = to_upper_case(l);
            } else if(letra_Resolvida != "-"){
                posicao_Letra[i] = letra_Resolvida;
            } else {
                posicao_Letra[i] = "-";
            }
        }

        this->Palavra_Resolvida = "";

        for(int i=0; i<get_n_letras(); i++){
            this->Palavra_Resolvida += posicao_Letra[i];
        }

        if(Palavra_Resolvida == letra_resolvida_verificar){
            if(check_existente == true){
                return true;
            }
            return false;
        } else{
            return true;
        }
}

bool Jogo::checkar_palavra(std::string p){

        if(p == Palavras[this->posicao_Palavra] or to_upper_case(p) == Palavras[this->posicao_Palavra]){
            return true;
        } else {
            return false;
        }
}

bool Jogo::check_prosseguir(int nTentativas){
    if(nTentativas != 0){
        return true;
    } else {
        return false;
    }
}

void Jogo::get_forca(int n){
    if(n == 5){
        std::cout << " ___ \n";
        std::cout << " | | \n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << " |___\n";
    } else if(n == 4){
        std::cout << " ___ \n";
        std::cout << " | | \n";
        std::cout << " | O  \n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << " |\n";
        std::cout << " |___ \n";
    } else if(n == 3){
        std::cout << " ___  \n";
        std::cout << " | |  \n";
        std::cout << " | O  \n";
        std::cout << " | |  \n";
        std::cout << " |    \n";
        std::cout << " |    \n";
        std::cout << " |___ \n";
    } else if(n == 2){
        std::cout << " ___  \n";
        std::cout << " | |  \n";
        std::cout << " | O  \n";
        std::cout << " |/|\\ \n";
        std::cout << " | |  \n";
        std::cout << " |    \n";
        std::cout << " |___ \n";
    } else if(n == 1){
        std::cout << " ___ \n";
        std::cout << " | | \n";
        std::cout << " | O  \n";
        std::cout << " |/|\\ \n";
        std::cout << " | |  \n";
        std::cout << " |/ \\ \n";
        std::cout << " |___ \n";
    }
}

std::string Jogo::get_palavra_resolvida(){
    return this->Palavra_Resolvida;
}

std::string Jogo::get_palavra_atual(){
    return Palavra_Atual;
}

void Jogo::imprimir_palavras(){
    int cont = 0;

    while(cont < 50){
        std::cout << this->Palavras[cont] << std::endl;
        cont++;
    }
}
