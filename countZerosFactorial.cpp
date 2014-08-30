#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
long long zer(long long n);
int main(){
    int n, t, i;
    cin>>t;
    for(i=0; i<t; i++){
         cin>>n;
         cout<<zer(n)<<"\n";

    }
    return 0;
}

long long zer(long long n)
{
  long long zeros = 0;
  long long  k = 5;

  while( k<= n ) {
    zeros += n/k;
    k *= 5;
  }

  return zeros;
}
