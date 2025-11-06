
#include <iostream>
using namespace std;

class MaxHeap{
    int * arr;
    int size;
    int totalSize;
public:
   MaxHeap(int n){
       arr = new int[n];
       size = 0;
       totalSize = n;
   }
   ///insertion
   void insert(int val){
       if(size == totalSize){
           cout<<"Heap overflow";
           return;
       }
       arr[size] = val;
       int index = size;
       size++;
       while(index> 0 && arr[(index-1)/2] < arr[index]){
           swap(arr[index],arr[(index-1)/2]);
           index = (index-1)/2;
       }
   }
   void Heapify(int index){
       int largest = index;
       int left = 2*index+1;
       int right = 2*index+2;
       if(left < size && arr[left]> arr[largest]){
          largest = left; 
       }
       if(right < size && arr[right] > arr[largest]){
           largest = right;
       }
       if(largest != index){
           swap(arr[index],arr[largest]);
           Heapify(largest);
       }
   }
   /////deletion
   void Delete(){
       if(size == 0){
           cout<<"Heap underflow";
           return;
       }
       cout<<arr[0]<<"deleted form the heap \n";
       arr[0] = arr[size-1];
       size--;
       if(size == 0){
           return ;
       }
       Heapify(0);
       
   }
   void print(){
       for(int i = 0; i< size;i++){
           cout<<arr[i]<<" ";
       }
       cout<<"\n";
   }
};
int main() {
   MaxHeap H1(6);
   H1.insert(66);
   H1.insert(30);
   H1.insert(40);
   H1.insert(55);
   H1.print();
   H1.Delete();
   H1.print();
   

    return 0;
}


///raoalimurad2006
// raoalimurad@2006
//Rao.ali09589
// Raoalimurad@2