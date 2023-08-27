#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED

#include <iostream>
using namespace std;

template<class T>
class Node
{
    public:
        T data;
        Node<T> *next, *prev;

        Node():
            data(0), next(NULL), prev(NULL){}

        Node(T ele):
            data(ele), next(NULL), prev(NULL){}
};


template<class T>
class DLL
{
    private:
        Node<T> *head, *tail;
        int sz;

    public:
        DLL();
//        ~DLL();
        void insertAtHead(T ele);
        void insertAtTail(T ele);
        void insertAt(T ele, int ind);
        void insertAfter(T ele, int ind); // watch out
        void removeAtHead();
        void removeAtTail();
        void removeAt(int ind);
        T retrieveAt(int ind);
        void replaceAt(T ele, int ind);
        bool isExist(T ele);
        bool isItemAtEqual(T ele, int ind);
        void swap(int frsInd, int secInd);
        void reverse();
        bool isEmpty();
        int doubleLinkedListSize();
        void clear();
        void forwardTraversal();
        void backwardTraversal();
};

#endif // DOUBLYLINKEDLIST_H_INCLUDED
