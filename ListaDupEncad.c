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
    struct cel *ant;
}cel;

typedef struct cel* ListaDup;

ListaDup* cria_lista(){
    ListaDup *li = (ListaDup*) malloc (sizeof(ListaDup));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

int insere_lista_fim(ListaDup *lista, int x){
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
        aux->ant = temp;
    }
    return 1;
}

int insere_lista_inicio(ListaDup *lista, int x){
    if(lista == NULL){ return 0; }
    cel * aux = (cel*)malloc(sizeof(cel));
    if(aux == NULL){ return 0; }
    aux->conteudo = x;
    aux->seg = *lista;
    aux->ant = NULL;
    
    *lista = aux;
    return 1;
}

int buscar(ListaDup *lista, int x){
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

int buscarFor(ListaDup *lista, int x){
    if(lista == NULL){ return 0; }
    cel *aux;
    for(aux = *lista;aux!=NULL;aux=aux->seg){
        if(aux->conteudo == x){
            return 1;
        }
    }
    return 0;
}

int contar(ListaDup *lista){
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

void libera_lista(ListaDup *lista){
    if(lista != NULL){
        cel* aux;
        while(*lista != NULL){
            aux = *lista;
            *lista = (*lista)->seg;
            free(aux);
        }
        free(lista);
    }
}

int remove_lista(ListaDup *lista, int x){
    if(lista == NULL){ return 0; }
    if(*lista == NULL){ return 0; }
    
    
    cel *aux = *lista;
    cel *ant;
    
    while(aux != NULL && aux->conteudo != x){
        ant = aux;
        aux = aux->seg;
    }
    
    if(aux == NULL){ return 0; }
    
    if(aux == *lista){
        *lista = aux->seg;
    }else{
        ant->seg = aux->seg;
    }
    
    free(aux);
    return 1;
}

void imprimir_lista(ListaDup* lista){
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
    ListaDup *lst;
    lst = cria_lista();

    insere_lista_fim(lst,1);
    insere_lista_fim(lst,2);
    insere_lista_fim(lst,3);
    insere_lista_fim(lst,4);
    insere_lista_fim(lst,5);
    insere_lista_inicio(lst,0);
    insere_lista_inicio(lst,7);
    
    imprimir_lista(lst);
    
    return 0;
}
