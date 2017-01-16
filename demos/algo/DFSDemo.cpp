#include "algorithms/DFS.h"
#include "data-structures/Graph.h"
#include <iostream>
using namespace std;

int main(){
  int N = 4;
  AdjList G(N);
  G.AppendNode( 0, 1 );
  G.AppendNode( 0, 2 );
  G.AppendNode( 1, 3 );
  G.AppendNode( 2, 3 );

  Node *s = G.GetNodePointer( 0 );
  DFS( G, s );
}

