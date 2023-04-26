#include <iostream>
#include <vector>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int TC, M, N;
vector<int> arr;

bool canSum(int targetSum, int startIdx) {
    if(targetSum <= 0) return targetSum == 0;
    if(startIdx >= N) return targetSum == 0;
    if(targetSum == arr[startIdx]) return true;

    for (int nextIdx = startIdx; nextIdx < N; ++nextIdx) {
        if(canSum(targetSum - arr[startIdx], nextIdx))
            return true;
    }

    return false;
}

bool canSum(int targetSum) {
    for(int i=0;i<N;++i) {
        if(canSum(targetSum, i))
            return true;
    }

    return false;
}

int main() {

    FAST_IO;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        cin >> M >> N;

        arr = vector<int>(N);
        for (int j = 0; j < N; ++j) {
            cin >> arr[j];
        }

        cout << (canSum(M) ? "true" : "false") << '\n';
    }
}
