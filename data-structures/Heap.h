#ifndef HEAP_H
#define HEAP_H


//------------------------------------------
// MinHeap
//------------------------------------------

template <class T>
class MinHeap{
  private:
    T *H;
    int heap_size;
  public:
    MinHeap();
    MinHeap( T*, int );
    void BuildMinHeap( T*, int );
    void MinHeapify( int );
    T ExtractMin();
};


template <class T>
MinHeap<T>::MinHeap(){
  H = new T[0];
  heap_size = 0;
}


template <class T>
MinHeap<T>::MinHeap( T* A, int N ){
  *H = new T[0];
  heap_size = 0;
  BuildMinHeap( A, N );
}


template <class T>
void MinHeap<T>::MinHeapify( int i ){
  int smallest;
  int left = ( (i+1) << 1 ) - 1; // may be problematic
  int right = ( ((i+1) << 1) + 1 ) - 1;
  
  if (left < heap_size && H[left] < H[i]) smallest = left;
  else smallest = i;

  if (right < heap_size && H[right] < H[smallest]) smallest = right;

  if (smallest != i){
    T tmp = H[i];
    H[i] = H[smallest];
    H[smallest] = tmp;
    MinHeapify( smallest );
  }
}


template <class T>
void MinHeap<T>::BuildMinHeap( T* A, int array_size ){
  heap_size = array_size;
  H = new T[heap_size];
  for (int i(0); i < heap_size; i++){
    H[i] = A[i];
  }

  int n = (heap_size >> 1) - 1;
  for (int i(n); i >= 0; i--){
    MinHeapify(i);
  }
}


template <class T>
T MinHeap<T>::ExtractMin(){
  T min = H[0];
  heap_size--;
  H[0] = H[heap_size];
  MinHeapify(0);
  return min;
}




//-------------------------------------------------
// MaxHeap
//-------------------------------------------------

template <class T>
class MaxHeap{
  private:
    T *H;
    int heap_size;
  public:
    MaxHeap();
    MaxHeap( T*, int );
    void BuildMaxHeap( T*, int );
    void MaxHeapify( int );
    T ExtractMax();
};


template <class T>
MaxHeap<T>::MaxHeap(){
  H = new T[0];
  heap_size = 0;
}


template <class T>
MaxHeap<T>::MaxHeap( T* A, int N ){
  *H = new T[0];
  heap_size = 0;
  BuildMaxHeap( A, N );
}


template <class T>
void MaxHeap<T>::MaxHeapify( int i ){
  int largest = i;
  int left = ( (i+1) << 1 ) - 1; // may be problematic
  int right = ( ((i+1) << 1) + 1 ) - 1;
   
  if (left < heap_size && H[left] > H[i]) largest = left;

  if (right < heap_size && H[right] > H[largest]) largest = right;
  if (largest != i){
    T tmp = H[i];
    H[i] = H[largest];
    H[largest] = tmp;
    MaxHeapify( largest );
  }
}


template <class T>
void MaxHeap<T>::BuildMaxHeap( T* A, int array_size ){
  heap_size = array_size;
  H = new T[heap_size];
  for (int i(0); i < heap_size; i++){
    H[i] = A[i];
  }

  int n = (heap_size >> 1) - 1;
  for (int i(n); i >= 0; i--){
    MaxHeapify(i);
  }
}


template <class T>
T MaxHeap<T>::ExtractMax(){
  T max = H[0];
  heap_size--;
  H[0] = H[heap_size];
  MaxHeapify(0);
  return max;
}


#endif
