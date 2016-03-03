#include <algorithm>
#include <time.h>
#include "Quicksort.h"
#include <iostream>
using namespace std;

int main(){
  int array[] = {3, 6, 1, 7, 2, 0, 9, 1, 2};

  srand(time(NULL));
  random_shuffle(array, array+9);

  int *A = &array[0];

  cout << "input array:" << endl;
  for (int i(0); i < 9; i++){
    cout << A[i] << " ";
  }
  cout << endl;

  quicksort(A, 0, 9);

  cout << "sorted array:" << endl;
  for (int i(0); i < 9; i++){
    cout << A[i] << " ";
  }
  cout << endl;
}

