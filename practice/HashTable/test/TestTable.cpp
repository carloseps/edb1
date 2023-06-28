// //
// //  TestTable.cpp
// //
// //  Created by Eiji Adachi Medeiros Barbosa 
// //

// #include "TestTable.h"
// #include "HashTable.h"
// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// extern HashEntry<std::string, std::string> *REMOVIDO;

// bool testar_Construtor()
// {
//     cout << "\nINÍCIO: Testes Construtor" << endl;

//     auto size = 17;

//     HashTable* table = new HashTable(size);

//     if( table->tamanho() != size )
//     {
//         cout << "\t*ERRO - Teste Construtor: Atributo 'size' não foi inicializado corretamente." << endl;
//         return false;
//     }

//     if( table->quantidade() != 0 )
//     {
//         cout << "\t*ERRO - Teste Construtor: Atributo 'quantity' não foi inicializado corretamente." << endl;
//         return false;
//     }

//     if( table->tabela == nullptr )
//     {
//         cout << "\t*ERRO - Teste Construtor: Atributo 'tabela' não foi inicializado corretamente." << endl;
//         return false;   
//     }

//     for(auto i = 0; i < table->tamanho(); ++i)
//     {
//         if( table->tabela[i] != nullptr )
//         {
//             cout << "\t*ERRO - Teste Construtor: " << i << "-ésimo elemento do atributo 'tabela[]' não foi inicializado corretamente." << endl;
//             return false;
//         }
//     }

//     delete table;

//     cout << "FIM: Testes Construtor" << endl;

//     return true;
// }

// bool testar_Inserir_CasoNormal()
// {
//     unsigned long tamanho = 17;
//     HashTable* tabela = new HashTable(tamanho);
    
//     bool inseriu = true;
    
//     for(unsigned long i = 0; i < tamanho/2 && inseriu; i++)
//     {
//         string chaveStr = "chave-" + to_string(i);
//         string valor = "conteudo-" + to_string(i);
        
//         auto tamanhoAntes = tabela->tamanho();
//         auto qtdElementoAntes = tabela->quantidade();
        
//         inseriu = tabela->inserir(chaveStr, valor);
        
//         auto tamanhoDepois = tabela->tamanho();
//         auto qtdElementoDepois = tabela->quantidade();
        
//         if( tamanhoAntes != tamanhoDepois )
//         {
//             cout << "\t*ERRO - Teste Inserir_CasoNormal: Tamanho foi modificado incorretamente. Tamanho só pode ser modificado quando ocorre redimensionamento." << endl;
//             inseriu = false;
//             break;
//         }
//         if( qtdElementoAntes != qtdElementoDepois-1 )
//         {
//             cout << "\t*ERRO - Teste Inserir_CasoNormal: Quantidade de elementos não foi incrementada corretamente." << endl;
//             inseriu = false;
//             break;
//         }
//     }
    
//     delete tabela;
    
//     return inseriu;
// }

// bool testar_Inserir_Atualizar()
// {
//     HashTable* tabela = new HashTable(7);
    
//     string chave = "chave";
//     string valor1 = "ConteudoInicial";
//     string valor2 = "ConteudoAtualizado";
    
//     tabela->inserir( chave, valor1 );
    
//     tabela->inserir( chave, valor2 );
    
//     bool resultado = true;
    
//     if( tabela->quantidade() == 1 )
//     {
//         for(unsigned long i = 0; i < tabela->tamanho(); i++)
//         {
//             HashEntry<string, string> *entry = tabela->tabela[i];
            
//             // A única entrada != null é a que foi atualizada com valor2
//             // Se tiver alguém com value() != valor2, então está errado
//             if( entry != nullptr && entry->getValue() != valor2)
//             {
//                 cout << "\t*ERRO - Teste Inserir_Atualizar: Ao inserir dois itens com mesma chave, o valor do segundo deve sobrescrever valor do primeiro. Neste teste, dois elementos com mesma chave foram inseridos na tabela. O esperado era que o conteúdo do item na tabela fosse igual a '" << valor2 << "', mas valor encontrado foi igual a '" << entry->getValue() << "'." << endl;
//                 resultado = false;
//                 break;
//             }
//         }
//     }
//     else
//     {
//         cout << "\t*ERRO - Teste Inserir_Atualizar: Ao inserir dois itens com mesma chave, o valor do segundo deve sobrescrever valor do primeiro. Neste teste, dois elementos com mesma chave foram inseridos na tabela; o esperado era uma tabela com 1 item, mas a tabela ficou com " << tabela->quantidade() << " itens." << endl;
        
