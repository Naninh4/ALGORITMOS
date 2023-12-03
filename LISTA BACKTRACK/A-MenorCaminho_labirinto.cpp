#include <iostream>

using namespace std;

int labirinto_bt(int labirinto[20][20], int &MenorC, int linha, int coluna, int l, int c, int tm)
{
    if (l == -1 || c == -1 || l == linha || c == coluna || labirinto[l][c] != 0)
        return 0;

    if (l == linha - 1 and c == coluna - 1)
    {
        if (tm < MenorC)
            MenorC = tm;
        return 1;
    }

    labirinto[l][c] = 9;

    int ans = labirinto_bt(labirinto, MenorC, linha, coluna, l + 1, c, tm + 1) +
              labirinto_bt(labirinto, MenorC, linha, coluna, l, c + 1, tm + 1) +
              labirinto_bt(labirinto, MenorC, linha, coluna, l, c - 1, tm + 1) +
              labirinto_bt(labirinto, MenorC, linha, coluna, l - 1, c, tm + 1);

    labirinto[l][c] = 0;
    return ans;
}

int main()
{
    int x, y;
    cin >> x >> y;

    int labirinto[20][20]; // Aqui você precisa criar a matriz labirinto

    // Inserir valores na matriz (exemplo)
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            cin >> labirinto[i][j];
        }
    }

    int MenorC = 1000000000;
    int caminhos = labirinto_bt(labirinto, MenorC, x, y, 0, 0, 1);

    if (caminhos > 0)
    {
        cout << MenorC << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
