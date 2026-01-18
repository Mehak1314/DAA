#include<iostream>
#include<climits>
using namespace std;
int maxCrossingSum(int arr[], int l, int m, int r){
    int sum=0;
    int ls=INT_MIN;
    for(int i=m;i>=l;i--){
        sum+=arr[i];
        ls=max(ls,sum);
    }
    sum=0;
    int rs=INT_MIN;
    for(int i=m+1;i<=r;i++){
        sum+=arr[i];
        rs=max(rs,sum);
    }
    return ls+rs;
}
int maxSubArraySum(int arr[],int l,int r){
     if (l == r)
        return arr[l];

    int m = (l + r) / 2;

    return max(
        maxSubArraySum(arr, l, m),max(
        maxSubArraySum(arr, m + 1, r),
        maxCrossingSum(arr, l, m, r)
    ));
}
int main(){
    int arr[]={-2, -5, 6, -2, -3, 1, 5, -6};
    int n=8;
    cout << "Maximum subarray sum = "
         << maxSubArraySum(arr, 0, n - 1);
}
