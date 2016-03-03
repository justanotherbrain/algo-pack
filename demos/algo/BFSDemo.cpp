#include "Queue.h"
#include "Graph.h"
#include "BFS.h"
#include <iostream>
using namespace std;

int main(){
  int N = 4;
  int dist;
  AdjList G(N);
  G.AppendNode( 0, 1 );
  G.AppendNode( 0, 2 );
  G.AppendNode( 1, 3 );
  G.AppendNode( 2, 3 );
  
  
  Node *s = G.GetNodePointer(0);
  BFS( G, s );

  for (int i(0); i < N; i++){
    cout << "Node " << i << ":  ";
    dist = G.GetNode(i).distance;
    cout << dist << endl;
  }
}