//         resultado = false;
//     }
    
//     delete tabela;
    
//     return resultado;
// }

// bool testar_Inserir_Colisao()
// {
//     HashTable* tabela = new HashTable(17);
//     string c1 = "abba";
//     string i1 = "conteudo1";
    
//     tabela->inserir(c1, i1);
    
//     string c2 = "bbaa";
//     string i2 = "conteudo2";
    
//     tabela->inserir(c2,i2);
    
//     bool achou1 = false, achou2 = false;
//     for(unsigned long x = 0; x < tabela->tamanho(); x++)
//     {
//         HashEntry<string, string> *entry = tabela->tabela[x];
        
//         if( entry != nullptr && entry->getKey() == c1 )
//         {
//             achou1 = true;
//         }
        
//         if( entry != nullptr && entry->getKey() == c2 )
//         {
//             achou2 = true;
//         }
//     }
    
//     bool resultado = true;
//     if( (achou1 && !achou2)||(!achou1 && achou2) )
//     {
//         cout << "\t*ERRO - Teste Inserir_Colisao: Duas chaves que colidem foram inseridas, mas apenas uma foi encontrada na tabela. Provavelmente uma sobrescreveu a outra. Rever tratamento de colisão." << endl;
//         resultado = false;
//     }
    
//     delete tabela;
    
//     return resultado;
// }

// bool testar_Inserir_Apos_Remocao()
// {
//     HashTable table(7);
    
//     auto index = table.hash("abcd");
    
//     table.tabela[index] = new HashEntry<string, string>("abcd", "value1");
//     table.tabela[index+1] = new HashEntry<string, string>("bcda", "value2");
//     table.tabela[index+2] = REMOVIDO;
//     table.tabela[index+3] = new HashEntry<string, string>("cdba", "value4");
    
//     table.inserir("cdba", "NovoValor");
    
//     auto entry = table.tabela[index+3];
//     if( entry == nullptr || entry == REMOVIDO || entry->getKey() != "cdba" || entry->getValue() != "NovoValor" )
//     {
//         cout << "\t*ERRO - Teste Inserir_Apos_Remocao: Não atualizou o valor da entrada corretamente quando existe uma posição removida no caminho das colisões." << endl;
//         return false;
//     }
    
//     table.inserir("dabc", "value5");
    
//     entry = table.tabela[index+2];
//     if( entry == nullptr || entry == REMOVIDO || entry->getKey() != "dabc" )
//     {
//         cout << "\t*ERRO - Teste Inserir_Apos_Remocao: Não inseriu corretamente quando existe uma posição removida no caminho das colisões." << endl;
//         return false;
//     }    
    
//     return true;
// }

// bool testar_Inserir()
// {
//     cout << "\nINÍCIO: Testes Inserir" << endl;
    
//     bool resultado = true;
    
//     cout << "\tTeste Inserir - Caso Normal" << endl;
//     resultado = testar_Inserir_CasoNormal();
    
//     if(resultado)
//     {
//         cout << "\tTeste Inserir - Colisão" << endl;
//         resultado = testar_Inserir_Colisao();
//     }
//     if(resultado)
//     {
//         cout << "\tTeste Inserir - Caso Atualizar" << endl;
//         resultado = testar_Inserir_Atualizar();
//     }
//     if(resultado)
//     {
//         cout << "\tTeste Inserir - Caso Após Remoção" << endl;
//         resultado = testar_Inserir_Apos_Remocao();
//     }
    
//     cout << "FIM: Testes Inserir" << endl;
    
//     return resultado;
// }

// bool testar_Remover_CasoNormal()
// {
//     HashTable tabela(17);
    
//     string c1 = "a";
//     string i1 = "conteudo1";
    
