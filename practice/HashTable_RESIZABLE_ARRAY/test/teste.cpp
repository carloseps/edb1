#include "../lib/catch2/catch_amalgamated.hpp"
#include "../include/TabelaHash.h"
#include <iostream>

TEST_CASE("Tabela Hash - Teste do Construtor") 
{
    std::size_t tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    CHECK(tabela.getTamanho() == tamanhoInicial);

    CHECK(tabela.getQuantidade() == 0);

    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir Simples") 
{
    std::size_t tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    std::string chave = "CHAVE";
    std::string valor = "VALOR";

    auto quantidadeAntes = tabela.getQuantidade();
    bool inseriu = tabela.inserir(chave, valor);
    auto quantidadeDepois = tabela.getQuantidade();

    CHECK(inseriu);
    CHECK(quantidadeAntes+1 == quantidadeDepois);
    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir Vários Seguidos") 
{
    std::size_t tamanhoInicial = 1379;
    
    TabelaHash tabela(tamanhoInicial);

    for(std::size_t i = 0; i < tamanhoInicial; ++i)
    {
        std::string chave = "CHAVE-" + std::to_string(i);
        std::string valor = "VALOR-" + std::to_string(i);
        tabela.inserir(chave, valor);
    }

    // CHECK(tabela.inserir("nova-chave", "tabela cheia") == false);

    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir e Buscar Simples") 
{
    std::size_t tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    std::string chave = "CHAVE";
    std::string valorInserido = "VALOR";

    tabela.inserir(chave, valorInserido);    
    
    auto valorRetornado = tabela.buscar(chave);
    
    CHECK(valorInserido == valorRetornado);
    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir com Colisões (Requer Busca)") 
{
    std::size_t tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    std::string chave1 = "CHAVE";
    std::string valor1 = "VALOR1";

    std::string chave2 = "AVECH";
    std::string valor2 = "VALOR2";

    bool inseriu1 = tabela.inserir(chave1, valor1);
    bool inseriu2 = tabela.inserir(chave2, valor2);
    
    CHECK(inseriu1);
    CHECK(inseriu2);

    CHECK(valor1 == tabela.buscar(chave1));
    CHECK(valor2 == tabela.buscar(chave2));    

    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir, Buscar e Remover Simples") 
{
    std::size_t tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    std::string chave = "CHAVE";
    std::string valorInserido = "VALOR";

    tabela.inserir(chave, valorInserido); 

    CHECK("NÃO ACHOU" == tabela.buscar("CHAVE QUE NAO EXISTE"));   

    auto valorRetornado = tabela.buscar(chave);
    
    CHECK(valorInserido == valorRetornado);

    auto quantidadeAntes = tabela.getQuantidade();
    
    auto removeu = tabela.remover(chave);
    
    auto quantidadeDepois = tabela.getQuantidade();

    CHECK(removeu);
    CHECK(quantidadeAntes == quantidadeDepois+1);

    valorRetornado = tabela.buscar(chave);

    CHECK("TABELA VAZIA" == valorRetornado);

    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir com Colisões, Remoções e Busca") 
{
    std::size_t tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    std::string chave1 = "CHAVE";
    std::string valor1 = "VALOR1";

    std::string chave2 = "ECHAV";
    std::string valor2 = "VALOR2";

    std::string chave3 = "VECHA";
    std::string valor3 = "VALOR3";

    std::string chave4 = "AVECH";
    std::string valor4 = "VALOR4";

    CHECK( tabela.inserir(chave1, valor1) );
    CHECK( tabela.inserir(chave2, valor2) );    
    CHECK( tabela.inserir(chave3, valor3) );
    CHECK( tabela.inserir(chave4, valor4) ); 

    CHECK( tabela.remover(chave1) );
    auto removeu2 = tabela.remover(chave2);
    CHECK( removeu2 );

    auto buscado4 = tabela.buscar(chave4);
    CHECK( buscado4 == valor4 );

    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserções sucessivas de mesma chave devem atualizar o valor") 
{
    TabelaHash tabela;

    std::string chave1 = "CHAVE";
    std::string valor1 = "VALOR1";

    tabela.inserir(chave1, valor1);

    CHECK(tabela.buscar(chave1) == valor1);

    std::string novoValor = "NOVO";

    auto quantidadeAntes = tabela.getQuantidade();
    tabela.inserir(chave1, novoValor);
    auto quantidadeApos = tabela.getQuantidade();

    CHECK(tabela.buscar(chave1) == novoValor);
    CHECK(quantidadeAntes == quantidadeApos);

    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir-Atualizar com remoções no meio") 
{
    TabelaHash tabela;

    std::string chave1 = "CHAVE";
    std::string valor1 = "VALOR1";

    std::string chave2 = "ECHAV";
    std::string valor2 = "VALOR2";

    std::string chave3 = "VECHA";
    std::string valor3 = "VALOR3";

    std::string chave4 = "AVECH";
    std::string valor4 = "VALOR4";
    
    std::string chave5 = "HAVEC";
    std::string valor5 = "VALOR5";
    
    tabela.inserir(chave1, valor1);
    tabela.inserir(chave2, valor2);
    tabela.inserir(chave3, valor3);
    tabela.inserir(chave4, valor4);
    tabela.inserir(chave5, valor5);
    tabela.remover(chave1);
    tabela.remover(chave2);    
    
    auto novoValor = "NOVO";

    CHECK(tabela.inserir(chave5, novoValor));
    CHECK(tabela.buscar(chave5) == novoValor);
    CHECK(tabela.inserir(chave2, valor2));

    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Aumentar dinamicamente a tabela") 
{
    std::size_t tamanhoInicial = 1779;
    
    TabelaHash tabela(tamanhoInicial);

    auto chaveBase = "CHAVE--";
    auto valorBase = "VALOR--";

    for(std::size_t i = 0; i < 2*tamanhoInicial; i++)
    {
        auto chaveInserida = chaveBase + std::to_string(i);
        auto valorInserido = valorBase + std::to_string(i);

        tabela.inserir(chaveInserida, valorInserido);
    }

    // Esperado que a tabela cresça
    CHECK( tamanhoInicial < tabela.getTamanho() );

    for(std::size_t i = 0; i < tamanhoInicial; i++)
    {
        auto chaveInserida = chaveBase + std::to_string(i);
        auto valorInserido = valorBase + std::to_string(i);

        // É esperado encontrar todos elementos que estavam antes sejam encontrados após o aumento
        auto valorRetornado = tabela.buscar(chaveInserida);
        CHECK( valorInserido == valorRetornado );        
    }

    CHECK( tabela.fatorDeCarga() < CARGA_LIMITE_SUPERIOR );
}

TEST_CASE("Tabela Hash - Teste de Diminuir dinamicamente a tabela") 
{
    std::size_t tamanhoInicial = 1779;
    
    TabelaHash tabela(tamanhoInicial);

    auto chaveBase = "CHAVE--";
    auto valorBase = "VALOR--";

    for(std::size_t i = 0; i < 2*tamanhoInicial; i++)
    {
        auto chaveInserida = chaveBase + std::to_string(i);
        auto valorInserido = valorBase + std::to_string(i);

        tabela.inserir(chaveInserida, valorInserido);
    }
    
    for(std::size_t i = 0; i < tamanhoInicial; i++)
    {
        auto chaveInserida = chaveBase + std::to_string(i);
        auto valorInserido = valorBase + std::to_string(i);

        // É esperado encontrar todos elementos que estavam antes sejam encontrados após o aumento
        auto valorRetornado = tabela.buscar(chaveInserida);
        CHECK( valorInserido == valorRetornado );        
    }

    auto tamanhoAntesDasRemocoes = tabela.getTamanho();
    
    // Série de remoções para forçar a diminuição
    for(std::size_t i = 0; i < 2*tamanhoInicial; i++)
    {
        auto chaveRemovida = chaveBase + std::to_string(i);

        auto foiRemovido = tabela.remover(chaveRemovida);
        CHECK( foiRemovido );
    }

    CHECK( tamanhoAntesDasRemocoes > tabela.getTamanho());
    CHECK( tabela.getQuantidade() == 0);

    CHECK( tabela.fatorDeCarga() < CARGA_LIMITE_SUPERIOR );
}