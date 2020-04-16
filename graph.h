//
// Created by sony on 08.04.2020.
//

#ifndef ZADANIE4A_GRAPH_H
#define ZADANIE4A_GRAPH_H
#include <iostream>
#include "Vertex.h"
#include "Edge.h"
#define MAX 20

using namespace std;


class Graph{

public:
    int tabOfConnections[MAX][MAX];
    int tabVertex[MAX];
    int tabEdgeValues[MAX][MAX];
    int tabEdge[MAX];
    int numberOfVertexes = 0;
    int numberOfEdges = 0;

    Graph(){
        for (auto & tabOfConnection : tabOfConnections) {
            for (int & j : tabOfConnection) {
                j = 0;
            }
        }
        for (int & k : tabVertex) {
            k = 0;
        }
        for (auto & l : tabEdgeValues) {
            for (int & i : l) {
                i = 0;
            }
        }
        for (int & i : tabEdge) {
            i =0;
        }
    }

    void addVertex(Vertex vertex){
        if(vertex.getVertexValue() == 0){
            cout << "You do not set vertex any value! " << endl;
            return;
        }
        tabVertex[numberOfVertexes] = vertex.getVertexValue();
        numberOfVertexes++;
    }

    void removeVertex(Vertex vertex){
        int finder = 0;
        int tabForIndexOfVertexWhichHasEdge[MAX];
        int numberOfConnectedEdges = 0;
        int tabThatHasValuesOfEdgesToDelete[MAX];
        int finderForValuesEdges = 0;
        while(tabVertex[finder] != vertex.getVertexValue()){
            finder++;
        }
        if(tabVertex[finder] == tabVertex[numberOfVertexes-1]){
            for (int i = 0; i < numberOfVertexes; ++i) {
                tabOfConnections[finder][i] = 0;
                tabOfConnections[i][finder] = 0;
                if(tabEdgeValues[finder][i] > 0){
                    tabThatHasValuesOfEdgesToDelete[numberOfConnectedEdges] = tabEdgeValues[finder][i];
                    tabForIndexOfVertexWhichHasEdge[numberOfConnectedEdges] = i;//index of neighbours that have edge with our removing vertex
                    numberOfConnectedEdges++;
                }
                for (int j = 0; j < numberOfConnectedEdges; ++j) {
               tabEdgeValues[finder][tabVertex[tabForIndexOfVertexWhichHasEdge[j]]] = 0;
               tabEdgeValues[tabVertex[tabForIndexOfVertexWhichHasEdge[j]]][finder] = 0;
            }
                for (int l = 0; l < numberOfConnectedEdges; ++l) {
                    for (int k = 0; k < numberOfEdges - 1; ++k) {

                        if(tabEdge[k] == tabThatHasValuesOfEdgesToDelete[l]){
                            finderForValuesEdges = k;
                            for (int j = finderForValuesEdges; j < numberOfEdges - 1; ++j) {
                                tabEdge[j] = tabEdge[j+1];
                            }
                        }
                    }
                    numberOfEdges--;
                }


            }

            numberOfVertexes--;

        }else{
            for (int i = finder; i < numberOfVertexes - 1; ++i) {
                tabVertex[i] = tabVertex[i+1];
            }
            for (int k = 0; k < numberOfVertexes; ++k) {
                if(tabEdgeValues[finder][k] > 0){
                    tabThatHasValuesOfEdgesToDelete[numberOfConnectedEdges] = tabEdgeValues[finder][k];
                    tabForIndexOfVertexWhichHasEdge[numberOfConnectedEdges] = k;//index of neighbours that have edge with our removing vertex
                    numberOfConnectedEdges++;
                }
            }
            for (int l = 0; l < numberOfConnectedEdges; ++l) {
                for (int k = 0; k < numberOfEdges - 1; ++k) {

                    if(tabEdge[k] == tabThatHasValuesOfEdgesToDelete[l]){
                        finderForValuesEdges = k;
                        for (int j = finderForValuesEdges; j < numberOfEdges - 1; ++j) {
                            tabEdge[j] = tabEdge[j+1];
                        }
                    }
                }
                numberOfEdges--;
            }
            for (int j = 0; j < numberOfConnectedEdges; ++j) {
                tabEdgeValues[finder][tabVertex[tabForIndexOfVertexWhichHasEdge[j]]] = 0;
                tabEdgeValues[tabVertex[tabForIndexOfVertexWhichHasEdge[j]]][finder] = 0;
            }
            int temp = finder;//to this place we copy bottom raw
            for (int l = finder; l < numberOfVertexes - 1; ++l) {
                for (int j = 0; j < numberOfVertexes - 1; ++j) {
                    if (j < temp){
                            tabOfConnections[l][j] = tabOfConnections[l+1][j];
                            tabOfConnections[j][l] = tabOfConnections[j][l+1];
                            tabEdgeValues[l][j] = tabEdgeValues[l+1][j];
                            tabEdgeValues[j][l] = tabEdgeValues[j][l+1];
                    }else{
                        tabOfConnections[l][j] = tabOfConnections[l+1][j+1];
                        tabEdgeValues[l][j] = tabEdgeValues[l+1][j+1];
                    }
                }
            }

            numberOfVertexes--;
        }
    }
   bool adjacent(Vertex vertex1, Vertex vertex2){
        int finder1 = 0,finder2 = 0;
        for (int i = 0; i < numberOfVertexes ; ++i) {
            if (tabVertex[i] == vertex1.getVertexValue()){
                finder1 = i;

            } else if (tabVertex[i] == vertex2.getVertexValue()){
                finder2 = i;
            }
        }
       return tabOfConnections[finder1][finder2] > 0;
    }
    void neighbours(Vertex vertex) {
        int finder = 0;
        for (int i = 0; i < numberOfVertexes; ++i) {
            if (tabVertex[i] == vertex.getVertexValue()) {
                finder = i;
            }
        }
        int temporaryTab[numberOfVertexes];
        int howManyNeighbours = 0;
        for (int j = 0; j < numberOfVertexes - 1; ++j) {
            if (tabOfConnections[finder][j] > 0 && j != finder){
                temporaryTab[howManyNeighbours] = j;//adding id of neighbour vertexes to tab
                howManyNeighbours++;
            }
        }
        for (int k = 0; k < howManyNeighbours; ++k) {
            int temp = temporaryTab[k]; // take index of neighbour vertex
            cout << k + 1 << ". neighbour: " <<  tabVertex[temp] << endl;
        }
    }
    void addEdge(Vertex vertex1, Vertex vertex2,Edge edge1){
        if (numberOfVertexes < 1){
            cout << "To add edge you must have an least 2 vertexes! " << endl;
        } else{
            int finder1 = 0,finder2 = 0;
            if(vertex1.getVertexValue() == vertex2.getVertexValue()){
                for (int i = 0; i < numberOfVertexes; ++i) {
                    if(tabVertex[i] == vertex1.getVertexValue()){
                        finder1 = i;
                    }
                }
                finder2 = finder1;
                tabOfConnections[finder1][finder2]++;
                int value = edge1.getEdgeValue();
                tabEdgeValues[finder1][finder2] = value;
                tabEdge[numberOfEdges] = value;
                numberOfEdges++;
            } else{
                for (int i = 0; i < numberOfVertexes ; ++i) {
                    if (tabVertex[i] == vertex1.getVertexValue()){
                        finder1 = i;

                    } else if (tabVertex[i] == vertex2.getVertexValue()){
                        finder2 = i;
                    }
                }
                tabOfConnections[finder1][finder2] ++;
                tabOfConnections[finder2][finder1] ++;
                int value = edge1.getEdgeValue();
                tabEdgeValues[finder1][finder2] = value;
                tabEdgeValues[finder2][finder1] = value;
                tabEdge[numberOfEdges] = value;
                numberOfEdges++;
            }
        }
    }

