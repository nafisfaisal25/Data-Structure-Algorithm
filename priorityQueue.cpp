#include<iostream>

using namespace std;

#define endl '\n'

int arraySize=10;

int left(int i){
    return i*2;
}

int right(int i){
    return i*2+1;
}

int parent(int i){
    return i/2;
}

void minHeapify(int *heap,int heapSize,int i){
    int l,r,t,smallest;
    l=left(i);
    r=right(i);

    smallest=i;
    if(l<=heapSize && heap[l]<heap[i])
        smallest=l;
    if(r<=heapSize && heap[r] <heap[smallest])
        smallest=r;

    if(smallest!=i){
        t=heap[i];
        heap[i]=heap[smallest];
        heap[smallest]=t;

        minHeapify(heap,heapSize,smallest);
    }

}

int pop(int *heap,int &heapSize){
    int minValue=heap[1];
    heap[1]=heap[heapSize];
    heapSize-=1;
    minHeapify(heap,heapSize,1);

    return minValue;
}

void extendArraySize(int *heap){
    arraySize*=2;
    int tHeap[arraySize];
    for(int i=0;i<arraySize;i++){
        tHeap[i]=heap[i];
    }
    heap=tHeap;
}

void push(int *heap,int &heapSize,int value){
    /*if(heapSize==arraySize-1)
        extendArraySize(heap);*/
    heapSize+=1;
    heap[heapSize]=value;
    int position=heapSize;
    int p=parent(position);
    while(position>1 && heap[p]>heap[position]){
        int t=heap[p];
        heap[p]=heap[position];
        heap[position]=t;
        position=p;
        p=parent(position);
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    int heap[arraySize];
    int heapSize=0;
    push(heap,heapSize,5);
    push(heap,heapSize,20);
    push(heap,heapSize,15);
    push(heap,heapSize,7);
    push(heap,heapSize,22);
    push(heap,heapSize,40);
    push(heap,heapSize,50);
    push(heap,heapSize,33);
    push(heap,heapSize,2);
    push(heap,heapSize,12);
    push(heap,heapSize,8);
    push(heap,heapSize,29);
    push(heap,heapSize,52);
    for(int i=1;i<=heapSize;i++){
        cout << heap[i] << " ";
    }
    cout << endl;
    cout << pop(heap,heapSize) << endl;
    cout << pop(heap,heapSize) << endl;
    cout << pop(heap,heapSize) << endl;
    cout << pop(heap,heapSize) << endl;

    for(int i=1;i<=heapSize;i++){
        cout << heap[i] << " ";
    }
    cout << endl;


}
