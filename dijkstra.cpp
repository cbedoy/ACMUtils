#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

#define INF 999
#define MAXN 100

// los nodos en el grafo van de 1 a n
int C[MAXN][MAXN], // matriz de adyacencia, 0 si no estan conectados
                   // costo para ir de i a j si estan conectados
    n,             // numero de nodos
    e;             // numero de aristas

void iniGrafo()
{
  for (int i=1; i<=n; i++)
    memset(&C[i][1], 0, n * sizeof(int));
}

void insertanodo(int a, int b, int c)
{
  C[a][b] = C[b][a] = c;
}

int D[MAXN];          /* distancias minima desde s al nodo i */
int padre[MAXN];      /* ruta hacia el nodo i desde s */
int permanente[MAXN]; /* verdadero al tener la menor ruta al nodo i */

void dijkstra(int s)
{
  priority_queue< pair<int,int> > pq;
  pair <int,int> nodotmp;
  int Vi, Vj;

  // inicializacion
  for (int i=1; i<=n; i++)
    D[i] = INF,
    padre[i] = -1,
    permanente[i] = false;
  // inicializacion del nodo inicial
  D[s] = 0;
  pq.push( pair <int,int> (D[s], s) );
  // calculamos las distancias
  while( !pq.empty() )
  {
    nodotmp = pq.top();  pq.pop();
    Vi = nodotmp.second;
    if ( !permanente[Vi] )
    {
      permanente[Vi] = true;
      for (Vj = 1; Vj <= n; Vj++)
        if ( !permanente[Vj] && C[Vi][Vj] > 0 && D[Vi] + C[Vi][Vj] < D[Vj] )
          D[Vj] = D[Vi] + C[Vi][Vj],
          padre[Vj] = Vi,
          pq.push( pair <int,int> (-D[Vj], Vj) );
    }
  }
}

void imprimeGrafo(int n)
{
  for (int i=1; i<=n; i++)
    printf("%d(%d)  ", i, D[i]);
  printf("\n");
}

int main()
{
  int a, b, c;

  // leemos el numero de nodos y aristas
  scanf("%d%d", &n, &e);
  // inicializamos el grafo
  iniGrafo();
  // leemos las aristas
  for (int i=0; i<e; i++)
    scanf("%d%d%d", &a, &b, &c),
    insertanodo(a, b, c);
  // usamos dijkstra para calcular la menor distancia
  // desde el i-esimo nodo hacia los demas
  for (int i=1; i<=n; i++)
    dijkstra( i ),
    printf("La menor distancia desde el nodo %d"
           " hacia los otros nodos es:\n", i),
    imprimeGrafo( n ),
    printf("\n");

    return 0;
}
