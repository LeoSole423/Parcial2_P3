#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "Case.h"
#include "BinaryTree.h"

void read_and_order_age(BinaryTree<Caso> &Orden);
void p_casos(int m,BinaryTree<Caso> B);

int main() {
    BinaryTree<Caso> Orden;
    read_and_order_age(Orden);
    p_casos(4,Orden);
    return 0;
}


void p_casos(int m,BinaryTree<Caso> B){
    int n=m;
    B.backwards(n);
}

void read_and_order_age(BinaryTree<Caso> &Orden){
    Caso myCase;
    string line_csv[25];
    string line_titles_csv;
    int count = 0;
    ifstream myFile;
    myFile.open("C:/Users/leone/Desktop/Parcial2_P3/test.csv");
    getline(myFile, line_titles_csv);
    while (myFile.good()) {
        string complete_line_csv;
        getline(myFile, complete_line_csv);
        for (int i = 0; i < 25; i++) {
            line_csv[i] = complete_line_csv.substr(0, complete_line_csv.find(','));
            complete_line_csv = complete_line_csv.substr( complete_line_csv.find(',')+1,complete_line_csv.length()-1);
            if (line_csv[i].length() > 2) { line_csv[i] = line_csv[i].substr(1, line_csv[i].length() - 2); }
        }
        myCase = {stoi(line_csv[0]), line_csv[1], stoi(line_csv[2]), line_csv[3], line_csv[4], line_csv[5],
                  line_csv[6], line_csv[7], line_csv[8], line_csv[9], stoi(line_csv[10]), line_csv[11], line_csv[12],
                  line_csv[13], line_csv[14], line_csv[15], line_csv[16], stoi(line_csv[17]), line_csv[18], line_csv[19],
                  line_csv[20], stoi(line_csv[21]), line_csv[22], stoi(line_csv[23]), line_csv[24]};
        Orden.put(myCase);
    }
    myFile.close();
}