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

#ifndef BFS_H
#include "bfs.h"
#define BFS_H
#endif

#define tam 8

int main()
{
    int opcion;
    while(opcion!=0)
        {
    printf("nuestra matriz de adyacenscia \n\n");
    mostrar_matriz();
    Nodo arreglo_nodos[tam];
	inicializar_arreglo_nodos(arreglo_nodos);
    printf("nuestro grafo \n\n");
	mostrar_grafo(arreglo_nodos);
    int i, tiempo=0;
    printf("Selecciona el metodo \n\n1.-bfs\n2.-dfs\n0.-salir\n");
    scanf("%d",&opcion);
    if (opcion == 1)
        {
        BFS(arreglo_nodos, arreglo_nodos[0], 0);
    }
    else{
        if(opcion == 2)
        {
            printf("Como nodo inicial tendremos al nodo a y luego de ello verificaremos cada vertice\n hasta llegar al final de la rama\n y agregar su tiempo(pasos) desde el final hasta su inicial\n\n");
            getchar();
          DFS(arreglo_nodos, 0, tiempo);
          printf("ahora hemos visto que cada nodo se ha pasado a negro eso es por que ya se han recorrido completamente el grafo y no quedan VERTICES por visitar\n");
          getchar();
        }else
        {
            }
        }
    }
    printf("gracias,por usar el programa se despide Francisco Campillay");
    return 0;
    }

