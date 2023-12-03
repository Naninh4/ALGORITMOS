#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double numero;

    cout << "Digite um número: ";
    cin >> numero;

    // Calcula a raiz quadrada
    double raizQuadrada = sqrt(numero);

    // Exibe o resultado
    cout << "A raiz quadrada de " << numero << " é: " << raizQuadrada << endl;

    return 0;
}
