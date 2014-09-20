#include <iostream>
#include <cstring>

using namespace std;

int main(){
    string s1, s2;

    while(cin>>s1){
    if (s1.find("da") != std::string::npos ||  s1.find("dd") != std::string::npos
        && (s1.find("i") != std::string::npos || s1.find("y") != std::string::npos)  ) {
    std::cout << "found!" << '\n';
    }
    }
}
