#include <iostream>
#include <vector>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

/* 공간 복잡도 분석
 * 입력 N에 대하여, N개의 크기를 갖는 arr와 temp를 이용하여 합병 정렬을 진행하였다.
 * arr와 temp는 사전에 N개의 크기만큼 초기화하였으므로, 2*N을 사용하였다.
 * 또한 재귀호출로 인해 log(N)만큼 스택이 쌓인다.
 * 따라서 공간복잡도 s(N)은 2N + log(N)이며, 빅오 표기법으로 표현한다면
 * s(N) = O(N)이다.
 * */

using namespace std;

void print(const vector<int> &arr) {
    for (const auto &item: arr) {
        cout << item << ' ';
    }
    cout << '\n';
}

void copy(vector<int> &arr, const vector<int> &temp, int tempIdx, const int &tempStartIdx) {
    for (int i = tempStartIdx; i < tempIdx; ++i) {
        arr[i] = temp[i];
    }
}

void myMergeSort(int from, int to, vector<int> &arr, vector<int> &temp) {
    if (from == to) {
        return;
    }
    int mid = from + to >> 1;

    myMergeSort(from, mid, arr, temp);
    myMergeSort(mid + 1, to, arr, temp);

    int leftIdx = from;
    int rightIdx = mid + 1;

    int tempIdx = from;

    const int &leftLimitIdx = mid + 1;
    const int &rightLimitIdx = to + 1;

    const int &tempStartIdx = from;

    while (leftIdx < leftLimitIdx || rightIdx < rightLimitIdx) {
        if ((rightIdx >= rightLimitIdx) || ((leftIdx < leftLimitIdx) && arr[leftIdx] < arr[rightIdx])) {
            temp[tempIdx++] = arr[leftIdx++];
        } else {
            temp[tempIdx++] = arr[rightIdx++];
        }
    }

    copy(arr, temp, tempIdx, tempStartIdx);

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

        myMergeSort(0, arr.size() - 1, arr, temp);

        print(arr);

    }

    return 0;
}