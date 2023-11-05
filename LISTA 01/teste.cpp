#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

    int tm_seq, cont=1,aux=0; // 5
    vector<int> seq; // 1
    cin >> tm_seq; // 1
    seq.resize(tm_seq); // 2
    
   	for(int x = 0; x < tm_seq; x++) cin>>seq[x]; //  2 +  (tm_seq * 2) + (tm_seq -1) 
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