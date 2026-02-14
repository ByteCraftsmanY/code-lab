#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

template <typename T>
class Graph {
   public:
    std::vector<std::vector<T>> adjMat;
    std::vector<std::vector<T>> adjList;

    Graph() {
        int n, e;
        std::cin >> n >> e;

        // way 1
        std::vector<std::vector<T>> adjMat(n + 1, std::vector<T>(n + 1, 0));
        // way 2
        std::vector<std::vector<T>> adjList(n + 1);

        T n1, n2;
        for (int i = 0; i < e; i++) {
            std::cin >> n1 >> n2;

            // way 1
            adjMat[n1][n2] = 1;
            adjMat[n2][n1] = 1;

            // way 2
            adjList[n1].push_back(n2);
            adjList[n2].push_back(n1);
        }
        this->adjMat = adjMat;
        this->adjList = adjList;
    }

    void printAdjList() {
        for (int i = 1; i < this->adjList.size(); i++) {
            std::cout << i << " -> ";
            for (auto& ele : this->adjList[i]) {
                std::cout << ele << " ";
            }
            std::cout << "\n";
        }
    }

    void printAdjMatrix() {
        std::cout << "    ";
        for (int i = 1; i < this->adjMat[0].size(); i++) {
            std::cout << i << " ";
        }
        std::cout << "\n";
        for (int i = 1; i < this->adjMat.size(); i++) {
            std::cout << i << " : ";
            for (int j = 1; j < this->adjMat[i].size(); j++) {
                std::cout << this->adjMat[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

std::vector<std::vector<int>> generateIntAdjcencyMatrix() {
    Graph<int>* g = new Graph<int>();
    g->printAdjMatrix();
    return g->adjMat;
}

std::vector<std::vector<int>> generateIntAdjcencyList() {
    Graph<int>* g = new Graph<int>();
    g->printAdjList();
    return g->adjList;
}

#endif