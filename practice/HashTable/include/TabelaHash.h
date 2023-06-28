//
//  TabelaHash.h
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#ifndef TabelaHash_h
#define TabelaHash_h

#include "Par.h"
#include <string>

static const int TAMANHO_PADRAO = 17;

class TabelaHash {
private:
    Par<std::string, std::string> **tabela;
    
    unsigned long tamanho;
    
    unsigned long quantidade;
    
public:    
    void iniciar();
    
    unsigned long preHash(const std::string);
    
    unsigned long hash(const std::string);
    
    TabelaHash();
    
    TabelaHash(const unsigned long tamanho);
    
    ~TabelaHash();    
    
    std::string buscar(const std::string chave);
    
    bool inserir(const std::string chave, const std::string valor);
    
    bool remover(const std::string chave);
    
    unsigned long getTamanho();

    void setTamanho(unsigned long);
    
    unsigned long getQuantidade();

    void getQuantidade(unsigned long);
    
    bool vazia();
    
    bool cheia();

    bool verificarDuplicatas();
    
    void imprimir();
};


#endif /* TabelaHash_h */

