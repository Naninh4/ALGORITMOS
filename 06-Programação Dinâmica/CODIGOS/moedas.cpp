#include  <bits/stdc++.h>

// problema das moedas
int tupla[20][5000];
int listademoedas[20];
int S, V;
 /* 20 moedas. Valor Máximo: 5000 */

using namespace std;

int moedas(int valor_restante, int indice_moeda_atual = 0) {
  if (valor_restante == 0) {
    return 0;
  }
  if (valor_restante > 0 && indice_moeda_atual == S) {
    return 5001;
  }
  if (valor_restante < 0) {
    return 5001;
  }
  if (tupla[indice_moeda_atual][valor_restante] == -1) {
    int pego_moeda = 1 + moedas(valor_restante - listademoedas[indice_moeda_atual], indice_moeda_atual);
    int nao_pego_moeda = moedas(valor_restante, indice_moeda_atual + 1);
    tupla[indice_moeda_atual][valor_restante] = min(pego_moeda, nao_pego_moeda);
  }
  return tupla[indice_moeda_atual][valor_restante];
}



int main(){
    cin >> S >> V;
    tupla[S][V+1];
    listademoedas[S];

    for (int i = 0; i < S; i++) {
        cin >> listademoedas[i];
    }


    for (int i = 0; i < S; i++) {
        for (int j = 0; j < V+1; j++) {
            tupla[i][j] = -1;
        }
    }

    int solucao = moedas(V);
    cout << solucao << endl;
    return 0;
}