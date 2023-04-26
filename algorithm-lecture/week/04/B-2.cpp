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

int getMoreThanHalfFreq(const vector<int> &arr) {
    int cand = arr[0];

    int cnt = 0;
    for (const auto &item: arr) {
        if (cand == item) {
            ++cnt;
        } else {
            --cnt;

            if(cnt == 0) {
                cand = item;
                cnt = 1;
            }
        }
    }

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

        cout << getMoreThanHalfFreq(arr) << '\n';
    }
}
