#include <bits/stdc++.h>


double tabela[100][10000];
int pesos[100];
double precos[100];

using namespace std;


double mochila_binaria(int next,int pesomaximo ){
    if(next == -1){ // Para não ultrapassar o limite da tabela
        return 0.0;
    }
    if(tabela[next][pesomaximo] != 0) return tabela[next][pesomaximo];// se já foi calculado retorna o valor

    double pegou_item = 0.0, nao_pegou_item = 0.0;
    if( pesomaximo - pesos[next] >=0) pegou_item = precos[next] + mochila_binaria( next-1, pesomaximo-pesos[next]);
    
    nao_pegou_item =  mochila_binaria(next-1, pesomaximo);
    
    tabela[next][pesomaximo] = max(nao_pegou_item, pegou_item);

    return tabela[next][pesomaximo];

}



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
    

    double result = mochila_binaria(c-1,n);

    cout << fixed << setprecision(2) << result << endl;
}