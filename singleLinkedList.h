#ifndef SINGLELINKEDLIST_H_INCLUDED
#define SINGLELINKEDLIST_H_INCLUDED

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
class SLL
{
    private:
        Node<T> *head;
        Node<T> *tail;
        int sz;

    public:
        SLL();
        ~SLL();
        void insertAtHead(T ele);
        void insertAtTail(T ele);
        void insertAt(T ele, int ind);
        void removeAtHead();
        void removeAtTail();
        void removeAt(int ind);
        T retrieveAt(int ind);
        void replaceAt(T ele, int ind);
        bool isExist(T ele);
        bool isItemAtEqual(T ele, int ind);
        void swap(int frsInd, int secInd);
        bool isEmpty();
        int linkedListSize();
        void clear();
        void print();
};

#endif // SINGLELINKEDLIST_H_INCLUDED
