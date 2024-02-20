#include <bits/stdc++.h>

using namespace std;

int main() {
    int tm, qtd_c, codigo, valor;
    vector<int> a;
    vector<int> result;
    cin >> qtd_c;
    for (int x = 0; x < qtd_c; x++) {
        cin >> codigo >> valor;
        if (codigo == 1) {
            a.push_back(valor);
        }
        if(codigo == 2){
            result.push_back(a[a.size()-valor]);
        }
    }
    for(int y = 0; y < result.size(); y++){
        cout << result[y] << endl;
    }
}
