#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

#ifndef GRAFO_Y_DFS_H
#include "graf_y_dfs.h"
#define GRAFO_Y_DFS_H
#endif


#define tam 8

typedef struct t_nodo
{
    struct t_nodo *sig;
    Nodo vertice_grafo;
    int ind_nodo_grafo;
}Nodo_cola;

typedef struct _tipo_cola
{
    Nodo_cola*primero,*ultimo;
    int tamano;
}Cola;

Cola *inicializar_cola()
{
    Cola *aux=(Cola*)malloc(sizeof(struct _tipo_cola));
    aux->tamano=0;
    aux->primero=aux->ultimo=NULL;

    return aux;
}

int esta_vacia_cola(Cola *aux_cola)
{
    if(aux_cola->tamano==0){
        return 1;
    }
    else
        return 0;
}

void encolar(Cola *aux_cola, Nodo aux_nodo, int indice_nodo_de_grafo)
{
    Nodo_cola *nuevo=(Nodo_cola*)malloc(sizeof(struct t_nodo));

    nuevo->vertice_grafo=aux_nodo;
    nuevo->ind_nodo_grafo=indice_nodo_de_grafo;
    nuevo->sig=NULL;

    if(esta_vacia_cola(aux_cola)==1)
        {
        aux_cola->primero=nuevo;
        aux_cola->ultimo=nuevo;
    }else
    {
        aux_cola->ultimo->sig=nuevo;
        aux_cola->ultimo=nuevo;
    }
    aux_cola->tamano++;
}

Nodo_cola *decolar(Cola *aux_cola)
{
    Nodo_cola *aux;
    Nodo_cola* Atencion_nodo=(Nodo_cola*)malloc(sizeof(struct t_nodo));
    aux=aux_cola->primero;
    aux_cola->primero=aux_cola->primero->sig;
    Atencion_nodo=aux;
    free(aux);
    aux_cola->tamano--;

    return(Atencion_nodo);

}

void mostrar_cola(Cola *aux_cola)
{
    Nodo_cola*actual;
    actual=aux_cola->primero;
    int i;
    for(i=0;i<aux_cola->tamano;i++)
        {
        printf(" cola_Q[%d]:%c\n", i, actual->vertice_grafo.etiqueta);
        actual=actual->sig;
    }
    if(esta_vacia_cola(aux_cola)==1)
    {
        printf("no hay elementos en la cola.\n");
    }else
    {
        printf("\n");
    }

}

int contar_vecinos(int Idice_nodo)
{
    int contador=0,j;

    for(j=0;j<tam;j++)
        {
        if(matriz_adyacencia[Idice_nodo][j]==1)
            contador++;
    }
        return contador;
}

int in_nodo_matriz(int Idice_nodo, int ind_nodo_visitado)
{
        int j;
        for(j=0;j<tam;j++)
            {
            if(matriz_adyacencia[Idice_nodo][j]==1 && j!=ind_nodo_visitado && j>ind_nodo_visitado)
            {
                return j;
            }

        }
        return 9999;
}



void mostrar_nodo(Nodo aux_nodo)
{
    printf("Valores del vertice:\n");
    printf("el color: %c \n", aux_nodo.color);
    printf("la distancia: %d\n", aux_nodo.distancia);
    printf("su etiqueta: %c\n", aux_nodo.etiqueta);
    printf("tiempo Ingreso: %d\n", aux_nodo.tiempo_I);
    printf("tiempo Final: %d\n", aux_nodo.tiempo_F);
    printf("su padre: %p\n", aux_nodo.padre);

}


void BFS(Nodo aux_grafo[tam], Nodo aux_nodo, int ind_nodo_aux)  // 999 SE REFIERE A INFINITO
{
    Nodo_cola*u=(Nodo_cola*)malloc(sizeof(struct t_nodo));
    int contador=0;
    int i;
    for(i=0;i<tam;i++)
        {
        aux_grafo[i].color='B';
        aux_grafo[i].distancia=9999;
        aux_grafo[i].padre=NULL;
    }
    printf("los nodos del grafo son inicializados 'B' blancos y con una distantancia '9999' (desconocida)\n");
    printf("Ahora nuestro punto inicial en este caso ''A'' tendra una distancia 0 y marcado con gris\n");
    aux_grafo[ind_nodo_aux].distancia=0;
    aux_grafo[ind_nodo_aux].padre=NULL;

    Cola *cola_Q=inicializar_cola();
    printf("para este metodo se crea una cola\n");
    printf("se inicializa ");
    encolar(cola_Q, aux_grafo[ind_nodo_aux], ind_nodo_aux);
    mostrar_cola(cola_Q);
    printf("ahora se ve que el vertice de inicio del grafo es encolado\n"); getchar();

    while(esta_vacia_cola(cola_Q)!=1)
        {
        *u=*decolar(cola_Q);
        printf("Una variable u toma el valor de lo que retorna decolar la Cola\n");
        printf("nuestro vertice u es: %c", u->vertice_grafo.etiqueta); getchar();
        int visitar=-1,indice_nodo_matriz;
        printf("Cada vecino no visitado a 'u' sera visitado si esta blanco.\n");getchar();
        printf("el nodo u tiene %d vecinos\n", contar_vecinos(u->ind_nodo_grafo));
        for(i=0;i<contar_vecinos(u->ind_nodo_grafo);i++)
        {
            indice_nodo_matriz=in_nodo_matriz(u->ind_nodo_grafo, visitar);
            if(aux_grafo[indice_nodo_matriz].color=='B')
            {
                printf("el vecino %c esta blanco por ende ahora se marca a gris\n", aux_grafo[indice_nodo_matriz].etiqueta);
                aux_grafo[indice_nodo_matriz].color='G';
                aux_grafo[indice_nodo_matriz].distancia=(u->vertice_grafo.distancia)+1;
                printf("y su distancia con el vecino %c es de %d\n", aux_grafo[indice_nodo_matriz].etiqueta, aux_grafo[indice_nodo_matriz].distancia);
                aux_grafo[indice_nodo_matriz].padre=&u->vertice_grafo;
                encolar(cola_Q, aux_grafo[indice_nodo_matriz], indice_nodo_matriz);
                printf("El vecino %c con respecto a %c ha sido encolado\n", aux_grafo[indice_nodo_matriz].etiqueta, u->vertice_grafo.etiqueta);
            }
            visitar=indice_nodo_matriz;
            printf("estado actual de la cola_Q:\n");
            mostrar_cola(cola_Q);getchar();
        }
        aux_grafo[u->ind_nodo_grafo].color='N';

    }
    printf("todos los nodos '(vertices)':\n");
    for(i=0;i<tam;i++)
        {
        printf("vertice %c:\n distancia %d, color %c \n", aux_grafo[i].etiqueta, aux_grafo[i].distancia, aux_grafo[i].color);
    }


}
