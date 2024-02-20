#include <bits/stdc++.h>

int tabela[101][100010];
int lista[100];
int soma = 0;

using namespace std;


bool sublista_soma(int next,int soma ){
    int existe;
    if(soma == 0){ 
        return true;
    }
    if(next == 0 || soma < 0){ 
        return false ;
    }
    if(tabela[next][soma] !=-1) return tabela[next][soma];

    existe = sublista_soma( next-1, soma - lista[next-1]);  
    existe =  existe || sublista_soma( next-1, soma);
    tabela[next-1][soma] = existe;

    return existe;
}



int main(){
    int n;
    
    cin >> n >> soma;

    for(int x = 0; x<n;x++){
        cin >> lista[x];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < soma+1; j++) {
            tabela[i][j] = -1;
        }
        
    }
    
   
    int result = sublista_soma(n, soma);
    cout << result ;
}