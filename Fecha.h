//
// Created by leone on 11/21/2020.
//

#ifndef PARCIAL2_P3_FECHA_H
#define PARCIAL2_P3_FECHA_H

#include <ostream>

class Fecha{
public:
    unsigned int dia;
    unsigned int mes;
    unsigned int anio;

    friend ostream &operator<<(ostream &os, const Fecha &fecha) {
        os << fecha.dia << "-" << fecha.mes << "-" << fecha.anio;
        return os;
    }

    bool operator<(const Fecha &rhs) const {
        if(anio<rhs.anio)
            return true;
        else if(anio==rhs.anio){
            if(mes<rhs.mes)
                return true;
            else if(mes==rhs.mes){
                if(dia<rhs.dia)
                    return true;
            }
        }
        return false;
    }

    bool operator>(const Fecha &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Fecha &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Fecha &rhs) const {
        return !(*this < rhs);
    }
};
#endif //PARCIAL2_P3_FECHA_H
