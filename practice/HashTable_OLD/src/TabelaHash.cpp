//
//  TabelaHash.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "../include/TabelaHash.h"
#include <string>
#include <iostream>

using namespace std;

Par<std::string, std::string> *REMOVIDO = (Par<std::string,std::string>*)(-1);

TabelaHash::TabelaHash()
{
    this->tamanho = TAMANHO_PADRAO;
    iniciar();
}

TabelaHash::TabelaHash(const unsigned long tamanho)
{
    this->tamanho = tamanho;
    iniciar();
}

void TabelaHash::iniciar()
{
    this->tabela = new Par<std::string, string>*[ this->getTamanho() ];
    this->quantidade = 0;
    for( unsigned long i = 0; i < this->getTamanho(); i++ )
    {
        this->tabela[i] = nullptr;
    }
}

TabelaHash::~TabelaHash()
{
    for( unsigned i = 0; i < this->getTamanho(); i++ )
    {
        Par<string, string>* entry = this->tabela[i];
        
        if( entry != nullptr && entry != REMOVIDO )
        {
            delete entry;
        }
    }
    delete [] tabela;
}

/**
 Este método deve inserir na tabela um novo Par com 'chave' e 'valor' recebidos como parâmetros. Neste caso, a quantidade de itens na tabela deve ser incrementada e retorna-se 'true'.
 Caso já exista um Par com atributo 'chave' == parâmetro 'chave', deve apenas atualizar o atributo 'valor' do Par. Neste caso, a quantidade de itens na tabela não é modificada e retorna-se 'true'.
 */
bool TabelaHash::inserir(const string chave, const string valor)
{
    if(this->cheia()){
        return false;
    }
    auto indiceBase = hash(chave) % this->getTamanho();

    int indiceDoRemovido = -1;

    for (std::size_t delta = 0; delta < this->getTamanho(); delta++) {
        if(tabela[indiceBase + delta] == nullptr){
            auto *ptrNovo = new Par<std::string, std::string>(chave, valor);
            tabela[indiceBase + delta] = ptrNovo;
            ++this->quantidade;
            return true;
        } else if(tabela[indiceBase + delta] == REMOVIDO && indiceDoRemovido == -1){
            indiceDoRemovido = indiceBase + delta;
        } else if(tabela[indiceBase + delta] != REMOVIDO && tabela[indiceBase + delta]->getChave() == chave){
            tabela[indiceBase + delta]->setValor(valor);
            return true;
        }
    }
    if(indiceDoRemovido != -1){
        auto *ptrNovo = new Par<std::string, std::string>(chave, valor);
        tabela[indiceDoRemovido] = ptrNovo;
        ++this->quantidade;
        return true;
    }
    return false;
}

/**
 Este método deve buscar na tabela um Par com 'chave', retornando o 'valor' associado. 
 */
std::string TabelaHash::buscar(const string chave)
{
    if(this->vazia()){
        return "TABELA VAZIA";
    }
    auto indiceBase = hash(chave) % this->getTamanho();

    for (unsigned long delta = 0; delta < this->getTamanho() - indiceBase; delta++) {
        if(tabela[indiceBase + delta] != REMOVIDO && (tabela[indiceBase + delta] != nullptr && tabela[indiceBase + delta]->getChave() == chave)){
            return tabela[indiceBase + delta]->getValor();
        }
    }
    return "NÃO ACHOU";
}

/**
 Este método deve remover da tabela o Par cujo atributo 'chave' == parâmetro 'chave'. Neste caso, a quantidade de itens na tabela deve ser dencrementada e retorna-se 'true'.
 Caso não exista um Par com atributo 'chave' == parâmetro 'chave',a quantidade de itens na tabela não é modificada e retorna-se 'false'.
 */
bool TabelaHash::remover(const string chave)
{
    if(this->vazia()){
        return false;
    }
    auto indiceBase = hash(chave);

    for (unsigned long delta = 0; delta < this->getTamanho(); delta++) {
        if(tabela[indiceBase + delta] != REMOVIDO && (tabela[indiceBase + delta] != nullptr && tabela[indiceBase + delta]->getChave() == chave)){
            delete tabela[indiceBase + delta];
            tabela[indiceBase + delta] = REMOVIDO;
            --this->quantidade;
            return true;
        }
    }
    return false;
}

unsigned long TabelaHash::preHash(const string chave)
{
    unsigned long x = 0;
    for(unsigned int i = 0; i < chave.size(); i++)
    {
        // Não mudar!
        // Coloquei propositalmente uma versão simples pra facilitar a criação de colisões nos testes!
        x += chave.at(i);
    }
    return x;
}

unsigned long TabelaHash::hash(const string chave)
{
    unsigned long hashValue = this->preHash(chave);
    return hashValue % this->getTamanho();
}

unsigned long TabelaHash::getTamanho()
{
    return this->tamanho;
}

unsigned long TabelaHash::getQuantidade()
{
    return this->quantidade;
}

bool TabelaHash::vazia()
{
    return this->quantidade == 0;
}

bool TabelaHash::cheia()
{
    return this->quantidade == this->getTamanho();
}

bool TabelaHash::verificarDuplicatas()
{
    
    for(unsigned long i = 0; i < tamanho; ++i)
    {
        auto elementoI = this->tabela[i];
        if(elementoI != nullptr && elementoI != REMOVIDO)
        {
            for(unsigned long j = i+1; j < tamanho; ++j)
            {
                auto elementoJ = this->tabela[j];
                if(elementoJ != nullptr && elementoJ != REMOVIDO)
                {
                    if(elementoI->getChave() == elementoJ->getChave())
                    {
                        // Repetição de chaves
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void TabelaHash::imprimir()
{
    for(unsigned long  i = 0; i < this->getTamanho(); i++)
    {
        Par<string, string> * entry = tabela[i];
        if( entry == REMOVIDO )
        {
            std::cout << i << ": REMOVIDO" << std::endl;
        }
        else if( entry != nullptr )
        {
            std::cout << i << ": " << entry->getChave() << ":" << entry->getValor() << std::endl;
        }
        else
        {
            std::cout << i << ": []" << std::endl;
        }
    }
}
