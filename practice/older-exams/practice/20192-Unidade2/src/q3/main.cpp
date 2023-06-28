#include <iostream>
#include <cassert>
#include <stack>
#include <vector>

using namespace std;

bool isWellFormed(string s)
{
    cout << "\nERRO: função isWellFormed(string) ainda não foi implementada." << endl;
    std::abort();
}

int main(int argc, const char * argv[]) 
{
    vector<string> valids = {
        "()",
        "[]",
        "{}",
        "()[]{}",
        "{}[]()",
        "[]{}()",
        "{[()]}",
        "({[]})",
        "[({})]",
        "(()){{}}[[]]",
        "(({{[[]]}}))",
        "((){{}[[]]})",
        "({})([])([])({})([])({})",
        "({}[])(([]))(({}[]))",
        "({[]()}{{[]()}}([]{}))",
    };

    int cont = 0;
    int incorreto = 0;

    cout << "Testando entradas válidas: " << endl;
    for(string valid : valids)
    {
        cout << "\tEntrada " << ++cont << ":\t" << valid << "\n\t\tResultado:\t";
        if( isWellFormed(valid) == true )
        {
            cout << "Correto" << endl;
        }
        else
        {
            cout << "Incorreto" << endl;
            ++incorreto;
        }
    }

    vector<string> invalids = {
        "(",
        "[",
        "{",
        ")",
        "]",
        "}",
        "{]",
        "[)",
        "(}",
        "{[",
        "[(",
        "({",
        ")]",
        "]}",
        "})",
        "()(",
        "[]{",
        "{}[",
        "()}",
        "[]]",
        "{})",
        "{})(",
        "{}((",
        "{}))",
        "{}[[",
        "{}{]",
        "()[]{}{)",
        "((){()}]",
        "{[(()[}[]{})]}",
        "((((((((((())))))",
        "(((()))))))))))))",
    };

    cont = 0;
    cout << "\nTestando entradas inválidas: " << endl;
    for(string invalid : invalids)
    {
        cout << "\tEntrada " << ++cont << ":\t" << invalid << "\n\t\tResultado:\t";
        if( isWellFormed(invalid) == false )
        {
            cout << "Correto" << endl;
        }
        else
        {
            cout << "Incorreto" << endl;
            ++incorreto;
        }
    }

    if(incorreto)
    {
        cout << "\nUm total de " << incorreto << " teste(s) falhou/falharam. Verificar acima quais testes falharam." << endl;    
    }
    else
    {
        cout << "\nPassou em todos os testes!" << endl;
    }

    return 0;
}
