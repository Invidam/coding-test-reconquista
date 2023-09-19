#include <iostream>
#include <vector>
#include <cstring>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
const int MAX = 2e3;

int N, M;
vector<int> arr;

int cache[MAX + 1][MAX + 1];

int solve(int s, int e) {
    if (e - s <= 1) return (arr[s] == arr[e]);

    int &ret = cache[s][e];
    if (ret != -1) return ret;

    return ret = (solve(s + 1, e - 1) && (arr[s] == arr[e]));
}

int main() {

    FAST_IO;

    cin >> N;
    arr.resize(N);
    memset(cache, -1, sizeof(cache));

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int s, e;

        cin >> s >> e;
        cout << solve(s - 1, e - 1) << '\n';
    }


}