    void removeEdge(Vertex vertex1, Vertex vertex2){
        int finder1 = 0,finder2 = 0;
        if(vertex1.getVertexValue() == vertex2.getVertexValue()) {
            for (int i = 0; i < numberOfVertexes; ++i) {
                if (tabVertex[i] == vertex1.getVertexValue()) {
                    finder1 = i;
                }
            }
            finder2 = finder1;
            int valueOfRemovingEdge = tabEdgeValues[finder1][finder2];
            int removingFinder = 0;
            for (int j = 0; j < numberOfEdges; ++j) {
                if(tabEdge[j] == valueOfRemovingEdge){
                    removingFinder = j;
                }
            }
            for (int k = removingFinder; k < numberOfEdges - 1; ++k) {
                tabEdge[k] = tabEdge[k+1];
            }
            tabOfConnections[finder1][finder2]--;
            tabEdgeValues[finder1][finder2] = 0;
            numberOfEdges--;
        }else{
            for (int i = 0; i < numberOfVertexes; ++i) {
                if (tabVertex[i] == vertex1.getVertexValue()){
                    finder1 = i;

                } else if (tabVertex[i] == vertex2.getVertexValue()){
                    finder2 = i;
                }
            }
            int valueOfRemovingEdge = tabEdgeValues[finder1][finder2];
            int removingFinder = 0;
            for (int j = 0; j < numberOfEdges; ++j) {
                if(tabEdge[j] == valueOfRemovingEdge){
                    removingFinder = j;
                }
            }
            for (int k = removingFinder; k < numberOfEdges - 1; ++k) {
                tabEdge[k] = tabEdge[k+1];
            }
            tabOfConnections[finder1][finder2] --;
            tabOfConnections[finder2][finder1] --;
            tabEdgeValues[finder1][finder2] = 0;
            tabEdgeValues[finder2][finder1] = 0;
            numberOfEdges--;
        }

    }
    void printValueOfVertexes(){
        for (int i = 0; i < numberOfVertexes; ++i) {
            cout << tabVertex[i] << " ";
        }
        cout << endl;
    }
    void printTabOfConnections(){
        for (int i = 0; i < numberOfVertexes; ++i) {
            for (int j = 0; j < numberOfVertexes; ++j) {
                cout <<"" << tabOfConnections[i][j] << " ";
            }
            cout <<  endl;
        }
        cout <<"-----------------------------------------" << endl;
    }
    void printTabOfEdges(){
        for (int i = 0; i < numberOfEdges; ++i) {
            cout << tabEdge[i] << " ";
        }
        cout << endl;
    }
    void printValueOfEdges(){
        for (int i = 0; i < numberOfVertexes; ++i) {
            for (int j = 0; j < numberOfVertexes; ++j) {
                cout <<"" << tabEdgeValues[i][j] << " ";
            }
            cout <<  endl;
        }
        cout <<"-----------------------------------------" << endl;
    }
};

#endif //ZADANIE4A_GRAPH_H
