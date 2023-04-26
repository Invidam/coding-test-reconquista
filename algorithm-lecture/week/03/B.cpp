#include <iostream>
#include <queue>

#define FAST_IO std::ios::sync_with_stdio(false); std::cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

string str;
int TC, K;

deque<int> charIndexesL[26];
deque<int> charIndexesR[26];

void init() {
    for (int i = 0; i < 26; ++i) {
        charIndexesL[i].clear();
        charIndexesR[i].clear();
    }
}

int getLeakIndex() {
    for (int i = 0; i < 26; ++i) {
        if(charIndexesL[i].empty() && charIndexesR[i].empty()) continue;
        if (charIndexesL[i].size() + charIndexesR[i].size() < K) {
            return i;
        }
    }
    return -1;
}

const int getLength(int from, int to) {
    return to - from + 1;
}

int longestFreqOverKIncludeMid(int from, int to) {
    int mid = from + to >> 1;

    init();

    for (int j = from; j <= to; ++j) {
        char i1 = str[j] - 'a';
        if (j <= mid) {
            charIndexesL[i1].emplace_back(j);
        } else {
            charIndexesR[i1].emplace_front(j);
        }
    }
    int leakIndex = getLeakIndex();
    int idxL = from, idxR = to;

    while (leakIndex != -1) {
        //idxL이 mid까지만
        //idxR이 mid까지만 가도록
        /*
         * 1
         * aaaaabcdefghijklmnopqrstuv
         * 5
         *
         * 의 경우 맨 왼쪽의 요소들은 전부 사라짐.
         *
         * 추가로 못찾은 경우 어떤 응답할지 정하기 어떻게 판별할지
         *
         * 좌 우에서 못찾고, 중앙에서만 찾음 왜냐하면 고정된 닻이 중앙에 있기 때문.
         *
         * */
        while (!(charIndexesL[leakIndex].empty())) {
            int front = charIndexesL[leakIndex].front();

            do {
                int currValue = str[idxL] - 'a';
                charIndexesL[currValue].pop_front();
            } while (idxL++ != front);
        }
        while (!(charIndexesR[leakIndex].empty())) {
            int front = charIndexesR[leakIndex].front();

            do {
                int currValue = str[idxR] - 'a';
                charIndexesR[currValue].pop_front();
            } while (idxR-- != front);
        }
        leakIndex = getLeakIndex();
    }

    return getLength(idxL, idxR);
}

int longestFreqOverK(int from, int to) {
    if(K== 1) return getLength(from, to);
    if(from > to) return 0;
    if(getLength(from, to) < K) return 0;

    int mid = from + to >> 1;

    const int retL = longestFreqOverK(from, mid);
    const int retR = longestFreqOverK(mid + 1, to);
    const int maxCand = retL > retR ? retL : retR;

    int retM = longestFreqOverKIncludeMid(from, to);

    return maxCand > retM ? maxCand : retM;
}


int main() {

    FAST_IO;
    cin >> TC;

    for (int i = 0; i < TC; ++i) {
        cin >> str;
        cin >> K;

        int from = 0, to = str.size() - 1;


        int ret = longestFreqOverK(from, to);

        cout << ret << '\n';

    }

}
