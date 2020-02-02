#include <iostream>
#include "Dictionary.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    Containers::Dictionary<int, int> dict;


    dict.insert(1, 2);

    int *val = dict.lookup(1);

    dict.remove(1);

    return NULL;
}
