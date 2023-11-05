#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

    int tm_seq, cont=1,aux=0;
    vector<int> seq;
    cin >> tm_seq;
    seq.resize(tm_seq);
    
   	for(int x = 0; x < tm_seq; x++) cin>>seq[x];
   	for(int i = 1; i <seq.size(); i++){
		if (seq[i] - seq[i-1] != seq[aux+1] - seq[aux]){
		    aux = i; // registrando próxima PA 
            cont++;
            i++; // registrou o fim da PA e pulou para a próxima.
        }
        
    }
    
    cout << cont;
    return 0;
}