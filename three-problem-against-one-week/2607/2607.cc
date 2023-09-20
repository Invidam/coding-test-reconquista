#include <iostream>
#include <unordered_set>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int N;

int solve() {
    return 0;
}

int main() {

    FAST_IO;
    int N;
    string str;

    cin >> N >> str;
    vector<int> freq(26, 0);

    for (auto ch: str) {
        freq[ch - 'A']++;
    }
    int ret = 0;
    for (int i = 0; i < N-1; ++i) {
        string temp;
        cin >> temp;
        vector<int> freqTemp(26, 0);

        for (auto ch: temp) {
            freqTemp[ch - 'A']++;
        }
        int overCnt = 0;
        int underCnt = 0;
        for (int j = 0; j < 26; ++j) {
            if (freq[j] - freqTemp[j] >= 1) {
                underCnt += freq[j] - freqTemp[j];
            } else if (freq[j] - freqTemp[j] <= -1) {
                overCnt += freqTemp[j] - freq[j];
            }
        }
        if(overCnt >= 2 || underCnt >= 2) continue;

        if (underCnt * overCnt <= 1) ++ret;
    }
    cout << ret << '\n';
}
