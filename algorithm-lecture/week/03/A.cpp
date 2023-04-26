a#include <iostream>
#include <vector>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int TC, N;
vector<int> arr;

int getInversionCount(int from, int to, vector<int>& temp) {
    if(from >= to) return 0;

    int mid = from + to >> 1;

    int ret = getInversionCount(from, mid, temp) + getInversionCount(mid + 1, to, temp);

    int startLIdx = from, startRIdx = mid + 1;
    const int endLIdx = mid +1, endRIdx = to +1;

    int tempIdx = from;

    while(startLIdx < endLIdx || startRIdx < endRIdx) {
        if((startRIdx >= endRIdx) || (startLIdx < endLIdx && arr[startLIdx] <= arr[startRIdx])) {
            temp[tempIdx++] = arr[startLIdx++];
        } else {
            temp[tempIdx++] = arr[startRIdx++];

            ret += endLIdx - startLIdx;
        }
    }

    for (int i = from; i <= to; ++i) {
        arr[i] = temp[i];
    }

    return ret;
}

int main() {

    FAST_IO;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        cin >>  N;

        arr =  vector<int>(N) ;
        for (int j = 0; j < N; ++j) {
            cin >> arr[j];
        }

        vector<int> temp = arr;

        cout << getInversionCount(0, N -1, temp) << '\n';
    }
}
