#include <bits/stdc++.h>
using namespace std;
int main(){
    long long A , M, L, R;
    long long result=0;

    cin >> A >> M >> L >> R;

    if( A < L){
        long long intervalo_AL = abs(L-A)/M;
        A+=intervalo_AL*M;
        if(A==L) result ++;
        if(A-M ==L) result ++;

        long long intervalo_aR = abs(A - R)/M;
        result += intervalo_aR;
    }
    if( A >= L){
       result ++;
       if(abs(A - R) >= M ) {
            long long intervalo_aR = abs(A - R)/M;
            result += intervalo_aR;
        }
        if(abs(A - L) >= M ) {

            long long intervalo_aL = abs(A - L)/M;
            result += intervalo_aL;
        }
    }
    
    cout << result;


}