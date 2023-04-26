#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void initFreq(int baseLength, const string &str, unordered_map<char, int> &beforeFreq) {
    for (int i = 0; i < baseLength - 1; ++i) {
        ++beforeFreq[str[i]];
    }
}

void updateCurr(unordered_map<char, int> &freq, int headChar) {
    ++freq[headChar];
}

bool isGoodCase(int baseLength, const unordered_map<char, int> &freq) { return freq.size() == baseLength; }

void removeBefore(unordered_map<char, int> &freq, int tailChar) {
    --freq[tailChar];

    if (freq[tailChar] == 0) {
        freq.erase(tailChar);
    }
}

int goodStringSize(const string &str, int baseLength = 3) {
    int ret = 0;

    if (baseLength < 1) {
        return -1;
    }
    if (str.size() < baseLength) {
        return 0;
    }

    unordered_map<char, int> freq;
    initFreq(baseLength, str, freq);

    for (int i = baseLength - 1; i < str.size(); ++i) {
        int headChar = str[i];
        int tailChar = str[i - baseLength + 1];

        updateCurr(freq, headChar);

        if(isGoodCase(baseLength, freq)) {
            ++ret;
        }

        removeBefore(freq, tailChar);
    }

    return ret;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        string str;
        cin >> str;

        cout << goodStringSize(str) << '\n';
    }

    return 0;
}