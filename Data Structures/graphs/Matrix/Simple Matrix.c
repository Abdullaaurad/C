#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100 

void createGraph(int numVertices, int array[MAX_VERTICES][MAX_VERTICES]) {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            array[i][j] = 0;
        }
    }
}

void addVertices(int numToAdd, int *numVertices, int array[MAX_VERTICES][MAX_VERTICES]) {
    *numVertices += numToAdd;
}

void addEdges(int source, int destination, int numVertices, int array[MAX_VERTICES][MAX_VERTICES]) {
    if (source >= 0 && source < numVertices && destination >= 0 && destination < numVertices) {
        array[source][destination] = 1;
        array[destination][source] = 1;
    } else {
        printf("Invalid indices. Edge not added.\n");
    }
}

void removeEdges(int source, int destination, int array[MAX_VERTICES][MAX_VERTICES]) {
    array[source][destination] = 0;
    array[destination][source] = 0;
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
    int numVertices = 5;
    int numEdges = 6;

    int graph[MAX_VERTICES][MAX_VERTICES];
    createGraph(numVertices, graph);

    int edgesToAdd[][2] = {{0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 4}};

    for (int i = 0; i < numEdges; i++) {
        int source = edgesToAdd[i][0];
        int destination = edgesToAdd[i][1];
        addEdges(source, destination, numVertices, graph);
    }

    printf("Initial Graph:\n");
    printGraph(numVertices, graph);

    int numVerticesToAdd = 2;
    addVertices(numVerticesToAdd, &numVertices, graph);

    int edgesToAddNew[][2] = {{0, 4}, {3, 0}};

    for (int i = 0; i < sizeof(edgesToAddNew) / sizeof(edgesToAddNew[0]); i++) {
        int source = edgesToAddNew[i][0];
        int destination = edgesToAddNew[i][1];
        addEdges(source, destination, numVertices, graph);
    }

    int edgesToRemove[][2] = {{1, 2}, {3, 4}};

    for (int i = 0; i < sizeof(edgesToRemove) / sizeof(edgesToRemove[0]); i++) {
        int source = edgesToRemove[i][0];
        int destination = edgesToRemove[i][1];
        removeEdges(source, destination, graph);
    }

    printf("\nFinal Graph:\n");
    printGraph(numVertices, graph);

    return 0;
}
