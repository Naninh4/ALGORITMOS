#include <iostream>
using namespace std;
#ifndef __SET_IFRN__
#define __SET_IFRN__

class set{
private:
    int *data;
    unsigned int size_;
    unsigned int capacy_;
public:
set(){
    this->size_ = 0;
    this->capacy_= 100;
    this->data = new int[100];
} // Construtor

~set(){
    clear();
    delete[] data;
} // Destrutor

bool insert(int value){
    bool aux = find(value);
    if (aux == false){
        int tamanho = size();
        if (tamanho < this->capacy_){
            this->data[tamanho] = value;
            this->size_++;
            return true;
        }
        return false;

    } 
    return false;

} // Insere 'value' no conjunto caso ele não esteja presente
// (não pode repetir elementos).
// Retorna verdadeiro caso o elemento seja inserido,
// falso caso contrário.

bool erase(int value){
    bool aux = find(value);
    if (aux == true){
        int x = index();
            for(unsigned int i = x; i < this->size_-1; i++) {
                data[i] = data[i+1];
            }
            this->size_--;
                return true;
    } 
    return false;
}

// Remove 'value' do conjunto caso esteja presente.
// Retorna verdadeiro se o elemento foi removido,
// falso caso contrário.

bool find(int value){
    for(int x = 0;x< this->size_ ; x++){
        if (value == data[x]){
             return true;
        }
    }
    return false;
} // Retorna verdadeiro se 'value' está
// presente no conjunto, falso caso contrário.
 
unsigned int index(){
    for(int x = 0;x< this->size_ ; x++){
        if (value == data[x]){
             return x;
        }
    }
    return -1;
}
unsigned int size(){
    return size_;
} // Retorna a quantidade de elementos do conjunto.

bool empty(){
    return size_ == 0;
} // Retorna verdadeiro se o conjunto estiver vazio,

// falso caso contrário.

void clear(){
    this->size_=0;
} // Apaga todos os elementos do conjunto.
};
#endif // __SET_IFRN__

int main(){
    set meuSet;

    // Teste de inserção
    meuSet.insert(10);
    meuSet.insert(20);
    meuSet.insert(30);
    meuSet.insert(20); // Tentativa de inserir um valor repetido
    
    // Teste de busca
    if (meuSet.find(20)) {
        std::cout << "Valor 20 encontrado no conjunto." << std::endl;
    } else {
        std::cout << "Valor 20 nao encontrado no conjunto." << std::endl;
    }

    // Teste de remoção
    if (meuSet.erase(20)) {
        std::cout << "Valor 20 removido do conjunto." << std::endl;
    } else {
        std::cout << "Valor 20 nao encontrado para remocao." << std::endl;
    }

    // Verificação do tamanho do conjunto
    std::cout << "Tamanho do conjunto: " << meuSet.size() << std::endl;

    // Verificação se o conjunto está vazio
    if (meuSet.empty()) {
        std::cout << "O conjunto esta vazio." << std::endl;
    } else {
        std::cout << "O conjunto nao esta vazio." << std::endl;
    }

    // Limpeza do conjunto
    meuSet.clear();
    return 0;
}
