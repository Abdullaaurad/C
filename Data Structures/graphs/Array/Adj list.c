#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    char c;
    struct Node* next;
};

struct Graph{
    int V;
    struct Node* list;
};

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

void FindEdge(struct Graph graph){
    int j;
    char source,destination;
    int sourceFound=0;
    printf("Enter the source :");
    getchar();
    scanf("%c",&source);
    printf("Enter the destination :");
    getchar();
    scanf("%c",&destination);
    for(int i=0;i<graph.V;i++){
        if(graph.list[i].c==source){
            j=i;
            sourceFound=1;
        }
    }
    if(sourceFound==0){
        printf("The source vertex is not found\n");
    }
    else{
        struct Node* ptr=&(graph.list[j]);
        while((ptr->next!=NULL)&&(ptr->c!=destination)){
            ptr=ptr->next;
        }
        if(ptr->c!=destination){
            printf("The destination vertex is not found\n");
        }
        else{
            printf("The edge is found\n");
            printf("%c -> %c \n",source,destination);
        }
    }
}

void RemoveEdges(struct Graph graph,char source,char destination){
    for(int i=0;i<graph.V;i++){
        if(graph.list[i].c==source){
            if(graph.list[i].next==NULL){
                printf("destination is no there\n");
            }
            else{
                struct Node* ptr=&(graph.list[i]);
                struct Node* pre=NULL;
                while((ptr!=NULL)&&(ptr->c!=destination)){
                    pre=ptr;
                    ptr=ptr->next;
                }
                pre->next=ptr->next;
                free(ptr);
            }   
        }
    }
    for(int i=0;i<graph.V;i++){
        if(graph.list[i].c==destination){
            if(graph.list[i].next==NULL){
                printf("destination is no there\n");
            }
            else{
                struct Node* ptr=&(graph.list[i]);
                struct Node* pre;
                while((ptr!=NULL)&&(ptr->c!=source)){
                    pre=ptr;
                    ptr=ptr->next;
                }
                pre->next=ptr->next;
                free(ptr);
            }
        }
    }
}

struct Graph AddVertices(struct Graph graph){
    printf("Enter Vertex :");
    getchar();
    char c;
    scanf("%c",&c);
    graph.list=(struct Node*)realloc(graph.list,(graph.V+1)*sizeof(struct Node));
    graph.list[graph.V].c=c;
    graph.list[graph.V].next=NULL;
    graph.V++;
    return graph;
}

struct Graph RemoveVertices(struct Graph graph){
    int j; char c;
    printf("Enter Vertex :");
    getchar();
    scanf("%c",&c);
    for(int i=0;i<graph.V;i++){
        if(graph.list[i].c==c){
            j=i;
        }
    }
    for(int i=j;i<(graph.V-1);i++){
        *(graph.list+i)=*(graph.list+i+1);
    }
    graph.list=(struct Node*)realloc(graph.list,(graph.V-1)*sizeof(struct Node));
    graph.V--;
    for(int i=0;i<graph.V;i++){
        if(graph.list[i].next!=NULL){
            struct Node* ptr=&(graph.list[i]);
            struct Node* pre;
            while((ptr!=NULL)&&(ptr->c!=c)){
                pre=ptr;
                ptr=ptr->next;
            }
            pre->next=ptr->next;
            free(ptr);
            }
    }
    return graph;
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
/*
    printf("Enter the number of edges to remove:");
    scanf("%d",&E); 
    for(int i=0;i<E;i++){
        char source,destination;
        printf("Enter the source :");
        getchar();
        scanf("%c",&source);
        printf("Enter the destination :");
        getchar();
        scanf("%c",&destination);
        RemoveEdges(graph,source,destination);
    }

    printf("Enter the number of Vertices to add:");
    int A;
    scanf("%d",&A); 
    for(int i=0;i<A;i++){
        graph=AddVertices(graph);
    }

    PrintGraph(graph);

    printf("Enter the number of Vertices to remove:");
    int B;
    scanf("%d",&B); 
    for(int i=0;i<B;i++){
        graph=RemoveVertices(graph);
    }

    PrintGraph(graph);

    for(int I=0;I<3;I++){
        FindEdge(graph);
    }
*/
    FreeGraph(graph);

    return 0;
}