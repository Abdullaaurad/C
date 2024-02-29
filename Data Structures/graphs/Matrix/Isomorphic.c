#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100 

bool areDegreeSequencesEqual(int degSeq1[MAX_VERTICES], int degSeq2[MAX_VERTICES], int n) {
    for (int i = 0; i < n; i++) {
        if (degSeq1[i] != degSeq2[i]) {
            return false;
        }
    }
    return true;
}

void calculateDegreeSequence(int Array[MAX_VERTICES][MAX_VERTICES], int degSeq[MAX_VERTICES], int n) {
    for (int i = 0; i < n; i++) {
        int degree = 0;
        for (int j = 0; j < n; j++) {
            degree += Array[i][j];
        }
        degSeq[i] = degree;
    }
}

void checkIsomorphic(int Array1[MAX_VERTICES][MAX_VERTICES], int n1, int Array2[MAX_VERTICES][MAX_VERTICES], int n2) {
    if (n1 != n2) {
        printf("Not Isomorphic graphs");
        return;
    }

    int degSeq1[MAX_VERTICES], degSeq2[MAX_VERTICES];
    calculateDegreeSequence(Array1, degSeq1, n1);
    calculateDegreeSequence(Array2, degSeq2, n2);

    if (areDegreeSequencesEqual(degSeq1, degSeq2, n1)) {
        printf("The two graphs are Isomorphic");
    } else {
        printf("Not Isomorphic graphs");
    }
}

void createGraph(int numVertices, int array[MAX_VERTICES][MAX_VERTICES]) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            array[i][j] = 0;
        }
    }
}

void addEdges(int source, int destination, int numVertices, int array[MAX_VERTICES][MAX_VERTICES]) {
    if (source >= 0 && source < numVertices && destination >= 0 && destination < numVertices) {
        array[source][destination] = 1;
        array[destination][source] = 1;
    } else {
        printf("Invalid indices. Edge not added.\n");
    }
}

void printGraph(int numVertices, int array[MAX_VERTICES][MAX_VERTICES]) {
    printf("\t");
    for (int i = 0; i < numVertices; i++) {
        printf("[%d]\t", i);
    }
    printf("\n");
    for (int i = 0; i < numVertices; i++) {
        printf("\n[%d]\t", i);
        for (int j = 0; j < numVertices; j++) {
            printf("%d\t", array[i][j]);
        }
    }
    printf("\n");
}

int main() {
    int numVertices1 = 5;
    int numEdges1 = 6;

    int graph1[MAX_VERTICES][MAX_VERTICES];
    createGraph(numVertices1, graph1);

    int edgesToAdd1[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 4}};

    for (int i = 0; i < numEdges1; i++) {
        int source = edgesToAdd1[i][0];
        int destination = edgesToAdd1[i][1];
        addEdges(source, destination, numVertices1, graph1);
    }

    printf("Graph 1:\n");
    printGraph(numVertices1, graph1);

    int numVertices2 = 5;
    int numEdges2 = 6;

    int graph2[MAX_VERTICES][MAX_VERTICES];
    createGraph(numVertices2, graph2);

    int edgesToAdd2[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 4}};

    for (int i = 0; i < numEdges2; i++) {
        int source = edgesToAdd2[i][0];
        int destination = edgesToAdd2[i][1];
        addEdges(source, destination, numVertices2, graph2);
    }

    printf("Graph 2:\n");
    printGraph(numVertices2, graph2);

    checkIsomorphic(graph1, numVertices1, graph2, numVertices2);

    return 0;
}
