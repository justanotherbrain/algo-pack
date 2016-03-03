#include "Graph.h"
#include <iostream>
using namespace std;

int main(){
  int N = 4;
  int k;
  AdjList G(N);
  G.AppendNode( 0, 1 );
  G.AppendNode( 0, 2 );
  G.AppendNode( 1, 3 );
  G.AppendNode( 2, 3 );

  Node* n;

  for (int i(0); i < N; i++){
    cout << "Node " << i << ":  ";
    for (int j(0); j < G.GetNode(i).GetNumAdjacent(); j++){
      k = G.GetNode(i).GetAdjPointer()[j].GetKey();
      cout << k << " "; 
    }
    cout << endl;
  }

}
