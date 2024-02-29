#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100


int Queue[MAX_SIZE];
int Front=0;
int Rear=0;

void Enqueue(int value) {
    if (Rear == MAX_SIZE - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    Queue[Rear++] = value;
}

bool IsEmpty(){
    if(Front==Rear){
        return 1;
    }
    else{
        return 0;
    }
}

int Dequeue() {
    if (IsEmpty()) {
        printf("Queue Underflow!\n");
        return -1;
    }
    return Queue[Front++];
}

void BFS(int** Array,int numVertices){
    printf("BFS Traversal =");
    int visited[numVertices];
    for(int i=0;i<numVertices;i++){
        visited[i]=0;                               //0 means it is not visited
    }
    int l=0;
    while(visited[l]==0){
        Enqueue(l);
        visited[l]=1;
        while (!IsEmpty()) {
            int current = Dequeue();
            printf("%d ", current);

            for (int b = 0; b < numVertices; b++) {
                if ((Array[current][b] != 0) && (visited[b] == 0)) {
                    Enqueue(b);
                    visited[b] = 1;
                }
            }
        }
        while(visited[l]==1){
            l++;
        }
    }
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
        array[destination][source] = 1;
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

    BFS(graph,numVertices);

    for (int i = 0; i < numVertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}