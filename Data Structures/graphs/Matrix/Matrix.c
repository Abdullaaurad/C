#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** createGraph(int numVertices);
int** AddVertices(int** array, int* numVertices, int numToAdd);
void addEdges(int** array, int source, int destination, int numVertices);
void removeEdges(int** array, int source, int destination);
void printGraph(int** array, int numVertices);

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    int** graph = createGraph(numVertices);

    for (int i = 0; i < numEdges; i++) {
        int source, destination;
        printf("\nEnter edge #%d:\n", i + 1);
        printf("Source index (0 to %d): ", numVertices - 1);
        scanf("%d", &source);
        printf("Destination index (0 to %d): ", numVertices - 1);
        scanf("%d", &destination);
        addEdges(graph, source, destination, numVertices);
    }

    printGraph(graph, numVertices);

    char response;
    printf("\nDo you want to add new vertices? (Y/N): ");
    scanf(" %c", &response);
    if (response == 'Y' || response == 'y') {
        int numToAdd;
        printf("How many vertices to add: ");
        scanf("%d", &numToAdd);
        graph = AddVertices(graph, &numVertices, numToAdd);
    }

    printf("\n");
    printGraph(graph, numVertices);

    printf("\nDo you want to add new edges? (Y/N): ");
    scanf(" %c", &response);
    if (response == 'Y' || response == 'y') {
        int numNewEdges;
        printf("How many edges to enter: ");
        scanf("%d", &numNewEdges);
        for (int i = 0; i < numNewEdges; i++) {
            int source, destination;
            printf("\nEnter new edge #%d:\n", i + 1);
            printf("Source index (0 to %d): ", numVertices - 1);
            scanf("%d", &source);
            printf("Destination index (0 to %d): ", numVertices - 1);
            scanf("%d", &destination);
            addEdges(graph, source, destination, numVertices);
        }
    }

    printf("\nDo you want to remove edges? (Y/N): ");
    scanf(" %c", &response);
    if (response == 'Y' || response == 'y') {
        int numToRemove;
        printf("How many edges to remove: ");
        scanf("%d", &numToRemove);
        for (int i = 0; i < numToRemove; i++) {
            int source, destination;
            printf("\nEnter edge #%d to remove:\n", i + 1);
            printf("Source index (0 to %d): ", numVertices - 1);
            scanf("%d", &source);
            printf("Destination index (0 to %d): ", numVertices - 1);
            scanf("%d", &destination);
            removeEdges(graph, source, destination);
        }
    }

    printf("\nFinal Graph:\n");
    printGraph(graph, numVertices);

    for (int i = 0; i < numVertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}

int** createGraph(int numVertices) {
    int** array = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        array[i] = (int*)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++) {
            array[i][j] = 0;
        }
    }
    return array;
}

int** AddVertices(int** array, int* numVertices, int numToAdd) {
    *numVertices += numToAdd;
    array= (int**)realloc(array, (*numVertices) * sizeof(int*));

    for (int i = *numVertices - numToAdd; i < *numVertices; i++) {
        array[i] = (int*)malloc(*numVertices * sizeof(int));
        for (int j = 0; j < *numVertices; j++) {
            array[i][j] = 0;
        }
    }

    for (int i = 0; i < *numVertices - numToAdd; i++) {
        array[i] = (int*)realloc(array[i], (*numVertices) * sizeof(int));
        for (int j = *numVertices - numToAdd; j < *numVertices; j++) {
            array[i][j] = 0;
        }
    }

    return array;
}

void addEdges(int** array, int source, int destination, int numVertices) {
    if (source >= 0 && source < numVertices && destination >= 0 && destination < numVertices) {
        array[source][destination] = 1;
        array[destination][source] = 1;
    } else {
        printf("Invalid indices. Edge not added.\n");
    }
}

void removeEdges(int** array, int source, int destination) {
    array[source][destination] = 0;
    array[destination][source] = 0;
}

void printGraph(int** array, int numVertices) {
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