#include <iostream>
#include <vector>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

const int MAX_SIZE = 3;
const vector<string> EMPTY_VECTOR = vector<string>();

int TC, N;

vector<int> freq;
vector<bool> isAnswer(1000, false);

void print() {
    for (int i = 100; i < 1000; ++i) {
        if(isAnswer[i]) cout << i << ' ';
    }
    cout << '\n';
}

void solve(string used, int startNumber) {
    if(freq[startNumber] == 0) return;

    if(used.size() == 0 && startNumber == 0) return;
    if(used.size() == 2 && startNumber % 2) return;

    used += ('0' + startNumber);

    if(used.size() == MAX_SIZE) {
        isAnswer[stoi(used)] = true;
        return;
    }

    for (int number = 0; number < 10; ++number) {
        if(freq[number] == 0) continue;

        --freq[startNumber];
        solve(used, number);
        ++freq[startNumber];
    }
}

void solve() {
    for (int number = 0; number < 10; ++number) {
        solve("", number);
    }
}


int main() {

    FAST_IO;

    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        cin >> N;

        freq = vector<int>(10, 0);
        isAnswer = vector<bool>(1000, false);

        for (int j = 0; j < N; ++j) {
            int num;
            cin >> num;

            ++freq[num];
        }

        solve();
        print();
    }

    return 0;
}