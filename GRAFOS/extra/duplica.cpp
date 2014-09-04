
#include <iostream>

using namespace std;

int main() {
  int n, k, x;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    for (int j = 0; j < k; ++j) {
      cin >> x;
      if (j > 0) cout << " ";
      cout << 2*x;
    }
    cout << endl;
  }
}
