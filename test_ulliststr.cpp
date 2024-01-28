#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
 ULListStr dat;
    dat.push_back("7");
    dat.push_front("8");
    dat.push_back("9");

    if(dat.size() >= 3) {
        std::cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << std::endl;
        // Should print: 8 7 9
    } else {
        std::cout << "Not enough elements in the list." << std::endl;
    }

    std::cout << "Size of list: " << dat.size() << std::endl;
    return 0;
}
