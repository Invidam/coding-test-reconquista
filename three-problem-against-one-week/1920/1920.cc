#include <iostream>
#include <unordered_set>
using namespace std;

//Problem site: https://www.acmicpc.net/problem/1920
int N, M;
const int SIZE = 1e5 + 1;
int A[SIZE], B[SIZE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_set<int> s;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        s.insert(n);

    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int k;
        cin >> k;

        cout << ((s.find(k) == s.end()) ? "0" : "1") << '\n';
    }




    return 0;
}
