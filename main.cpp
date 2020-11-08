#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "Case.h"
#include "BinaryTree.h"
#include "Provincia.h"

void read_and_save(Provincia *Provincias);
void generate_all_Provincias(Provincia *Provincias);
//void p_casos(int m,BinaryTree<Caso> B);

int main(int argc,char *argv[]) {
    Provincia Provincias[24];
    generate_all_Provincias(Provincias);
    read_and_save(Provincias);
    return 0;
}


void read_and_save(Provincia *Provincias){
    //Caso myCase;
    string line_csv[25];
    string line_titles_csv;
    float count_samples=0,count_infected=0,count_death=0;
    ifstream myFile;
    myFile.open("C:/Users/leone/Desktop/Covid19Casos.csv");
    getline(myFile, line_titles_csv);
    while (myFile.good()) {
        string complete_line_csv;
        getline(myFile, complete_line_csv);
        for (int i = 0; i < 25; i++) {
            line_csv[i] = complete_line_csv.substr(0, complete_line_csv.find(','));
            complete_line_csv = complete_line_csv.substr( complete_line_csv.find(',')+1,complete_line_csv.length()-1);
            if (line_csv[i].length() > 2) { line_csv[i] = line_csv[i].substr(1, line_csv[i].length() - 2); }
        }
        //Contadores para analisis Estadistico
        count_samples++;
        if(line_csv[19].find("confirmado")!= -1) count_infected++;
        if(line_csv[14]=="SI") count_death++;
        //Contadores en Provincias
        if(line_csv[5]=="CABA") {
            if (line_csv[19].find("confirmado") != -1) Provincias[23].contagios++;
            if (line_csv[14] == "SI") Provincias[23].muertes++;
        }
        if(line_csv[5]=="Buenos Aires") {
            if (line_csv[19].find("confirmado") != -1) Provincias[0].contagios++;
            if (line_csv[14] == "SI") Provincias[0].muertes++;
        }
       if(line_csv[5]=="La Pampa") {
           if (line_csv[19].find("confirmado") != -1) Provincias[1].contagios++;
           if (line_csv[14] == "SI") Provincias[1].muertes++;
       }
        if(line_csv[5]=="Córdoba") {
            if (line_csv[19].find("confirmado") != -1) Provincias[2].contagios++;
            if (line_csv[14] == "SI") Provincias[2].muertes++;
        }
        if(line_csv[5]=="Salta") {
            if (line_csv[19].find("confirmado") != -1) Provincias[3].contagios++;
            if (line_csv[14] == "SI") Provincias[3].muertes++;
        }
        if(line_csv[5]=="Jujuy") {
            if (line_csv[19].find("confirmado") != -1) Provincias[4].contagios++;
            if (line_csv[14] == "SI") Provincias[4].muertes++;
        }
        if(line_csv[5]=="Formosa") {
            if (line_csv[19].find("confirmado") != -1) Provincias[5].contagios++;
            if (line_csv[14] == "SI") Provincias[5].muertes++;
        }
        if(line_csv[5]=="Santiago del Estero") {
            if (line_csv[19].find("confirmado") != -1) Provincias[6].contagios++;
            if (line_csv[14] == "SI") Provincias[6].muertes++;
        }
        if(line_csv[5]=="Misiones") {
            if (line_csv[19].find("confirmado") != -1) Provincias[7].contagios++;
            if (line_csv[14] == "SI") Provincias[7].muertes++;
        }
        if(line_csv[5]=="Corrientes") {
            if (line_csv[19].find("confirmado") != -1) Provincias[8].contagios++;
            if (line_csv[14] == "SI") Provincias[8].muertes++;
        }
        if(line_csv[5]=="Tucumán") {
            if (line_csv[19].find("confirmado") != -1) Provincias[9].contagios++;
            if (line_csv[14] == "SI") Provincias[9].muertes++;
        }
        if(line_csv[5]=="Chaco") {
            if (line_csv[19].find("confirmado") != -1) Provincias[10].contagios++;
            if (line_csv[14] == "SI") Provincias[10].muertes++;
        }
        if(line_csv[5]=="La Rioja") {
            if (line_csv[19].find("confirmado") != -1) Provincias[11].contagios++;
            if (line_csv[14] == "SI") Provincias[11].muertes++;
        }
        if(line_csv[5]=="San Juan") {
            if (line_csv[19].find("confirmado") != -1) Provincias[12].contagios++;
            if (line_csv[14] == "SI") Provincias[12].muertes++;
        }
        if(line_csv[5]=="Mendoza") {
            if (line_csv[19].find("confirmado") != -1) Provincias[13].contagios++;
            if (line_csv[14] == "SI") Provincias[13].muertes++;
        }
        if(line_csv[5]=="Entre Ríos") {
            if (line_csv[19].find("confirmado") != -1) Provincias[14].contagios++;
            if (line_csv[14] == "SI") Provincias[14].muertes++;
        }
        if(line_csv[5]=="San Luis") {
            if (line_csv[19].find("confirmado") != -1) Provincias[15].contagios++;
            if (line_csv[14] == "SI") Provincias[15].muertes++;
        }
        if(line_csv[5]=="Catamarca") {
            if (line_csv[19].find("confirmado") != -1) Provincias[16].contagios++;
            if (line_csv[14] == "SI") Provincias[16].muertes++;
        }
        if(line_csv[5]=="Santa Fe") {
            if (line_csv[19].find("confirmado") != -1) Provincias[17].contagios++;
            if (line_csv[14] == "SI") Provincias[17].muertes++;
        }
        if(line_csv[5]=="Neuquén") {
            if (line_csv[19].find("confirmado") != -1) Provincias[18].contagios++;
            if (line_csv[14] == "SI") Provincias[18].muertes++;
        }
        if(line_csv[5]=="Río Negro") {
            if (line_csv[19].find("confirmado") != -1) Provincias[19].contagios++;
            if (line_csv[14] == "SI") Provincias[19].muertes++;
        }
        if(line_csv[5]=="Chubut") {
            if (line_csv[19].find("confirmado") != -1) Provincias[20].contagios++;
            if (line_csv[14] == "SI") Provincias[20].muertes++;
        }
        if(line_csv[5]=="Santa Cruz") {
            if (line_csv[19].find("confirmado") != -1) Provincias[21].contagios++;
            if (line_csv[14] == "SI") Provincias[21].muertes++;
        }
        if(line_csv[5]=="Tierra del Fuego") {
            if (line_csv[19].find("confirmado") != -1) Provincias[22].contagios++;
            if (line_csv[14] == "SI") Provincias[22].muertes++;
        }

        /*Clase Case
         * myCase = {stoi(line_csv[0]), line_csv[1], stoi(line_csv[2]), line_csv[3], line_csv[4], line_csv[5],
                  line_csv[6], line_csv[7], line_csv[8], line_csv[9], stoi(line_csv[10]), line_csv[11], line_csv[12],
                  line_csv[13], line_csv[14], line_csv[15], line_csv[16], stoi(line_csv[17]), line_csv[18], line_csv[19],
                  line_csv[20], stoi(line_csv[21]), line_csv[22], stoi(line_csv[23]), line_csv[24]};
        Orden.put(myCase);*/
    }
    //Analisis Estadistico
    cout<<"Cantidad total de muestras: "<<count_samples<<endl;
    cout<<"Cantidad total de infectados: "<<count_infected<<endl;
    cout<<"Cantidad total de muertos: "<<count_death<<endl;
    cout<<"% Infectados por muestra: "<<(count_infected/count_samples)*100<<"%"<<endl;
    cout<<"% Fallecidos por muestra: "<<(count_death/count_samples)*100<<"%"<<endl;
    //
    myFile.close();
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


/*
void p_casos(int m,BinaryTree<Caso> B){
    int n=m;
    B.backwards(n);
}*/