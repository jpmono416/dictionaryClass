//
// Created by jpmon on 14/01/2020.
//

#ifndef DICTIONARYCLASS_DICTIONARY_H
#define DICTIONARYCLASS_DICTIONARY_H


#include <string>
#include "LinkedList.h"

namespace Containers
{
    template <typename K, typename V>
    class Dictionary {
        public:
            using Key = K;
            using Item = V;

            LinkedList<std::pair<Key,Item>> dictList;

            Dictionary();
            bool insert(Key, Item);
            Item* lookup(Key);
            bool remove(Key);
    };

    template<typename K, typename V>
    bool Dictionary<K, V>::insert(Key k, Item i) {
        std::pair<Key, Item> newElem;
        try
        {
            newElem.first = k;
            newElem.second = i;

            dictList.insert(newElem);
            // TODO DELETE
            std::cout << "Insert successful" << std::endl;
        } catch
        {
            // TODO DELETE
            std::cout << "Could not insert into list" << std::endl;
            return false;
        }
        return true;
    }

    template<typename K, typename V>
    typename Dictionary<K, V>::Item* Dictionary<K, V>::lookup(const Key k) {

        for(elem&& : dictList)
        {
            // Implementation assumes a pair will be used
            if(!elem.element.first == k) { continue; }

            return elem.element.second;
        }
        return nullptr;
    }
}

#endif //DICTIONARYCLASS_DICTIONARY_H