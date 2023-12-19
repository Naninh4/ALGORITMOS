#include <iostream>

using namespace std;

int main() {
    // Contando operaÃ§Ãµes
    int qtd_array, soma, cont = 0; // 4 operaÃ§Ãµes
    bool achou = false; // 2 operaÃ§Ãµes

    cin >> qtd_array >> soma; // 2 operaÃ§Ãµes
    int array[qtd_array]; // 2 operaÃ§Ãµes
    for (int x = 0; x < qtd_array; x++) { // 4 operaÃ§Ãµes + qtd_array
        cin >> array[x]; // qtd_array-1 * 2 
    }
    while (achou == false && cont < qtd_array) { // 
        int aux = soma - array[cont];
        for (int j = 0; j < qtd_array; j++) {
            if (array[j] == aux && j != cont) {
                achou = true;
                break;
            }
        }
        cont++;
    }
    if (achou == false) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;  // AdiÃ§Ã£o necessÃ¡ria
}