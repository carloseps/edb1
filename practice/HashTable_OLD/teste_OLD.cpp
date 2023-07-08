#include "../lib/catch2/catch_amalgamated.hpp"
#include "../include/TabelaHash.h"

TEST_CASE("Tabela Hash - Teste do Construtor") 
{
    unsigned long tamanhoInicial = 23;
    
    TabelaHash tabela(tamanhoInicial);

    CHECK(tabela.getTamanho() == tamanhoInicial);

    CHECK(tabela.getQuantidade() == 0);

    CHECK(tabela.verificarDuplicatas());
}

TEST_CASE("Tabela Hash - Teste de Inserir Simples") 
{
    unsigned long tamanhoInicial = 23;
    
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


TEST_CASE("Tabela Hash - Teste de Inserir e Buscar Simples") 
{
    unsigned long tamanhoInicial = 23;
    
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
    unsigned long tamanhoInicial = 23;
    
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
    unsigned long tamanhoInicial = 23;
    
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
    unsigned long tamanhoInicial = 23;
    
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

    CHECK(tabela.verificarDuplicatas());
}