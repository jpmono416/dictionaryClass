//
// Created by jpmon on 14/01/2020.
//

#ifndef DICTIONARYCLASS_DICTIONARY_H
#define DICTIONARYCLASS_DICTIONARY_H


#include <string>
#include <iostream>
#include "LinkedList.h"
#include <functional>

namespace Containers
{
    template <typename K, typename V>
    class Dictionary {
        public:
            using Key = K;
            using Item = V;
            using Pair = std::pair<Key, Item>;

            LinkedList<std::pair<Key,Item>> dictList;

            bool insert(Key, Item);
            Item* lookup(Key);
            bool remove(Key);
            bool removeIf(const std::function<bool(std::pair<Key,Item>)>&);
    };

    template<typename K, typename V>
    bool Dictionary<K, V>::insert(Key k, Item i) {
        std::pair<Key, Item> newElem = {k,i};
        dictList.insert(newElem);
        return true;
    }

    template<typename Key, typename Item>
    typename Dictionary<Key, Item>::Item* Dictionary<Key, Item>::lookup(const Key k) {

        for(typename LinkedList<Pair>::Iterator iterator = dictList.begin(); iterator != dictList.end(); iterator++)
        {
            if(iterator.currentNode->element.first != k) { continue; }

            return &iterator.currentNode->element.second;
        }
        // Not found
        return nullptr;
    }



    template<typename Key, typename Item>
    bool Dictionary<Key, Item>::remove(Key k)
    {
        // Function that finds element
        return removeIf([k](std::pair<Key, Item> element){
            return element.first == k;
        });
    }

    template<typename K, typename V>
    bool Dictionary<K, V>::removeIf(const std::function<bool(Pair)> &funct) {

        bool hasRemoved = false;
        for(typename LinkedList<Pair>::Iterator iterator = dictList.begin();
        iterator != dictList.end(); iterator++)
        {
            if(funct(iterator.currentNode->element))
            {
                dictList.remove(iterator.currentNode->element);
                hasRemoved = true;
            }
        }

        return hasRemoved;
    }
}

#endif //DICTIONARYCLASS_DICTIONARY_H