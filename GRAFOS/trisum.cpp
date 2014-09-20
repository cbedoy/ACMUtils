#include <iostream>

using namespace std;

int main(){
    int f, a, b, c, x, y, z;
    cin>>f>>a>>b>>c;
    for(int i = 0 ; i<f ;  i++){
        c *= c;
        x = (c - b) + b;
        b = (c + 1) * x;
        y = (b - a) + a;
        a *=y;
        cout<<c<<" "<<x<<" "<<a;
    }

}
