#include <iomanip>
#include <iostream>

using namespace std;

class Graph
{
protected:
  int n;
  int m;
  int **inc;
  int edge_num = 0;

public:
  Graph(int n, int m)
  {
    this->n = n;
    this->m = m;
    this->inc = new int *[n];
    for (int i = 0; i < n; i++)
    {
      this->inc[i] = new int[m];
      for (int j = 0; j < m; j++)
      {
        this->inc[i][j] = 0;
      }
    }
  }

  ~Graph()
  {
    for (int i = 0; i < n; i++)
    {
      delete[] this->inc[i];
    }
    delete[] this->inc;
  }

  void addEdge(int u, int v, int w = 1)
  {
    this->inc[u][edge_num] = w;
    this->inc[v][edge_num] = -w;
    edge_num++;
  }

  void print()
  {
    for (int i = 0; i < this->n; i++)
    {
      for (int j = 0; j < this->m; j++)
      {
        cout << setw(4) << right << this->inc[i][j] << " ";
      }
      cout << endl;
    }
  }
};

// Driver Code
int main(void)
{
  Graph g(5, 8);
  g.addEdge(0, 1, 2);
  g.addEdge(0, 4);
  g.addEdge(1, 2);
  g.addEdge(1, 3, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 3, 1);
  g.addEdge(3, 0);
  g.addEdge(3, 4, 4);
  g.print();
  return 0;
}
