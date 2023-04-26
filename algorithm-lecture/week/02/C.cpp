#include <iostream>
#include <vector>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

const int INVALID = -1;
const vector<int> INVALID_VECTOR = vector<int>(1, INVALID);
const vector<int> EMPTY_VECTOR = vector<int>();

const string INVALID_TEXT = "-1";

vector<int> arr;
int TC, M, N;

vector<int> howSum(int targetSum, int idx) {
    if (targetSum < 0) return INVALID_VECTOR;
    if (idx >= N) return targetSum == 0 ? EMPTY_VECTOR : INVALID_VECTOR;
    if (targetSum == arr[idx]) return vector<int>(1, arr[idx]);

    for (int nextIdx = idx; nextIdx < N; ++nextIdx) {

        vector<int> ret = howSum(targetSum - arr[idx], nextIdx);

        if (ret == INVALID_VECTOR)
            continue;

        ret.emplace_back(arr[idx]);
        return ret;
    }

    return INVALID_VECTOR;
}

vector<int> howSum(int targetSum) {
    if(targetSum == 0) return EMPTY_VECTOR;

    for (int i = 0; i < N; ++i) {
        vector<int> ret = howSum(targetSum, i);

        if(ret != INVALID_VECTOR)
            return ret;
    }

    return INVALID_VECTOR;
}

void print(const vector<int> &ret) {
    for (const auto &item: ret) {
        cout << item << ' ';
    }
    cout  << '\n';
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

        const vector<int> &ret = howSum(M);

        if(ret == INVALID_VECTOR) {
            cout << INVALID_TEXT << '\n';
            continue;
        }
        cout << ret.size() << ' ';
        print(ret);
    }
}