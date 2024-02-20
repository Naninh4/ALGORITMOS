#include <bits/stdc++.h>
int pd[100][100000];
int gasto_m;
using namespace std;
int gasto_max(int a[],int tm,int gasto){
    if(tm == -1) return 0;
    if(pd[tm][gasto] != -1) return pd[tm][gasto];

    int acende = 0, n_acende = 0;
    
    if(gasto +  a[tm] <= gasto_m)
        acende = a[tm]  + gasto_max(a, tm-1, gasto +  a[tm]);
    n_acende =  gasto_max(a, tm-1, gasto);

    pd[tm][gasto] = max(acende, n_acende);

    return pd[tm][gasto];

}


int main(){
    int tm;

    cin >> tm >> gasto_m;
    int* a = new int[tm]; 
    for(int x=0; x<tm; x++)
    {
        cin >> a[x];
    }

    for(int y=0; y<tm; y++){
        for(int z=0; z<=gasto_m;z++){
            pd[y][z] = -1;
        }
    }

    int result = gasto_max(a,tm-1, 0);

    cout << result;
    delete a;
    return 0;
}