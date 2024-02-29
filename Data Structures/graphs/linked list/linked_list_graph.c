#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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



struct Graph RemoveVertices(struct Graph graph) {
    printf("Enter the Vertex to remove =");
    char c;
    getchar();
    scanf("%c", &c);

    struct Vertex* ptr = graph.list;
    struct Vertex* prevPtr = NULL;
    if (ptr != NULL && ptr->C == c) {
        graph.list = graph.list->next;
    } 
    else{
        while (ptr != NULL && ptr->C != c) {
            prevPtr = ptr;
            ptr = ptr->next;
        }
        if (ptr != NULL) {
            prevPtr->next = ptr->next;
        } 
        else {
            printf("Vertex not found.\n");
            return graph;
        }
    }
    struct Node* n;
    struct Node* k = ptr->Edge;
    while (k != NULL) {
        n = k;
        k = k->next;
        free(n);
    }
    free(ptr);
    return graph;
}

struct Graph RemoveEdges(struct Graph graph){
    printf("Enter the source =");
    char source;
    getchar();
    scanf("%c", &source);
    printf("Enter the destination =");
    char destination;
    getchar();
    scanf("%c", &destination);
    struct Vertex* V1=graph.list;
    while((V1!=NULL)&&(V1->C!=source)){
        V1=V1->next;
    }
    if(V1==NULL){
        printf("source not found");
        return graph;
    }
    else{
        struct Node* N1=V1->Edge;
        struct Node* N2=NULL;
        while((N1!=NULL)&&(N1->C!=destination)){
            N2=N1;
            N1=N1->next;
        }
        if(N1==NULL){
            printf("source not found");
            return graph;
        }
        else{
            if (N2 == NULL) {
                V1->Edge = N1->next;
            }
            else{
                N2->next = N1->next;
            }
            free(N1);
        }
    }
    return graph;
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

void findEdge(struct Graph graph){
    printf("Enter the source =");
    char source;
    getchar();
    scanf("%c", &source);
    printf("Enter the destination =");
    char destination;
    getchar();
    scanf("%c", &destination);
    struct Vertex* V1=graph.list;
    while((V1!=NULL)&&(V1->C!=source)){
        V1=V1->next;
    }
    if(V1==NULL){
        printf("source not found");
        return;
    }
    else{
        struct Node* N1=V1->Edge;
        struct Node* N2=NULL;
        while((N1!=NULL)&&(N1->C!=destination)){
            N2=N1;
            N1=N1->next;
        }
        if(N1==NULL){
            printf("source not found");
            return;
        }
        else{
            printf("%c->%c is found on graph",source,destination);
        }
    }
}

int main(){
    struct Graph graph;
    graph=CreateGraph(graph);
    printGraph(graph);
    AddEdges(graph);
    printGraph(graph);
    //graph=RemoveEdges(graph);
    //printGraph(graph);
    //graph=RemoveVertices(graph);
    //printGraph(graph);
    findEdge(graph);
    return 0;
}