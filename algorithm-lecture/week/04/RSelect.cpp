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


void printVector(const vector<int> &vec) {
    for (const auto &item: vec) {
        cout << item << ' ';
    }
    cout << '\n';
}


void mySwap(int l, int r, vector<int> &arr) {
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}

int myPartition(int from, int to, vector<int> &arr) {
    int pivot = getRandomPivot(from, to);
    mySwap(from, pivot, arr);
    pivot = from;
    int L = from + 1;
    int R = to;

    while (L <= R) {
        if (arr[L] <= arr[pivot]) {
            ++L;
        } else {
            mySwap(L, R--, arr);
        }
    }
    mySwap(pivot, R, arr);

    return R;
}

int getMidValue(int from, int to, vector<int> &arr, int baseMid) {
    if (from >= to) return arr[from];
    int loc = myPartition(from, to, arr);

    if(loc == baseMid) return arr[baseMid];

    return (loc > baseMid) ? getMidValue(from, loc - 1, arr, baseMid) : getMidValue(loc, to, arr, baseMid);
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

        int mid = (0 + arr.size() - 1) / 2;

        cout << getMidValue(0, arr.size() - 1, arr, mid) << '\n';
    }
}
