#include <stdio.h>
#include <stdlib.h>

struct elemento{
    int conteudo;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Pilha;

struct fila{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

typedef struct fila Fila;

Fila* cria_fila(){
    Fila *fi = (Fila*) malloc (sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
    }
    return fi;
}

int insere_fila(Fila *fila, int x){
    if(fila == NULL){ return 0; }
    Elem * aux = (Elem*)malloc(sizeof(Elem));
    if(aux == NULL){ return 0; }
    aux->conteudo = x;
    aux->prox = NULL;
    
    if((*fila)==NULL){
        *fila = aux;
        fila->qtd++;
    }else{
        Elem *temp;
        temp = *fila;
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        temp->prox = aux;
        fila->qtd++;  
    }
    return 1;  
}

void imprimir_fila(Fila* fila){
    if(fila == NULL){
        printf("\nFila nao existe\n");
    }else{
        if(*fila == NULL){
            printf("\nFila vazia\n");
        }else{
            Elem *temp;
            temp = *fila;
            while(temp != NULL){
                printf("%d | ", temp->conteudo);
                temp = temp->prox;
            }
        }
    }
}

int main()
{
    printf("Inicio\n");
    Fila *fil;
    fil = cria_fila();

    insere_fila(fil,1);
    insere_fila(fil,2);
    insere_fila(fil,3);
    insere_fila(fil,4);
    insere_fila(fil,5);
    
    imprimir_fila(fil);

    return 0;
}
