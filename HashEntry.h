//
// Created by leone on 11/18/2020.
//

#ifndef PARCIAL2_P3_HASHENTRY_H
#define PARCIAL2_P3_HASHENTRY_H

template <class K, class T> class HashEntry {
private:
    K key;
    T dato;

public:
    HashEntry(K key, T dato) : key(key), dato(dato) {}
    K getKey() const { return key; }
    void setKey(K key) { HashEntry::key = key; }
    T getDato() const { return dato; }
    void setDato(T dato) { HashEntry::dato = dato; }

    bool operator==(const HashEntry &rhs) const { return key == rhs.key; }
    bool operator!=(const HashEntry &rhs) const { return !(rhs == *this); }

    bool operator<(const HashEntry &rhs) const { return key < rhs.key; }
    bool operator>(const HashEntry &rhs) const { return rhs < *this; }
    bool operator<=(const HashEntry &rhs) const { return !(rhs < *this); }
    bool operator>=(const HashEntry &rhs) const { return !(*this < rhs); }
};

#endif //PARCIAL2_P3_HASHENTRY_H
