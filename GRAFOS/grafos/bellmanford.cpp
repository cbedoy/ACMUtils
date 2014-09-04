
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

#define M 1000000000               // distancia inicial
typedef pair<pair<int,int>,int> P; // par de nodos + coste
int N;                             // numero de nodos
vector<P> v;                       // lista de aristas

int bellmanford(int a, int b) {
  vector<int> d(N, M);
  d[a] = 0;
  for (int i = 1; i < N; i++)
    for (int j = 0; j < (int)v.SZ; j++)
      if (d[v[j].X.X] < M && 
	  d[v[j].X.X] + v[j].Y < d[v[j].X.Y])
        d[v[j].X.Y] = d[v[j].X.X] + v[j].Y;
  for (int j = 0; j < (int)v.SZ; j++)
    if (d[v[j].X.X] < M &&
	d[v[j].X.X] + v[j].Y < d[v[j].X.Y])
      return -M; // existe ciclo negativo
  return d[b];
}

int main() {
  N = 5;
  v.push_back(make_pair(make_pair(0, 1), -1)); // arista (0,1) con coste -1
  v.push_back(make_pair(make_pair(0, 2),  0)); // arista (0,2) con coste 0
  v.push_back(make_pair(make_pair(1, 3),  3)); // arista (1,3) con coste 3
  v.push_back(make_pair(make_pair(2, 1),  2)); // arista (2,1) con coste 2
  v.push_back(make_pair(make_pair(3, 2), -6)); // arista (3,2) con coste -6
  v.push_back(make_pair(make_pair(3, 4), -3)); // arista (3,4) con coste -3
  cout << bellmanford(0, 4) << "\n";
}
