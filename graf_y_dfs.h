#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

#define tam 8


typedef struct tipo_nodo
{
    char color;// B white, N black, G grey;
    struct tipo_nodo *padre;
    int distancia, tiempo_I, tiempo_F;
    char etiqueta;//simbolo o contenido?
}Nodo;

const int matriz_adyacencia[8][8]=
{
                       // a b c d e f g h
                  /*a*/  {0,1,1,0,1,1,1,1},
                  /*b*/  {1,0,1,0,0,0,0,0},
                  /*c*/  {1,1,0,1,0,0,0,0},
                  /*d*/  {0,0,1,0,0,0,0,0},
                  /*e*/  {1,0,0,0,0,0,0,0},
                  /*f*/  {1,0,0,0,0,0,0,0},
                  /*g*/  {1,0,0,0,0,0,0,1},
                  /*h*/  {1,0,0,0,0,0,1,0}};

Nodo Iniciar_nodo(char etiqueta)
{
    Nodo aux;
    aux.color='B';
    aux.padre=NULL;
    aux.distancia=aux.tiempo_I=aux.tiempo_F=0;
    aux.etiqueta=etiqueta;

    return aux;
}

void inicializar_arreglo_nodos(Nodo aux_arreglo[8])
{
    int i;
    for(i=0;i<8;i++){
        aux_arreglo[i]=Iniciar_nodo('a'+i);
    }

}

void mostrar_grafo(Nodo aux_grafo[tam]){

printf("     |%c|  |%c|  \n",aux_grafo[7].etiqueta,aux_grafo[1].etiqueta);
printf("    / |  / |\n");
printf(" |%c|-|%c|--|%c|\n",aux_grafo[6].etiqueta,aux_grafo[0].etiqueta,aux_grafo[2].etiqueta);
printf("    / |    |\n");
printf(" |%c|  |   |%c|\n",aux_grafo[5].etiqueta,aux_grafo[3].etiqueta);
printf("     |%c|\n",aux_grafo[4].etiqueta);

}

void mostrar_matriz()
{
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++)
            if(matriz_adyacencia[i][j]==1){
            printf("1");
            }
            else
            {
                    if(matriz_adyacencia[i][j]==0)
                    {
                    printf("0");
            }
            }
        printf("\n");
    }
       printf("\n\n");
}


void DFS(Nodo aux_grafo[tam], int indice_inicial, int tiempo)
{
    printf(" ahora nos econtramos en el vertice ' %c 'cada vez que pasemos por aca agregaremos +1 al tiempo transcurrido tiempo actual %d \n",aux_grafo[indice_inicial].etiqueta,tiempo);
    tiempo++;
    (aux_grafo[indice_inicial]).color='G';
    (aux_grafo[indice_inicial]).tiempo_I=tiempo;
    int aux_i, visitar=-1, indice_nodo_matriz;
    for(aux_i=0;aux_i<(contar_vecinos(indice_inicial));aux_i++)
        {
        indice_nodo_matriz=in_nodo_matriz(indice_inicial, visitar);
        if((aux_grafo[indice_nodo_matriz]).color=='B')
        {
            printf("aca hemos encontrado un vertice que no ha sido visitado en este caso %c",aux_grafo[indice_nodo_matriz].etiqueta);
            (aux_grafo[indice_nodo_matriz]).color='N';
            DFS(aux_grafo, indice_nodo_matriz, tiempo);
        }
        printf(" la funcion saltara aca por no existir una casilla blanca o un vertice apto para visitar \n");
        visitar=indice_nodo_matriz;
        getchar();
    }
     printf(" Ahora esta funcion procedera a llenar de negro, el cuadro %c que se econtraban gris \n",aux_grafo[indice_inicial].etiqueta);
    (aux_grafo[indice_inicial]).color='N';
    (aux_grafo[indice_inicial]).tiempo_F=tiempo+1;
    int i;
    for(i=0;i<tam;i++)
        {
        printf("aux_grafo[%d]: Color actual %c ", i , aux_grafo[i].color);
        getchar();
    }

    getchar();
    printf("\n\n");

}

