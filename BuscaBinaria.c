#include <stdio.h>

int BuscaBinaria(int*x, int inicio, int fim, int numero){
    int meio = 1;
    int contador = 1;
    int aux = (inicio + fim) / 2;
    
    while(contador <= aux){
        meio = (inicio + fim) / 2;
        if(x[meio] == numero){
            return meio;
        }else if(x[meio] > numero){
            fim = meio - 1;
            contador++;
        }else{
            inicio = meio + 1;
            contador++;
        }
    }
    
    return -1;
}

int BuscaBinariaRecursiva(int*x, int inicio, int fim, int numero){
    int meio = (inicio + fim)/2;
    int aux = 0;
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
    int vetor[7] = {0,3,8,10,54,70,92};
    
    printf("%d",BuscaBinaria(vetor,0,6,92));

    return 0;
}
