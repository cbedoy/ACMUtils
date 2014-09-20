#include <iostream>
#include <cstring>

using namespace std;

int main(){
    string s1, s2;
    cin>>s1>>s2;

    if (s1.find(s2) != std::string::npos) {
    std::cout << "found!" << '\n';
    }
}
