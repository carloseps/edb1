#include "../lib/catch2/catch_amalgamated.hpp"
#include "../include/ListaDuplamenteEncadeada.h"

TEST_CASE("Inserir na cabeça da lista") 
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(auto s : v)
    {
        int tamanhoAntes = lista.tamanho();
        
        auto valorInserido = s;

        CHECK(lista.checarConsistencia() == OK);
                
        bool inseriu = lista.inserirNaCabeca( valorInserido );

        CHECK(inseriu);

        CHECK(lista.checarConsistencia() == OK);
        
        auto primeiroElemento = lista.getCabeca()->getProximo();

        CHECK(primeiroElemento != nullptr);
        
        auto primeiroValor = primeiroElemento->getValor();

        CHECK(primeiroValor == valorInserido);
        
        int tamanhoDepois = lista.tamanho();

        CHECK(tamanhoDepois == tamanhoAntes+1);
    }
}

TEST_CASE("Inserir na cauda da lista") 
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(auto s : v)
    {
        int tamanhoAntes = lista.tamanho();
        
        auto valorInserido = s;

        CHECK(lista.checarConsistencia() == OK);
                
        bool inseriu = lista.inserirNaCauda( valorInserido );

        CHECK(inseriu);

        CHECK(lista.checarConsistencia() == OK);
        
        auto ultimoElemento = lista.getCauda()->getAnterior();

        CHECK(ultimoElemento != nullptr);
        
        auto ultimoValor = ultimoElemento->getValor();

        CHECK(ultimoValor == valorInserido);
        
        int tamanhoDepois = lista.tamanho();

        CHECK(tamanhoDepois == tamanhoAntes+1);
    }
}

TEST_CASE("Recuperar elemento da i-ésima posição da lista") 
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(auto s : v)
    {
        CHECK( lista.inserirNaCauda( s ) );
    }

    int i = 1;
    for(auto s : v)
    {
        CHECK( lista.recuperar(i) == s );
        ++i;
    }
}

TEST_CASE("Inserir na i-ésima posição da lista") 
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    int tamanhoAntes = lista.tamanho();
    bool inseriu = lista.inserir( 1, v[0] );
    
    CHECK(inseriu);
    
    int tamanhoDepois = lista.tamanho();
    
    CHECK(tamanhoAntes+1 == tamanhoDepois);

    auto verificada = lista.checarConsistencia();

    CHECK(verificada == OK);
    
    int i = 1;
    for(auto s : v)
    {
        int tamanhoAntes = lista.tamanho();
        
        std::string valorInserido = s;
        
        int indice = i % 2 == 0 ? 2 : 1;
        
        verificada = lista.checarConsistencia();
        CHECK(verificada == OK);
        
        inseriu = lista.inserir(indice, valorInserido);
        CHECK(inseriu);
        
        auto valorRetornado = lista.recuperar(indice);

        CHECK(valorRetornado == valorInserido);
        
        int tamanhoDepois = lista.tamanho();
        CHECK(tamanhoAntes+1 == tamanhoDepois);

        ++i;
    }
}

TEST_CASE("Remover elemento da cabeça da lista")
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(auto s : v)
    {
        auto valorInserido = s;
        lista.inserirNaCabeca( valorInserido );
    }
    
    for(int i = 0; i < 10; ++i)
    {
        auto verificada = lista.checarConsistencia();
        CHECK( verificada == OK );
        
        int tamanhoAntes = lista.tamanho();
        auto valorRemovido = lista.removerDaCabeca();
        int tamanhoDepois = lista.tamanho();
        
        CHECK( tamanhoDepois == tamanhoAntes-1 );
        
        auto valorEsperado = v[9-i];

        CHECK( valorRemovido == valorEsperado );
    }
}

TEST_CASE("Remover elemento da cauda da lista")
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(auto s : v)
    {
        auto valorInserido = s;
        lista.inserirNaCauda( valorInserido );
    }
    
    for(int i = 0; i < 10; ++i)
    {
        auto verificada = lista.checarConsistencia();
        CHECK( verificada == OK );
        
        int tamanhoAntes = lista.tamanho();
        auto valorRemovido = lista.removerDaCauda();
        int tamanhoDepois = lista.tamanho();
        
        CHECK( tamanhoDepois == tamanhoAntes-1 );
        
        auto valorEsperado = v[9-i];

        CHECK( valorRemovido == valorEsperado );
    }
}

TEST_CASE("Remover elemento da i-ésima posição da lista")
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(auto s : v)
    {
        auto valorInserido = s;
        lista.inserirNaCabeca( valorInserido );
    }
    
    for(int i = 0; i < 10; ++i)
    {
        auto verificada = lista.checarConsistencia();
        CHECK( verificada == OK );
        
        int tamanhoAntes = lista.tamanho();
        auto valorRemovido = lista.remover(1);
        int tamanhoDepois = lista.tamanho();
        
        CHECK( tamanhoDepois == tamanhoAntes-1 );
        
        auto valorEsperado = v[9-i];

        CHECK( valorRemovido == valorEsperado );
    }
}

TEST_CASE("Buscar elemento na lista")
{
    ListaDuplamenteEncadeada lista;
    
    std::string v[] = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    for(auto s : v)
    {
        auto valorInserido = s;
        lista.inserirNaCauda(valorInserido);
    }
    
    for(int i = 0; i < 10; ++i)
    {
        auto valorBuscado = v[i];
        int indiceRetornado = lista.buscar(valorBuscado);

        CHECK(indiceRetornado == i+1);
        
        auto verificada = lista.checarConsistencia();

        CHECK( verificada == OK );
    }
    
    std::string inexistentes[] = {"0", "50", "100", "200"};
    
    for(int i = 0; i < 4; i++)
    {
        int indiceRetornado = lista.buscar(inexistentes[i]);
        CHECK( indiceRetornado == -1 );
        
        auto verificada = lista.checarConsistencia();
        CHECK( verificada == OK );
    }
}

TEST_CASE("Inserir elemento na lista mantendo a ordenação crescente")
{
    ListaDuplamenteEncadeada lista;

    std::string v[] = {"juliet", "india", "hotel", "golf", "fox", "echo", "delta", "charlie","bravo", "alpha"};
    
    for(auto s : v)
    {
        int tamanhoAntes = lista.tamanho();
        lista.inserirOrdenado(s);
        int tamanhoDepois = lista.tamanho();
        
        CHECK( tamanhoDepois == tamanhoAntes+1 );

        // Verifica se o primeiro elemento possui o valor igual ao elemento inserido,
        // pois o elemento recém-inserido sempre será menor do que os que já existem na lista,
        // logo, sempre será o primeiro
        CHECK( lista.getCabeca()->getProximo()->getValor() == s );
    }
}

TEST_CASE("Buscar elemento na lista e mover para frente")
{
    ListaDuplamenteEncadeada lista;

    std::string v[] = {"juliet", "india", "hotel", "golf", "fox", "echo", "delta", "charlie","bravo", "alpha"};
    
    for(auto s : v)
    {
        lista.inserirNaCabeca(s);
    }

    for(auto s : v)
    {
        int tamanhoAntes = lista.tamanho();
        
        int i = lista.buscarMF(s);
        CHECK( i == 1 );
        
        int tamanhoDepois = lista.tamanho();
        
        CHECK( tamanhoDepois == tamanhoAntes );

        CHECK( lista.getCabeca()->getProximo()->getValor() == s );
    }
}

