#include <ruhash.h>

int main() {
    while (true) {
    std::vector <char> varr;
    char s;
    while (std::cin >> s) {
        if (s == ';') break;
        varr.push_back(s);
    }
    
    std :: cout << "Hash: " << ruhash(varr) << std::endl;
    }
    return 0;	
}
