#include "circularlyLinkedList.h"

template<class T>
CLL<T>::CLL() {
    head = tail = NULL;
    sz = 0;
}

template<class T>
void CLL<T>::insertAtHead(T ele) {
    Node<T> *temp = new Node<T>(ele);
    if (head == NULL) {
        head = tail = temp;
    } else {
        temp->next = head;
        tail->next = temp;
        head = temp;
    }
    ++sz;
}

template<class T>
void CLL<T>::insertAtEnd(T ele) {
    Node<T> *temp = new Node<T>(ele);
    if (head == NULL) {
        head = tail = temp;
    } else {
        temp->next = head;
        tail->next = temp;
        tail = temp;
    }
    ++sz;
}

template<class T>
void CLL<T>::insertAt(T ele, int ind) {
    if (ind >= sz || ind < 0) {
        cerr << "\nOut of Bounds\n" << "Couldn't insert element\n";
        return;
    }

    Node<T> *newNode = new Node<T>(ele), *temp = head;
    for (int i = 1; i < ind; ++i)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
    ++sz;
}

template<class T>
void CLL<T>::removeAtHead() {
    if (sz == 0) {
        return;
    } else if (sz == 1) {
        delete head;
        head = tail = NULL;
    } else {
        Node<T> *temp = head;
        head = head->next;
        tail->next = head;
        temp->next = NULL;
        delete temp;
    }
    --sz;
}

template<class T>
void CLL<T>::removeAtEnd() {
    if (sz == 0 || sz == 1) {
        removeAtHead();
    } else {
        Node<T> *temp = head;
        for (; temp->next != tail; temp = temp->next)

        temp->next = head;
        tail->next = NULL;
        delete tail;
        tail = temp;
        --sz;
    }
}

template<class T>
void CLL<T>::removeAt(int ind) {
    if (ind >= sz || ind < 0) {
        cerr << "\nOut of Bounds\n" << "Couldn't remove element\n";
        return;
    }

    Node<T> *temp = head;
    for (int i = 1; i < ind; ++i)
        temp = temp->next;

    Node<T> *node = temp->next;
    temp->next = node->next;
    node->next = NULL;
    delete node;
    --sz;
}

template<class T>
T CLL<T>::retrieveAt(int ind) {
    if (ind >= sz || ind < 0) {
        cerr << "\nOut of Bounds\n" << "Couldn't retrieve element\n";
        return -1;
    }

    Node<T> *temp = head;
    for (int i = 0; i < ind; ++i)
        temp = temp->next;

    return temp->data;
}

template<class T>
void CLL<T>::replaceAt(T ele, int ind) {
    if (ind >= sz || ind < 0) {
        cerr << "\nOut of Bounds\n" << "Couldn't replace element\n";
        return;
    }

    Node<T> *temp = head;
    for (int i = 0; i < ind; ++i)
        temp = temp->next;
    temp->data = ele;
}

template<class T>
bool CLL<T>::isExist(T ele) {
    Node<T> *temp = head;
    for (; temp != tail; temp = temp->next){
        if (temp->data == ele)
            return true;
    }
    return false;
}

template<class T>
bool CLL<T>::isItemAtEqual(T ele, int ind) {
    if (ind >= sz || ind < 0) {
        cerr << "\nIndex Out of Bounds\n";
        return;
    }

    Node<T> *temp = head;
    for (int i = 0; i < ind; ++i)
        temp = temp->next;

    return temp->data == ele ? true : false;
}

template<class T>
void CLL<T>::swap(int frsInd, int secInd) {
    if (frsInd >= sz || frsInd < 0 || secInd >= sz || secInd < 0) {
        cerr << "\nRanges are Out of Bound\n";
        return;
    }


}

template<class T>
bool CLL<T>::isEmpty() {
    return sz == 0;
}

template<class T>
int CLL<T>::circularLinkedListSize() {
    return sz;
}

template<class T>
void CLL<T>::clear() {
    Node<T> *temp = head;
    while (head != tail) {
        temp = temp->next;
        head->next = NULL;
        delete head;
        head = temp;
    }
    delete head;
    head = tail = NULL;
    sz = 0;
}

template<class T>
void CLL<T>::print() {
    Node<T> *temp = head;
    cout << '[';
    for (; temp != tail; temp = temp->next)
        cout << temp->data << ", ";
    cout << temp->data << "]\n";
}

template<class T>
CLL<T>::~CLL() {
    CLL<T>::clear();
}
