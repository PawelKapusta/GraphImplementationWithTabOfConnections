//
// Created by sony on 09.04.2020.
//

#ifndef ZADANIE4A_VERTEX_H
#define ZADANIE4A_VERTEX_H
#include <iostream>

using namespace std;
#define MAX 20
class Vertex  {
    int valueOnVertex = 0;

    int valueTab[MAX]={};
    int number = 0;


public:
    void setVertexValue(int value){
        for (int i = 0; i < MAX; ++i) {
            if (valueTab[i] == value) {
                cout << "Vertex with this value is already exist in this graph " << endl;
                return;
            }
        }
        valueOnVertex = value;
        valueTab[number] = valueOnVertex;
        number++;
    }

    int getVertexValue(){
        if (valueOnVertex == 0){
            cout << "This vertex has no special value, only default equals: ";
        }
        return valueOnVertex;
    }
};




#endif //ZADANIE4A_VERTEX_H
