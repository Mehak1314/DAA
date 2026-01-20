#include<iostream>
using namespace std;
int quickSelect(int arr[], int l, int r, int k) {
    if (l == r) return arr[l];

    int pivot = arr[(l + r) / 2];
    int i = l, j = r;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }

    if (k <= j) return quickSelect(arr, l, j, k);
    if (k >= i) return quickSelect(arr, i, r, k);
    return arr[k];
}

int median(int sub[], int len) {
    int k = len / 2;
    return quickSelect(sub, 0, len - 1, k);
}
int main(){
    int n;
    cin>>n;
    int a[200];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    while(n>2){
        int medians[500];
        int m=0;

        for(int len=3;len<=n;len++){
            for(int i=0;i+len<=n;i++){
                int sub[200];
                for(int j=0;j<len;j++){
                    sub[j]=a[i+j];
                }
                medians[m]=median(sub,len);
            }
        }
        int mn = medians[0];
        for (int i = 1; i < m; i++)
            if (medians[i] < mn) mn = medians[i];

        // remove first occurrence
        for (int i = 0; i < n; i++) {
            if (a[i] == mn) {
                for (int j = i; j < n - 1; j++)
                    a[j] = a[j + 1];
                break;
            }
        }
        n--;
    }
    cout << a[0] + a[1];
    return 0;
}
//o(n4)->dc
//o(n4logn)->normal sorting
