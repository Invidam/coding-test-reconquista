#include <iostream>
#include <vector>
#include <set>
//#include <bits/stdc++.h>
using namespace std;
// TC: O(max)
// SC: O(max)

typedef long long ll;
vector<int> primes;

int getSqrt(ll num) {
    ll i = 1LL;
    for (; i * i <= num; i += 2);
    return i;
}

void fillSieveOfEratosthenes(ll maxNum) {
    int sqrtNum = getSqrt(maxNum);
    vector<bool> sieves(sqrtNum + 1, true);
    sieves[0] = sieves[1] = false;

    for (int num = 2; num <= sqrtNum; num +=2) {
        if (!sieves[num]) continue;
        primes.push_back(num);

        for (ll nextNum = 1LL * num * num; nextNum <= sqrtNum; nextNum += num) {
            sieves[nextNum] = false;
        }
        //+=2를 만족시키기 위해 2만 예외경우로 1을 뺀다.
        if(num ==2) num -=1;
    }
}

int noNoPrimesCnt(ll min, ll max) {
    vector<bool> visited(max - min + 1, false);
    for (ll prime: primes) {
        ll primeMult = prime * prime;
        ll quotient = max / primeMult;
        ll maxNum = quotient * primeMult;

        for (ll num = maxNum; num >= min; num -= primeMult) {
            visited[(int) (num - min)] = true;
        }
    }

    int ret = 0;
    for (int i = 0; i < visited.size(); ++i) {
        if (!visited[i])
            ++ret;
    }
    return ret;
}

void solve(ll min, ll max) {
    fillSieveOfEratosthenes(max);

    cout << noNoPrimesCnt(min, max) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll min, max;
    cin >> min >> max;

    solve(min, max);

    return 0;
}