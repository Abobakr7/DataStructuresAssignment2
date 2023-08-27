#ifndef CIRCULARLYLINKEDLIST_H_INCLUDED
#define CIRCULARLYLINKEDLIST_H_INCLUDED

#include <iostream>
using namespace std;

template<class T>
class Node
{
    public:
        T data;
        Node<T> *next;

        Node():
            data(0), next(NULL){}

        Node(T ele):
            data(ele), next(NULL){}
};


template<class T>
class CLL
{
    private:
        Node<T> *head, *tail;
        int sz;

    public:
        CLL();
        ~CLL();
        void insertAtHead(T ele);
        void insertAtEnd(T ele);
        void insertAt(T ele, int ind);
        void removeAtHead();
        void removeAtEnd();
        void removeAt(int ind);
        T retrieveAT(int ind);
        void replaceAt(T ele, int ind);
        bool isExist(T ele);
        bool isItemAtEqual(T ele, int ind);
        void swap(int frsInd, int secInd);
        bool isEmpty();
        int circularLinkedListSize();
        void clear();
        void print();
};


#endif // CIRCULARLYLINKEDLIST_H_INCLUDED
