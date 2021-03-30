#ifndef _GRAFOS_H_
#define _GRAFOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Codigo: https://www.geeksforgeeks.org/graph-and-its-representations/
struct AdjListNode 
{ 
	int dest; 
	int peso;
	struct AdjListNode* next; 
}; 

struct AdjList 
{ 
	struct AdjListNode *head; 
}; 

struct Graph 
{ 
	int V; 
	struct AdjList* array; 
}; 

struct AdjListNode* newAdjListNode(int dest) 
{ 
	struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
	newNode->dest = dest; 
	newNode->next = NULL; 
	return newNode; 
} 

struct Graph *createGraph(int V) 
{ 
	struct Graph *graph = 
		(struct Graph *) malloc(sizeof(struct Graph)); 
	graph->V = V; 

	graph->array = 
	(struct AdjList *) malloc(V *sizeof(struct AdjList)); 

	int i; 
	for (i = 0; i < V; ++i) 
		graph->array[i].head = NULL; 

	return graph; 
} 

void addEdge(struct Graph *graph, int src, int dest) 
{ 

	struct AdjListNode* newNode = newAdjListNode(dest); 
	newNode->next = graph->array[src].head; 
	graph->array[src].head = newNode; 

	newNode = newAdjListNode(src); 
	newNode->next = graph->array[dest].head; 
	graph->array[dest].head = newNode; 
} 

void printGraph(struct Graph* graph) 
{ 
	int v; 
	for (v = 0; v < graph->V; ++v) 
	{ 
		struct AdjListNode* pCrawl = graph->array[v].head; 
		printf("\n Lista de adyacencia del vertice: %d\n Nodo actual ", v); 
		while (pCrawl) 
		{ 
			printf("-> %d ", pCrawl->dest); 
			pCrawl = pCrawl->next; 
		} 
		printf("\n"); 
	} 
} 

/*
typedef struct _NodoListaAdyacencia{
    int peso;
    struct _NodoListaAdyacencia *siguiente;
}NodoLA;

typedef struct _ListaAdyacencia{
    struct NodoLA *cabeza;
}ListaA;

typedef struct _grafo{
    int dato;
    struct ListaA *mapa;
}Grafo;
*/
#endif