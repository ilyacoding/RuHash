#include <ruhash.h>

int main() {
    while (true) {
    std::vector<char> v;
    char s;
    while (std::cin>>s) {
        if (s == ';') break;
        v.push_back(s);
    }
    
    std::cout<<"Hash: "<<ruhash(v)<<std::endl;
    }
    return 0;	
}
