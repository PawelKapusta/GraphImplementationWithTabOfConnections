#include <iostream>
#include <fstream>
#include <chrono>

#include "Vertex.h"
#include "Edge.h"
#include "graph.h"
using namespace std;
#define MAX 500


int main() {

    Vertex vertex0;
    vertex0.setVertexValue(2);
    cout << vertex0.getVertexValue() << endl;

    Vertex vertex1;
    vertex1.setVertexValue(45);
    cout << vertex1.getVertexValue() << endl;

    Vertex vertex2;
    vertex2.setVertexValue(21);
    cout << vertex2.getVertexValue() << endl;

    Vertex vertex3;
    vertex3.setVertexValue(5);
    cout << vertex3.getVertexValue() << endl;

    Vertex vertex4;
    vertex4.setVertexValue(120);
    cout << vertex4.getVertexValue() << endl;

    Vertex vertex5;
    vertex5.setVertexValue(65);
    cout << vertex5.getVertexValue() << endl;

    Vertex vertex6;
    vertex6.setVertexValue(78);
    cout << vertex6.getVertexValue();

    Graph graph;

    graph.addVertex(vertex0);
    graph.addVertex(vertex1);
    graph.addVertex(vertex2);
    graph.addVertex(vertex3);
    graph.addVertex(vertex4);
    graph.addVertex(vertex5);
    graph.addVertex(vertex6);
    cout << endl;
    graph.printValueOfVertexes();


    graph.printTabOfConnections();

    Edge edge0;
    edge0.setEdgeValue(13);
    cout << edge0.getEdgeValue() << endl;

    Edge edge1;
    edge1.setEdgeValue(3);
    cout << edge1.getEdgeValue()<< endl;
    Edge edge2;
    edge2.setEdgeValue(5);
    cout << edge2.getEdgeValue()<< endl;
    Edge edge3;
    edge3.setEdgeValue(7);
    cout << edge3.getEdgeValue()<< endl;
    Edge edge4;
    edge4.setEdgeValue(12);
    cout << edge4.getEdgeValue()<< endl;
    Edge edge5;
    edge5.setEdgeValue(20);
    cout << edge5.getEdgeValue()<< endl;
    Edge edge6;
    edge6.setEdgeValue(30);
    cout << edge6.getEdgeValue()<< endl;
    Edge edge7;
    edge7.setEdgeValue(2);
    cout << edge7.getEdgeValue()<< endl;
    Edge edge8;
    edge8.setEdgeValue(4);
    cout << edge8.getEdgeValue()<< endl;


    graph.addEdge(vertex0, vertex1,edge0);
    graph.addEdge(vertex0, vertex2,edge1);
    graph.addEdge(vertex0, vertex4,edge2);
    graph.addEdge(vertex1,vertex2,edge3);
    graph.addEdge(vertex2,vertex4,edge4);
    graph.addEdge(vertex2,vertex5,edge5);
    graph.addEdge(vertex3,vertex4,edge6);
    graph.addEdge(vertex4,vertex5,edge7);
    graph.addEdge(vertex5,vertex5,edge8);

    graph.printTabOfConnections();

   graph.displayGraph();
//
//    cout << "Is edge between vertex0 and vertex0? -> (read circle around vertex0): "<<  graph.adjacent(vertex0,vertex0) << endl;
//    cout << "Is edge between vertex2 and vertex4? " << graph.adjacent(vertex2,vertex4) << endl;
//    graph.neighbours(vertex4);

//    graph.removeEdge(vertex0,vertex2);
//    graph.printTabOfConnections();
 //   graph.removeVertex(vertex4);
   // graph.printTabOfConnections();
    //graph.printValueOfVertexes();

//    graph.printTabOfEdges();
//    cout << "---------------------" << endl;
//    graph.printValueOfEdges();
//    graph.removeVertex(vertex4);
//    graph.printValueOfVertexes();
//    graph.printTabOfConnections();
//    graph.printValueOfEdges();
//    graph.printTabOfEdges();
//    graph.removeEdge(vertex0,vertex1);
//    graph.printTabOfEdges();
//    cout << "---------------------" << endl;
//    graph.printValueOfEdges();
//    Graph newGraph;
//    Vertex tab[MAX];
//    for (auto & k : tab) {
//        Vertex newVertex;
//        newVertex.setVertexValue(rand()%1000);
//        k = newVertex;
//    }
//    srand(time(NULL));
//    //int n=200;
//    ofstream zapis;
//    double ile = 0;
//    zapis.open("/home/sony/CLionProjects/AISD2/Zadanie4A/daneInsertVertex.txt",ios::out | ios::app);
//    double totalTime = 0;
//    if (zapis.good()) {
//        for (int i = 0; i < 1000; ++i) {
//            auto start = chrono::high_resolution_clock::now();
//            for (int j = 0; j < MAX; ++j) {
//                newGraph.addVertex(tab[j]);
//            }
//            auto end = chrono::high_resolution_clock::now();
//            chrono::duration<double> elapsed = end - start;
//            totalTime = elapsed.count();
//            ile += totalTime;
//        }
//    }
//    zapis << MAX  << " " << ile/1000 << endl;
//
//    zapis.flush();
//    zapis.close();


    return 0;
}
