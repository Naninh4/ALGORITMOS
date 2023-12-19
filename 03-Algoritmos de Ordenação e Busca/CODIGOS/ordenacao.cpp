#include "ordenacao.hpp"

/* TODO: Implementar função */
bool ordenado(int a[],  unsigned int t){

  int anterior = a[0];
  for (unsigned int x = 1; x < t; x++)
  {
    if (anterior > a[x])
    {
      return false;
    }
    anterior = a[x];
  }
  return true;
}

/* TODO: Implementar função */
void selecao(int num[], unsigned int tam){
  int i, j, min, aux;
  for (i = 0; i < (tam - 1); i++)
  {
    min = i;
    for (j = (i + 1); j < tam; j++)
    {
      if (num[j] < num[min])
        min = j;
    }
    if (num[i] != num[min])
    {
      aux = num[i];
      num[i] = num[min];
      num[min] = aux;
    }
  }
}


/* TODO: Implementar função */
void insercao(int a[], unsigned int t){
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
}void merge_sort(int a[], unsigned int primeiro, unsigned int ultimo){
  unsigned int meio;
  if (primeiro < ultimo)
  {
    meio = (primeiro + ultimo) / 2;
    merge_sort(a, primeiro, meio);
    merge_sort(a, meio + 1, ultimo);
    merge(a, primeiro, meio, meio + 1, ultimo);
  }
}
/* TODO: Implementar função */

void merge(int a[], int i1, int j1, int i2, int j2){
  int *temp = new int[((j1 - i1) + (j2 - i2) + 2)];
  int i, j, k;
  i = i1;
  j = i2;
  k = 0;
  while (i <= j1 && j <= j2)
  {
    if (a[i] < a[j])
      temp[k++] = a[i++];
    else
      temp[k++] = a[j++];
  }
  while (i <= j1)
    temp[k++] = a[i++];
  while (j <= j2)
    temp[k++] = a[j++];
  for (i = i1, j = 0; i <= j2; i++, j++)
    a[i] = temp[j];
  delete[] temp;
}
