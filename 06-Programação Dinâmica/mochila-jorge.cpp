#include <bits/stdc++.h>
using namespace std;

double pd[110][100010]; /* 100 itens. Peso máximo: 100000 */

double mochila_binaria_pd(double valor[], int peso[], int next, int p) {
    if (next == -1) return 0;
    if (pd[next][p] != -1) return pd[next][p];
    double v1 = 0.0, v2 = 0.0;
    if (p - peso[next] >= 0)
        v1 = valor[next] + mochila_binaria_pd(valor, peso, next - 1, p - peso[next]);
    v2 = mochila_binaria_pd(valor, peso, next - 1, p);
    if (v1 > v2)
        pd[next][p] = v1;
    else
        pd[next][p] = v2;
    return pd[next][p];
}

int main() {
    int c, n;

    cin >> c >> n;
    double list_precos[c];
    int list_pesos[c];

    for (int x = 0; x < c; x++) {
        cin >> list_pesos[x] >> list_precos[x];
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < n + 1; j++) {
            pd[i][j] = -1;
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < n + 1; j++) {
            cout << pd[i][j] << " ";
        }
        cout << "\n";
    }

    double result = mochila_binaria_pd(list_precos, list_pesos, c - 1, n);
    cout << result << endl;
cout << fixed << setprecision(2) << result << endl;
    cout << "\n";
     for (int i = 0; i < c; i++) {
        for (int j = 0; j < n+1; j++) {
            cout << " " << pd[i][j];
        }
         cout << "\n";
    }
    return 0;
}
