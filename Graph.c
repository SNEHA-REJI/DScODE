#include <stdio.h>
#include <stdlib.h>
struct node 
{
  int vertex;
  struct node *next;
};
struct node *p;
struct Graph 
{
  int numVertices;
  struct node **adjLists;
};
struct node *createNode(int v);
struct Graph *createAGraph(int vertices);
void addEdge(struct Graph *graph,int s,int d);
void DFS(struct Graph *graph,int v,int visited[]);
void BFS(struct Graph *graph,int start);
void displayAdjacencyMatrix(struct Graph *graph);
void displayAdjacencyList(struct Graph *graph);
void main()
{
    int choice,vertices,start,end;
    printf("Enter the number of vertices in the directed graph: ");
    scanf("%d", &vertices);
    struct Graph *graph=createAGraph(vertices);
    do {
        printf("\nMenu:\n");
        printf("1.Add Edge\t2.DFS\t3.BFS\t4.Display Adjacency List\t5.Display Adjacency Matrix\t6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the start and end vertices of the edge: ");
                scanf("%d %d",&start,&end);
                addEdge(graph,start,end);
                break;
            }
            case 2:
            {
                printf("Enter the starting vertex for DFS: ");
                scanf("%d",&start);
                int visited[50]={0};
                printf("DFS Traversal: ");
                DFS(graph,start,visited);
                printf("\n");
                break;
            }
            case 3:
            {
                printf("Enter the starting vertex for BFS: ");
                scanf("%d",&start);
                printf("BFS Traversal: ");
                BFS(graph,start);
                printf("\n");
                break;
            }
            case 4:
            {
                printf("Adjacency List:\n");
                displayAdjacencyList(graph);
                break;
            }
            case 5:
            {
                printf("Adjacency Matrix:\n");
                displayAdjacencyMatrix(graph);
                break;
            }
            case 6:
            {
                printf("Exiting the program...\n");
                break;
            }
            default:
            {
                printf("INVALID CHOICE\n");
            }
        }
    }
    while (choice != 6);
}
struct node *createNode(int v)
{
  struct node* newNode=(struct node*)malloc(sizeof(struct node));
  newNode->vertex=v;
  newNode->next=NULL;
  return newNode;
}
struct Graph *createAGraph(int vertices)
{
  int i;
  struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));
  graph->numVertices=vertices;
  graph->adjLists=(struct node**)malloc(vertices*sizeof(struct node*));
  for(i=0;i<vertices;i++)
  {
    graph->adjLists[i]=NULL;
  }
  return graph;
}
void addEdge(struct Graph *graph,int s,int d)
{
  struct node* newNode=createNode(d);
  newNode->next=graph->adjLists[s];
  graph->adjLists[s]=newNode;
  newNode=createNode(s);
  newNode->next=graph->adjLists[d];
  graph->adjLists[d]=newNode;
}
void DFS(struct Graph *graph,int v,int visited[]) 
{
    printf("%d ",v);
    visited[v]=1;
    struct node *currentNode=graph->adjLists[v];
    while(currentNode!=NULL) 
    {
        int adjacentVertex=currentNode->vertex;
        if (!visited[adjacentVertex]) 
        {
            DFS(graph,adjacentVertex,visited);
        }
        currentNode=currentNode->next;
    }
}
void BFS(struct Graph *graph,int start) 
{
    int queue[50];
    int visited[50]={0};
    int front=-1,rear=-1;
    visited[start]=1;
    queue[++rear]=start;
    while(front!=rear) 
    {
        int currentVertex=queue[++front];
        printf("%d ",currentVertex);

        struct node *currentNode=graph->adjLists[currentVertex];
        while(currentNode!=NULL) 
        {
            int adjacentVertex=currentNode->vertex;
            if(!visited[adjacentVertex]) 
            {
                visited[adjacentVertex]=1;
                queue[++rear]=adjacentVertex;
            }
            currentNode=currentNode->next;
        }
    }
}
void displayAdjacencyList(struct Graph *graph) 
{
    int i;
    for(i=0;i<graph->numVertices;i++) 
    {
        struct node *currentNode=graph->adjLists[i];
        printf("%d -> ",i);
        while(currentNode!=NULL) 
        {
            printf("%d ",currentNode->vertex);
            currentNode=currentNode->next;
        }
        printf("\n");
    }
}
void displayAdjacencyMatrix(struct Graph *graph) 
{
    int i,j;
    int adjacencyMatrix[50][50];
    printf("   ");
    for (j=0;j<graph->numVertices;j++) 
    {
        printf("%d ",j);
    }
    printf("\n   ");
    for (j=0;j<graph->numVertices;j++) 
    {
        printf("- ");
    }
    printf("\n");
    for(i=0;i<graph->numVertices;i++) 
    {
        struct node *currentNode=graph->adjLists[i];
        while(currentNode!=NULL) 
        {
            adjacencyMatrix[i][currentNode->vertex]=1;
            currentNode=currentNode->next;
        }
    }
    for(i=0;i<graph->numVertices;i++) 
    {
        printf("%d| ",i);
        for(j=0;j<graph->numVertices;j++) 
        {
            printf("%d ",adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

