//
//  Par.h
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#ifndef Par_h
#define Par_h

template <typename C, typename V>
class Par {
    
private:
    C chave;
    V valor;
    
public:
    Par()
    {
    }
    
    Par(C chave, V valor):
    chave(chave), valor(valor){}
    
    ~Par()
    {
        
    }
    
    C getChave()
    {
        return this->chave;
    }
    void setChave( const C chave )
    {
        this->chave = chave;
    }
    
    V getValor()
    {
        return this->valor;
    }
    
    void setValor( const V valor )
    {
        this->valor = valor;
    }
};

#endif 
