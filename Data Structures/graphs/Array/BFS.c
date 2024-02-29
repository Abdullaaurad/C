#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

# define MAX_SIZE 100

char Queue[MAX_SIZE];
int Rear=0,Front=0;

struct Node{
    char c;
    struct Node* next;
};

struct Graph{
    int V;
    struct Node* list;
};

bool IsEmpty(){
    if(Front==Rear){
        return 1;
    }
    else{
        return 0;
    }
}

void Enqueue(char value) {
    if (Rear == MAX_SIZE - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    Queue[Rear++] = value;
}

char Dequeue(){
    return Queue[Front++];
}

void BFS(struct Graph graph,int Size){
    printf("BFS Traversal =");
    int Visited[Size];
    for(int i=0;i<Size;i++){
        Visited[i]=0;
    }
    for (int start = 0; start < Size; start++) {
        if (!Visited[start]) {
            Enqueue(graph.list[start].c);
            Visited[start] = 1;

            while (!IsEmpty()) {
                char k = Dequeue();
                printf(" %c", k);
                int i;
                for (i = 0; i < Size; i++) {
                    if (graph.list[i].c == k) {
                        break;
                    }
                }
                struct Node* ptr = &graph.list[i];
                while (ptr != NULL) {
                    if (!Visited[ptr->c - 'A']) {
                        Enqueue(ptr->c);
                        Visited[ptr->c - 'A'] = 1;
                    }
                    ptr = ptr->next;
                }
            }
        }
    }
}

struct Graph CreateGraph(int V){
    struct Graph graph;
    graph.V=V;
    graph.list=(struct Node*)malloc(graph.V*sizeof(struct Node));
    for(int i=0;i<V;i++){
        printf("Enter Vertex %d :",i+1);
        getchar();
        scanf("%c",&(graph.list[i].c));
        graph.list[i].next=NULL;
    }
    return graph;  
}

void AddEdges(struct Graph graph,char source,char destination){
    for(int i=0;i<graph.V;i++){
        if((graph.list[i]).c==source){
            for(int j=0;j<graph.V;j++){
                if((graph.list[j]).c==destination){
                    struct Node* ptr=&(graph.list[i]);
                    while(ptr->next != NULL){
                        ptr=ptr->next;
                    }
                    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
                    NewNode->c=destination;
                    NewNode->next=NULL;
                    ptr->next=NewNode;
                }
            }
        } 
    }
    for(int i=0;i<graph.V;i++){
        if((graph.list[i]).c==destination){
            for(int j=0;j<graph.V;j++){
                if((graph.list[j]).c==source){
                    struct Node* ptr=&(graph.list[i]);
                    while(ptr->next != NULL){
                        ptr=ptr->next;
                    }
                    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
                    NewNode->c=source;
                    NewNode->next=NULL;
                    ptr->next=NewNode;
                }
            }
        } 
    }
}

void PrintGraph(struct Graph graph){
    printf("\t\tGraph\n");
    for(int i=0;i<graph.V;i++){
        struct Node* ptr=&(graph.list[i]);
        while(ptr->next!=NULL){
            printf("%c -> ",ptr->c);
            ptr=ptr->next;
        }
        printf("%c",ptr->c);
        printf("\n");
    }
}

void FreeGraph(struct Graph graph) {
    for (int i = 0; i < graph.V; i++) {
        struct Node* ptr = &(graph.list[i]);
        struct Node* temp;
        while (ptr != NULL) {
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
    }
    free(graph.list);
}

int main(){
    int V,E;
    printf("Enter the number of Vertices :");
    scanf("%d",&V);
    struct Graph graph;
    graph=CreateGraph(V);

    PrintGraph(graph);

    printf("Enter the number of edges to add:");
    scanf("%d",&E); 
    for(int i=0;i<E;i++){
        char source,destination;
        printf("Enter the source :");
        getchar();
        scanf("%c",&source);
        printf("Enter the destination :");
        getchar();
        scanf("%c",&destination);
        AddEdges(graph,source,destination);
    }
    PrintGraph(graph);
    BFS(graph,V);
    FreeGraph(graph);

    return 0;
}