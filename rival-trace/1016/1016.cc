#include <iostream>
#include <vector>
#include <set>
//#include <bits/stdc++.h>
using namespace std;
// TC: O()
// SC: O()

typedef long long ll;
vector<int> primes;

ll getSqrt(ll num) {
    ll i = 1LL;
    while(1) {
        if(i > num/i) break;

        ++i;
    }
    return i;
}

void fillSieveOfEratosthenes(ll maxNum) {
    int sqrtNum = (int) getSqrt(maxNum);
    vector<bool> sieves(sqrtNum + 1, true);
    sieves[0] = sieves[1] = false;

    for (int i = 2; i <= sqrtNum; ++i) {
        if (!sieves[i]) continue;

        for (ll num = 1LL * i * i; num <= sqrtNum; num += i) {
            sieves[num] = false;
        }
    }
    for (int num = 1; num < sieves.size(); ++num) {
        if (!sieves[num]) continue;
        primes.push_back(num);
    }
}

vector<int> noNoPrimes(ll min, ll max) {
    vector<bool> visited(max - min + 1, false);
    for (ll prime: primes) {
        ll primeMult = prime * prime;
        ll quotient = max / primeMult;
        ll maxNum = quotient * primeMult;

        for (ll num = maxNum; num >= min; num -= primeMult) {
            visited[(int)(num - min)] = true;
        }
    }
    vector<int> ret;
    for (int i = 0; i < visited.size(); ++i) {
        if(!visited[i])
            ret.push_back(min + i);
    }
    return ret;
}

void solve(ll min, ll max) {
    fillSieveOfEratosthenes(max);

    vector<int> ret = noNoPrimes(min, max);

    cout << ret.size() << '\n';

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