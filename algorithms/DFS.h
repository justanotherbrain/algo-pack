#ifndef DFS_H
#define DFS_H

#include "data-structures/Graph.h"

void DFS( AdjList G, Node *v ){
  Node *w;
 
  v->explored = true;
  
  for (int i(0); i < v->GetNumAdjacent(); i++){
    w = G.GetNodePointer( v->GetAdjPointer()[i].GetKey() );
    if (w->explored == false) DFS( G, w );
  }
}

#endif
