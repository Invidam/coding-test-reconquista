#include <iostream>
#include <vector>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);
static const int MAX_VAL = 0x7fff'ffff;
static const int MIN_VAL = 0x8000'0000;
using namespace std;

int TC, N;

int solve(vector<int> &arr) {
    vector<int> tournaments(arr.size() - 1);
    tournaments.insert(tournaments.end(), arr.begin(), arr.end());

    int from = arr.size()-1, to = tournaments.size();
    while (from != 0) {

        if(from % 2 == 0) ++from;

        for (int i = from; i < to; i += 2) {
            int parentIdx = i >> 1;

            if(i + 1 >= tournaments.size()) {
                tournaments[parentIdx] = tournaments[i];
                break;
            }

            tournaments[parentIdx] = max(tournaments[i], tournaments[i + 1]);
        }

        to = from;
        from >>= 1;
    }

    int idx = 0;
    int ret = MIN_VAL;

    while(((idx << 1) + 1) < tournaments.size()) {
        int leftIdx = (idx << 1) + 1;
        int leftElem = tournaments[leftIdx];

        int rightIdx = (idx << 1) + 2;

        if(rightIdx >= tournaments.size()) {
            return max(leftElem, ret);
        }

        int rightElem = tournaments[rightIdx];

        int cand = leftElem == tournaments[idx] ? rightElem : leftElem;
        int nextIdx = leftElem == tournaments[idx] ? leftIdx : rightIdx;

        ret = max(cand, ret);


        idx = nextIdx;
    }
    return ret;
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

        cout << solve(arr) << '\n';
    }
}
