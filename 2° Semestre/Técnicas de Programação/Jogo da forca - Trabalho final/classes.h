#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>

class Jogador{
public:
    Jogador(std::string nome);

    void set_nome(std::string nome);
    void set_tentativas(int n);
    void set_tempo(time_t tempo1, time_t tempo2);

    std::string get_nome();
    int get_tentativas();
    int get_tempo();

private:
    int tentativas;
    int tempo;

    std::string nome;
};


// Class JOGO
class Jogo{
public:
    Jogo();

    void set_palavras();

    void imprimir_palavras();
    void sorter_palavra();
    void set_record(std::string nome, int tempo);

    void get_forca(int n);

    void get_ranked();

    bool checkar_letra(std::string l);
    bool checkar_palavra(std::string p);
    bool check_prosseguir(int nTentativas);

    int get_n_letras();
    std::string get_palavra_atual();
    std::string get_palavra_resolvida();

private:
    std::string Palavra_Atual;
    std::string Palavra_Resolvida;
    std::string Palavras[50];

    int nLetras;
    int posicao_Palavra;
};

#endif // CLASSES_H
