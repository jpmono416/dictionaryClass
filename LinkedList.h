//
// Created by jon on 17/01/2020.
//

#ifndef DICTIONARYCLASS_LINKEDLIST_H
#define DICTIONARYCLASS_LINKEDLIST_H


template<typename T>
class LinkedList
{

    struct Node
    {
        T element;
        Node *nextElem;
    };

    Node *firstNode, *lastNode;


    LinkedList()
    {
        firstNode = nullptr;
        lastNode = nullptr;
    }
    bool insert(T);
    bool pop_back();
    bool remove(T*);
    // Overloading to search and remove by value rather than pointer
    bool remove(T);
    // Overloading to remove a particular item by position
    bool remove(int);
    

};

template<typename T>
bool LinkedList<T>::insert(T value) {
    // Insertion at the end of the list

    Node *temp = new Node;
    temp->element = value;
    temp->next = nullptr;

    if(firstNode == nullptr)
    {
        //Empty list, hence the new node is first and last
        firstNode = temp;
        lastNode = temp;
        temp = nullptr;
    } else
    {
        // Prepopulated list
        lastNode->nextElem=temp;
        lastNode = temp;
    }

    return false;
}

template<typename T>
bool LinkedList<T>::remove(T *) {


}

template<typename T>
bool LinkedList<T>::pop_back() {

    // Remove first element


        Node *temp = new Node;
        temp = firstNode;

        firstNode = firstNode->nextElem;
        delete temp;

        return true;

}

#endif //DICTIONARYCLASS_LINKEDLIST_H