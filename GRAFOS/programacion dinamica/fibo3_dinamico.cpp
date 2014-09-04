
#include <iostream>

using namespace std;

int main() {
  int res[1000001];
  res[0] = res[1] = 1;
  for (int n = 2; n <= 1000000; ++n)
    res[n] = res[n-2] + res[n-1];
  cout << res[40] << endl;
}
