#include <iostream>
#include <vector>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

const pair<int, int> INVALID = pair<int, int>(-1, 0);

int TC, K;
string str;
vector<int> freq;

int getFreqIndex(int stringIdx) {
    return str[stringIdx] - 'a';
}

bool canIncludeFromFreq(int stringIdx) { return freq[getFreqIndex(stringIdx)] >= K; }

bool canIncludeFromRealFreq(const vector<int> &realFreq, int i) { return realFreq[getFreqIndex(i)] > K; }

pair<int, int> getLongestRange(int from, int to, const pair<int, int> range1,
                               const pair<int, int> range2) {

    int mid = from + to >> 1;
    if(!canIncludeFromFreq(mid)) return INVALID;

    int leftOfMid = mid, rightOfMid = mid;

//    if(range1.second == mid) {
//        leftOfMid = range1.first;
//    }
//
//    if(canIncludeFromFreq(mid + 1) && range2.first == mid + 1) {
//        rightOfMid = range2.second;
//    }

    while(from < leftOfMid && canIncludeFromFreq(leftOfMid -1)) {
        --leftOfMid;
    }
    while(rightOfMid < to && str[rightOfMid + 1] == str[mid]) {
        ++rightOfMid;
    }

    vector<int> realFreq(26, 0);

    for (int i = leftOfMid; i <= rightOfMid; ++i) {
        ++realFreq[getFreqIndex(i)];
    }

    for (int i = leftOfMid; i < mid; ++i) {
        if(!canIncludeFromRealFreq(realFreq, i)) {
            ++leftOfMid;
            --realFreq[getFreqIndex(i)];
        }
    }

}

const int getLength(const pair<int, int>& p) {
    return p.second - p.first + 1;
}

pair<int, int> getLongestRange(int from, int to) {
    if (from == to) return make_pair(from, to);
    if (getLength(make_pair(from, to)) < K) return INVALID;

    int mid = from + to >> 1;

    const pair<int, int> &range1 = getLongestRange(from, mid);
    const pair<int, int> &range2 = getLongestRange(mid + 1, to);

    const pair<int, int> &range3 = getLongestRange(from, to, range1, range2);

    if(getLength(range1) > getLength(range2)) {
        return getLength(range1) > getLength(range3) ? range1 : range3;
    }
    return getLength(range2) > getLength(range3) ? range2 : range3;
}

int solve() {

    freq = vector<int>(26, 0);
    int mostFreq = 0;
    for (int j = 0; j < str.size(); ++j) {
        mostFreq = max(mostFreq, ++freq[getFreqIndex(j)]);
    }

    if(mostFreq < K) return 0;

    return getLength(getLongestRange(0, str.size() -1));
}

int main() {

    FAST_IO;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        cin >> str;
        cin >> K;

        cout << solve() << '\n';
    }
}
