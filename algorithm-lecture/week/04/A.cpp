#include <iostream>
#include <vector>
#include <random>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int TC, N;
vector<int> arr;

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


void mySwap(int l, int r) {
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
}

int myPartition1(int from, int to) {
    int pivot = getRandomPivot(from,to);
    mySwap(from, pivot);
    pivot = from;
    int L = from + 1;
    int R = to;

    while (L <= R) {
        if (arr[L] <= arr[pivot]) {
            ++L;
        } else {
            mySwap(L, R--);
        }
    }
    mySwap(pivot, R);

    return R;
}


int myPartition2(int from, int to) {
    int pivot = from;
    int L = from + 1;
    int R = to;

    while (L <= R) {
        while (L <= R && arr[L] <= arr[pivot]) {
            ++L;
        }
        while (L <= R && arr[R] > arr[pivot]) {
            --R;
        }

        if(L <= R) {
            mySwap(L++, R--);
        }
    }
    mySwap(pivot, R);

    return R;
}

void myQuickSort(int from, int to) {
    if (from >= to) return;

    int pivotLocation = myPartition1(from, to);

    myQuickSort(from, pivotLocation - 1);
    myQuickSort(pivotLocation + 1, to);

}

int main() {

    FAST_IO;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        cin >> N;
        arr = vector<int>(N);

        for (int j = 0; j < N; ++j) {
            cin >> arr[j];
        }

        myQuickSort(0, arr.size() - 1);

        printVector(arr);
    }
}
