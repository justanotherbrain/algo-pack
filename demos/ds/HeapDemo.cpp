#include <iostream>
#include "Heap.h"
using namespace std;


int main() {
  int A[] = {4, 6, 1, 3, 10, 2, 4, 9, 1, 8};
  int N = 10;

  MinHeap<int> mh;

  mh.BuildMinHeap(A, N);
  
  for (int i(0); i < N; i++){
    cout << mh.ExtractMin() << endl;
  }

}
