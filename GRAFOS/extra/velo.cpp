
#include <iostream>
#include <vector>

using namespace std;

unsigned F, C;			// número de filas y de columnas
char M[501][501];		// matriz representando el mapa
vector< unsigned > A[250001];	// listas de adyacencia

// devuelve el número único asociado con el par (i,j)
unsigned unique( unsigned i, unsigned j ) {
	return i*C + j;
}

// devuelve el par (i,j) asociado con el número n
pair< unsigned, unsigned > cell( unsigned n ) {
	return make_pair( n/C, n%C );
}

int main() {
	for ( unsigned z = 0; cin >> F >> C; ++z ) {
		// imprimir separador entre casos
		if ( z ) cout << "---\n";

		vector< unsigned > raptors;

		// leer la entrada y guardar en la matriz M
		// también guardar la posici\'on de los velociraptors
		for ( unsigned i = 0; i < F; ++i )
			for ( unsigned j = 0; j < C; ++j ) {
				cin >> M[i][j];
				if ( M[i][j] == 'V' )
					raptors.push_back( unique( i, j ) );
			}

		// crear las listas de adyacencias
		for ( unsigned i = 0; i < F; ++i )
			for ( unsigned j = 0; j < C; ++j )
				if ( M[i][j] != '#' ) {
					int n = unique( i, j );
					A[n].clear(); // vaciar la lista
					if ( i > 0 && M[i-1][j] != '#' )
						A[n].push_back( unique( i-1, j ) );
					if ( i + 1 < F && M[i+1][j] != '#' )
						A[n].push_back( unique( i+1, j ) );
					if ( j > 0 && M[i][j-1] != '#' )
						A[n].push_back( unique( i, j-1 ) );
					if ( j + 1 < C && M[i][j+1] != '#' )
						A[n].push_back( unique( i, j+1 ) );
				}

		// inicializar el vector de distancias
		// 0 para velocirraptors, -1 para otras casillas
		vector<int> dist( F*C, -1 );
		for ( unsigned i = 0; i < raptors.size(); ++i )
			dist[raptors[i]] = 0;

		// iterar sobre la distancia de los velocirraptors
		// inicialmente u = ubicación de los velocirraptors (distancia 0)
		vector< unsigned > u = raptors;
		vector< unsigned > v;
		while ( u.size() > 0 ) {
			v = u;
			u.clear();

			// iterar sobre cada nodo con distancia actual
			for ( unsigned i = 0; i < v.size(); ++i )
				// iterar sobre cada vecino del nodo
				for ( unsigned j = 0; j < A[v[i]].size(); ++j )
					// si el vecino no ha sido visitado (dist = -1)
					if ( dist[A[v[i]][j]] < 0 ) {
						// actualizar la distancia
						dist[A[v[i]][j]] = dist[v[i]] + 1;
						// añadir vecino al vector u
						u.push_back( A[v[i]][j] );
					}
		}
		
		// añadir un 'X' para cada casilla más lejana
		for ( unsigned i = 0; i < v.size(); ++i ) {
			pair< unsigned, unsigned > p = cell( v[i] );
			M[p.first][p.second] = 'X';
		}

		// imprimir el mapa con los 'X'
		for ( unsigned i = 0; i < F; ++i ) {
			for ( unsigned j = 0; j < C; ++j )
				cout << M[i][j];
			cout << "\n";
		}

	}
 }





