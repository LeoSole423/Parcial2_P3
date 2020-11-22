//
// Created by leone on 11/18/2020.
//PARCIAL2_P3_HASHMAP_H
#ifndef PARCIAL2_P3_HASHMAP_H
#define PARCIAL2_P3_HASHMAP_H

#include "HashEntry.h"

template <class K, class T> class HashMap {
private:
    HashEntry<K, T> **table;

    unsigned int size;

    static unsigned int hashFunc(K clave);

    unsigned int (*hashFuncP)(K clave);

public:
    explicit HashMap(unsigned int size);

    HashMap(unsigned int size, unsigned int (*hashFuncP)(K clave));

    T get(K clave);

    void put(K clave, T valor);

    void remove(K clave);

    ~HashMap();

    bool isEmpty();
};

template <class K, class T> HashMap<K, T>::HashMap(unsigned int size) {
    this->size = size;
    table = new HashEntry<K, T> *[size];
    for (int i = 0; i < size; ++i) {
        table[i] = nullptr;
    }
    hashFuncP = hashFunc;
}

template <class K, class T> HashMap<K, T>::~HashMap() {
    for (int i = 0; i < size; ++i) {
        if (table[i] != nullptr)
            delete table[i];
    }
    delete table;
}

template <class K, class T> void HashMap<K, T>::put(K clave, T valor) {
    unsigned int pos = hashFuncP(clave) % size;
    if (table[pos] != nullptr)
        throw 503;

    table[pos] = new HashEntry<K, T>(clave, valor);
}

template <class K, class T> T HashMap<K, T>::get(K clave) {
    unsigned int pos = hashFuncP(clave) % size;
    if (table[pos] == nullptr)
        throw 404;


    return table[pos]->getDato();
}

template <class K, class T> void HashMap<K, T>::remove(K clave) {
    unsigned int pos = hashFuncP(clave) % size;
    if (table[pos] == nullptr)
        throw 404;

    if (table[pos]->getKey() != clave)
        throw 404;

    delete table[pos];
    table[pos] = nullptr;
}

template <class K, class T> bool HashMap<K, T>::isEmpty() {
    for (int i = 0; i < size; ++i) {
        if (table[i] != nullptr)
            return false;
    }
    return true;
}

template <class K, class T> unsigned int HashMap<K, T>::hashFunc(K clave) {
    return clave;
}

template <class K, class T>
HashMap<K, T>::HashMap(unsigned int size, unsigned int (*fp)(K)) {
    this->size = size;
    table = new HashEntry<K, T> *[size];
    for (int i = 0; i < size; ++i) {
        table[i] = nullptr;
    }
    hashFuncP = fp;
}

#endif PARCIAL2_P3_HASHMAP_H
