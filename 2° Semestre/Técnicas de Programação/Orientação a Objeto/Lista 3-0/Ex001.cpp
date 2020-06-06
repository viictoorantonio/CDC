#include <iostream>
using namespace std;

class Cachorro {
public:
    string nome;
    int idade;
};

int main(){

    Cachorro C1;
    Cachorro C2;

    C1.nome = "Alfredo";
    C2.nome = "Vanderlei";

    C1.idade = 8;
    C2.idade = 2;

    cout << "Primeiro cachorro: \nNome: " << C1.nome << "\nIdade: " << C1.idade << "\n";
    cout << "Segundo cachorro: \nNome: " << C2.nome << "\nIdade: " << C2.idade << "\n";

    return 0;
}