#include <iostream>
#include <unordered_map>
#include <vector>
#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int N, M;

int solve() {
    return 0;
}

bool isNumeric(string& str) {
    for (int i = 0; i < str.size(); ++i) {
        if(!isdigit(str[i])) return false;
    }
    return true;
}
int main() {

    FAST_IO;

    cin >> N >> M;

    vector<string> idxToName(N+1);
    unordered_map<string, int> nameToIdx;
    string str;
    for (int i = 0; i < N; ++i) {
        cin >> str;

        idxToName[i+1] = str;
        nameToIdx[str] = i+1;
    }

    for (int i = 0; i < M; ++i) {
        cin >> str;
        if(isNumeric(str)) cout << idxToName[stoi(str)];
        else cout << nameToIdx[str];

        cout << '\n';
    }
}
