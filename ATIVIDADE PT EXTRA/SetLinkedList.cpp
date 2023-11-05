#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__
class linked_list {
private:
struct int_node {
int value;
int_node∗ next, ∗ prev;
};
int_node∗ head, ∗ tail;
unsigned int size_;
public:
linked_list() {}
~linked_list() {}
unsigned int size() {} // Retorna a quantidade de elementos armazenados
unsigned int capacity() {} // Retorna o espaço reservado para armazenar os elementos
double percent_occupied() {} // Retorna um valor entre 0.0 a 1.0 com o percentual da

// memória usada.

bool insert_at(unsigned int index, int value) {} // Insere elemento no índice index
bool remove_at(unsigned int index) {} // Remove elemento do índice index
int get_at(unsigned int index) {} // Retorna elemento no índice index,

// −1 se índice inválido

void clear() {} // Remove todos os elementos, deixando o vetor no estado inicial
void push_back(int value) {} // Adiciona um elemento no ``final'' do vetor
void push_front(int value) {} // Adiciona um elemento no ``início'' do vetor
bool pop_back() {} // Remove um elemento do ``final'' do vetor
bool pop_front() {} // Remove um elemento do ``início'' do vetor
int back(){} // Retorna o elemento do ``final'' do vetor
int front(){} // Retorna o elemento do ``início'' do vetor
bool remove(int value) {} // Remove value do vetor caso esteja presente
int find(int value) {} // Retorna o índice de value, −1 caso value não esteja presente
int count(int value) {} // Retorna quantas vezes value occorre no vetor
int sum() {} // Retorna a soma dos elementos do vetor
};
#endif // __LINKED_LIST_IFRN__