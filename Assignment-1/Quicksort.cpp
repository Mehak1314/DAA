#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int low, int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int p=partition(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}
int main(){
    int arr[]={4,2,6,9,2};
    quicksort(arr,0,4);
    cout<<"Sorted array"<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
