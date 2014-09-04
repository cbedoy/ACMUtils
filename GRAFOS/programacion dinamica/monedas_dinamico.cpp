
#include <iostream>

using namespace std;

int main() {
  int M[3] = {1, 4, 9};
  int res[1000001];
  res[0] = 0;
  for (int c = 1; c <= 1000000; ++c) {
    res[c] = c;
    for (int i = 0; i < 3; ++i)
      if (M[i] <= c && 1 + res[c - M[i]] < res[c])
	res[c] = 1 + res[c - M[i]];
  }

  cout << res[1] << endl;
  cout << res[12] << endl;
  cout << res[20] << endl;
  cout << res[22] << endl;
}
