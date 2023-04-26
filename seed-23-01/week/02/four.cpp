#include <iostream>
#include <queue>
#include <algorithm>
//#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e6;

int TC, N;

int solve() {
    return 0;
}

ll powOf10(int pow) {
    if (pow == 0) return 1LL;

    return powOf10(pow - 1) * 10LL;
}

int main() {

    FAST_IO;
    cin >> N;

    vector<vector<int>> freq(11, vector<int>(26, 0));
    string str;

    for (int i = 0; i < N; ++i) {
        cin >> str;

        for (int j = 0; j < str.size(); ++j) {
            int digit = str.size() - j - 1;

            freq[digit][str[j] - 'A'] += 1;
        }
    }

    priority_queue<p> freqAndChar;
    int allocatedValue = 9;
    vector<int> allocated(26, -1);
    ll sum = 0;

    for (int i = 9; i >=0; --i) {
        for (int j = 0; j < 26; ++j) {
            if(!freq[i][j]) continue;
            freqAndChar.emplace(freq[i][j], j);
        }

        while(!freqAndChar.empty()) {
            int mostFreqCharIdx = freqAndChar.top().second;
            int freq = freqAndChar.top().first;

            if(allocated[mostFreqCharIdx] == -1) {
                allocated[mostFreqCharIdx] = allocatedValue--;
            }

            sum += 1LL * freq * allocated[mostFreqCharIdx] * powOf10(i);

            freqAndChar.pop();
        }
    }

    cout << sum;

}
