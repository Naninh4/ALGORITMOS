#include <bits/stdc++.h>


double tabela[100][10000];
int pesos[100];
double precos[100];

using namespace std;
int main(){
    int c, n;
    
    cin >> c >> n;

    for(int x = 0; x<c;x++){
        cin >> pesos[x] >> precos[x];
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < n+1; j++) {
            tabela[i][j] = 0;
        }
        
    }

    for (int i = 0; i <c-1; i++) {
        int resto  = n-pesos[i];
        for (int j = i+1; j < c; j++) {
            if(resto - pesos[j] >=0) tabela[i][n-pesos[j]] = precos[i];
        }

        // for (int j = i+1; j < n-1; j++) {
        //     if(tabela[i][j]!=0) {
        //         double valor = tabela[i][j];
        //         double diferenca = precos[n+1-j] + valor;

        //         if(diferenca > tabela[i][n]) tabela[i][n] = diferenca;
        //     }
        // }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < n+1; j++) {
           cout << tabela[i][j];
        }
        cout << "\n";
        
    }
}