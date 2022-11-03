/**
 * Implement an directed, unweighted graph using adjacency matrix.
 *
 * Written by Sudipto Ghosh for the University of Calcutta
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIM 100

struct Graph
{
  int n;
  int matrix[MAX_DIM][MAX_DIM];
};

struct Graph *initGraph(int _n, int _m)
{
  struct Graph *graph = malloc(sizeof(struct Graph));

  graph->n = _n;

  for (int i = 0; i < graph->n; i++)
  {
    for (int j = 0; j < graph->n; j++)
    {
      graph->matrix[i][j] = 0;
    }
  }

  return graph;
}

void addEdge(struct Graph *graph, int u, int v)
{
  graph->matrix[u][v] = 1;
}

void printGraph(struct Graph *graph)
{
  for (int i = 0; i < graph->n; i++)
  {
    for (int j = 0; j < graph->n; j++)
    {
      printf("%i ", graph->matrix[i][j]);
    }
    printf("\n");
  }
}

// Driver Code
int main(void)
{
  struct Graph *graph = initGraph(5, 8);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 1, 4);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 0);
  addEdge(graph, 3, 4);
  printGraph(graph);
  free(graph);
  return 0;
}
