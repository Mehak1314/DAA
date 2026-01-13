#include<iostream>
using namespace std;
int binarySearch(int arr[], int low, int high, int key) {
    int left=low;
    int right=high;

    while(left<=right) {
        int mid=(right+left)/2;
        if(arr[mid]==key){
            return mid; 
        }
        else if(arr[mid]<key){
            return binarySearch(arr, mid+1, high, key); 
        }
        else{
            return binarySearch(arr,low,mid-1,key);
        }
    }
    return -1;
}
int main() {
    int arr[]={2,5,8,16,23,38,56,72,91};
    int size=sizeof(arr)/sizeof(arr[0]);
    int result=binarySearch(arr,0,size-1,23);
    cout<<"Element found at index: "<<result<<endl;
    return 0;
}
