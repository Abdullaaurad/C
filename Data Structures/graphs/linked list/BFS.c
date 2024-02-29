#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 100
int Rear=-1,Front=-1;
char Queue[MAX_SIZE];

struct Node{
    char C;
    struct Node* next;
};

struct Vertex{
    char C;
    struct Vertex* next;
    struct Node* Edge;
    int visited;
};

struct Graph{
    int V;
    struct Vertex* list;
};

bool IsEmpty(){
    if(Front==-1&&Rear==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void Enqueue(char value){
    if(IsEmpty()){
        Front++;
    }
    Rear++;
    Queue[Rear]=value;
}

char Dequeue(){
    char temp=Queue[Front];
    Front++;
    if(Front>Rear){
        Front=Rear=-1;
    }    
    return temp;
}

struct Graph CreateGraph(struct Graph graph) {
    printf("Enter the number of Vertices :");
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
    printf("Enter the number of Edges to enter :");
    getchar();
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        char source, destination;
        printf("Enter the source :");
        getchar();
        scanf("%c", &source);
        printf("Enter the destination :");
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
    printf("\nGraph:\n");

    struct Vertex* ptr = graph.list;
    while (ptr != NULL) {
        printf("%c -> ", ptr->C);

        struct Node* edge = ptr->Edge;
        while (edge != NULL) {
            if(edge->next!=NULL){
                printf("%c->", edge->C);
            }
            else{
                printf(" %c", edge->C);
            }
            edge = edge->next;
        }

        printf("\n");
        ptr = ptr->next;
    }
}

void BFS(struct Graph graph) {
    printf("The graph's BFS = ");
    struct Vertex* resetVertex = graph.list;
    while (resetVertex != NULL) {
        resetVertex->visited = 0;
        resetVertex = resetVertex->next;
    }

    struct Vertex* V1 = graph.list;

    if (V1->visited == 0) {
        Enqueue(V1->C);
        V1->visited = 1;
    }

    while (!IsEmpty()) {
        char c = Dequeue();
        printf("%c ", c);

        struct Vertex* V2 = graph.list;
        while ((V2 != NULL) && (V2->C != c)) {
            V2 = V2->next;
        }

        if (V2 != NULL) {
            struct Node* N1 = V2->Edge;
            while (N1 != NULL) {
                struct Vertex* V3 = graph.list;
                while ((V3 != NULL) && (V3->C != N1->C)) {
                    V3 = V3->next;
                }
                if ((V3 != NULL) && (V3->visited == 0)) {
                    Enqueue(N1->C);
                    V3->visited = 1;
                }
                N1 = N1->next;
            }
            V2->visited = 2;
        }
    }
}


int main(){
    struct Graph graph;
    graph=CreateGraph(graph);
    printGraph(graph); 
    AddEdges(graph);
    printGraph(graph);
    BFS(graph);
    return 0;
}