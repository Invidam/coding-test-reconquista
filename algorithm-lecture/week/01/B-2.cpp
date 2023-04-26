#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int THRESHOLD = 8;

class RunStack {
private:
    vector<int> arr1;
    vector<pair<int, int>> runIdxAndLen = vector<pair<int, int>>(THRESHOLD + 8);
    int size = 0;

    static int getMergeStartLen(int bStartElem, int aStartIdx, int aSize, vector<int>& arr) {
        int aStartElem = arr[aStartIdx];

        if (bStartElem < aStartElem) {
            return 0;
        }

        int maxLen = aSize;
        int lo = 0, hi = 1;
        while (hi < maxLen && arr[aStartIdx + hi] <= bStartElem) {
            lo = hi;
            hi = (hi << 1) + 1;

            if (hi <= 0) {
                hi = maxLen;
            }
        }

        if (hi > maxLen) {
            hi = maxLen;
        }


        //lo: bStartElem보다 작은 인덱스
        //hi: bStartElem보다 큰 인덱스

        while (lo + 1 < hi) {
            int mid = lo + hi >> 1;

            if (arr[aStartIdx + mid] <= bStartElem) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        return hi;
    }

    static int getMergeEndLen(int aEndElem, int bStartIdx, int bSize, vector<int>& arr) {
        int bEndElem = arr[bStartIdx + bSize - 1];

        if (aEndElem > bEndElem) {
            return bSize;
        }

        int maxLen = bSize;
        int lo = 0, hi = 1;
        while (hi < maxLen && aEndElem <= arr[bStartIdx + bSize - 1 - hi]) {
            lo = hi;
            hi = (hi << 1) + 1;

            if (hi <= 0) {
                hi = maxLen;
            }
        }

        if (hi > maxLen) {
            hi = maxLen;
        }
        int temp = lo;
        lo = maxLen - hi - 1;
        hi = maxLen - temp - 1;



        //lo: aStartElem보다 작은 인덱스
        //hi: aStartElem보다 큰 인덱스

        while (lo + 1 < hi) {
            int mid = lo + hi >> 1;

            if (arr[bStartIdx + mid] < aEndElem) {
                lo = mid;
            } else {
                hi = mid; //살짝 다름
            }
        }

        if (hi > maxLen) {
            hi = maxLen;
        }

        return hi;
    }

    static void copyVector(vector<int> &from, vector<int> &to, int fromStartIdx, int toStartIdx, int len) {
        if (len == 0) {
            return;
        }

        for (int i = 0; i < len; ++i) {
            to[toStartIdx + i] = from[fromStartIdx + i];
        }
    }

    void mergeLo(pair<int, int> curr, pair<int, int> next, vector<int>& arr) {
        //A curr가 작음

        vector<int> temp(curr.second);
        copyVector(arr, temp, curr.first, 0, curr.second);

        int insertIdx = curr.first;
        int runBIdx = next.first;
        int tempIdx = 0;

        int remainedA = curr.second;
        int remainedB = next.second;

        while (remainedA != 0 && remainedB != 0) {
            if (arr[runBIdx] < temp[tempIdx]) {
                arr[insertIdx++] = arr[runBIdx++];
                --remainedB;
            } else {
                arr[insertIdx++] = temp[tempIdx++];
                --remainedA;

            }
        }

        copyVector(temp, arr, tempIdx, insertIdx, remainedA);
        copyVector(arr, arr, runBIdx, insertIdx, remainedB);
    }

    void mergeHi(pair<int, int> curr, pair<int, int> next, vector<int>& arr) {
        //B next가 작음

        vector<int> temp(next.second);
        copyVector(arr, temp, next.first, 0, next.second);

        int insertIdx = next.first + next.second - 1;
        int runAIdx = curr.first + curr.second - 1;
        int tempIdx = next.second - 1;

        int remainedA = curr.second;
        int remainedB = next.second;

        while (remainedA != 0 && remainedB != 0) {
            if (arr[runAIdx] > temp[tempIdx]) {
                arr[insertIdx--] = arr[runAIdx--];
                --remainedA;
            } else {
                arr[insertIdx--] = temp[tempIdx--];
                --remainedB;

            }
        }

        copyVector(temp, arr, 0, curr.first, remainedB);
    }

    void merge(int startStackIdx, vector<int>& arr) {
        pair<int, int> curr = runIdxAndLen[startStackIdx];
        pair<int, int> next = runIdxAndLen[startStackIdx + 1];

        runIdxAndLen[startStackIdx] = pair(curr.first, curr.second + next.second);
        if (startStackIdx + 2 < size) {
            runIdxAndLen[startStackIdx + 1] = runIdxAndLen[startStackIdx + 2];
        }
        --size;

        int startLen = getMergeStartLen(arr[next.first], curr.first, curr.second, arr);
        if (curr.second == startLen) {
            return;
        }

        curr.first += startLen;
        curr.second -= startLen;

        int endLen = getMergeEndLen(arr[curr.first + curr.second - 1], next.first, next.second, arr);

        if (endLen == 0) {
            return;
        }

        next.second = endLen;

        if (curr.second <= next.second) {
            mergeLo(curr, next, arr);
        } else {
            mergeHi(curr, next, arr);
        }

    }

public:
    explicit RunStack(vector<int> &originArr) {
        this->arr1 = originArr;
    }

    void push(int runStartIdx, int runLength) {
        runIdxAndLen[size++] = pair(runStartIdx, runLength);

    }

    void merge(vector<int>& arr) {
        while (size > 1) {
            if ((size > 2 &&
                 (runIdxAndLen[size - 3].second <= runIdxAndLen[size - 2].second + runIdxAndLen[size - 1].second))
                || (size > 3 &&
                    (runIdxAndLen[size - 4].second <= runIdxAndLen[size - 3].second + runIdxAndLen[size - 2].second))
                    )
            {
                if (runIdxAndLen[size - 3].second < runIdxAndLen[size - 1].second) {
                    merge(size - 3, arr);
                } else {
                    merge(size - 2, arr);
                }
            } else if (runIdxAndLen[size - 2].second <= runIdxAndLen[size - 1].second)
            {
                merge(size - 2, arr);
            } else {
                break;
            }
        }
    }

    void mergeForce(vector<int>& arr) {
        while (size > 1) {
            if ((size > 2 && (runIdxAndLen[size - 3].second < runIdxAndLen[size - 1].second))) {
                merge(size - 3, arr);
            } else {
                merge(size - 2, arr);
            }
        }
    }
};

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

int getMinLength(int size) {
    int rest = 0;
    while (size >= THRESHOLD) {
        if (size % 2) {
            rest = 1;
        }
        size >>= 1;
    }

    return size + rest;
}

int optimizeAndGetAscendingLength(int from, int to, vector<int> &arr) {
    stack<vector<int>> runStack;
    int ascendingIdx = from + 1;

    if (from == to) return 1;

    if (arr[from] <= arr[ascendingIdx]) {
        while (ascendingIdx <= to && (arr[ascendingIdx - 1] <= arr[ascendingIdx])) {
            ++ascendingIdx;
        }
    } else {
        while (ascendingIdx <= to && (arr[ascendingIdx - 1] > arr[ascendingIdx])) {
            ++ascendingIdx;
        }
        reverse(arr.begin() + from, arr.begin() + ascendingIdx);
    }

    return ascendingIdx - from;
}

void myTimSort(int from, int to, vector<int> &arr) {
    if (from == to) {
        return;
    }

    int length = to - from + 1;
    if (length < THRESHOLD) {
        myInsertionSort(from, to, arr, from + optimizeAndGetAscendingLength(from, to, arr));
    }

    RunStack runStack(arr);
    int minRunLen = getMinLength(length);
    int remainedLen = length;
    int runStartIdx = from;

    while (remainedLen > 0) {
        int runLen = optimizeAndGetAscendingLength(runStartIdx, to, arr);

        if (runLen < minRunLen) {
            int toSortLen = remainedLen < minRunLen ? remainedLen : minRunLen;

            myInsertionSort(runStartIdx, runStartIdx + toSortLen - 1, arr, runStartIdx + runLen);

            runLen = toSortLen;
        }

        runStack.push(runStartIdx, runLen);
        runStack.merge(arr);

        runStartIdx += runLen;
        remainedLen -= runLen;
    }

    runStack.mergeForce(arr);

}
void printArr(const vector<int> &arr) {
    for (int num : arr) {
        cout << num << ' ';
    }
    cout << '\n';
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC;
    cin >> TC;
    for (int i = 0; i < TC; ++i) {
        int N;
        cin >> N;

        vector<int> arr = vector<int>(N);

        for (int j = 0; j < N; ++j) {
            cin >> arr[j];
        }

        myTimSort(0, arr.size() - 1, arr);

        printArr(arr);
    }

    return 0;
}