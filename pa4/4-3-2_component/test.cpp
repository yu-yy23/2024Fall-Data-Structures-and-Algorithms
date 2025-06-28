#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <iostream>

int times = 10000;

std::string getLastLine(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::string lastLine;

    while (std::getline(file, line)) {
        lastLine = line;
    }

    return lastLine;
}

int main() {
    system("g++ data.cpp -o data");
    system("g++ code.cpp -o code -O2");

    while (times--) {
        system("./data > data.in");

        system("./code < data.in > code.out");

        std::string lastLine = getLastLine("code.out");
        std::cout << lastLine << std::endl;
    }

    return 0;
}