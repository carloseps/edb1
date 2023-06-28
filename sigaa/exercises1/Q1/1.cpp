//Dada uma string S, implemente uma função recursiva que retorne uma outra string com os caracteres
//de S em ordem inversa

#include <iostream>
#include <string>

using namespace std;

std::string reverteString (std::string palavra, int tamanhoPalavra){
    if (tamanhoPalavra == 0){
        return "\0";
    } else if (tamanhoPalavra == 1){
        std::string stringAux = palavra.substr(0,1);
        return stringAux;
    } else {
        tamanhoPalavra -= 1;
        return palavra[tamanhoPalavra] + reverteString(palavra, tamanhoPalavra);
    }
}

int main(int argc, char const *argv[]){
    std::string palavra;
    cin >> palavra;
    int tamanhoPalavra = palavra.size();
    cout << reverteString(palavra, tamanhoPalavra) << endl;
    return 0;
}
