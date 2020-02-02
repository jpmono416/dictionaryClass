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
        class Iterator;
        Iterator begin()
        {
            return Iterator(firstNode);
        }

        Iterator end()
        {
            return Iterator(nullptr);
        }
        struct Node
        {
            T element;
            Node *nextElem;

            bool operator==(const Node *elem)
            {
                return(elem->element == this->element);
            }
        };



        // Got this idea for the iterator for the loop to work for this custom class
        // https://www.geeksforgeeks.org/implementing-iterator-pattern-of-a-single-linked-list/
        // Copied most of the code because the rest of the implementation was almost completed
        // but custom iterator didn't work
        class Iterator
        {
            public:
                /*Iterator() noexcept :
                        currentNode (firstNode) { }*/

                explicit Iterator(Node* node) noexcept :
                        currentNode (node) { }

                // Prefix ++ overload
                Iterator& operator++()
                {
                    if (currentNode)
                        currentNode = currentNode->nextElem;
                    return *this;
                }

                // Postfix ++ overload
                Iterator operator++(int)
                {
                    Iterator iterator = *this;
                    ++*this;
                    return iterator;
                }

                bool operator!=(const Iterator& iterator)
                {
                    return currentNode != iterator.currentNode;
                }

                int operator*()
                {
                    return currentNode->element;
                }
                Node *currentNode;
            private:


        };


        LinkedList() : firstNode{nullptr}, lastNode{nullptr}{}

        bool insert(T);
        T pop_back();
        bool remove(T);

        Node *firstNode, *lastNode;
    private:
        Node * getElem(T);

};

template<typename T>
bool LinkedList<T>::insert(T value) {
    // Insertion at the end of the list

    Node *temp = new Node;
    temp->element = value;
    temp->nextElem = nullptr;

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

    return true;
}

template<typename T>
bool LinkedList<T>::remove(T elem) {

    Node *currentElement = new Node;
    Node *lastChecked = new Node;
    Node *nextElement = new Node;
    while(currentElement->nextElem != nullptr)
    {
        if(currentElement->element == elem)
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
    Node *temp = firstNode;

    firstNode = firstNode->nextElem;
    T first = temp->element;

    delete temp;
    return first;

}

template<typename T>
typename LinkedList<T>::Node *LinkedList<T>::getElem(T elem) {
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

#endif //DICTIONARYCLASS_LINKEDLIST_H