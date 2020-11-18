//
// Created by leone on 11/18/2020.
//

#ifndef PARCIAL2_P3_PAR_H
#define PARCIAL2_P3_PAR_H

template <class K, class V> class Par {
public:
    K clave;
    V valor;
    bool operator<(const Par &rhs) const { return clave < rhs.clave; }
    bool operator>(const Par &rhs) const { return rhs < *this; }
    bool operator<=(const Par &rhs) const { return !(rhs < *this); }
    bool operator>=(const Par &rhs) const { return !(*this < rhs); }
};

#endif //PARCIAL2_P3_PAR_H
