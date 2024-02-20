#include <bits/stdc++.h>
using namespace std;


map<long long, long long>  table;

long long divdiv(long long n) {
    if (n < 2) return 0;
    if (table.find(n) != table.end()) return table[n];
    if( n%2 !=0) table[n] = n +  divdiv(n/ 2) + divdiv((n / 2LL+1LL));
    else table[n] = n +  divdiv(n/ 2) + divdiv(n / 2LL);
    return table[n];
}

int main() {
    long long num;
    cin >> num;
    long long result = divdiv(num);
    cout << result << endl;
    return 0;
}
