#include <utility>
#include <fstream>
#include "Dictionary.h"


int main() {

    std::ifstream file( "/names.txt" ) ;
    std::string line ;
    int line_number = 0 ;

    std::cout << "Starting" ;
    //Read file
    while( file && std::getline( file, line ) )
    {
        ++line_number ;

        std::cout << "line " << line_number << ": " << line << '\n' ;
        std::cout << ++line_number; // read the next line too
        std::getline(file, line);  // then do whatever you want.

    }
    std::cout << "End" ;
    return NULL;
}
