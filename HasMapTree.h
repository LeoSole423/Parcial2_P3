//
// Created by leone on 11/18/2020.
//

#ifndef PARCIAL2_P3_HASMAPTREE_H
#define PARCIAL2_P3_HASMAPTREE_H
#include "HashEntry.h"
#include "BinaryTree.h"

template <class K, class T> class HashMapTree {
private:
    BinaryTree<HashEntry<K, T>> **table;

    unsigned int size;

    static unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);

public:
    explicit HashMapTree(unsigned int size);

    HashMapTree(unsigned int size, unsigned int (*hashFuncP)(K clave));

    T get(K clave);

    void put(K clave, T valor);

    void remove(K clave);

    ~HashMapTree();

    bool isEmpty();
};

template <class K, class T> HashMapTree<K, T>::HashMapTree(unsigned int size) {
    this->size = size;
    table = new BinaryTree<HashEntry<K, T>> *[size];
    for (int i = 0; i < size; ++i) {
        table[i] = nullptr;
    }
    hashFuncP = hashFunc;
}

template <class K, class T> HashMapTree<K, T>::~HashMapTree() {
    for (int i = 0; i < size; ++i) {
        if (table[i] != nullptr)
            delete table[i];
    }
    delete table;
}

template <class K, class T> void HashMapTree<K, T>::put(K clave, T valor) {
    unsigned int pos = hashFuncP(clave) % size;
    if (table[pos] == nullptr) {
        table[pos] = new BinaryTree<HashEntry<K, T>>();
    }

    table[pos]->put({clave, valor});
}

template <class K, class T> T HashMapTree<K, T>::get(K clave) {
    unsigned int pos = hashFuncP(clave) % size;
    if (table[pos] == nullptr)
        throw 404;
    T dato;
    return table[pos]->search({clave, dato}).getDato();
}

template <class K, class T> void HashMapTree<K, T>::remove(K clave) {
    unsigned int pos = hashFuncP(clave) % size;
    if (table[pos] == nullptr)
        throw 404;

    T dato;
    table[pos]->remove({clave, dato});
    if (table[pos]->isEmpty()) {
        delete table[pos];
        table[pos] = nullptr;
    }
}

template <class K, class T> bool HashMapTree<K, T>::isEmpty() {
    for (int i = 0; i < size; ++i) {
        if (table[i] != nullptr)
            return false;
    }
    return true;
}

template <class K, class T> unsigned int HashMapTree<K, T>::hashFunc(K clave) {
    return clave;
}

template <class K, class T>
HashMapTree<K, T>::HashMapTree(unsigned int size, unsigned int (*fp)(K)) {
    this->size = size;
    table = new BinaryTree<HashEntry<K, T>> *[size];
    for (int i = 0; i < size; ++i) {
        table[i] = nullptr;
    }
    hashFuncP = fp;
}
#endif PARCIAL2_P3_HASMAPTREE_H
