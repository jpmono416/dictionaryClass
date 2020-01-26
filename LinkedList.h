//
// Created by jon on 17/01/2020.
//

#ifndef DICTIONARYCLASS_LINKEDLIST_H
#define DICTIONARYCLASS_LINKEDLIST_H

/*
 * Followed some references online for information about how
 * singly linked lists internally work, no unreferenced code
 * has been used from these webpages
 */

template<typename T>
class LinkedList
{
    public:
        struct Node
        {
            T element;
            Node *nextElem;

            // Override operator for pointer to return Node
            // https://www.artificialworlds.net/blog/2017/05/11/c-iterator-example-and-an-iterable-range/
            //TODO check running the code without this once finished
            Node operator*()
            {
                return this;
            }
        };

        Node *firstNode, *lastNode, *currentNode;


        LinkedList()
        {
            firstNode = nullptr;
            lastNode = nullptr;
        }

        bool insert(T);
        T pop_back();
        bool remove(T*);
        // Overloading to search and remove by value rather than pointer
        void remove(T);
        T* getElem(T);

        // Make the class range-based iterable
        // https://stackoverflow.com/a/31457319
        Node* begin();
        Node* end();

        // Override ++ operator to allow iteration on the class
        // https://www.artificialworlds.net/blog/2017/05/11/c-iterator-example-and-an-iterable-range/
        Node& operator++()
        {
            currentNode = currentNode->nextElem;

            if(currentNode == nullptr)
            {
                currentNode = begin();
                return end();
            }

            return *currentNode;

        }
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
bool LinkedList<T>::remove(T * elem) {

    Node *currentElement = new Node;
    Node *lastChecked = new Node;
    Node *nextElement = new Node;
    while(currentElement->nextElem != nullptr)
    {
        if(lastChecked = currentElement;
        if(currentElement == elem)
        {
            nextElement = currentElement->nextElem;
            delete currentElement;
        }
        lastChecked->nextElem = nextElement;
        return true;
    }

    // Node not in list
    return false;
}

template<typename T>
T LinkedList<T>::pop_back() {

    // Remove first element


        Node *temp = new Node;
        temp = firstNode;

        firstNode = firstNode->nextElem;
        T first = temp->element;

        delete temp;
        return first;

}

template<typename T>
void LinkedList<T>::remove(T elem) {

    Node *element = getElem(elem);
    delete element;
}

template<typename T>
T* LinkedList<T>::getElem(T elem) {
    Node *temp = firstNode;
    while(temp->nextElem != nullptr)
    {
        if(elem == temp->element)
        {
            return temp;
        }
    }
    // Not found
    return nullptr;
}

template<typename T>
typename LinkedList<T>::Node *LinkedList<T>::begin() {
    return firstNode;
}

template<typename T>
typename LinkedList<T>::Node *LinkedList<T>::end() {
    return lastNode->nextElem;
}

#endif //DICTIONARYCLASS_LINKEDLIST_H