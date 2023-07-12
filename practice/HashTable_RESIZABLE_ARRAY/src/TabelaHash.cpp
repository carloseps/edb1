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

TabelaHash::TabelaHash(const std::size_t tamanho)
{
    this->tamanho = tamanho;
    iniciar();
}

void TabelaHash::iniciar()
{
    this->tabela = new Par<std::string, string>*[ this->getTamanho() ];
    this->quantidade = 0;
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
    {
        this->tabela[i] = nullptr;
    }
}

TabelaHash::~TabelaHash()
{
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
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
    if(fatorDeCarga() >= CARGA_LIMITE_SUPERIOR){
        aumentar();
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

    if(fatorDeCarga() <= CARGA_LIMITE_INFERIOR && this->getTamanho() > 20){
        diminuir();
    }

    auto indiceBase = hash(chave);

    for (unsigned long delta = 0; delta < this->getTamanho(); delta++) {

        auto indiceAtual = (indiceBase + delta) % this->getTamanho();

        if(tabela[indiceAtual] != REMOVIDO && (tabela[indiceAtual] != nullptr && tabela[indiceAtual]->getChave() == chave)){
            delete tabela[indiceAtual];
            tabela[indiceAtual] = REMOVIDO;
            --this->quantidade;
            return true;
        }
    }
    return false;
}

float TabelaHash::fatorDeCarga()
{
    return (float)this->getQuantidade() / (float)this->getTamanho();
}

void TabelaHash::aumentar()
{
    std::size_t tamanhoNovo = 2*this->getTamanho() + 1;
    this->redimensionar(tamanhoNovo);
}

void TabelaHash::diminuir()
{
    std::size_t metadeTamanho = this->getTamanho()/2;
    std::size_t tamanhoNovo = metadeTamanho % 2 == 0 ? metadeTamanho + 1 : metadeTamanho;
    this->redimensionar(tamanhoNovo);
}

void TabelaHash::redimensionar(std::size_t tamanhoNovo)
{
    auto arrayAntigo = this->tabela;
    auto tamanhoAntigo = this->getTamanho();

    this->setTamanho(tamanhoNovo);

    auto arrayNovo = new Par<std::string, string>*[tamanhoNovo];

    prepararArrayNovo(arrayNovo, tamanhoNovo);
    
    for (std::size_t i = 0; i < tamanhoAntigo; i++)
    {
        auto elementoAtual = arrayAntigo[i];
        if(elementoAtual != nullptr && elementoAtual != REMOVIDO){

            auto indiceBase = hash(elementoAtual->getChave());
            for (size_t delta = 0; delta < tamanhoNovo; delta++)
            {
                auto indiceAtual = (indiceBase + delta) % tamanhoNovo;
                if(arrayNovo[indiceAtual] == nullptr){
                    arrayNovo[indiceAtual] = elementoAtual;
                    break;
                }
            }
        }
    }
    delete[] arrayAntigo;
    this->tabela = arrayNovo;
}

std::size_t TabelaHash::preHash(const string chave)
{
    std::size_t x = 0;
    for(std::size_t i = 0; i < chave.size(); i++)
    {
        // Não mudar!
        // Coloquei propositalmente uma versão simples pra facilitar a criação de colisões nos testes!
        x += chave.at(i);
    }
    return x;
}

std::size_t TabelaHash::hash(const string chave)
{
    std::size_t hashValue = this->preHash(chave);
    return hashValue % this->getTamanho();
}

std::size_t TabelaHash::getTamanho()
{
    return this->tamanho;
}

void TabelaHash::setTamanho(std::size_t tamanhoNovo)
{
    this->tamanho = tamanhoNovo;
}

std::size_t TabelaHash::getQuantidade()
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
    
    for(std::size_t i = 0; i < tamanho; ++i)
    {
        auto elementoI = this->tabela[i];
        if(elementoI != nullptr && elementoI != REMOVIDO)
        {
            for(std::size_t j = i+1; j < tamanho; ++j)
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
    for(std::size_t  i = 0; i < this->getTamanho(); i++)
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

void TabelaHash::prepararArrayNovo(Par<std::string, std::string>** arrayNovo, std::size_t tamanhoNovo){
    for (size_t i = 0; i < tamanhoNovo; i++)
    {
        arrayNovo[i] = nullptr;
    }
}
