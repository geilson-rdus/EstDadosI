#include <stdio.h>

int BuscaBinaria(int*x, int inicio, int fim, int numero){
    int meio = 1;

    
    while(inicio <= fim){
        meio = (inicio + fim) / 2;
        if(x[meio] == numero){
            return meio;
        }else if(x[meio] > numero){
            fim = meio - 1;
        }else{
            inicio = meio + 1;
        }
    }
    
    return -1;
}

int BuscaBinariaRecursiva(int*x, int inicio, int fim, int numero){
    int meio = (inicio + fim)/2;
    int aux = 0;
    
    if (inicio > fim) {
        return -1;
    }
    
    if(x[meio] == numero){
        return meio;
    }else if (x[meio] > numero){
        aux = BuscaBinariaRecursiva(x,inicio,meio-1,numero);
        return aux;
    }else{
        aux = BuscaBinariaRecursiva(x,meio+1,fim,numero);
        return aux;
    }
    return -1;
}

int main()
{
    int vetor[8] = {0,3,8,10,54,70,92,93};
    
    printf("%d",BuscaBinaria(vetor,0,7,-3));
    printf("\n%d",BuscaBinariaRecursiva(vetor,0,7,-3));

    return 0;
}
