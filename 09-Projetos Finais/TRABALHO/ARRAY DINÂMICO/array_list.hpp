#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__
class array_list
{
private:
    int *data;

    unsigned int size_, capacity_, capacityI;

    bool IncreaseCapacity()
    { // O(1)
        return percent_occupied() == 100.00;
    }

    void Incrase()
    { // O(n)
        if (this->capacityI == 8)
        {
            this->capacity_ *= 2;
            int *new_data = new int[this->capacity_];

            for (unsigned int x = 0; x < size(); x++)
            {
                new_data[x] = data[x];
            }
            delete[] data;
            this->data = new_data;
        }
        else
        {
            this->capacity_ += this->capacityI;
            int *new_data = new int[this->capacity_];

            for (unsigned int x = 0; x < size(); x++)
            {
                new_data[x] = data[x];
            }
            delete[] data;
            this->data = new_data;
        }
    }

public:
    array_list(unsigned int capa) // O(1)
    {
        this->size_ = 0;
        this->capacity_ = capa;
        this->capacityI = this->capacity_;
        this->data = new int[capacity_];
    }

    array_list()
    { // O(1)
        this->size_ = 0;
        this->capacity_ = 100;
        this->capacityI = this->capacity_;
        this->data = new int[100];
    }

    ~array_list()
    { // O(1)
        clear();
        delete[] this->data;
    } // Destrutor

    unsigned int size()
    { // O(1)
        return this->size_;
    } // Retorna a quantidade de elementos armazenados
    
    unsigned int capacity() 
    { // O(1)
        return this->capacity_;
    } // Retorna o espaço reservado para armazenar os elementos

    double percent_occupied() //O(1)
    { // O(1)
        return this->size_ * 100 / this->capacity_;
    } // Retorna um valor entre 0.0 a 1.0 com o percentual da

    // memória usada.
    bool insert_at(unsigned int index, int value) // O(n)
    { 
        if (index <= size_)
        {
            if (IncreaseCapacity()) // O(1)
            {
                Incrase(); // O(n)
            }
            int *new_data = new int[capacity_];
            new_data[index] = value;

            for (unsigned int x = 0; x < index; x++)
            {
                new_data[x] = data[x];
            }

            for (unsigned int x = index; x < size_; x++)
            { // Corrigido o loop
                new_data[x + 1] = data[x];
            }

            delete[] data;
            data = new_data;
            this->size_++;
            return true;
        }
        return false;
    }

    bool remove_at(unsigned int index) // O(n)
    {
    if (index < size())
    {
        for (unsigned int i = index; i < size() - 1; i++)
        {
            this->data[i] = this->data[i + 1];
        }
        this->size_--;
        return true;
    }
    return false;
    }
 // Remove elemento do índice index

    int get_at(unsigned int index)
    {
        if (index < this->size())
        {
            return this->data[index];
        }
        return -1;
    } // Retorna elemento no índice index,

    // −1 se índice inválido

    void clear() // O(1)
    {
        this->size_ = 0;
        delete[] data;
    } // Remove todos os elementos, deixando o vetor no estado inicial
    
    void push_back(int value)
    {
        if (IncreaseCapacity()) // O(1)
        {
            Incrase(); // O(n)
        }
        this->data[size()] = value; // O(1)
        this->size_++;

    } // Adiciona um elemento no ``final'' do vetor

    void push_front(int value) // O(n)
    {
        if (IncreaseCapacity())
        {
            Incrase(); // O(n)
        }
        int *new_data = new int[capacity_];
        new_data[0] = value;

        for (unsigned int x = 0; x < size(); x++) // O(n)
        {
            new_data[x + 1] = this->data[x];
        }

        delete[] this->data; // Libera a memória do array antigo
        this->size_++;
        this->data = new_data; // Atualiza o ponteiro para apontar para o novo array
    }

    bool pop_back() // O(1)
    {
        if (size() > 0)
        {
            this->size_--;
            return true;
        }
        return false;
    } // Remove um elemento do ``final'' do vetor
    
    bool pop_front()
    {
        if (size() > 0) {
            for (int x = 0; x < size() - 1; x++) {
                this->data[x] = this->data[x + 1];
            }
            this->size_--; // Movido para fora do loop
            return true;
        }
        return false; // O(n)
    } // Remove um elemento do ``início'' do vetor
    
    int back() // O(1)
    {
        return this->data[size() - 1];
    } // Retorna o elemento do ``final'' do vetor
    
    int front() // O(1)
    {
        return this->data[0];
    } // Retorna o elemento do ``início'' do vetor

bool remove(int value) // O(n)
{
    int index = find(value); // O(n)
    if (index != -1)
    {
        for (unsigned int i = index; i < size() - 1; i++) { // O(n)
            this->data[i] = this->data[i + 1];
        }
        this->size_--;
        return true;
    }
    return false;
} // Remove value do vetor caso esteja presente.
    int find(int value) // O(n)
    {
        for (unsigned int x = 0; x < size(); x++)
        {
            if (this->data[x] == value)
            {
                return x;
            }
        }
        return -1;
    } // Retorna o índice de value, −1 caso value não esteja presente.
    int count(int value) // O(n)
    {
        int cont = 0;
        for (unsigned int x = 0; x < size(); x++)
        {
            if (this->data[x] == value)
            {
                cont++;
            }
        }
        return cont;
    } // Retorna quantas vezes value occorre no vetor
    int sum() // O(n)
    {
        int soma = 0;
        for (unsigned int x = 0; x < size(); x++)
        {
            soma = soma + this->data[x];
        }
        return soma;
    }
}; // Retorna a soma dos elementos do vetor

#endif // __ARRAY_LIST_IFRN__