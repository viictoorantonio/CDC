#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Cachorro {
public:
    void setNome(string nome);
    void setIdade(int idade);
    string latir();
    string latir(int n);
    string reproduzir(Cachorro* outroCachorro);

    string getNome();
    int getIdade();

    Cachorro();
    Cachorro(string somLatido);
private:
    string nome;
    int idade;
    string latido;
};

void Cachorro::setNome(string nome) {
    this->nome=nome;
}
void Cachorro::setIdade(int idade) {
    this->idade=idade;
}

string Cachorro::getNome() {
    return nome;
}

int Cachorro::getIdade() {
    return idade;
}

Cachorro::Cachorro(string somLatido) {
    this->latido = somLatido;
}

Cachorro::Cachorro() {
    this->latido = "Auuuu!";
}

string Cachorro::latir() {
    return this->latido;
}

string Cachorro::latir(int n) {
    string total;
    for(int i=0; i<n; i++){
        if(i==0)
            total = total + this->latido;
        else
            total = total + " " + this->latido;
    }

    total = total + "\n";

    return total;
}

string Cachorro::reproduzir(Cachorro* outroCachorro) {

    char * str = new char[this->latido.length() +1]; // Cria uma variavel char do tamanho do string +1
    strcpy(str, this->latido.c_str()); //Copia o valor da string para variavel char criada

    char * str2 = new char[outroCachorro->latido.length() +1]; // Cria uma variavel char do tamanho do string +1
    strcpy(str2, outroCachorro->latido.c_str()); //Copia o valor da string para variavel char criada

    double MetadeLatido1 = this->latido.length()/2; // Fala até onde vai o latido dentro do vetor
    double MetadeLatido2 = outroCachorro->latido.length()/2; // Fala até onde vai o latido dentro do vetor

    string LatidoFinal;
    for(int i=0; i<MetadeLatido1; i++){
        LatidoFinal = LatidoFinal + str[i];
    }
    for(int i=MetadeLatido2; i<outroCachorro->latido.length(); i++){
        LatidoFinal = LatidoFinal + str2[i];
    }


    return LatidoFinal;
}

int main(){

    Cachorro a;
    Cachorro b("Woof!");

    Cachorro x = a.reproduzir(&b);
    Cachorro y = b.reproduzir(&a);

    cout << a.latir() <<endl;
    cout << b.latir() <<endl;
    cout << x.latir() <<endl;
    cout << y.latir() <<endl;
    return 0;
}