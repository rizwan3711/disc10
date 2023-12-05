//
// Created by james on 12/3/2023.
//

#ifndef WEEK10DI_CUSTOMLINKEDLIST_H
#define WEEK10DI_CUSTOMLINKEDLIST_H

#include <iostream>

using namespace std;

template <class T>
struct Node {
    T value;
    Node* next;

    Node(T aValue, Node* aNextPtr = nullptr){
        value = aValue;
        next = aNextPtr;
    }
};

// TODO: Given a first and last node as a section of linked list, find the middle node
template<class T>
Node<T>* findMiddle(Node<T>*& first, Node<T>*& last){
    if(first){
        Node<T>* fast = first->next;
        Node<T>* slow = first;
        while(fast != last){
            fast = fast->next;
            if(fast != last){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    return nullptr;
}


template<class T>
class UnsortedLinkedList {
private:
    Node<T>* head = nullptr;

public:
    void printList(){
        Node<T>* nodePtr = head;
        while(nodePtr != nullptr){
            cout << nodePtr->value << " ";
            nodePtr = nodePtr->next;
        }
        cout << endl;
    }

    // TODO: Append aValue to the end of the list
    void append(T aValue){
        Node<T>* addition = new Node<T>(aValue);
        if(!head)
            head = addition;
        else{
            Node<T>* it = head;
            while(it->next){
                it = it->next;
            }
            it->next = addition;
        }
    }

    // TODO: Search for aValue using linear search, return if the value is in the list or not.
    bool linearSearch(T aValue){
        Node<T>* it = head;
        while(it->next){
            if(it->value)
                return true;
            it = it->next;
        }
        return false;
    }
};

template<class T>
class SortedLinkedList {
private:
    Node<T>* head = nullptr;

public:

    // Inserts a node in ascending order to the linked list
    void insertSorted(T aValue){
        Node<T>* newNode = new Node(aValue);
        Node<T>* nodePtr;
        Node<T>* prevNode = nullptr;

        if (head == nullptr){
            head = newNode;
        }
        else {
            nodePtr = head;

            // Skip all nodes less than the new value
            while(nodePtr != nullptr && nodePtr->value < aValue){
                prevNode = nodePtr;
                nodePtr = nodePtr->next;
            }

            // If the new node needs to be inserted as head
            if (prevNode == nullptr){
                head = newNode;
                newNode->next = nodePtr;
            }
            else { // insert after previous node
                prevNode->next = newNode;
                newNode->next = nodePtr;
            }
        }
    }

    void printList(){
        Node<T>* nodePtr = head;
        while(nodePtr != nullptr){
            cout << nodePtr->value << " ";
            nodePtr = nodePtr->next;
        }
        cout << endl;
    }

    // TODO: Uses binary search to find aValue, return if the value is found or not.
    bool binarySearch(T aValue){
        Node<T>* mid = head;
        Node<T>* last = head;
        Node<T>* first = head;
        first = head;
        while(last->next){
            last = last->next;
        }
        while(1){
            mid = findMiddle(first, last);
            if(!mid)
                break;
            if(mid->value == aValue){
                return true;
            }
            if(mid->value < aValue){
                first = mid->next;
            }
            else{
                last = mid;
                if(last->value == aValue)
                    return true;
            }
            if(first == last || last == first->next)
                break;
        }
        return false;
    }
};


#endif //WEEK10DI_CUSTOMLINKEDLIST_H
