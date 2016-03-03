#ifndef GRAPH_H
#define GRAPH_H


//-------------------------------------------------
// Node
//-------------------------------------------------
class Node {
  private:
    int num_adjacent;
    int array_size;
    int key;
    Node *adj;

  public:
    bool explored;
    int distance;
    
    Node();
    
    void Append( Node );
    int GetNumAdjacent() { return num_adjacent; }
    Node* GetAdjPointer() { return adj; }
    int GetKey() {return key;}
    void SetKey( int );
};

Node::Node(){
  explored = false;
  num_adjacent = 0;
  array_size = 0;
  distance = 0;
}

void Node::Append( Node N ){
  num_adjacent++;
  if (num_adjacent > array_size){
    if (array_size == 0) array_size++;
    array_size *= 2;
    Node *tmp;
    tmp = new Node[array_size];
    for (int i(0); i < (num_adjacent-1); i++){
      tmp[i] = adj[i];
    }
    adj = tmp;
  }
  adj[num_adjacent-1] = N;
}

void Node::SetKey( int k ){
  key = k;
}


//-------------------------------------------------
// AdjList
//-------------------------------------------------

class AdjList {
  private:
    Node *G;
    int num_nodes;
    int array_size;

  public:
    AdjList();
    AdjList( int );
    void Append( Node );
    void AppendNode( int, int );
    Node GetNode( int );
    Node* GetNodePointer( int );
    int GetNumNodes() {return num_nodes;}
};

AdjList::AdjList(){
  num_nodes = 0;
  array_size = 0;
}

AdjList::AdjList( int nn ){
  num_nodes = nn;
  array_size = num_nodes;
  G = new Node[num_nodes];
  for (int i(0); i < nn; i++){
    G[i].SetKey(i);
  }
}

void AdjList::AppendNode( int v, int w ){
  G[v].Append( G[w] );
}

void AdjList::Append( Node N ){
  num_nodes++;
  if (num_nodes > array_size){
    if (array_size == 0) array_size++;
    array_size *= 2;

    Node *tmp;
    tmp = new Node[array_size];

    for (int i(0); i < (num_nodes-1); i++){
      tmp[i] = G[i];
    }
    G = tmp;
  }
  G[num_nodes-1] = N;
}

Node AdjList::GetNode( int n ){
  return G[n];
}

Node* AdjList::GetNodePointer( int n ){
  return &G[n];
}

#endif
