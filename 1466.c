#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 1000



struct regen{   
    struct regen *esq;
    int i;
    struct regen *dir;

};
typedef struct regen TipoArv;

TipoArv * funcp(TipoArv *a, int x){  
    if(a==NULL){
        return NULL;
    }
    else if(x < a->i){
        if(a->esq==NULL){
        return a;
        }
    else{
        return funcp(a->esq, x);
        }
    if(a->dir==NULL){
        return a;
        }
    else{
        return funcp(a->dir, x);
    }
    }
    else if (x==a->i){
        return a;
    }
    
    
}


int main()
{  
    TipoArv *raiz, *p, *j, *v[MAX];
    int casos, val, k, l, noh, contA, contB;
    

    scanf("%d", &casos);
        for(k=1; k<=casos; k++){
	        for(l=0;l<MAX;l++){
	            v[l] = NULL;
                raiz = NULL;
        }
    scanf("%d", &val);
        for(l=0; l<val; l++){
            scanf("%d", &noh);
            j = (TipoArv *) malloc(sizeof(TipoArv));
            j->i = noh;
            j->dir = j->esq = NULL;

            p = funcp(raiz, noh);
            if(p==NULL){
                raiz = j;
            }
            else if (p->i != noh){
                if (noh > p->i){
                     p->dir = j;
                }
                else{
                    p->esq = j;
                }
            }
        }
        printf("Case %d:", k);
        j = raiz;
        contA = 1;
        contB  = 1;
        v[0] = j;
        while(j != NULL){
            printf("%d", j->i);
            if(j->dir != NULL){
                v[contA] = j->dir;
                contA++;
            }
            if(j->esq != NULL){
                v[contA] = j->esq;
                contA++;
            }

            if(v[contB]!=NULL){
                printf(" ");
                j = v[contB];
                contB++;
            }
        }

        printf("\n\n");
    }
 return 0;
}
