#include <utility>
#include "Dictionary.h"


int main() {

    using Dict = Containers::Dictionary<char,std::pair<int,int>>;

    Dict::Key  key  = 'A';
    Dict::Item item = std::pair<int,int>(0,1);

    Dict dict;
    bool insertSuccess  = dict.insert(key,item);
    Dict::Item* itemPtr = dict.lookup(key);
    bool removeSuccess  = dict.remove(key);

    if(insertSuccess && removeSuccess && itemPtr != nullptr)
    {
        std::cout << "BIG YES MAN";
    }
    else { std::cout << "FUCK U BRO"; }

    return insertSuccess && removeSuccess && itemPtr != nullptr;

    /*
     *
     *
     * std::cout << "Hello, World!" << std::endl;

    Containers::Dictionary<int, int> dict;
    Containers::Dictionary<long, std::string> dict2;

    dict.insert(1, 2);
    dict.insert(3,7);
    dict.insert(4, 5);

    dict2.insert(5L, "cinco");
    dict2.insert(1L, "uno");

    std::cout << "Value 2: " << *dict.lookup(1) << std::endl;
    std::cout << "Str 5: " << *dict2.lookup(5L) << std::endl;

    std::cout << "Value 7: " << *dict.lookup(3) << std::endl;
    std::cout << "Str 1: " << *dict2.lookup(1L) << std::endl;

    dict.remove(3);
    dict2.remove(5L);

    std::cout << "Value (null): " << (dict.lookup(3)==nullptr) << std::endl;
    std::cout << "Str (null): " << (dict2.lookup(1L)==nullptr) << std::endl;
     *
     *
     */
    //return NULL;
}
