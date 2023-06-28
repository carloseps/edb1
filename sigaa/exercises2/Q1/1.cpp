/*
Dado um inteiro X e um array A contendo N inteiros distintos, o problema
Soma-2 é definido como o problema de determinar se existem dois índices i e j tais que A[i] + A[j] == X. Neste
contexto, projete duas soluções para o problema Soma-2 com complexidades Θ(n2) e Θ(n*lg(n)).
*/
#include <iostream>

using namespace std;

int buscaBinaria(int chave, int entrada[], int inicio, int fim){
    if (inicio > fim){
        return -1;
    }
    int meio = (inicio + fim) / 2;
    if (chave < entrada[meio]){
        return buscaBinaria(chave, entrada, inicio, meio - 1);
    }
    else if (chave > entrada[meio]){
        return buscaBinaria(chave, entrada, meio + 1, fim);
    }
    else{
        return meio;
    }
}

bool soma2Solucao1(int array[], int tamanho, int numero){
    if (tamanho <= 1){
        return false;
    }
    else{
        for (int i = 0; i < tamanho; i++){
            for (int j = 0; j < tamanho; j++){
                if ((array[i] + array[j]) == numero){
                    cout << array[i] << endl;
                    cout << array[j] << endl;
                    return true;
                }
            }
        }
        return false;
    }
}

bool soma2Solucao2(int array[], int tamanho, int numero){
    if (tamanho <= 1){
        return false;
    }
    else {
        for (int i = 0; i < tamanho; i++){
            int posicao = buscaBinaria(numero - array[i], array, array[0], array[tamanho-1]);
            if((array[posicao] + array[i]) == numero){
                cout << array[posicao] << endl;
                cout << array[i] << endl;
                return true;
            }
        }
        return false;
    }
}

int main(int argc, char const *argv[]){
    int array[] = {3, 6, 1, 8, 2, 9, 4, 7, 5};
    int tamanho = sizeof(array) / sizeof(array[0]);

    int array2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int tamanho2 = sizeof(array2) / sizeof(array2[0]);

    int numero;
    cin >> numero;
    if (soma2Solucao1(array, tamanho, numero)){
        cout << "SOLUÇÃO 1: São dois números no array que quando somados resultam em " << numero << endl;
    }
    else{
        cout << "SOLUÇÃO 1: Não existem dois números no array que quando somados resultam em " << numero << endl;
    }

    if (soma2Solucao2(array2, tamanho2, numero)){
        cout << "SOLUÇÃO 2: São dois números no array que quando somados resultam em " << numero << endl;
    }
    else{
        cout << "SOLUÇÃO 2: Não existem dois números no array que quando somados resultam em " << numero << endl;
    }
    return 0;
}
