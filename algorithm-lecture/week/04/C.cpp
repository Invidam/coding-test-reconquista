#include <iostream>
#include <vector>
#include <random>
#include <deque>

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

bool checkValid(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        if(i % 2) {
            if(arr[i-1] >= arr[i]) return true;
        }
        else {
            if(arr[i-1] <= arr[i]) return true;
        }
    }
    return false;
}

void divideForWiggle(vector<int> &arr, deque<int> &less, deque<int> &more) {
    int mid = (0 + arr.size() - 1) / 2;

    int midValue = getMidValue(0, arr.size() - 1, arr, mid);
    int equalCnt = 0;

    for (const auto &item: arr) {
        if(item < midValue) {
            less.emplace_back(item);
        }
    }
    for (const auto &item: arr) {
        if(item >= midValue) {
            more.emplace_back(item);
        }
    }


    for (int i = 0; i < equalCnt; ++i) {
        if(less.size() <= more.size()) {
            less.emplace_back(midValue);
        } else {
            more.emplace_front(midValue);
        }
    }
}

void printWiggleSortedResult(vector<int>& arr) {
    deque<int> less;
    deque<int> more;
    divideForWiggle(arr, less, more);

    vector<int> result;

    while(!less.empty() && !more.empty()) {
        result.emplace_back(less.back());
        less.pop_back();

        result.emplace_back(more.back());
        more.pop_back();
    }
    if(!less.empty())
        result.emplace_back(less.back());

    cout << arr.size() << '\n';
    printVector(result);
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

        printWiggleSortedResult(arr);
    }
}
