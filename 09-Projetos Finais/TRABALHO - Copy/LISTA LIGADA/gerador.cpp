#include <bits/stdc++.h>

int main() {
    // Abra o arquivo para escrita
    std::ofstream arquivo("entrada3000.txt");
    int n;
    // Verifique se o arquivo foi aberto corretamente
    std::cin >> n ;
    if (arquivo.is_open()) {
        // Escreva no arquivo
        arquivo << n << std::endl;
        for(int x = 1; x <= n; x++){
            arquivo << x << std::endl;
        }
        arquivo << n << std::endl;
        int resto = n-((n/2));
        for(int x = 0; x <(n/2); x++){
            arquivo << x << std::endl;
        }
        for(int x = resto; x <n; x++){
            arquivo << 0 << std::endl;
        }
        // Feche o arquivo
        arquivo.close();
    } else {
        std::cout << "Não foi possível abrir o arquivo.\n";
    }

    return 0;
}
