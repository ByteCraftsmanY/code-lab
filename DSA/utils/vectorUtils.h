#ifndef VECTORUTILS_H
#define VECTORUTILS_H

// template <typename T>
void printVector(std::vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        printf("[%d]: %d \t", i, arr[i]);
        // std::cout << arr[i] << " ";
    }
    printf("\n");
}

void printMat(std::vector<std::vector<int>>& mat) {
    for (auto& row : mat) {
        printVector(row);
    }
}

#endif