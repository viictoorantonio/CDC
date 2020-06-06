#include <iostream>
using namespace std;

class Cachorro {
public:
    void setNome(string nome);
    void setIdade(int idade);
    void latir();

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

void Cachorro::latir() {
    cout << this->latido << " ";
}

int main(){

    Cachorro C1;
    Cachorro C2("Woof!");

    C1.setNome("Alfredo");
    C2.setNome("Vanderlei");

    C1.setIdade(8);
    C2.setIdade(2);

    cout << "Primeiro cachorro: \nNome: " << C1.getNome() << "\nIdade: " << C1.getIdade() << "\n\n";
    cout << "Segundo cachorro: \nNome: " << C2.getNome() << "\nIdade: " << C2.getIdade() << "\n";

    for(int i=0; i<5; i++){
        C1.latir();
    }

    cout << "\n";

    for(int i=0; i<7; i++){
        C2.latir();
    }

    return 0;
}