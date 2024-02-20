#include <bits/stdc++.h>

using namespace std;

int main() {
    long long d;
    cin >> d;

    long long r = sqrt(d);
    long long menor = 10000000;

    for (long long i = 1; i <= r; i++) {
        for (long long j = i; j <= r; j++) {
            if (abs(((j * j) + (i * i)) - d) < menor ){
                menor = abs(((j * j) + (i * i)) - d);
            }
        }
    }
    cout << menor << endl;

    return 0;
}
