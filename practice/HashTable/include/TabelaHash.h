//
//  TabelaHash.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef TabelaHash_h
#define TabelaHash_h

#include "Par.h"
#include <string>

static const std::size_t TAMANHO_PADRAO = 17;
static const float CARGA_LIMITE_INFERIOR = 0.125f;
static const float CARGA_LIMITE_SUPERIOR = 0.5f;

class TabelaHash {
private:
    Par<std::string, std::string> **tabela;
    
    std::size_t tamanho;
    
    std::size_t quantidade;

    void setTamanho(std::size_t);
    
public:    
    void iniciar();
    
    std::size_t preHash(const std::string);
    
    std::size_t hash(const std::string);
    
    TabelaHash();
    
    TabelaHash(const std::size_t tamanho);
    
    ~TabelaHash();    
    
    std::string buscar(const std::string chave);
    
    bool inserir(const std::string chave, const std::string valor);
    
    bool remover(const std::string chave);
    
    std::size_t getTamanho();
    
    std::size_t getQuantidade();

    void getQuantidade(std::size_t);
    
    bool vazia();
    
    bool cheia();

    bool verificarDuplicatas();
    
    void imprimir();

    float fatorDeCarga();

    void aumentar();

    void diminuir();

    void redimensionar(std::size_t);

    void prepararArrayNovo(Par<std::string, std::string>** arrayNovo, std::size_t tamanhoNovo);
};


#endif /* TabelaHash_h */

