#include <bits/stdc++.h>

using namespace std;

int main() {
    int qtd_tam, qtd_pedidos, vendas_efetivadas = 0;
    cin >> qtd_tam;

    vector<int> estoque(qtd_tam + 1);

    for (int x = 1; x <= qtd_tam; x++) {
        cin >> estoque[x];
    }

    cin >> qtd_pedidos;

    for (int y = 0; y < qtd_pedidos; y++) {
        int pedido;
        cin >> pedido;
        if (estoque[pedido] > 0) {
            estoque[pedido] -= 1;
            vendas_efetivadas++;
        }
    }

    cout << vendas_efetivadas;

    return 0;
}