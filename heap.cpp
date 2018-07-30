#include<iostream>

using namespace std;

#define endl '\n'

int left(int i){
    return i*2;
}

int right(int i){
    return i*2+1;
}

int parent(int i){
    return i/2;
}

void maxHeapify(int *heap,int heapSize,int i){
    int l=left(i);
    int r=right(i);

    int largest=i;


    if(l<=heapSize && heap[l]>heap[i])
        largest=l;

    if(r<=heapSize && heap[r]>heap[largest])
        largest=r;
    int t;
    if(largest!=i){
        t=heap[i];
        heap[i]=heap[largest];
        heap[largest]=t;

        maxHeapify(heap,heapSize,largest);
    }

}

void bulidMaxHeap(int *heap,int heapSize){

    for(int i=heapSize/2;i>=1;i--)
        maxHeapify(heap,heapSize,i);
}

void heapSort(int *heap,int heapSize){
    bulidMaxHeap(heap,heapSize);

    int t;
    for(int i=heapSize;i>=1;i--){
        t=heap[1];
        heap[1]=heap[i];
        heap[i]=t;

        heapSize-=1;
        maxHeapify(heap,heapSize,1);
    }
}

int main(){
    int heap[10]={0,1,2,5,3,9,4,7,8,6};
    int heapSize=9;
    heapSort(heap,heapSize);
    for(int i=1;i<=heapSize;i++){
        cout << heap[i] << " ";
    }
    cout << endl;

}




