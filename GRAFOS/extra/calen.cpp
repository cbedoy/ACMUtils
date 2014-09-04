
#include <iostream>
#include <map>

using namespace std;

int main() {
  string meses[] = {"enero", "febrero", "marzo",
		    "abril", "mayo", "junio",
		    "julio", "agosto", "septiembre",
		    "octubre", "noviembre", "diciembre"};
  int dias[] = {31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31};
  
  map<string,int> m;
  for (int i = 0; i < 12; ++i)
    m[meses[i]] = i;
  
  int n, d;
  string s;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> d >> s >> s;
    int num = m[s];
    if (d < dias[num])
      cout << d+1 << " de " << s << endl;
    else
      cout << "1 de " << meses[(num + 1)%12] << endl;
  }
}
