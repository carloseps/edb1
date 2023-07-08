//
//  main.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "../include/TabelaHash.h"
#include <iostream>

int main(int argc, const char * argv[]) 
{
    TabelaHash tabela;

    std::cout << tabela.getTamanho() << std::endl;
    tabela.imprimir();

    return 0;
}

