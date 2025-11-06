
#include <iostream>
using namespace std;
class MinHeap{
    int *arr;
    int size;
    int totalSize;
public:
 MinHeap(int n){
     arr = new int[n];
     size = 0 ;
     totalSize = n;
 }
 ///insertion
 void insert(int val){
     if(size == totalSize){
         cout<<"heap overflow";
         return;
     }
     arr[size] = val;
     int index = size;
     size++;
     while(index > 0 && arr[(index-1)/2] > arr[index]){
         swap(arr[index],arr[(index-1)/2]);
         index = (index-1)/2;
     }
 }
 // heapify
 void Heapify(int index){
     int smallest = index;
     int left = 2*index+1;
     int right = 2*index+2;
     if(left< size && arr[left]< arr[smallest]){
         smallest = left;
     }
       if(right< size && arr[right]< arr[smallest]){
         smallest = right;
     }
     if(index != smallest){
         swap(arr[index],arr[smallest]);
         Heapify(smallest);
     }
 }
 /// delete
 void Delete(){
     if(size == 0){
         cout<<"heap underflow";
         return;
     }
     arr[0] = arr[size-1];
     size--;
     if(size == 0){
         return;
     }
     Heapify(0);
 }
 //print
 void print(){
     for(int i = 0; i< size;i++){
         cout<<arr[i]<<" ";
     }
 }
};
int main() {
   MinHeap H1(5);
   H1.insert(20);
   H1.insert(40);
   H1.insert(30);
   H1.insert(10);
   H1.Delete();
   H1.print();

    return 0;
}