//     string c2 = "b";
//     string i2 = "conteudo2";
    
//     string c3 = "c";
//     string i3 = "conteudo3";
    
//     tabela.tabela[ tabela.hash(c1) ] = new HashEntry<string, string>(c1, i1);
//     tabela.tabela[ tabela.hash(c2) ] = new HashEntry<string, string>(c2, i2);
//     tabela.tabela[ tabela.hash(c3) ] = new HashEntry<string, string>(c3, i3);
    
//     tabela.quantity = 3;
    
//     auto qtdAntes = tabela.quantidade();
    
//     tabela.remover( c2 );
    
//     bool resultado = true;
    
//     auto qtdDepois = tabela.quantidade();
    
//     if( qtdAntes - 1 != qtdDepois )
//     {
//         cout << "\t*ERRO - Teste Remover_CasoNormal: Não decrementou corretamente a quantidade de itens durante a remoção." << endl;
//         resultado = false;
//     }
    
//     bool achou = false;
//     for(unsigned long x = 0; x < tabela.tamanho(); x++)
//     {
//         HashEntry<string, string>* c = tabela.tabela[x];
        
//         if( c == nullptr ) continue;
//         if( c == REMOVIDO ) continue;
//         if( c->getKey() == c2 )
//         {
//             achou = true;
//             break;
//         }
//     }
    
//     if(achou)
//     {
//         cout << "\t*ERRO - Teste Remover_CasoNormal: Remoção não foi feita corretamente, pois o item passado como parâmetro ainda foi encontrado na tabela." << endl;
//         resultado = false;
//     }
    
//     return resultado;
// }

// bool testar_Remover_Sucessivas()
// {
//     HashTable table(17);
    
//     auto keys = {"abc", "bca", "cab"};
//     auto value = "Valor";
//     for(auto key : keys)
//     {
//         table.tabela[ table.hash( key ) ] = new HashEntry<string, string>(key, value);
//         ++table.quantity;
//     }
    
//     bool hasRemoved = false;
    
//     auto quantityBefore = table.quantidade();
    
//     for(auto key : keys)
//     {
        
//         bool hasRemoved = table.remover(key);
        
//         if(!hasRemoved)
//         {
//             cout << "\t*ERRO - Teste Remover_Sucessivas: Não removeu corretamente item com chave igual a : " << key << "." << endl;
//             hasRemoved = false;
//             break;
//         }
        
//         auto quantityAfter = table.quantidade();
        
//         if( quantityBefore - 1 != quantityAfter )
//         {
//             cout << "\t*ERRO - Teste Remover_Sucessivas: Não decrementou corretamente a quantidade de itens durante a remoção." << endl;
//             hasRemoved = false;
//             break;
//         }
        
//     }
    
//     // Série de remoções com sucesso
//     for(unsigned long i = 0; i < qtdRemovido; i++)
//     {
//         string chave;
        
//         if( i%3==0 )
//         {
//             chave = base1 + to_string(i);
//         }
//         else if( i%3==1 )
//         {
//             chave = base2 + to_string(i-1);
//         }
//         else
//         {
//             chave = base3 + to_string(i-2);
//         }
        
//         auto qtdAntes = table->quantidade();
        
//         hasRemoved = table->remover(chave);
        
//         if(!hasRemoved)
//         {
//             cout << "\t*ERRO - Teste Remover_Sucessivas: Não removeu corretamente item com chave igual a : " << chave << "." << endl;
//             hasRemoved = false;
//             break;
//         }
        
//         auto qtdDepois = table->quantidade();
        
//         if( qtdAntes - 1 != qtdDepois )
//         {
//             cout << "\t*ERRO - Teste Remover_Sucessivas: Não decrementou corretamente a quantidade de itens durante a remoção." << endl;
//             hasRemoved = false;
//             break;
//         }
//     }
    
//     delete tabela;
    
//     return hasRemoved;
// }

// bool testar_Remover_Colisao()
// {
//     HashTable* tabela = new HashTable(17);
//     string c1 = "abba";
//     string i1 = "conteudo1";
    
//     string c2 = "bbaa";
//     string i2 = "conteudo2";
    
