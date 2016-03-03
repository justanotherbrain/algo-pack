#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
struct QNode{
  T x;
  
  QNode* next;
  QNode* prev;
};

template <class T>
class Queue{
  private:
    QNode<T> *head;
    QNode<T> *tail;
    QNode<T> *nil;
    int size;
  public:
    Queue();
    void Enqueue( T );
    T Dequeue();
    int GetSize() {return size;}
};

template <class T>
Queue<T>::Queue(){
  size = 0;
  T null;
  

  head = new QNode<T>;
  head->x = null;
  head->next = tail;
  head->prev = nil;
  
  tail = new QNode<T>;
  tail->x = null;
  tail->next = nil;
  tail->prev = head;
}

template <class T>
void Queue<T>::Enqueue( T input ){
  size++;
  QNode<T> *N;
  N = new QNode<T>;
  N->x = input;
  N->next = tail;
  N->prev = tail->prev;
  tail->prev->next = N;
  tail->prev = N;
}

template <class T>
T Queue<T>::Dequeue(){
  size--;
  if (size < 0){
    T null;
    return null;
  }
  T out = head->next->x;
  head->next = head->next->next;
  head->next->prev = head;
  return out;
}

#endif
