//
// Created by leone on 11/18/2020.
//

#ifndef PARCIAL2_P3_NODE_H
#define PARCIAL2_P3_NODE_H

template <class T> class Node {
private:
    T data;
    Node<T> *next;

public:
    Node(T data, Node<T> *next) : data(data), next(next) {}
    Node() { next = nullptr; }

    T getData() const { return data; }
    void setData(T data) { Node::data = data; }
    Node<T> *getNext() const { return next; }
    void setNext(Node<T> *next) { Node::next = next; }
};

#endif //PARCIAL2_P3_NODE_H
