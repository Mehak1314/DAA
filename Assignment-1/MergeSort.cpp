#include<iostream>
using namespace std;
void merge(int arr[],int left,int right,int mid){
    int n1=mid-left+1;
    int n2=right-mid;
    
    int arr1[n1],arr2[n2];
    for(int i=0;i<n1;i++){
        arr1[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++){
        arr2[j]=arr[mid+1+j];
    }
    int k=left;
    int i=0,j=0;
    while(i<n1&&j<n2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
            k++;
        }
        else{
            arr[k]=arr2[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k]=arr1[i];
        i++;
        k++;    
    }
    while(j<n2){
        arr[k]=arr2[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,right,mid);
    }
}
int main() {
    int arr[]={38,27,43,3,9,82,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,size-1);
    cout<<"Sorted array: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
