#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "Case.h"
#include "BinaryTree.h"
#include "Provincia.h"
#include "HasMapTree.h"
#include "List.h"
#include "Par.h"
#include "Fecha.h"
#include <string.h>

void read_and_save(Provincia *Provincias,int argc,char **argv);
void generate_all_Provincias(Provincia *Provincias);
template <typename T> void quicksort(T *arr, int start, int end);
unsigned int miHF(string c);
Fecha stoFecha(string fecha_string);

int main(int argc,char **argv) {
        Provincia Provincias[24];
        generate_all_Provincias(Provincias);
        read_and_save(Provincias,argc,argv);
        return 0;
}


void read_and_save(Provincia *Provincias,int argc,char **argv) {
    Caso myCases;//siempre menos -estad
    HashMapTree<string, List<Caso> *> Orden(24, miHF);//Para provincias
    BinaryTree<Caso> OrdenFecha;
    string line_csv[25];
    string line_titles_csv;
    int count_samples = 0, count_infected = 0, count_death = 0;
    int inf_RE_10A[11];
    for (int i = 0; i < 12; i++) {
        inf_RE_10A[i] = 0;
    }
    int f_RE_10A[11];
    for (int i = 0; i < 12; i++) {
        f_RE_10A[i] = 0;
    }
    ifstream myFile;
    myFile.open("C:/Users/leone/Desktop/Covid19Casos.csv");
    getline(myFile, line_titles_csv);
    string complete_line_csv;
    while (getline(myFile, complete_line_csv)) {
        for (int i = 0; i < 25; i++) {
            line_csv[i] = complete_line_csv.substr(0, complete_line_csv.find(','));
            complete_line_csv = complete_line_csv.substr(complete_line_csv.find(',') + 1,
                                                         complete_line_csv.length() - 1);
            if (line_csv[i].length() > 2) { line_csv[i] = line_csv[i].substr(1, line_csv[i].length() - 2); }
        }
        count_samples++;
        //Contadores para analisis Estadistico
        if (strcmp(argv[1], "-estad") == 0) {
            if (line_csv[19].find("confirmado") != -1) count_infected++;
            if (line_csv[14] == "SI") count_death++;
            // Infectados por Rango Etario 10
            if (line_csv[19].find("confirmado") != -1) {
                if (line_csv[2] == "") line_csv[2] = "-1";
                if (stoi(line_csv[2]) < 10 || line_csv[4] == "Meses") {
                    inf_RE_10A[0]++;
                } else if (stoi(line_csv[2]) > 10 && stoi(line_csv[2]) < 20) {
                    inf_RE_10A[1]++;
                } else if (stoi(line_csv[2]) > 20 && stoi(line_csv[2]) < 30) {
                    inf_RE_10A[2]++;
                } else if (stoi(line_csv[2]) > 30 && stoi(line_csv[2]) < 40) {
                    inf_RE_10A[3]++;
                } else if (stoi(line_csv[2]) > 40 && stoi(line_csv[2]) < 50) {
                    inf_RE_10A[4]++;
                } else if (stoi(line_csv[2]) > 50 && stoi(line_csv[2]) < 60) {
                    inf_RE_10A[5]++;
                } else if (stoi(line_csv[2]) > 60 && stoi(line_csv[2]) < 70) {
                    inf_RE_10A[6]++;
                } else if (stoi(line_csv[2]) > 70 && stoi(line_csv[2]) < 80) {
                    inf_RE_10A[7]++;
                } else if (stoi(line_csv[2]) > 80 && stoi(line_csv[2]) < 90) {
                    inf_RE_10A[8]++;
                } else if (stoi(line_csv[2]) > 90 && stoi(line_csv[2]) < 100) {
                    inf_RE_10A[9]++;
                } else if (stoi(line_csv[2]) > 100 && stoi(line_csv[2]) < 110) {
                    inf_RE_10A[10]++;
                }
            }
            //Muertos por Rango Etario 10
            if (line_csv[14] == "SI") {
                if (line_csv[2] == "") line_csv[2] = "-1";
                if (stoi(line_csv[2]) < 10 || line_csv[4] == "Meses") {
                    f_RE_10A[0]++;
                } else if (stoi(line_csv[2]) > 10 && stoi(line_csv[2]) < 20) {
                    f_RE_10A[1]++;
                } else if (stoi(line_csv[2]) > 20 && stoi(line_csv[2]) < 30) {
                    f_RE_10A[2]++;
                } else if (stoi(line_csv[2]) > 30 && stoi(line_csv[2]) < 40) {
                    f_RE_10A[3]++;
                } else if (stoi(line_csv[2]) > 40 && stoi(line_csv[2]) < 50) {
                    f_RE_10A[4]++;
                } else if (stoi(line_csv[2]) > 50 && stoi(line_csv[2]) < 60) {
                    f_RE_10A[5]++;
                } else if (stoi(line_csv[2]) > 60 && stoi(line_csv[2]) < 70) {
                    f_RE_10A[6]++;
                } else if (stoi(line_csv[2]) > 70 && stoi(line_csv[2]) < 80) {
                    f_RE_10A[7]++;
                } else if (stoi(line_csv[2]) > 80 && stoi(line_csv[2]) < 90) {
                    f_RE_10A[8]++;
                } else if (stoi(line_csv[2]) > 90 && stoi(line_csv[2]) < 100) {
                    f_RE_10A[9]++;
                } else if (stoi(line_csv[2]) > 100 && stoi(line_csv[2]) < 110) {
                    f_RE_10A[10]++;
                }
            }
        }

        //Contadores en Provincias
        if (strcmp(argv[1], "-p_casos") == 0 || strcmp(argv[1], "-p_muertes") == 0) {
            if (line_csv[5] == "CABA") {
                if (line_csv[19].find("confirmado") != -1) Provincias[23].contagios++;
                if (line_csv[14] == "SI") Provincias[23].muertes++;
            } else if (line_csv[5] == "Buenos Aires") {
                if (line_csv[19].find("confirmado") != -1) Provincias[0].contagios++;
                if (line_csv[14] == "SI") Provincias[0].muertes++;
            } else if (line_csv[5] == "La Pampa") {
                if (line_csv[19].find("confirmado") != -1) Provincias[1].contagios++;
                if (line_csv[14] == "SI") Provincias[1].muertes++;
            } else if (line_csv[5] == "Córdoba") {
                if (line_csv[19].find("confirmado") != -1) Provincias[2].contagios++;
                if (line_csv[14] == "SI") Provincias[2].muertes++;
            } else if (line_csv[5] == "Salta") {
                if (line_csv[19].find("confirmado") != -1) Provincias[3].contagios++;
                if (line_csv[14] == "SI") Provincias[3].muertes++;
            } else if (line_csv[5] == "Jujuy") {
                if (line_csv[19].find("confirmado") != -1) Provincias[4].contagios++;
                if (line_csv[14] == "SI") Provincias[4].muertes++;
            } else if (line_csv[5] == "Formosa") {
                if (line_csv[19].find("confirmado") != -1) Provincias[5].contagios++;
                if (line_csv[14] == "SI") Provincias[5].muertes++;
            } else if (line_csv[5] == "Santiago del Estero") {
                if (line_csv[19].find("confirmado") != -1) Provincias[6].contagios++;
                if (line_csv[14] == "SI") Provincias[6].muertes++;
            } else if (line_csv[5] == "Misiones") {
                if (line_csv[19].find("confirmado") != -1) Provincias[7].contagios++;
                if (line_csv[14] == "SI") Provincias[7].muertes++;
            } else if (line_csv[5] == "Corrientes") {
                if (line_csv[19].find("confirmado") != -1) Provincias[8].contagios++;
                if (line_csv[14] == "SI") Provincias[8].muertes++;
            } else if (line_csv[5] == "Tucumán") {
                if (line_csv[19].find("confirmado") != -1) Provincias[9].contagios++;
                if (line_csv[14] == "SI") Provincias[9].muertes++;
            } else if (line_csv[5] == "Chaco") {
                if (line_csv[19].find("confirmado") != -1) Provincias[10].contagios++;
                if (line_csv[14] == "SI") Provincias[10].muertes++;
            } else if (line_csv[5] == "La Rioja") {
                if (line_csv[19].find("confirmado") != -1) Provincias[11].contagios++;
                if (line_csv[14] == "SI") Provincias[11].muertes++;
            } else if (line_csv[5] == "San Juan") {
                if (line_csv[19].find("confirmado") != -1) Provincias[12].contagios++;
                if (line_csv[14] == "SI") Provincias[12].muertes++;
            } else if (line_csv[5] == "Mendoza") {
                if (line_csv[19].find("confirmado") != -1) Provincias[13].contagios++;
                if (line_csv[14] == "SI") Provincias[13].muertes++;
            } else if (line_csv[5] == "Entre Ríos") {
                if (line_csv[19].find("confirmado") != -1) Provincias[14].contagios++;
                if (line_csv[14] == "SI") Provincias[14].muertes++;
            } else if (line_csv[5] == "San Luis") {
                if (line_csv[19].find("confirmado") != -1) Provincias[15].contagios++;
                if (line_csv[14] == "SI") Provincias[15].muertes++;
            } else if (line_csv[5] == "Catamarca") {
                if (line_csv[19].find("confirmado") != -1) Provincias[16].contagios++;
                if (line_csv[14] == "SI") Provincias[16].muertes++;
            } else if (line_csv[5] == "Santa Fe") {
                if (line_csv[19].find("confirmado") != -1) Provincias[17].contagios++;
                if (line_csv[14] == "SI") Provincias[17].muertes++;
            } else if (line_csv[5] == "Neuquén") {
                if (line_csv[19].find("confirmado") != -1) Provincias[18].contagios++;
                if (line_csv[14] == "SI") Provincias[18].muertes++;
            } else if (line_csv[5] == "Río Negro") {
                if (line_csv[19].find("confirmado") != -1) Provincias[19].contagios++;
                if (line_csv[14] == "SI") Provincias[19].muertes++;
            } else if (line_csv[5] == "Chubut") {
                if (line_csv[19].find("confirmado") != -1) Provincias[20].contagios++;
                if (line_csv[14] == "SI") Provincias[20].muertes++;
            } else if (line_csv[5] == "Santa Cruz") {
                if (line_csv[19].find("confirmado") != -1) Provincias[21].contagios++;
                if (line_csv[14] == "SI") Provincias[21].muertes++;
            } else if (line_csv[5] == "Tierra del Fuego") {
                if (line_csv[19].find("confirmado") != -1) Provincias[22].contagios++;
                if (line_csv[14] == "SI") Provincias[22].muertes++;
            }
        }
        //Muestra la carga
        if (count_samples % 10000 == 0) {
            cout << (count_samples * 100) / 2710000 << "%" << endl;
        }
        if (line_csv[2] == "") line_csv[2] = "-1"; //Arregla error stoi
        if (line_csv[0] == "") break;
        //Clase Case ordenada en tabla hash con lista enlazada
        if (strcmp(argv[1], "-p_casos") == 0 || strcmp(argv[1], "-p_muertes") == 0) {
            myCases = {stoi(line_csv[0]),
                       line_csv[1],
                       stoi(line_csv[2]),
                       line_csv[3],
                       line_csv[4],
                       line_csv[5],
                       line_csv[6],
                       line_csv[7],
                       line_csv[8],
                       line_csv[9],
                       stoi(line_csv[10]),
                       line_csv[11],
                       line_csv[12],
                       stoFecha(line_csv[13]),
                       line_csv[14],
                       line_csv[15],
                       line_csv[16],
                       stoi(line_csv[17]),
                       line_csv[18],
                       line_csv[19],
                       line_csv[20],
                       stoi(line_csv[21]),
                       line_csv[22],
                       stoi(line_csv[23]),
                       line_csv[24]};
            try {
                Orden.get(myCases.residencia_provincia_nombre)->insert(0, myCases);
            }
            catch (...) {
                Orden.put(myCases.residencia_provincia_nombre, new List<Caso>());
                Orden.get(myCases.residencia_provincia_nombre)->insert(0, myCases);
            }
        }
        // Mete en la lista enlazada del hash solo los datos cuya edad coincida con la string de arv[2] -> (Años) o (Meses)
        if (strcmp(argv[1], "-casos_edad") == 0) {
            if (line_csv[3].compare(argv[2]) == 0) {
                myCases = {stoi(line_csv[0]),
                           line_csv[1],
                           stoi(line_csv[2]),
                           line_csv[3],
                           line_csv[4],
                           line_csv[5],
                           line_csv[6],
                           line_csv[7],
                           line_csv[8],
                           line_csv[9],
                           stoi(line_csv[10]),
                           line_csv[11],
                           line_csv[12],
                           stoFecha(line_csv[13]),
                           line_csv[14],
                           line_csv[15],
                           line_csv[16],
                           stoi(line_csv[17]),
                           line_csv[18],
                           line_csv[19],
                           line_csv[20],
                           stoi(line_csv[21]),
                           line_csv[22],
                           stoi(line_csv[23]),
                           line_csv[24]};
                try {
                    Orden.get(myCases.residencia_provincia_nombre)->insert(0, myCases);
                }
                catch (...) {
                    Orden.put(myCases.residencia_provincia_nombre, new List<Caso>());
                    Orden.get(myCases.residencia_provincia_nombre)->insert(0, myCases);
                }
            }
        }
        //Orden en arbol segun fecha de cuidados intensivos
        if (strcmp(argv[1], "-casos_cui") == 0) {
            if (line_csv[12].find("SI") != -1) {
                myCases = {stoi(line_csv[0]),
                           line_csv[1],
                           stoi(line_csv[2]),
                           line_csv[3],
                           line_csv[4],
                           line_csv[5],
                           line_csv[6],
                           line_csv[7],
                           line_csv[8],
                           line_csv[9],
                           stoi(line_csv[10]),
                           line_csv[11],
                           line_csv[12],
                           stoFecha(line_csv[13]),
                           line_csv[14],
                           line_csv[15],
                           line_csv[16],
                           stoi(line_csv[17]),
                           line_csv[18],
                           line_csv[19],
                           line_csv[20],
                           stoi(line_csv[21]),
                           line_csv[22],
                           stoi(line_csv[23]),
                           line_csv[24]};
                OrdenFecha.put(myCases);
            }
        }
    }
        myFile.close();
        //Analisis Estadistico
        if (strcmp(argv[1], "-estad") == 0) {
            cout << "Cantidad total de muestras: " << count_samples << endl;
            cout << "Cantidad total de infectados: " << count_infected << endl;
            cout << "Cantidad total de muertos: " << count_death << endl;
            cout << "% Infectados por muestra: " << (count_infected / (float) count_samples) * 100 << "%" << endl;
            cout << "% Fallecidos por muestra: " << (count_death / (float) count_samples) * 100 << "%" << endl;
            cout << "Infectados por Rango Etario" << endl;
            for (int i = 0; i < 11; i++) {
                cout << "Infectados entre " << 10 * i << " y " << 10 * (i + 1) << ": " << inf_RE_10A[i] << endl;
            }
            cout << endl << "Fallecidos por Rango Etario" << endl;
            for (int i = 0; i < 11; i++) {
                cout << "Fallecidos entre " << 10 * i << " y " << 10 * (i + 1) << ": " << f_RE_10A[i] << endl;
            }
        }
        //p_casos
        if (strcmp(argv[1], "-p_casos") == 0) {
            Par<unsigned int, Provincia> porInfectados[24];
            for (int i = 0; i < 24; i++) {
                porInfectados[i] = {Provincias[i].contagios, Provincias[i]};
            }
            quicksort(porInfectados, 0, 23);
            int n;
            if (argc <= 2)
                n = 10;
            else
                n = stoi(argv[2]);
            for (int i = 0; i < n; i++) {
                cout << porInfectados[i].valor.Nombre << ": " << endl;
                cout << "Cantidad de contagios: " << porInfectados[i].valor.contagios << endl;
            }
            //Muestra la lista de casos en la Provincia
            /*for (int i = 0; i < n; i++) {
                cout << "Lista de casos en: "<<porInfectados[i].valor.Nombre<< endl;
                Orden.get(porInfectados[i].valor.Nombre)->print();
            }*/
        }
        //Muestra la lista de casos en la Provincia (10 minutos)
        //p_muertes
        if (strcmp(argv[1], "-p_muertes") == 0) {
            Par<unsigned int, Provincia> porMuertes[24];
            for (int i = 0; i < 24; i++) {
                porMuertes[i] = {Provincias[i].muertes, Provincias[i]};
            }
            quicksort(porMuertes, 0, 23);
            int n;
            if (argc <= 2)
                n = 10;
            else
                n = stoi(argv[2]);
            for (int i = 0; i < n; i++) {
                cout << porMuertes[i].valor.Nombre << ": " << endl;
                cout << "Cantidad de muertos: " << porMuertes[i].valor.muertes << endl;
            }
            //Muestra la lista de casos en la Provincia (10 minutos)
            /*for (int i = 0; i < n; i++) {
                cout << "Lista de casos en: "<<porMuertes[i].valor.Nombre<< endl;
                Orden.get(porMuertes[i].valor.Nombre)->print();
            }*/
        }
        //casos_edad Años  (Problema en CORDOBA CON MESES y Años)
        if (strcmp(argv[1], "-casos_edad") == 0) {
            //Orden por Alfabeto de provincias
            Provincia aux;
            int ord;
            do {
                ord = 0;
                for (int i = 0; i < 23; i++) {
                    if (Provincias[i].Nombre.compare(Provincias[i + 1].Nombre) > 0) {
                        ord = 1;
                        aux = Provincias[i + 1];
                        Provincias[i + 1] = Provincias[i];
                        Provincias[i] = aux;
                    }
                }
            } while (ord != 0);
            for (int i = 0; i < 24; i++) {
                cout << endl << "Lista de casos de la Provincia " << Provincias[i].Nombre << endl;
                system("PAUSE");
                Orden.get(Provincias[i].Nombre)->print();
            }
        }
        //casos_cui
        if(strcmp(argv[1], "-casos_cui") == 0){
            OrdenFecha.inorder();
        }

    }


