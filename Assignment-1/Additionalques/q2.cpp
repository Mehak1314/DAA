#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A[] = {1, 5, 3, 9, 12, 13, 15};
    int N = 7;

    sort(A, A + N);

    int i = 0, ans = 1;

    for (int j = 0; j < N; j++) {
        while (A[j] - A[i] > 10)
            i++;
        ans = max(ans, j - i + 1);
    }

    cout << ans;
}
