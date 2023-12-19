#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__
class linked_list{
private:
    struct int_node
    {
        int value;
        int_node *proximo, *anterior;
    };
    int_node *primeiro, *ultimo;
    unsigned int size_;

public:
    linked_list() : primeiro(nullptr), ultimo(nullptr), size_(0) {}

    ~linked_list(){ // O(N)
        int_node *current = this->primeiro;
        while (current != nullptr)
        {
            int_node *to_remove = current;
            current = current->proximo;
            delete to_remove;
        }
    }

    unsigned int size() // O(1)
    {
        return this->size_;
    } // Retorna a quantidade de elementos armazenados
    
    unsigned int capacity() // O(1)
    {
        return this->size_;
    } // Retorna o espaço reservado para armazenar os elementos
    
    double percent_occupied() // O(1)
    {
        return 100.00;
    } // Retorna um valor entre 0.0 a 1.0 com o percentual da

    // memória usada.

    bool insert_at(unsigned int index, int value) // O(N)
    {
        if (index < size())
        {
            if (index == 0)
            {
                push_front(value);
                return true;
            }
            if (index == (size() - 1))
            {
                push_back(value);
                return true;
            }
            int_node *novo_no = new int_node;
            novo_no->value = value;
            int_node *current =  this->primeiro;
            for (unsigned int x = 1; x <index; x++){
                current = current->proximo;
            }
            novo_no->anterior =  current;
            novo_no->proximo = current->proximo;
            current->proximo->anterior = novo_no;
            current->proximo = novo_no;  
            this->size_++;          
            return true;
        }
        return false;
    } // Insere elemento no índice index
    
    bool remove_at(unsigned int index) // O(N)
    {
        if (index < size())
        {
            if (index == 0)
            {
                pop_front();
                return true;
            }
            if (index == (size() - 1))
            {
                pop_back();
                return true;
            }
            int_node *remove = this->primeiro;

            for (unsigned int x = 0; x < index; x++){
                    remove = remove->proximo;
            }
            int_node * ant = remove->anterior;
            int_node * pro = remove->proximo;
            ant->proximo = pro;
            pro->anterior = ant;
            delete remove;
            this->size_--;
            return true;
        }
        return false;
    } // Remove elemento do índice index
    
    int get_at(unsigned int index) // O(N)
    {
        if (index < size())
        {
            int_node *get = this->primeiro;

            for (unsigned  x = 1; x <= index; x++)
            {
                get = get->proximo;
            }
            return get->value;
        }
        return -1;
    } // Retorna elemento no índice index,

    // −1 se índice inválido

    void clear(){ // O(1)
        
        this->size_ = 0;
    } // Remove todos os elementos, deixando o vetor no estado inicial
    
    void push_back(int value) // O(1)
    {
        int_node *novo_valor = new int_node;
        novo_valor->value = value;
        novo_valor->anterior = this->ultimo;
        novo_valor->proximo = 0;
        if (this->primeiro == 0)
        {
            this->primeiro = novo_valor;
        }
        else
        {
            this->ultimo->proximo = novo_valor;
        }
        this->ultimo = novo_valor;
        this->size_++;
    } // Adiciona um elemento no ``final'' do vetor

    void push_front(int value) // O(1)
    {
        int_node *novo_valor = new int_node;
        novo_valor->value = value;
        if (this->primeiro == 0)
        {
            this->primeiro = this->ultimo = novo_valor;
            novo_valor->proximo = novo_valor->anterior = nullptr;
            this->size_++;
        }
        else
        {
            novo_valor->proximo = this->primeiro;
            novo_valor->anterior = nullptr;
            this->primeiro->anterior = novo_valor;
            this->primeiro = novo_valor;
            this->size_++;
        }
    } // Adiciona um elemento no ``início'' do vetor
    
    bool pop_back() // O(1)
    {
        if (this->primeiro)
        {
            if (size() == 1)
            {
                delete primeiro;
                // delete ultimo;
                primeiro = nullptr;
                ultimo = nullptr;
                this->size_--;
                return true;
            }
            int_node *remove = this->ultimo;
            this->ultimo = this->ultimo->anterior;
            this->ultimo->proximo = nullptr;
            delete remove;
            this->size_--;

            return true;
        }
        return false;
    } // Remove um elemento do ``final'' do vetor

    bool pop_front() // O(1)
{
    if (this->primeiro)
    {
        if (size() == 1)
        {
            delete ultimo; // Libera a área de memória ocupada
            primeiro = nullptr; // esvaziando os ponteiros
            ultimo = nullptr;
            this->size_--;
            return true;
        }
        else
        {
            int_node *remove = this->primeiro;
            this->primeiro = this->primeiro->proximo;
            if (this->primeiro) // Verifique se o próximo nó existe
                this->primeiro->anterior = nullptr;
            delete remove;
            this->size_--;
            return true;
        }
    }
    return false;
    } // Remove um elemento do ``início'' do vetor

    int back() // O(1)
    {
        return this->ultimo->value;
    } // Retorna o elemento do ``final'' do vetor
    
    int front() // O(1)
    {
        return this->primeiro->value;
    } // Retorna o elemento do ``início'' do vetor
    
    bool remove(int value){ //O(N)
        int_node *no = this->primeiro;
        for (unsigned int x = 0; x < size(); x++)
        {
            if (no->value == value)
            {
                int_node *ant = no->anterior;
                int_node *pro = no->proximo;
                ant->proximo = pro;
                pro->anterior = ant;
                delete no;
                this->size_--;
                return true;
            }
        
            no = no->proximo;
        }
        return false;

    }

    // } // Remove value do vetor caso esteja presente
    
    int find(int value) // O(N)
    {
        int_node *no = this->primeiro;
        for (unsigned int x = 0; x < size(); x++)
        {
            if (no->value == value)
            {
                return x;
            }
            else
            {
                no = no->proximo;
            }
        }
        return -1;

    } // Retorna o índice de value, −1 caso value não esteja presente7
    
    int count(int value){ // O(N)
        int_node *no = this->primeiro;
        int cont = 0;
        for (unsigned int x = 0; x < size(); x++){
            if (no->value == value)
            {
                cont++;
                
            }
            no = no->proximo;
        }
        return cont;
    } // Retorna quantas vezes value occorre no vetor
    
    int sum() // O(N)
    {
        int sum = 0;
        int_node *no = this->primeiro;
        
        for (unsigned int x = 0; x < size(); x++)
        {
            sum += no->value;
            no = no->proximo;
        }

        return sum;
    } // Retorna a soma dos elementos do vetor
};

#endif // __LINKED_LIST_IFRN__