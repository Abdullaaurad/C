#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int Top = -1;
char Stack[MAX_SIZE];
int time = 0;

struct Node {
    char C;
    struct Node* next;
};

struct Vertex {
    char C;
    struct Vertex* next;
    struct Node* Edge;
    int visited;
    int start;
    int end;
};

struct Graph {
    int V;
    struct Vertex* list;
};

struct StackNode {
    struct Vertex* vertex;
    struct StackNode* next;
};

struct Stack {
    struct StackNode* top;
};

// Function to push a vertex onto the stack
void push(struct Stack* stack, struct Vertex* vertex) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->vertex = vertex;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a vertex from the stack
struct Vertex* pop(struct Stack* stack) {
    if (stack->top == NULL) {
        return NULL;  // Empty stack
    }
    struct StackNode* temp = stack->top;
    stack->top = stack->top->next;
    struct Vertex* poppedVertex = temp->vertex;
    free(temp);
    return poppedVertex;
}

struct Graph CreateGraph(struct Graph graph) {
    printf("Enter the number of Vertices: ");
    scanf("%d", &graph.V);

    graph.list = NULL;
    struct Vertex* tail = NULL;
    for (int i = 0; i < graph.V; i++) {
        struct Vertex* newVertex = (struct Vertex*)malloc(sizeof(struct Vertex));
        printf("Enter Vertex %d: ", i + 1);
        scanf(" %c", &newVertex->C);
        newVertex->next = NULL;
        newVertex->Edge = NULL;
        if (tail == NULL) {
            graph.list = newVertex;
        } else {
            tail->next = newVertex;
        }
        tail = newVertex;
    }
    return graph;
}

void AddEdges(struct Graph graph) {
    int E;
    printf("Enter the number of Edges to enter: ");
    getchar();
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        char source, destination;
        printf("Enter the source: ");
        getchar();
        scanf("%c", &source);
        printf("Enter the destination: ");
        getchar();
        scanf("%c", &destination);
        bool destinationExists = false;
        struct Vertex* ptr = graph.list;
        while (ptr != NULL) {
            if (ptr->C == destination) {
                destinationExists = true;
                break;
            }
            ptr = ptr->next;
        }

        if (!destinationExists) {
            printf("Destination vertex not found.\n");
            continue;
        }

        ptr = graph.list;
        while (ptr != NULL && ptr->C != source) {
            ptr = ptr->next;
        }

        if (ptr == NULL) {
            printf("Source vertex not found.\n");
            continue;
        }

        struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
        NewNode->C = destination;
        NewNode->next = NULL;

        if (ptr->Edge == NULL) {
            ptr->Edge = NewNode;
        } else {
            struct Node* temp = ptr->Edge;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = NewNode;
        }
    }
}

void printGraph(struct Graph graph) {
    printf("Graph:\n");
    struct Vertex* vertex = graph.list;
    while (vertex != NULL) {
        printf("%c -> ", vertex->C);
        struct Node* edge = vertex->Edge;
        while (edge != NULL) {
            printf("%c -> ", edge->C);
            edge = edge->next;
        }
        printf("\n");
        vertex = vertex->next;
    }
}

void printTime(struct Graph graph) {
    printf("Time for each vertex:\n");
    struct Vertex* vertex = graph.list;
    while (vertex != NULL) {
        printf("%c start: %d end: %d\n", vertex->C, vertex->start, vertex->end);
        vertex = vertex->next;
    }
}

void DFSUtil(struct Graph graph, struct Vertex* vertex) {
    if (vertex == NULL || vertex->visited == 1) {
        return;
    }

    time++;
    vertex->start = time;

    printf("%c ", vertex->C);
    vertex->visited = 1;

    struct Node* edge = vertex->Edge;
    while (edge != NULL) {
        struct Vertex* adjacentVertex = graph.list;
        while (adjacentVertex != NULL) {
            if (adjacentVertex->C == edge->C && adjacentVertex->visited == 0) {
                DFSUtil(graph, adjacentVertex);
                break;
            }
            adjacentVertex = adjacentVertex->next;
        }
        edge = edge->next;
    }

    time++;
    vertex->end = time;
}

void DFS(struct Graph graph) {
    printf("The graph's DFS = ");

    struct Stack stack;
    stack.top = NULL;

    struct Vertex* resetVertex = graph.list;
    while (resetVertex != NULL) {
        resetVertex->visited = 0;
        resetVertex = resetVertex->next;
    }

    struct Vertex* vertex = graph.list;
    while (vertex != NULL) {
        if (vertex->visited == 0) {
            DFSUtil(graph, vertex);
        }
        vertex = vertex->next;
    }
}

int main() {
    struct Graph graph;
    graph = CreateGraph(graph);
    printGraph(graph);
    AddEdges(graph);
    printGraph(graph);
    DFS(graph);
    printTime(graph);
    return 0;
}
