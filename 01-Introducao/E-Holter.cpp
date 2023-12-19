#include <bits/stdc++.h> // importa toda biblioteca padrão do c++ USAR EM COMPETIÇÃO
using namespace std;


int main(){

    int qtd_leituras, soma=0, leitura, media, menos10=0, mais10=0, cont=0;
    vector<int> leituras;
    cin >>  qtd_leituras;

    for (int x=0; x < qtd_leituras;x++){
        cin >> leitura;
        soma +=leitura;
        leituras.push_back(leitura);
     }
    media = soma /qtd_leituras;
    mais10 = ((media*0.1)+media);
    menos10 = (media-(media*0.1));
    for(int a=0;a<qtd_leituras;a++){
        if (leituras[a] > mais10  or leituras[a] < menos10  ){
            cont++;
        }
    }
    cout << media << "\n" << cont;
    return 0;
}