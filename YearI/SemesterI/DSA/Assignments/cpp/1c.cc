#include <iomanip>
#include <iostream>

using namespace std;

class Graph
{
protected:
  int n;
  int **adj;

public:
  Graph(int n)
  {
    this->n = n;
    this->adj = new int *[n];
    for (int i = 0; i < n; i++)
    {
      this->adj[i] = new int[n];
      for (int j = 0; j < n; j++)
      {
        this->adj[i][j] = 0;
      }
    }
  }

  ~Graph()
  {
    for (int i = 0; i < n; i++)
    {
      delete[] this->adj[i];
    }
    delete[] this->adj;
  }

  void addEdge(int u, int v)
  {
    this->adj[u][v] = 1;
  }

  void print()
  {
    for (int i = 0; i < this->n; i++)
    {
      for (int j = 0; j < this->n; j++)
      {
        cout << setw(4) << right << this->adj[i][j] << " ";
      }
      cout << endl;
    }
  }
};

// Driver Code
int main(void)
{
  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 3);
  g.addEdge(3, 0);
  g.addEdge(3, 4);
  g.print();
  return 0;
}
