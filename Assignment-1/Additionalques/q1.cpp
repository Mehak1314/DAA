#include <iostream>
using namespace std;

int main() {
    int N = 4, M = 2;
    int A[100] = {1, 2, 3, 4};

    int lo = 0, hi = 0;
    for (int i = 0; i < N; i++) hi |= A[i];   
    int ans = hi;

    while (lo <= hi) {
        int X = (lo + hi) / 2;  
        int seg = 1, curr = 0;  

        bool ok = true;

        for (int i = 0; i < N; i++) {
            if (A[i] > X) { ok = false; break; }
            if ((curr | A[i]) <= X) curr |= A[i];
            else seg++, curr = A[i];
        }

        if (ok && seg <= M) ans = X, hi = X - 1; 
        else lo = X + 1;
    }

    cout << ans;
}
