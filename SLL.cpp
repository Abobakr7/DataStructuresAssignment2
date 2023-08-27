#include "singleLinkedList.h"

template<class T>
SLL<T>::SLL() {
    head = tail = nullptr;
    sz = 0;
}

template<class T>
void SLL<T>::insertAtHead(T ele) {
    Node<T> *temp = new Node<T>(ele);
    if (sz == 0) {
        head = tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
    ++sz;
}

template<class T>
void SLL<T>::insertAtTail(T ele) {
    Node<T> *temp = new Node<T>(ele);
    if (sz == 0) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
    ++sz;
}

template<class T>
void SLL<T>::insertAt(T ele, int ind) {
    if (ind >= sz || ind < 0) {
        cerr << "\nOut of Bounds\n" << "Couldn't Insert Element\n";
        return;
    }

    Node<T> *temp = new Node<T>(ele);
    if (sz == 0) {
        head = tail = temp;
        ++sz;
        return;
    }

    Node<T> *frsNode = head;
    for (int i = 1; i < ind; ++i) {
        frsNode = frsNode->next;
    }
    temp->next = frsNode->next;
    frsNode->next = temp;
    ++sz;
}

template<class T>
void SLL<T>::removeAtHead() {
    if (sz == 0) {
        return;
    } else if (sz == 1) {
        delete head;
        head = tail = NULL;
    } else {
        Node<T> *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    --sz;
}

template<class T>
void SLL<T>::removeAtTail() {
    if (sz == 0 || sz == 1) {
        removeAtHead();
    } else {
        Node<T> *temp = head;
        for (; temp->next->next != NULL; temp = temp->next)
        temp->next = NULL;
        delete tail;
        tail = temp;
        --sz;
    }
}

template<class T>
void SLL<T>::removeAt(int ind) {
    if (ind >= sz || ind < 0) {
        cerr << "\nOut of Bounds\n" << "Couldn't Remove Element\n";
    } else if (ind == 0) {
        removeAtHead();
    } else if (ind == sz-1) {
        removeAtTail();
    } else {
        Node<T> *temp = head;
        for (int i = 1; i < ind; ++i) {
            temp = temp->next;
        }
        Node<T> *node = temp->next;
        temp->next = node->next;
        node->next = NULL;
        delete node;
        --sz;
    }
}

template<class T>
T SLL<T>::retrieveAt(int ind) {
    if (ind >= 0 || ind < 0) {
        cerr << "\nOut of Bounds\n" << "Couldn't Retrieve Element\n";
        return -1;
    }

    Node<T> *temp = head;
    for (int i = 0; i < ind; ++i) {
        temp = temp->next;
    }
    return temp->data;
}

template<class T>
void SLL<T>::replaceAt(T ele, int ind) {
    if (ind >= sz || ind < 0) {
        cerr << "\nOut of Bounds\n";
        return;
    }

    Node<T> *temp = head;
    for (int i = 0; i < ind; ++i) {
        temp = temp->next;
    }
    temp->data = ele;
}

template<class T>
bool SLL<T>::isExist(T ele) {
    for (Node<T> *temp = head; temp != NULL; temp = temp->next) {
        if (temp->data == ele)
            return true;
    }
    return false;
}

template<class T>
bool SLL<T>::isItemAtEqual(T ele, int ind) {
    if (ind >= sz || ind < 0) {
        cerr << "\nIndex Out of Bounds\n";
        return false;
    }

    Node<T> *temp = head;
    for (int i = 0; i < ind; ++i)
        temp = temp->next;

    return temp->data == ele ? true : false;
}

template<class T>
void SLL<T>::swap(int frsInd, int secInd) {
    if (frsInd >= sz || frsInd < 0 || secInd >= sz || secInd < 0) {
        cerr << "\nRanges are Out of Bound\n";
        return;
    }


}

template<class T>
bool SLL<T>::isEmpty() {
    return head == NULL;
}

template<class T>
int SLL<T>::linkedListSize() {
    return sz;
}

template<class T>
void SLL<T>::clear() {
    Node<T> *temp = head;
    while (head != NULL) {
        temp = temp->next;
        head->next = NULL;
        delete head;
        head = temp;
    }
    head = tail = NULL;
    sz = 0;
}

template<class T>
void SLL<T>::print() {
    if (head == NULL){
        cout << "[]";
        return;
    }

    Node<T> *temp = head;
    cout << '[';
    for (; temp->next != NULL; temp = temp->next) {
        cout << temp->data << ", ";
    }
    cout << temp->data << ']';
}

template<class T>
SLL<T>::~SLL() {
    SLL<T>::clear();
}
