
#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#define X first
#define Y second
#define LI long long
#define MP make_pair
#define PB push_back
#define SZ size()
#define SQ(a) ((a)*(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

using namespace std;

typedef vector<pair<int,pair<int,int> > > V;

int N, mf[2000]; // numero de nodos N <= 2000
V v;             // lista de aristas (coste, (nodo1, nodo2))

int find(int n) { // conjunto conexo de n
  if (mf[n] == n) return n;
  else return mf[n] = find(mf[n]);
}

int kruskal() {
  int a, b, sum = 0;
  sort(v.begin(), v.end());
  for (int i = 0; i < N; i++)
    mf[i] = i; // inicializar conjuntos conexos

  for (int i = 0; i < (int)v.SZ; i++) {
    a = find(v[i].Y.X), b = find(v[i].Y.Y);
    if (a != b) { // si conjuntos son diferentes
      mf[b] = a;  // unificar los conjuntos
      sum += v[i].X; // agregar coste de arista
    }
  }
  return sum;
}

int main() {
  N = 5;               // solucion 13:
                       // (0,3),(1,2),(2,3),(3,4)
  v.PB(MP(4,MP(0,1))); // arista (0,1) coste 4
  v.PB(MP(4,MP(0,2))); // arista (0,2) coste 4
  v.PB(MP(3,MP(0,3))); // arista (0,3) coste 3
  v.PB(MP(6,MP(0,4))); // arista (0,4) coste 6
  v.PB(MP(3,MP(1,2))); // arista (1,2) coste 3
  v.PB(MP(7,MP(1,4))); // arista (1,4) coste 7
  v.PB(MP(2,MP(2,3))); // arista (2,3) coste 2
  v.PB(MP(5,MP(3,4))); // arista (3,4) coste 5
  cout << kruskal() << endl;
}
