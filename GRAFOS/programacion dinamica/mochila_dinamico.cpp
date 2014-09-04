#include <iostream>

using namespace std;

int main() {
	int N = 11; // número de objetos <= 1000
	int C = 100; // capacidad de la mochila <= 1000
	int v[] = {5,6,7,8,9,10,11,12,13,14,15}; // valor de objetos
	int p[] = {11,13,17,19,23,29,33,37,41,43,47}; // peso de objetos
	
	int M[1001][1001]; // guarda soluciones a subproblemas
	bool Z[1001][1001]; // guarda decisiones tomadas
	for ( int j = 0; j <= 100; ++j )
		M[0][j] = 0; // caso base: sin objeto el valor máximo es 0
	for ( int i = 1; i <= 11; ++i ) {
		M[i][0] = 0; // caso base: con capacidad 0 el valor máximo es 0
		for ( int j = 1; j <= 100; ++j ) {
			M[i][j] = M[i-1][j]; // no cogemos el objeto
			Z[i][j] = 0; // recordar decision
			if ( p[i-1] <= j && M[i][j] < M[i-1][j-p[i-1]] + v[i-1] ) {
				M[i][j] = M[i-1][j-p[i-1]] + v[i-1]; // sí cogemos el objeto
				Z[i][j] = 1; // recordar decision
			}
		}
	}
	cout << M[11][100] << ":";

	// trazar las decisiones hechas
	int n = 11, c = 100;
	for ( n = 11; n > 0; --n ) {
		if ( Z[n][c] ) { // si cogimos el objeto
			cout << " " << n; // imprimir
			c -= p[n-1]; // restar capacidad
		}
	}
	cout << "\n";
}
