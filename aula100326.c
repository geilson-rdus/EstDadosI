#include <stdio.h>

void SelectionSortP(int *v, int size){
    int aux = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(v[j] > v[i]){
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

void selectionSort(int *x, int n){
    int i,j, menor, troca;
    for(i = 0; i < n-1; i++){
        menor = i;
        for(j=i+1;j<n;j++){
            if(x[j]<x[menor]){
                menor = j;
            }
        }
        if(i!=menor){
            troca = x[i];
            x[i] = x[menor];
            x[menor] = troca;
        }
    }
}

int main()
{
    int v[7] = {7,4,5,9,8,2,1};
    SelectionSortP(v,7);
    for(int i = 0; i < 7; i++){
        printf("%d ",v[i]);
    }
    return 0;
}
