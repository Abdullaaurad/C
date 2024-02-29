#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int Stack[MAX_SIZE];
int Top=-1;

bool IsEmpty(){
    if(Top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void Push(int Value){
    Top++;
    Stack[Top]=Value;
}

int Pop(){
    int temp=Stack[Top];
    Top--;
    return temp;
}

void pre_DFS(int** array, int vertex, int numVertices, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < numVertices; i++) {
        if (array[vertex][i] == 1 && !visited[i]) {
            pre_DFS(array, i, numVertices, visited);
        }
    }
}

void post_DFS(int** array, int vertex, int numVertices, int* visited) {
    visited[vertex] = 1;
    for (int i = 0; i < numVertices; i++) {
        if (array[vertex][i] == 1 && !visited[i]) {
            post_DFS(array, i, numVertices, visited);
        }
    }
    printf("%d ", vertex);
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

void addEdges(int** array, int source, int destination, int numVertices) {
    if (source >= 0 && source < numVertices && destination >= 0 && destination < numVertices) {
        array[source][destination] = 1;
    } else {
        printf("Invalid indices. Edge not added.\n");
    }
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

    int visited1[numVertices];
    for(int i=0;i<numVertices;i++){
        visited1[i]=0;
    }
    printf("\npreorder DFS traversal: ");
    pre_DFS(graph,0,numVertices,visited1);

    int visited2[numVertices];
    for(int i=0;i<numVertices;i++){
        visited2[i]=0;
    }   
    printf("\npostorder DFS traversal: ");
    post_DFS(graph,0,numVertices,visited2);
    free(graph);

    return 0;
}