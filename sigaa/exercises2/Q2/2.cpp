/*
Considere um array A contendo N inteiros, com possíveis repetições, já ordenado. Neste contexto:
(A) Projete um algoritmo que recebe como entrada um inteiro K e retorna um índice i tal que A[i] == K, sendo A[i]
o elemento igual a K que está mais a esquerda em A. Sua solução deverá ter complexidade Θ (lg(n)).
(B) Projete um algoritmo que recebe como entrada um inteiro K e retorna quantos elementos em A tem valor igual
a K ocorrem no array A. Sua solução deverá ter complexidade Θ (lg(n)).

*/
#include <iostream>

using namespace std;

int buscaBinariaAEsquerda(int chave, int entrada[], int inicio, int fim){
    if (inicio > fim){
        return -1;
    }
    int meio = (inicio + fim) / 2;
    if (chave < entrada[meio]){
        return buscaBinariaAEsquerda(chave, entrada, inicio, meio - 1);
    }
    else if (chave > entrada[meio]){
        return buscaBinariaAEsquerda(chave, entrada, meio + 1, fim);
    }
    else{
        if (entrada[meio - 1] == chave){
            return meio - 1;
        }
        return meio;
    }
}

int buscaBinariaContarOcorrencias(int chave, int entrada[], int inicio, int fim){
    if (inicio >= fim){
        return 0;
    }
    int meio = (inicio + fim) / 2;
    if (chave < entrada[meio]){
        return buscaBinariaContarOcorrencias(chave, entrada, inicio, meio - 1);
    }
    else if (chave > entrada[meio]){
        return buscaBinariaContarOcorrencias(chave, entrada, meio + 1, fim);
    }
    else {
        if (entrada[meio - 1] == chave){
            return (1 + buscaBinariaContarOcorrencias(chave, entrada, inicio, meio - 2));
        } else if(entrada[meio + 1] == chave){
            return (1 + buscaBinariaContarOcorrencias(chave, entrada, inicio, meio + 2));
        }
    } return 1;
}

int main(int argc, char const *argv[]){
    int array[] = {1, 2, 3, 4, 4, 5, 6, 7, 7, 7, 7, 8, 8, 9};
    int tamanho = sizeof(array) / sizeof(array[0]);

    int numero;
    cin >> numero;
    int posicao = buscaBinariaAEsquerda(numero, array, array[0], array[tamanho-1]);
    if (array[posicao] == numero){
        cout << "O número " << numero << " foi encontrado na posicao " << posicao << endl;
    }
    else{
        cout << "O número " << numero << " não foi encontrado no array" << endl;
    }

    int ocorrencias = buscaBinariaContarOcorrencias(numero, array, array[0], array[tamanho-1]);
    cout << "Houveram " << ocorrencias << " ocorrências do número "<< numero << endl;
    return 0;
}
