//
//  ListaDuplamenteEncadeada.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "../include/ListaDuplamenteEncadeada.h"

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada()
{
    this->cabeca = new No<std::string>("CABECA_NAO_DEVE_SER_ACESSADA");
    this->cauda = new No<std::string>("CAUDA_NAO_DEVE_SER_ACESSADA");
    
    this->cabeca->setProximo(this->cauda);
    this->cabeca->setAnterior(nullptr);

    this->cauda->setProximo(nullptr);
    this->cauda->setAnterior(this->cabeca);

    this->quantidade = 0;
}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada()
{
	while(this->getCabeca()->getProximo() != nullptr){
		delete this->getCabeca()->getProximo();
	}
	delete this->getCabeca();
	delete this->getCauda();

	//trocar o delete por remover da cauda!!
}

No<std::string>* ListaDuplamenteEncadeada::getCabeca(void)
{
    return this->cabeca;
}

No<std::string>* ListaDuplamenteEncadeada::getCauda(void)
{
    return this->cauda;
}

int ListaDuplamenteEncadeada::tamanho(void)
{
    return this->quantidade;
}

bool ListaDuplamenteEncadeada::vazia(void)
{
    return this->tamanho() == 0;
}

std::string ListaDuplamenteEncadeada::recuperar(int i)
{
	No<std::string>* auxiliar = this->getCabeca();
	int contador = 0;
	if(i > this->tamanho() || i <= 0){
		return "Não foi possível recuperar o nó!";
	} else {
		while(contador != i){
			auxiliar = auxiliar->getProximo();
			contador++;
		}
	}
	return auxiliar->getValor();
}

int ListaDuplamenteEncadeada::buscar(std::string s)
{	
	No<std::string>* auxiliar = this->getCabeca()->getProximo();
	int contador = 1;
	for (int i = 0; i < this->tamanho(); i++){
		if(auxiliar->getValor() == s){
			return contador;
		}
		auxiliar = auxiliar->getProximo();
	}
	return -1;
}

int ListaDuplamenteEncadeada::buscarMF(std::string s)
{

	return -1;
}

bool ListaDuplamenteEncadeada::inserirNaCabeca(std::string s)
{   
    No<std::string>* novo = new No<std::string>(s);

    novo->setAnterior( this->getCabeca() );
    novo->setProximo( this->getCabeca()->getProximo() );

    // COMO NÃO FAZER
    // this->getCabeca()->getProximo()->setAnterior(novo);
    // this->getCabeca()->setProximo( novo );

    // COMO RECOMENDO FAZER
    novo->getAnterior()->setProximo( novo );
    novo->getProximo()->setAnterior( novo );

    ++this->quantidade;

    return true;
}

bool ListaDuplamenteEncadeada::inserirNaCauda(std::string s)
{    
    return true;
}

bool ListaDuplamenteEncadeada::inserir(int i, std::string s)
{    
    return true;
}

bool ListaDuplamenteEncadeada::inserirOrdenado(std::string s)
{
	return true;
}

std::string ListaDuplamenteEncadeada::removerDaCabeca(void)
{   
    return "";
}

std::string ListaDuplamenteEncadeada::removerDaCauda(void)
{    
    return "";
}

std::string ListaDuplamenteEncadeada::remover(int i)
{    
    return "";
}

void ListaDuplamenteEncadeada::imprimir(void)
{
	for(auto n = this->cabeca->getProximo(); n != this->cauda; n = n->getProximo())
	{
		std::cout << n->getValor() << " ";
	}
	std::cout << std::endl;
}

StatusDaLista ListaDuplamenteEncadeada::checarConsistencia()
{
	if( this->cabeca == nullptr )
	{
		return CABECA_NULA;
	}
	else if( this->cabeca->getProximo() == nullptr )
	{
		return CABECA_PROXIMO_NULO;
	}
	else if( this->cabeca->getProximo()->getAnterior() != this->cabeca )
	{
		return ENCADEAMENTO_INCORRETO;
	}
	else if( this->cabeca->getAnterior() != nullptr )
	{
		return CABECA_ANTERIOR;
	}
	
	if( this->cauda == nullptr )
	{
		return CAUDA_NULA;
	}
	else if( this->cauda->getAnterior() == nullptr )
	{
		return CAUDA_ANTERIOR_NULO;
	}
	else if( this->cauda->getAnterior()->getProximo() != this->cauda )
	{
		return ENCADEAMENTO_INCORRETO;
	}
	else if( this->cauda->getProximo() != nullptr )
	{
		return CAUDA_PROXIMO;
	}
	
	if(this->vazia())
	{
		if( this->cabeca->getProximo() != this->cauda )
		{
			return CABECA_CAUDA;
		}
		
		if( this->cabeca != this->cauda->getAnterior() )
		{
			return CABECA_CAUDA;
		}
	}
	else
	{
		// Verifica encadeamento dos elementos
		for(No<std::string>* i = this->cabeca->getProximo(); i != this->cauda; i=i->getProximo())
		{
			if( i->getProximo()->getAnterior() != i )
			{
				return ENCADEAMENTO_INCORRETO;
			}
			if( i->getAnterior()->getProximo() != i )
			{
				return ENCADEAMENTO_INCORRETO;
			}
		}
	}
	
	return OK;
}
