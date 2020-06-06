#include <iostream>
using namespace std;

class Cachorro {
public:
    void setNome(string nome);
    void setIdade(int idade);

    string getNome();
    int getIdade();
private:
    string nome;
    int idade;
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

int main(){

    Cachorro C1;
    Cachorro C2;

    C1.setNome("Alfredo");
    C2.setNome("Vanderlei");

    C1.setIdade(8);
    C2.setIdade(2);

    cout << "Primeiro cachorro: \nNome: " << C1.getNome() << "\nIdade: " << C1.getIdade() << "\n\n";
    cout << "Segundo cachorro: \nNome: " << C2.getNome() << "\nIdade: " << C2.getIdade() << "\n";

    return 0;
}