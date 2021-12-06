#ifndef PROJECT_LINKEDLIST_H
#define PROJECT_LINKEDLIST_H

#include <iostream>

template<typename T>
struct Node {
    T value;
    Node *next;
    Node *prev;

    explicit Node(T const &value, Node *next = nullptr, Node *prev = nullptr);

    Node() = default;

};

template<typename T>
class DuoLinkedList {
public:

    DuoLinkedList();

    ~DuoLinkedList();

    DuoLinkedList<T> &operator=(const DuoLinkedList<T> &) = delete;

    DuoLinkedList(DuoLinkedList const &) = delete;

    void push_back(const T &value);

    void pop_back();

    void show();

    Node<T> &operator[](size_t index);

    void sort();

    void swap(Node<T> &node1, Node<T> &node2);

private:
    Node<T> *head;
    Node<T> *tail;

    size_t size = 0;
};

template<typename T>
Node<T>::Node(const T &value, Node *next, Node *prev) : value(value), next(next), prev(prev) {}

template<typename T>
DuoLinkedList<T>::DuoLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
DuoLinkedList<T>::~DuoLinkedList() {
    Node<T> *temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

template<typename T>
void DuoLinkedList<T>::push_back(const T &value) {
    if (size++ == 0) {
        head = new Node<T>(value, nullptr, nullptr);
        tail = head;
    } else {
        tail->next = new Node<T>(value, nullptr, tail);
        tail = tail->next;
    }
}

template<typename T>
void DuoLinkedList<T>::pop_back() {
    if (tail == nullptr) {
        return;
    }
    if (size == 0) {
        return;
    }
    Node<T> *tmp = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    }
    size--;
    delete tmp;
}

template<typename T>
void DuoLinkedList<T>::show() {
    Node<T> *tmp;
    tmp = head;
    while (tmp) {
        std::cout << tmp->value << std::endl;
        tmp = tmp->next;
    }
}

template<typename T>
Node<T> &DuoLinkedList<T>::operator[](size_t index) {
    int count = 0;
    Node<T> *curr = head;
    while (curr) {
        if (count == index) {
            return curr;
        }
        curr = curr->next;
        ++count;
    }
    return nullptr;
}

template<typename T>
void DuoLinkedList<T>::sort() {
    Node<T> *left = head;
    Node<T> *right = head->next;

    auto *tmp = new Node<T>;
    while (left->next) {
        while (right) {
            if ((left->value) > (right->value)) {
                tmp->value = left->value;
                left->value = right->value;
                right->value = tmp->value;
            }
            right = right->next;
        }
        left = left->next;
        right = left->next;
    }
    delete tmp;
}

template<typename T>
void DuoLinkedList<T>::swap(Node<T> &node1, Node<T> &node2) {
    std::swap(node1.value, node2.value);
    std::swap(node1.next, node2.next);
    std::swap(node1.prev, node2.prev);
}

#endif //PROJECT_LINKEDLIST_H