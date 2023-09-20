#include <iostream>
#include <vector>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
vector<int> arr;
int N;

void solve() {

    cin >> arr[0] >> arr[1] >> arr[2];

    vector<int> values_min = arr;
    vector<int> befValues_min;
    vector<int> values_max = arr;
    vector<int> befValues_max;

    for (int i = 1; i < N; ++i) {

        cin >> arr[0] >> arr[1] >> arr[2];
        befValues_min = values_min;
        befValues_max = values_max;

        for (int j = 0; j < 3; ++j) {
            values_min[j] += arr[j];
            values_max[j] += arr[j];
        }

        for (int j = 0; j < 3; ++j) {
            for (int k = -1; k < 2; ++k) {
                int prevIdx = j + k;

                if (prevIdx < 0 || prevIdx > 2) continue;

                int cand_min = befValues_min[prevIdx] + arr[j];
                int cand_max = befValues_max[prevIdx] + arr[j];

                if (cand_min < values_min[j]) {
                    values_min[j] = cand_min;
                }
                if (cand_max > values_max[j]) {
                    values_max[j] = cand_max;
                }

            }
        }
    }

    int ret_min = values_min[0], ret_max = values_max[0];

    for (int i = 1; i < 3; ++i) {
        ret_min = min(ret_min, values_min[i]);
        ret_max = max(ret_max, values_max[i]);
    }
    cout << ret_max << ' ' << ret_min;
}

int main() {

    FAST_IO;

    cin >> N;
    arr = vector<int>(3);

    solve();

    return 0;
}
