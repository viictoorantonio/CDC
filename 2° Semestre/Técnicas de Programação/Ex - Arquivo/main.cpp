#include <iostream>
#include <fstream>

// Victor Antonio Araujo e Vinicius Elias da Silva TP-01

std::string to_upper_case(std::string palavra){
    std::string palavraUPER = "";
    for( int i=0; i<(int)palavra.size(); i++ )
        palavraUPER+= ( palavra[i] >= 'a' && palavra[i] <= 'z')? ( palavra[i] -'a'+'A' ): palavra[i];
    return palavraUPER;
}

int main(){
    std::string palavra;
    std::ifstream arqAbertura("textoInicial.txt");
    std::ofstream arqFinal("textoFinal.txt");

    std::string palavrasRepetidas[100];

    int cont = 0;

    arqFinal.is_open();

    if (arqAbertura.is_open()){
        while (arqAbertura >> palavra){

            bool RepPalavra = true;

            palavra = to_upper_case(palavra);

            for(int i=0; RepPalavra && i<100; i++){

                if(palavrasRepetidas[i] == palavra){
                    RepPalavra = false;
                }
            }


            if(RepPalavra){
              arqFinal << palavra << std::endl;
            }

            palavrasRepetidas[cont] = palavra;

            cont++;
        }
    }

    arqAbertura.close();
    arqFinal.close();
}