void generate_all_Provincias(Provincia *Provincias){
    Provincias[0]={"Buenos Aires",0,0};
    Provincias[1]={"La Pampa",0,0};
    Provincias[2]={"Cordoba",0,0};
    Provincias[3]={"Salta",0,0};
    Provincias[4]={"Jujuy",0,0};
    Provincias[5]={"Formosa",0,0};
    Provincias[6]={"Santiago del Estero",0,0};
    Provincias[7]={"Misiones",0,0};
    Provincias[8]={"Corrientes",0,0};
    Provincias[9]={"Tucuman",0,0};
    Provincias[10]={"Chaco",0,0};
    Provincias[11]={"La Rioja",0,0};
    Provincias[12]={"San Juan",0,0};
    Provincias[13]={"Mendoza",0,0};
    Provincias[14]={"Entre Rios",0,0};
    Provincias[15]={"San Luis",0,0};
    Provincias[16]={"Catamarca",0,0};
    Provincias[17]={"Santa Fe",0,0};
    Provincias[18]={"Neuquen",0,0};
    Provincias[19]={"Rio Negro",0,0};
    Provincias[20]={"Chubut",0,0};
    Provincias[21]={"Santa Cruz",0,0};
    Provincias[22]={"Tierra del Fuego",0,0};
    Provincias[23]={"CABA",0,0};
}

