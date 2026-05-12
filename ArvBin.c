#include <stdio.h>
#include <stdlib.h>

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO NO;

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin(){
    ArvBin *raiz = (ArvBin*) malloc (sizeof(ArvBin));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

int insere_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL){return 0;}
    NO * aux = (NO*)malloc(sizeof(NO));
    
    if(aux == NULL){return 0;}
    
    aux->info = valor;
    aux->esq = NULL;
    aux->dir = NULL;
    
    if(*raiz == NULL){
        *raiz = aux;
        return 1;
    }
    
    NO *temp;
    temp = *raiz;
    while(1){
        if(valor < temp->info){
            if(temp->esq == NULL){
                temp->esq = aux;
                return 1;
            }
            temp = temp->esq;
        }else{
            if(temp->dir == NULL){
                temp->dir = aux;
                return 1;
            }
            temp = temp->dir;
        }
    }
}

//-------------IMPRIMIR------------------
/* Função auxiliar recursiva */
void imprime_NO(struct NO *no, const char *prefixo, int ehUltimo, char lado){
  if(no == NULL){ return;}
  printf("%s", prefixo);
  if(ehUltimo){printf("└── ");
  } else {printf("├── ");}
  if(lado == 'E'){printf("E: ");
  } else if(lado == 'D'){printf("D: ");}
  printf("%d\n", no->info);
  char novoPrefixo[1000];
  snprintf(novoPrefixo,sizeof(novoPrefixo),"%s%s",prefixo,ehUltimo ? "    " : "│   ");
  if(no->esq != NULL){
    imprime_NO(no->esq, novoPrefixo, no->dir == NULL, 'E');
  }
  if(no->dir != NULL){
    imprime_NO(no->dir, novoPrefixo, 1, 'D');
  }
}
/* Função principal de impressão */
void imprime_ArvBin(ArvBin *raiz){
  if(raiz == NULL || *raiz == NULL){
    printf("Árvore vazia.\n");
    return;
  }
  printf("%d\n", (*raiz)->info);
  if((*raiz)->esq != NULL){
    imprime_NO((*raiz)->esq, "", (*raiz)->dir == NULL, 'E');
  }
  if((*raiz)->dir != NULL){
    imprime_NO((*raiz)->dir, "", 1, 'D');
  }
}

int altura_ArvBin(ArvBin* raiz){
  return 1;
}

int totalNosArvBin(ArvBin* raiz){
  return 1;
}

void preOrdem_arvBin(ArvBin *raiz){

}

void emOrdem_arvBin(ArvBin *raiz){

}

void posOrdem_arvBin(ArvBin *raiz){
  
}

int consulta_ArvBin(ArvBin *raiz, int valor){
  return 1;
}


int main()
{
    ArvBin* raiz = cria_ArvBin();
    int N = 10,dados[10] = {28,16,40,11,21,36,48,19,32,56};
    for(int i=0;i<N;i++){
        insere_ArvBin(raiz, dados[i]);
    }
    
    imprime_ArvBin(raiz);
    return 0;
}
