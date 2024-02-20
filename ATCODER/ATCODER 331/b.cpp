#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, l, r, elemento;
    cin >> x >> l >> r;
    int view[x];

    for(int i = 0; i < x ;i++){
        cin >> elemento;
        if(elemento<=l){
            view[i] = l;
        }else{
            if(elemento > l && elemento < r){
                view[i] = elemento;
            }else{
                if(elemento>=r){
                    view[i] = r;
                }
            }
            
        }
        
    }
    
    for(int i = 0; i < x-1 ;i++){
        cout << view[i] << " ";
    }
    cout << view[x-1];

}