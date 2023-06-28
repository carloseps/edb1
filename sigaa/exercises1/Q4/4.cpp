/*
Considere a seguinte função que retorna o n-ésimo elemento na sequência de Fibonacci:
int fib(int n)
{
 int a = 1, b = 0, res = 0;
 for (int i = 1; i <= n; ++i)
 {
 res = a + b;
 b = a;
 a = res;
 }
 return res;
}
Inspirado nesta solução, implemente uma função com recursão em cauda para determinar o n-ésimo elemento na
sequência de Fibonacci.

*/
#include <iostream>
#include <string>

using namespace std;

int fibo(int numero){
    if (numero <= 1) {
        return numero;
    } else {
        return (fibo(numero-1) + fibo(numero-2));
    }
}

int main(int argc, char const *argv[]){
    int numero;
    cin >> numero;
    cout << fibo(numero) << endl;
    return 0;
}
