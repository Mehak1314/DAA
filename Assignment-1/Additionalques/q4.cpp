#include<iostream>
using namespace std;
int main(){
    int n=5;
    int a[]={4,1,3,5,2};
    int k=2;
    long long special=0;
    for(int l=0;l<n;l++){
        bool isspecial=false;
        for(int i=0;i<n;i++){
            int countgreater=0;
            for(int j=i;j<n;j++){
                if(a[j]>a[l]){
                    countgreater++;
                }
                if(countgreater==k){
                    isspecial=true;
                    break;
                }
            }
            if(isspecial){
            break;
            }
        }
        if(isspecial){
            special+=a[l];
        }
    }
    cout<<special<<endl;
}
