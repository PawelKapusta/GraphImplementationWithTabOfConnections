//
// Created by sony on 09.04.2020.
//

#ifndef ZADANIE4A_EDGE_H
#define ZADANIE4A_EDGE_H
#include <iostream>

using namespace std;
class Edge{
public:
    int edgeValue;


    void setEdgeValue(int value){
        edgeValue = value;
    }
    int getEdgeValue(){
        if (edgeValue == 0){
            cout << "This edge has no value!!! " << endl;
            return -1;
        }
        return edgeValue;
    }

};
#endif //ZADANIE4A_EDGE_H
