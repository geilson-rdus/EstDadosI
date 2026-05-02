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

Pilha* cria_pilha(){
    Pilha *pi = (Pilha*) malloc (sizeof(Pilha));
    if(pi != NULL){
        *pi = NULL;
    }
    return pi;
}

void libera_pilha(Pilha* pilha){
    if(pilha!=NULL){
        Elem* aux;
        while(*pilha!=NULL){
            aux = *pilha;
            *pilha = (*pilha)->prox;
            free(aux);
        }
        free(pilha);
    }
}

int consulta_topo(Pilha* pilha){
    if(pilha==NULL){return -1;}
    if((*pilha)==NULL){return -1;}
    return (*pilha)->conteudo;
}

int push (Pilha *pi, int x){
    if(pi==NULL){return -1;}
    Elem* no = (Elem*) malloc (sizeof(Elem));
    if(no==NULL){return -1;}
    no->conteudo = x;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int pop (Pilha* pi){
    if(pi == NULL){return -1;}
    if((*pi)==NULL){return -1;}

    Elem *no = *pi;
    *pi = no->prox;

    int valor = no->conteudo;
    free(no);

    return 1;
}

Fila* cria_fila(){
    Fila *fi = (Fila*) malloc (sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->final = NULL;
        fi->qtd = 0;
    }
    return fi;
}

void libera_fila(Fila* fi){
    if(fi!=NULL){
        Elem* no;
        while(fi->inicio!=NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

int enqueue(Fila *fi, int x){
    if(fi = NULL){return -1;}

    Elem *no = (Elem*) malloc (sizeof(Elem));
    if(no==NULL){ return -1; }
    no->conteudo = x;
    no->prox = NULL;

    if(fi->inicio == NULL){
        fi->inicio = no;
    }

    fi->final->prox = no;
    fi->qtd++;

    return 1;
}

int dequeue(Fila* fi, int x){
    if(fi == NULL){return -1;}
    if(fi->inicio == NULL){return -1;}

    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox; // fi->inicio = no->prox; errado

    if(fi->inicio = NULL){
        fi->final = NULL;
    }

    free(no);
    fi->qtd--;

    return 1;
}

void imprimir_fila(Fila* fila){
    if(fila == NULL){
        printf("\nFila nao existe\n");
    }else{
        if(fila->inicio == NULL){
            printf("\nFila vazia\n");
        }else{
            Elem *temp;
            temp = fila->inicio ;
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
    int retorno;

    retorno = enqueue(fil,1);
    retorno = enqueue(fil,2);

    imprimir_fila(fil);
    

    return 0;
}
