//
// Created by leone on 10/27/2020.
//

#ifndef TP_PROGRA3_CASE_H
#define TP_PROGRA3_CASE_H

#include <string>
#include <ostream>

using namespace std;

class Caso{
public:
    long id;
    string sexo;
    int edad;
    string edad_anios_meses;
    string residencia_pais_nombre;
    string residencia_provincia_nombre;
    string residencia_departamento_nombre;
    string carga_provincia_nombre;
    string fecha_inicio_sintomas;
    string fecha_apertura;
    int sepi_apertura;
    string fecha_internacion;
    string cuidado_intensivo;
    string fecha_cui_intensivo;
    string fallecido;
    string fecha_fallecimiento;
    string asistencia_respiratoria_mecanica;
    int carga_provincia_id;
    string origen_financiamiento;
    string clasificacion;
    string clasificacion_resumen;
    int residencia_provincia_id;
    string fecha_diagnostico;
    int residencia_departamento_id;
    string ultima_actualizacion;

    friend ostream &operator<<(ostream &os, const Caso &caso) {
        os << "\n\n\nid_caso: " << caso.id << " \nsexo: " << caso.sexo << " \nedad: " << caso.edad << " \nedad_anios_meses: "
           << caso.edad_anios_meses << " \nresidencia_pais_nombre: " << caso.residencia_pais_nombre
           << " \nresidencia_provincia_nombre: " << caso.residencia_provincia_nombre
           << " \nresidencia_departamento_nombre: " << caso.residencia_departamento_nombre << " \ncarga_provincia_nombre: "
           << caso.carga_provincia_nombre << " \nfecha_inicio_sintomas: " << caso.fecha_inicio_sintomas
           << " \nfecha_apertura: " << caso.fecha_apertura << " \nsepi_apertura: " << caso.sepi_apertura
           << " \nfecha_internacion: " << caso.fecha_internacion << " \ncuidado_intensivo: " << caso.cuidado_intensivo
           << " \nfecha_cui_intensivo: " << caso.fecha_cui_intensivo << " \nfallecido: " << caso.fallecido
           << " \nfecha_fallecimiento: " << caso.fecha_fallecimiento << " \nasistencia_respiratoria_mecanica: "
           << caso.asistencia_respiratoria_mecanica << " \ncarga_provincia_id: " << caso.carga_provincia_id
           << " \norigen_financiamiento: " << caso.origen_financiamiento << " \nclasificacion: " << caso.clasificacion
           << " \nclasificacion_resumen: " << caso.clasificacion_resumen << " \nresidencia_provincia_id: "
           << caso.residencia_provincia_id << " \nfecha_diagnostico: " << caso.fecha_diagnostico
           << " \nresidencia_departamento_id: " << caso.residencia_departamento_id << " \nultima_actualizacion: "
           << caso.ultima_actualizacion;
        return os;
    }


    bool operator<(const Caso &rhs) const {
        return id < rhs.id;
    }

    bool operator>(const Caso &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Caso &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Caso &rhs) const {
        return !(*this < rhs);
    }
};


#endif //TP_PROGRA3_CASE_H
