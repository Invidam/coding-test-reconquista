#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> p;
//Problem site: https://www.acmicpc.net/problem/17619
int N, Q;
vector<vector<int> > items;
vector<p> links;

void solve() {
    std::sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });

    vector<int> endCoordSet;
    vector<int> setToIdx(N);
    for (int i = 0; i < items.size(); ++i) {
        const auto& item = items[i];
        if( i== 0 ) {
            endCoordSet.push_back(item[1]);
            setToIdx[item[2]] = (endCoordSet.size() -1);
            continue;
        }

        if(item[0] <= endCoordSet.back()) {
            endCoordSet.back() = max(item[1], endCoordSet.back());
            setToIdx[item[2]] = (endCoordSet.size() - 1);
        } else {
            endCoordSet.push_back(item[1]);
            setToIdx[item[2]] = (endCoordSet.size() - 1);
        }
    }

    for (int i = 0; i < Q; ++i) {
        auto link = links[i];

        if(setToIdx[link.first - 1] == setToIdx[link.second - 1]) {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    items = vector<vector<int> >(N, vector<int>(3));
    links.resize(Q);

    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> items[i][0] >> items[i][1] >> tmp;
        items[i][2] = i;
    }

    for (int i = 0; i < Q; ++i) {
        cin >> links[i].first >> links[i].second;
    }

    solve();


    return 0;
}