template <typename T> void quicksort(T *arr, int start, int end) {
    T pivote = arr[start];
    int izq = start;
    int der = end;
    T temp;

    while (izq <= der) {
        while (arr[der] < pivote)
            der--;

        while (arr[izq] > pivote)
            izq++;

        if (izq <= der) {
            temp = arr[izq];
            arr[izq] = arr[der];
            arr[der] = temp;

            der--;
            izq++;
        }
    }

    if (der > start)
        quicksort(arr, start, der);
    if (izq < end)
        quicksort(arr, izq, end);
}

unsigned int miHF(string c) {
    unsigned int pos = 0;
    for (int i = 0; i < c.length(); ++i) {
        pos += c[i];
    }
    return pos;
}

Fecha stoFecha(string fecha_string){
    Fecha f;
    if(fecha_string.compare("")==0){
        f.dia=0;
        f.mes=0;
        f.anio=0;
        return f;
    }
    f.anio= stoi(fecha_string.substr(0, fecha_string.find('-')));
    fecha_string=fecha_string.substr(fecha_string.find('-')+1,fecha_string.length()-1);
    f.mes= stoi(fecha_string.substr(0, fecha_string.find('-')));
    fecha_string=fecha_string.substr(fecha_string.find('-')+1,fecha_string.length()-1);
    f.dia= stoi(fecha_string);
    return f;
}


