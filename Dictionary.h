//
// Created by jpmon on 14/01/2020.
//

#ifndef DICTIONARYCLASS_DICTIONARY_H
#define DICTIONARYCLASS_DICTIONARY_H


#include <string>
#include <forward_list>

template <typename K, typename V>
class Dictionary {
public:
    using Key = K;
    using Item = V;

    std::forward_list<std::pair<Key,Item>> dictList;

};


#endif //DICTIONARYCLASS_DICTIONARY_H