//     string c3 = "baba";
//     string i3 = "conteudo3";
    
//     tabela->inserir(c1, i1);
//     tabela->inserir(c2, i2);
//     tabela->inserir(c3, i3);
    
//     tabela->remover(c2);
    
//     bool achou1 = false, achou3 = false;
//     for(unsigned long x = 0; x < tabela->tamanho(); x++)
//     {
//         HashEntry<string, string>* c = tabela->tabela[x];
        
//         if( c != nullptr && c != REMOVIDO && c->getKey() == c1  )
//         {
//             achou1 = true;
//         }
        
//         if( c != nullptr && c != REMOVIDO && c->getKey() == c3  )
//         {
//             achou3 = true;
//         }
//     }
    
//     bool resultado = true;
//     if( (achou1 && !achou3)||(!achou1 && achou3) )
//     {
//         cout << "\t*ERRO - Teste Remover_Colisao: Três chaves que colidem foram inseridas e uma foi removida, mas foi removida a chave errada. Rever tratamento de colisão." << endl;
//         resultado = false;
//     }
    
//     delete tabela;
    
//     return resultado;
// }

// bool testar_Remover()
// {
//     cout << "\nINÍCIO: Testes Remover" << endl;
    
//     bool resultado = true;
    
//     cout << "\tTeste Remover - Caso Normal" << endl;
//     resultado = testar_Remover_CasoNormal();
    
//     if(resultado)
//     {
//         cout << "\tTeste Remover - Sucessivas" << endl;
//         resultado = testar_Remover_Sucessivas();
//     }
    
//     if(resultado)
//     {
//         cout << "\tTeste Remover - Colisão" << endl;
//         resultado = testar_Remover_Colisao();
//     }
    
//     cout << "FIM: Testes Remover" << endl;
    
//     return resultado;
// }

// bool testar_Redimensionamento()
// {
//     cout << "INÍCIO: Testes Redimensionamento" << endl;
    
//     unsigned long initialSize = 7;
//     HashTable table(initialSize);
    
//     for(unsigned long i = 0; i < table.size; i++)
//     {
//         table.tabela[i] = REMOVIDO;
//     }
    
//     auto keys  = {"abcde", "bcdea", "cdeab", "deabc", "eabcd"};
//     auto value =  "Value1";
    
//     auto index = table.hash("abcde");
//     int delta = 0;
    
//     for(auto key : keys)
//     {
//         table.tabela[ (index+delta) % table.size ] = new HashEntry<string, string>(key, value);
//         ++table.quantity;
//         ++delta;
//     }
    
//     table.expand();
    
//     for(unsigned long i = 0; i < table.size; i++)
//     {
//         auto entry = table.tabela[i];
//         if(entry == nullptr)
//         {
//             continue;
//         }
//         else if(entry == REMOVIDO)
//         {
//             cout << "\t*ERRO - Teste Redimensionamento: Foi encontrada uma entrada deletada na tabela após o redimensionamento. Entradas deletadas não devem ser copiadas para a tabela após o redimensionamento." << endl;
//             return false;
//         }
//         else
//         {
//             bool found = false;
//             for(auto key : keys)
//             {
//                 if( key == entry->getKey() )
//                 {
//                     found = true;
//                     break;
//                 }
//             }
//             if(!found)
//             {
//                 cout << "\t*ERRO - Teste Redimensionamento: Após o redimensionamento, foi encontrada uma entrada na tabela que não estava antes:" << entry->getKey() << endl;
//                 return false;
//             }
//         }
//     }
    
//     for(auto key : keys)
//     {
//         bool found = false;
//         for(unsigned long i = 0; i < table.size; i++)
//         {
//             auto entry = table.tabela[i];
//             if(entry != nullptr && entry != REMOVIDO && entry->getKey() == key)
//             {
//                 found = true;
//                 break;
//             }
//         }
//         if(!found)
//         {
//             cout << "\t*ERRO - Teste Redimensionamento: A seguinte chave estava inicialmente na tabela, mas não foi encontrada após o redimensionamento: " << key << endl;
//             return false;
//         }
//     }
    
//     cout << "FIM: Testes Redimensionamento" << endl;
    
//     return true;
// }
