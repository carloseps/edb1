#include "LinkedList.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

/**
A ideia geral do teste é:
    - criar uma lista
    - realizar múltiplas buscas SearchCF, verificando:
        - se o valor retornado está correto
        - se o contador foi incrementado
        - se a lista fica em ordem decrescente com base no contador
*/
bool test_SearchCF()
{
    cout << "INÍCIO: Teste SearchCF" << endl;
    
    bool resultado = true;
    
    LinkedList lista;
    
    vector<string> inputs = {"alpha","bravo","charlie","delta","echo","fox","golf","hotel","india","juliet"};
    
    // Insere elementos na lista
    for(string input : inputs)
    {
        lista.insertEnd(input);
    }

    // Criar repetição de elementos no vector 'inputs'
    // Isso servirá para fazer os testes da busca SearchCF
    vector<string> repeated = {"alpha", "alpha", "bravo", "alpha", "fox", "fox", "fox", "alpha", "charlie", "charlie"};
    for(string rep : repeated)
    {
    	inputs.push_back(rep);
    }

    auto size = inputs.size();
    
    for(int i = 0; i < size; ++i)
    {
        int index = size-i-1;
        string valorBuscado = inputs[index];

        // Imprime a lista antes de realizar a busca
        cout << "Antes de chamar searchCF(\"" << valorBuscado << "\"):" << endl;
        lista.print();
        
        Node<string>* noRetornado = lista.searchCF(valorBuscado);

        // Imprime a lista após a busca, para vermos se o nó mudou de lugar
        cout << "Após chamar searchCF(\"" << valorBuscado << "\"):" << endl;
        lista.print();

        cout << endl;

        string valorRetornado = noRetornado->getValue();
        
        // Verifica se o valor retornado pela busca está correto
        if( valorRetornado != valorBuscado )
        {
            cerr << "\tERRO - Teste SearchCF: buscou a chave " << valorBuscado << ", mas retornou nó com conteúdo igual a " << valorRetornado << endl;
            resultado = false;
            break;
        }
        
        // Verifica se a lista está ordenada pelo contador de acesso
        for( Node<string>* no = lista.getHead()->getNext(); no->getNext() != lista.getTail(); no = no->getNext() )
        {
            if( no->getCount() < no->getNext()->getCount() )
            {
                cerr << "\tERRO - Teste SearchCF: a lista não está ordenada pelo contador de acessos." << endl;
                resultado = false;
                break;
            }
        }

        if(!resultado)
        {
        	break;
        }
        
        // Verifica consistência da lista
        ListStatus verificada = lista.checkConsistency();
        if( verificada != OK )
        {
            cerr << "\tERRO - Teste SearchCF: alguma invariante da lista foi quebrada. Código do erro: " << verificada << ". Veja no enum 'ListStatus' no arquivo 'LinkedList.h' o que este código de erro quer dizer." << endl;
            resultado = false;
            break;
        }
    }
    
    if(!resultado)
    {
        return resultado;
    }
    
    vector<string> inexistentes = {"0", "50", "100", "200"};
    
    for(string valorBuscado : inexistentes)
    {
        Node<string>* noRetornado = lista.searchCF(valorBuscado);
        if( noRetornado != nullptr )
        {
            cerr << "\tERRO - Teste SearchCF: buscou chave inexistente e não retornou 'nullptr'." << endl;
            resultado = false;
            break;
        }
        
        ListStatus verificada = lista.checkConsistency();
        if( verificada != OK )
        {
            cerr << "\tERRO - Teste SearchCF: alguma invariante da lista foi quebrada. Código do erro: " << verificada << ". Veja no enum 'ListStatus' no arquivo 'LinkedList.h' o que este código de erro quer dizer." << endl;
            resultado = false;
            break;
        }
    }

    assert( lista.searchCF("alpha")->getCount() == 6 );
    assert( lista.searchCF("fox")->getCount() == 5 );
    assert( lista.searchCF("charlie")->getCount() == 4 );
    assert( lista.searchCF("bravo")->getCount() == 3 );
    assert( lista.searchCF("juliet")->getCount() == 2 );
    assert( lista.searchCF("india")->getCount() == 2 );
    assert( lista.searchCF("golf")->getCount() == 2 );
    assert( lista.searchCF("echo")->getCount() == 2 );
    assert( lista.searchCF("delta")->getCount() == 2 );
    
    cout << "FIM: Teste SearchCF" << endl << endl;
    
    return resultado;
}

int main(void)
{
	if(test_SearchCF())
	{
		cout << "Passou em todos os testes!" << endl;
	}
	else
	{
		cout << "Não passou em todos os testes. Verifique as mensagens de erro." << endl;	
	}
	
	return 0;
}
