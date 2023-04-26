#include <iostream>
#include <vector>
#include <algorithm>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

const int THRESHOLD = 8;

void printArr(const vector<int> &arr) {
    for (int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';
}

void copy(vector<int> &arr, const vector<int> &temp, int tempCurrIdx, const int &tempStartIdx) {
    for (int i = tempStartIdx; i < tempCurrIdx; ++i) {
        arr[i] = temp[i];
    }
}

int getInsertIndex(int from, const vector<int> &arr, int i) {
    int lo = from - 1, hi = i;

    while (lo + 1 < hi) {
        int mid = lo + hi >> 1;

        if (arr[mid] <= arr[i]) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    return hi;
}

void myInsertionSort(int from, int to, vector<int> &arr, int startIdx) {
    if (from == to) {
        return;
    }
    if (startIdx == from) {
        ++startIdx;
    }

    for (int i = startIdx; i - 1 < to; ++i) {
        int insertElem = arr[i];
        int insertIdx = getInsertIndex(from, arr, i);

        for (int toGrabIdx = i; toGrabIdx > insertIdx; --toGrabIdx) {
            arr[toGrabIdx] = arr[toGrabIdx - 1];
        }

        arr[insertIdx] = insertElem;
    }
}

void myTimSort(int from, int to, vector<int> &arr, vector<int>& temp) {
    if (from == to) {
        return;
    }

    int length = to - from + 1;

    if (length <= THRESHOLD) {
        myInsertionSort(from, to, arr, from);
        return;
    }
    int mid = from + to >> 1;

    myTimSort(from, mid, arr, temp);
    myTimSort(mid + 1, to, arr, temp);

    int leftIdx = from;
    int rightIdx = mid + 1;

    int tempCurrIdx = from;

    const int& leftLimitIdx = mid + 1;
    const int& rightLimitIdx = to + 1;

    const int& tempStartIdx = from;

    while (leftIdx < leftLimitIdx || rightIdx < rightLimitIdx) {
        if((rightIdx >= rightLimitIdx) || ((leftIdx < leftLimitIdx) && arr[leftIdx] < arr[rightIdx])) {
            temp[tempCurrIdx++] = arr[leftIdx++];
        } else {
            temp[tempCurrIdx++] = arr[rightIdx++];
        }
    }

    copy(arr, temp, tempCurrIdx, tempStartIdx);

}

int main() {

    FAST_IO

    int TC;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        int N;
        cin >> N;

        vector<int> arr = vector<int>(N);
        vector<int> temp = vector<int>(N);

        for (int j = 0; j < N; ++j) {
            cin >> arr[j];
        }

        myTimSort(0, arr.size() - 1, arr, temp);

        printArr(arr);
    }

    return 0;
}