#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

# define MAX_SIZE 100

char Stack[MAX_SIZE];
int Top=-1;

struct Node{
    char c;
    struct Node* next;
};

struct Graph{
    int V;
    struct Node* list;
};

bool IsEmpty(){
    if(Top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void Push(char Value){
    Top++;
    Stack[Top];
}

char Pop(){
    return Stack[Top--];
}

void PreDFS(struct Graph graph, int v, int visited[]) {
    visited[v] = 1;
    printf("%c ", graph.list[v].c);

    struct Node* temp = &(graph.list[v]);
    while (temp != NULL) {
        int index = temp->c - 'A';
        if (!visited[index]) {
            PreDFS(graph, index, visited);
        }
        temp = temp->next;
    }
    for(int i=0;i<graph.V;i++){
        if(visited[i]==0){
            PreDFS(graph,i,visited);
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

    int visited[graph.V];
    for(int i=0;i<graph.V;i++){
        visited[i]=0;
    }
    printf("PreDFS traversal of the graph =");
    PreDFS(graph,0,visited);

    printf("\nPostDFS traversal of the graph =");
    PostDFS(graph,0,visited);
    FreeGraph(graph);

    return 0;
}