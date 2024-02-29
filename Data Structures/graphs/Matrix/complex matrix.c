#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Graph{
    int V;
    char* Content;
    int** Matrix;
};

struct Graph createGraph(int V){
    struct Graph graph;
    graph.V=V;
    graph.Content=(char *)malloc(graph.V*sizeof(char));
    for(int i=0;i<graph.V;i++){
        printf("Enter Vertex %d :",i+1);
        getchar();
        scanf("%c",&graph.Content[i]);
    }
    graph.Matrix=(int **)malloc(V*sizeof(int *));
    for(int i=0;i<V;i++){
        graph.Matrix[i]=(int*)malloc(graph.V*sizeof(int));
        for(int j=0;j<V;j++){
            graph.Matrix[i][j]=0;
        }
    }
    return graph;
}

struct Graph AddVertices(struct Graph graph, int L) {
    graph.Content = (char *)realloc(graph.Content, (graph.V + L) * sizeof(char));
    for (int i = graph.V; i < (graph.V + L); i++) {
        printf("Enter Vertex %d :", i + 1);
        getchar();
        scanf("%c", &graph.Content[i]);
    }
    graph.Matrix = (int **)realloc(graph.Matrix, (graph.V + L) * sizeof(int *));
    for (int i = graph.V; i < (graph.V + L); i++) {
        graph.Matrix[i] = (int *)malloc((graph.V + L) * sizeof(int));
        for (int j = 0; j < (graph.V + L); j++) {
            graph.Matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < graph.V; i++) {
        graph.Matrix[i] = (int *)realloc(graph.Matrix[i], (graph.V + L) * sizeof(int));  
        for (int j = graph.V; j < (graph.V + L); j++) {
            graph.Matrix[i][j] = 0;
        }
    }

    graph.V = graph.V + L;
    return graph;
}

struct Graph RemoveVertices(struct Graph graph,char c){
    int j;
    for(int i=0;i<graph.V;i++){
        if(graph.Content[i]==c){
            j=i;
        }
    } 
    for(int i=j;i<graph.V-1;i++){
        graph.Content[i]=graph.Content[i+1];
    }
    for(int i=j;i<(graph.V-1);i++){
        for(int k=0;k<graph.V;k++){
            graph.Matrix[i][k]=graph.Matrix[i][k+1];
        }
        free(graph.Matrix[graph.V]);
    }
    for(int i=0;i<(graph.V-1);i++){
        for(int k=j;k<(graph.V-1);k++){
            graph.Matrix[i][k]=graph.Matrix[i+1][k];
        }
    }
    
    graph.V=graph.V-1;
    return graph;
}

void addEdges(struct Graph graph,char source,char destination){
    int sourceIndex,destinationIndex;
    for(int i=0;i<graph.V;i++){
        if(graph.Content[i]==source){
            sourceIndex=i;
            for(int j=0;j<graph.V;j++){
                if(graph.Content[j]==destination){
                    destinationIndex=j;
                        graph.Matrix[sourceIndex][destinationIndex]=1;
                        graph.Matrix[destinationIndex][sourceIndex]=1;
                }
            }
        }
    }
}

void RemoveEdges(struct Graph graph,char source,char destination){
    int sourceIndex,destinationIndex;
    for(int i=0;i<graph.V;i++){
        if(graph.Content[i]==source){
            sourceIndex=i;
            for(int j=0;j<graph.V;j++){
                if(graph.Content[j]==destination){
                    destinationIndex=j;
                        graph.Matrix[sourceIndex][destinationIndex]=0;
                        graph.Matrix[destinationIndex][sourceIndex]=0;
                }
            }
        }
    }
}

void printGraph(struct Graph graph){
    printf("\t\tGraph\n");
    for(int i=0;i<graph.V;i++){
        printf("\t%c",graph.Content[i]);
    }
    printf("\n");
    for(int i=0;i<graph.V;i++){
        printf("%c\t",graph.Content[i]);
        for(int j=0;j<graph.V;j++){
            printf("%d\t",graph.Matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V,E;
    printf("Enter the number of vertices :");
    scanf("%d",&V);
    struct Graph graph=createGraph(V);

    printGraph(graph);

    printf("Enter the number of Edges to add :");
    scanf("%d",&E);
    for(int i=0;i<E;i++){
        char source,destination;
        printf("Enter the source :");
        getchar();
        scanf("%c",&source);
        printf("Enter the destination :");
        getchar();
        scanf("%c",&destination);    
        addEdges(graph,source,destination);    
    }

    printGraph(graph);

    int l;
    printf("Enter the number of Edges to remove :");
    scanf("%d",&l);
    for(int i=0;i<l;i++){
        char source,destination;
        printf("Enter the source :");
        getchar();
        scanf("%c",&source);
        printf("Enter the destination :");
        getchar();
        scanf("%c",&destination);
        RemoveEdges(graph,source,destination);
    }

    printGraph(graph);

    printf("Enter the number of Vertices to add :");
    scanf("%d",&l);
    graph=AddVertices(graph,l);

    printf("Enter the number of Edges to add :");
    scanf("%d",&E);
    for(int i=0;i<E;i++){
        char source,destination;
        printf("Enter the source :");
        getchar();
        scanf("%c",&source);
        printf("Enter the destination :");
        getchar();
        scanf("%c",&destination);    
        addEdges(graph,source,destination);    
    }

    printGraph(graph);

    int n;
    char e;
    printf("Enter the number of vertices to remove :");
    getchar();
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the Vertices to remove :");
        getchar();
        scanf("%c",&e);
        graph=RemoveVertices(graph,e);
    }
    printGraph(graph);

    free(graph.Content);
    for(int i=0;i<graph.V;i++){
        free(graph.Matrix[i]);
    }
    return 0;
}
