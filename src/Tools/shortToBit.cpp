#include <iostream>
#include <bitset>
#include <cstring>

int main(int argc, char* argv[]){
    for(int i = 1; i < argc; i++){
        std::bitset<16> arg(atoi(argv[i]));
        std::cout << arg << std::endl;   
    }
    return 0;
}