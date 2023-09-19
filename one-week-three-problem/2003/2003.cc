#include <iostream>
#include <vector>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int TC, N, M;
vector<int> arr;
int solve() {
    int s, e;
    s = e= 0;
    int  ret = 0;
    int sum = 0;
    while(s < N) {
        if(e < N && sum < M) {
            sum += arr[e++];
        } else {
            sum -= arr[s++];
        }

        if(sum == M)
            ++ret;
    }
    return ret;
}

int main() {

    FAST_IO;

    cin >> N >> M;
    arr.resize(N);
    for(int i=0;i<N;++i) {
        cin >> arr[i];
    }

    cout << solve();
}
