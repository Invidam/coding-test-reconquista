#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
using namespace std;
int TC, N, mostAppearK;
random_device rd;
mt19937 gen(rd());

int getRandomPivot(int from, int to) {
    uniform_int_distribution<> dis(from, to);
    return dis(gen);
}

void printVector(const vector<int> &vec) {
    for (const auto &item: vec) {
        cout << item << ' ';
    }
    cout << '\n';
}

int myPartition(int from, int to, vector<int> &arr, unordered_map<int,
        int> &freq) {
    int pivot = getRandomPivot(from, to);
    swap(arr[from], arr[pivot]);
    pivot = from;
    int L = from + 1;
    int R = to;
    while (L <= R) {
        if (freq[arr[L]] >= freq[arr[pivot]]) {
            ++L;
        } else {
            swap(arr[L], arr[R--]);
        }
    }
    swap(arr[pivot], arr[R]);
    return R;
}

void fillMostFreqFor(int from, int to, vector<int> &ret, int K,
                     unordered_map<int, int> &freq) {
    if (from >= to) return;
    int loc = myPartition(from, to, ret, freq);
    if (loc == K) return;
    (loc > K) ?
    fillMostFreqFor(from, loc - 1, ret, K, freq) :
    fillMostFreqFor(loc, to, ret, K, freq);
}

vector<int> fillFreqNums(vector<int> &arr, int K) {
    unordered_map<int, int> freq;
    vector<int> rets;
    for (const auto &elem: arr) {
        ++freq[elem];
    }
    for (const auto &elem: freq) {
        rets.emplace_back(elem.first);
    }
    fillMostFreqFor(0, rets.size() - 1, rets, K, freq);
    return vector<int>(rets.begin(), rets.begin() + K);
}

int main() {
    FAST_IO;
    cin >> TC;
    for (int i = 0; i < TC; ++i) {
        cin >> N >> mostAppearK;
        vector<int> arr(N);
        for (int j = 0; j < N; ++j) {
            cin >> arr[j];
        }
        vector<int> rets = fillFreqNums(arr, mostAppearK) - 1;
        printVector(rets);
    }
}