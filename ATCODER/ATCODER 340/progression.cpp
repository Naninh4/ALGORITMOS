#include <bits/stdc++.h>


using namespace std;

int main(){

    int start, end, pass;

    cin >> start >> end >> pass;
    cout << start;
    start+=pass;
    for( int x = start; x <=end; x+=pass){
        cout << " "<<  x;
    }
}
