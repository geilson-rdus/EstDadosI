/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int conteudo;
    struct cel *seg;
}cel;

typedef struct cel* Lista;

Lista* cria_lista(){
    Lista *li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

int insere_lista_fim(Lista *lista, int x){
    if(lista == NULL){ return 0; }
    cel * aux = (cel*)malloc(sizeof(cel));
    if(aux == NULL){ return 0; }
    aux->conteudo = x;
    aux->seg = NULL;
    
    if((*lista)==NULL){//se a lista estiver vazia
        *lista = aux;
    }else{
        cel *temp;
        temp = *lista;
        while(temp->seg != NULL){//anda atÃ© o fim da lista
            temp = temp->seg;
        }
        temp->seg = aux;
    }
    return 1;  
}

int insere_lista_inicio(Lista *lista, int x){
    if(lista == NULL){ return 0; }
    cel * aux = (cel*)malloc(sizeof(cel));
    if(aux == NULL){ return 0; }
    aux->conteudo = x;
    aux->seg = *lista;
    
    *lista = aux;
    return 1;
}

int buscar(Lista *lista, int x){
    if(lista == NULL){ return 0; }
    if(*lista == NULL){ return 0; }
    
    cel *temp;
    temp = *lista;
    
    while(temp->seg != NULL){
            if(temp->conteudo == x){
                return 1;
            }else{
                temp = temp->seg;
            }
    }
    return 0;
}

int buscarFor(Lista *lista, int x){
    if(lista == NULL){ return 0; }
    cel *aux;
    for(aux = *lista;aux!=NULL;aux=aux->seg){
        if(aux->conteudo == x){
            return 1;
        }
    }
    return 0;
}

int contar(Lista *lista){
    if(lista == NULL){ return 0; }
    if(*lista == NULL){ return 0; }
    
    cel *temp;
    temp = *lista;
    int contador = 0;
    
    while(temp->seg != NULL){
        contador++;
        temp = temp->seg;
    }
    
    return ++contador;
}

int remover(Lista *lista, int x){
    if(lista == NULL || *lista == NULL){
        return 0;
    }
    cel *aux = *lista;
    cel *ant = NULL;
    
    while(aux != NULL && aux->conteudo != x){
        ant = aux;
        aux = aux->seg;
    }
    
    if(aux == NULL){
        return 0;
    }

    if(ant == NULL){
        *lista = aux->seg;
    }else{
        ant->seg = aux->seg;
    }
    free(aux);
    return 1;
}

void imprimir_lista(Lista* lista){
    if(lista == NULL){
        printf("\nLista nao existe\n");
    }else{
        if(*lista == NULL){
            printf("\nLista vazia\n");
        }else{
            cel *temp;
            temp = *lista;
            while(temp != NULL){
                printf("%d | ", temp->conteudo);
                temp = temp->seg;
            }
        }
    }
}

int main()
{
    printf("Inicio\n");
    Lista *lst;
    lst = cria_lista();

    insere_lista_fim(lst,1);
    insere_lista_fim(lst,2);
    insere_lista_fim(lst,3);
    insere_lista_fim(lst,4);
    insere_lista_fim(lst,5);
    insere_lista_inicio(lst,6);
    insere_lista_inicio(lst,0);
    
    imprimir_lista(lst);
    
    printf("\nBuscar: %d",buscar(lst,9));
    printf("\nContagem: %d",contar(lst));
    
    printf("\nRemover 3: %d\n", remover(lst, 3));
    imprimir_lista(lst);
    
    return 0;
}
