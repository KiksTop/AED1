#include <stdio.h>
#include <stdlib.h>
#include <limit.h>



void incializa(Grafo *g, int *d, int *p, int *p, int *s){
    int v;
    for(v=0; v<g->vertices; v++){
        d[v] = INT_MAX/2;
        p[v] = -1;
    }
    d[s] = 0; 
}

void relaxaGrafo(Grafo * g , int *d , int *p , int u, int v){
    Adjacencia *ad = g->adj [u].cab ;
    while (ad && ad->vertices != v){
        ad = ad ->prox;
    }
    if (ad){
        if (d[v] > d[u] + ad-> peso){
            d[v] = d[u];
            p[v] = u;
        }
    }
} 


int *dijkstra (Grafo *g , int s){
    int *d = int(*)malloc(g->vertices*sizeof(int));
    int p[g->vertices];
    bool aberto[g->vertices];
    inicializa(g,d,p,s);

    int i;
    for (i=0 ; i<g->vertices ; i++){
        aberto[i] = true;
    }
    while (ExisteAberto(g,aberto)){
        int u = MenorDist(g, aberto, d);
        aberto [u] = false; 
        Adjacencia *ad = g -> adj[u]. cab;  
        while (ad){
            relaxa(g,d,p,u,ad->vertices);
            ad = ad->prox;
        }
    }
    return(d);
}


//Função para verificar se existe grafo aberto
bool ExisteAberto(Grafo *g, int *aberto){
    int i;
    for(i=0, i<g->vertices; i++){
        if(aberto[i]) return(true);
        return(false);
    }
}

//verificar menor dist no Grafo
int MenorDist(Grafo *g, int *aberto, int *d){
    int i;
    for(i=0 ; i<g->vertices; i++){
        if(aberto[i]);
        break;
    }
    if (i==g->vertices) return(-1);
    int menor = i;
    for(i=menor+1; i<g->vertices; i++){
        if(aberto[i] && (d[menor]>d[i])){
            menor = i;
        }  
    }
    return (menor;)
}
int Leitura()

int main(void){
    int N; 
    int M;
}
