
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

int n;             // número de nodos
int A[1001][1001]; // matriz n*n de adyacencia con costes
                   // ausencia de arista representada por un numero grande

void floydwarshall() {
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
	A[i][j] = MIN(A[i][j], A[i][k] + A[k][j]);
}

int main() {
  n = 4;
  A[0][0] = 0;          // distancia de un nodo a su mismo es 0
  A[0][1] = 2;          // arista (0,1) con coste 2
  A[0][2] = 1000000000; // ninguna arista (0,2)
  A[0][3] = 1000000000; // ninguna arista (0,3)
  A[1][0] = 1000000000;
  A[1][1] = 0;
  A[1][2] = 4;
  A[1][3] = 1000000000;
  A[2][0] = 5;
  A[2][1] = 2;
  A[2][2] = 0;
  A[2][3] = 7;
  A[3][0] = 3;
  A[3][1] = 4;
  A[3][2] = 1000000000;
  A[3][3] = 0;

  floydwarshall();
  cout << A[0][3] << "\n";
}
