//Dado um número natural N, implemente uma função recursiva que imprima na tela do terminal a
//representação binária deste número.

#include <iostream>
#include <string>

using namespace std;

void conversorNpraB(int numero){
    if (numero / 2 != 0) {
        conversorNpraB(numero / 2);
    }
    cout << numero % 2;
}

int main(int argc, char const *argv[]){
    int numero;
    cin >> numero;
    conversorNpraB(numero);
    cout << endl;
    return 0;
}
