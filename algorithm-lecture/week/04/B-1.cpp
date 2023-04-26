#include <iostream>
#include <vector>
#include <random>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int TC, N;

random_device rd;
mt19937 gen(rd());

int getRandomPivot(int from, int to) {
    uniform_int_distribution<> dis(from, to);

    return dis(gen);
}

bool isMoreThanHalf(int num, const vector<int> &arr) {
    int cnt = 0;
    for (const auto &item: arr) {
        if (num == item) ++cnt;
    }

    return cnt > (arr.size() - 1) / 2;
}

int getMoreThanHalfFreq(int from, int to, vector<int> &arr) {

    int cand;

    do {
        int pivot = getRandomPivot(from, to);
        cand = arr[pivot];

    } while (!isMoreThanHalf(cand, arr));


    return cand;
}

int main() {

    FAST_IO;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        cin >> N;
        vector<int> arr(N);

        for (int j = 0; j < N; ++j) {
            cin >> arr[j];
        }

        cout << getMoreThanHalfFreq(0, arr.size() - 1, arr) << '\n';
    }
}
