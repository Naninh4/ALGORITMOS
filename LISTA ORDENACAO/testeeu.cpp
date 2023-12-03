#include <bits/stdc++.h>

using namespace std;
void insercao(int a[], unsigned int t) {
    int i, x, j;
    for (i = 1; i < t; ++i) {
        x = a[i];
        j = i;
        while(j > 0 && x < a[j-1]){
            a[j] = a[j-1];
            j--;
        }
        a[j] = x;
}
}

void imprime_array(int a[], int n) {
  int i;
  if (n > 0) {
    std::cout << a[0];
    for (i = 1; i < n; ++i)
      std::cout << " " << a[i];
    std::cout << "\n";
  }
}

int main(){
    unsigned int n, i;
    std::cin >> n;
    int a[n];
    for (unsigned int i = 0; i < n; ++i) cin >> a[i];

    insercao(a,n);
    imprime_array(a,n);

}