#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Problem site: https://www.acmicpc.net/problem/1026
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    int ret = 0 ;

    for (int i = 0; i < N; ++i) {
        ret += A[i] * B [i];
    }

    cout << ret;

    return 0;
}
