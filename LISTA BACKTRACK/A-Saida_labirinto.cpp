#include <iostream>

using namespace std;

bool labirinto_bt(int labirinto[20][20], int linha, int coluna, int l, int c) {
    if (l < 0 or c < 0 or l >= linha or c >= coluna or labirinto[l][c] == 1)
        return false; /* Rejeita */

    if (l == linha - 1 and c == coluna - 1)
        return true; /* Aceita */

    // Marca a célula como visitada
    labirinto[l][c] = 1;

    // Tenta mover para baixo
    if (labirinto_bt(labirinto, linha, coluna, l + 1, c))
        return true;

    // Tenta mover para a direita
    if (labirinto_bt(labirinto, linha, coluna, l, c + 1))
        return true;

    // Tenta mover para a esquerda
    if (labirinto_bt(labirinto, linha, coluna, l, c - 1))
        return true;

    // Tenta mover para cima
    if (labirinto_bt(labirinto, linha, coluna, l - 1, c))
        return true;

    // Se nenhum dos movimentos acima leva à saída, marca a célula como não visitada
    labirinto[l][c] = 0;

    // Nenhuma das opções chegou ao final
    return false;
}

int main() {
    int x, y;
    cin >> x >> y;

    int labirinto[20][20];  // Aqui você precisa criar a matriz labirinto

    // Inserir valores na matriz (exemplo)
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cin >> labirinto[i][j];
        }
    }

    bool saida = labirinto_bt(labirinto, x, y, 0, 0);
    cout << saida<< endl;
    return 0;
}
