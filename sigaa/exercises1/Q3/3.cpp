//Dado um número natural N, implemente uma função recursiva que retorne a soma dos dígitos de N. Por
//exemplo, se N for igual a 2117, sua função deve retornar 11 (que é a soma de 2 + 1 + 1 + 7).

#include <iostream>
#include <string>

using namespace std;

int somador(int numero){
    if (numero < 10) {
        return numero;
    } else {
        int ultimoAlgarismo = numero % 10;
        return ultimoAlgarismo + somador(numero/10);
    }
}

int main(int argc, char const *argv[]){
    int numero;
    cin >> numero;
    cout << somador(numero) << endl;
    return 0;
}
