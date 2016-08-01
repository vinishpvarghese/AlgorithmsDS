



typedef struct graphNode{

      int src;
      int dest;
      int weight;
      struct graphNode * next;
}graphNode;


typedef struct graphArrayList{

	graphNode * head;

}gArrayList;

typedef struct graph{

      int num ;
      gArrayList * myArrayList;

}graph;


graph * createGraph(int num);
void addVertices(graph * gr ,int src,int dest,int dir,int weight);
void printGraph(graph * gr);


