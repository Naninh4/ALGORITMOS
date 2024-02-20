#include <bits/stdc++.h>
using namespace std;

long long N;
vector<long long> m;

long long muro(long long tm){
    if ( m[tm] != -1LL ) return m[tm];

    if(tm == 0 or tm == 1) return m[tm] = 1LL;
    if ( tm == 2 ) return m[tm] = 5LL;

    return m[tm] = muro(tm-1) + 4 * muro(tm-2) + 2 * muro(tm-3)%1000000007;


} 
// nesse caso do muro, a tabela dinamica é apenas um array
// Quando vai diminuindo o tamanho da mureta po 2 3 e 1 podem ter valores repetivos.


int main(){

    cin >> N;
    m = vector<long long>(N+1,-1LL);

    cout << muro(N);


    return 0;
}