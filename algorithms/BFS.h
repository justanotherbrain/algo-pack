#ifndef BFS_H
#define BFS_H

#include "Graph.h"
#include "Queue.h"

void BFS( AdjList G, Node *s ){
  Node *v;
  Node *w;
  Queue<Node*> Q;

  s->explored = true;
  s->distance = 0;

  Q.Enqueue(s);
  while (Q.GetSize() != 0){
    v = Q.Dequeue();
    for (int i(0); i < v->GetNumAdjacent(); i++){
      w = G.GetNodePointer( v->GetAdjPointer()[i].GetKey() );
      if (w->explored == false){
        w->distance = v->distance + 1;
        w->explored = true;
        Q.Enqueue(w);
      }
    }
  }
}



#endif
