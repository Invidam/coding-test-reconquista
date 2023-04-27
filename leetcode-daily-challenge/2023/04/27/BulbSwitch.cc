#include <cmath>

//url: https://leetcode.com/problems/bulb-switcher/description/

class Solution {
public:
    int bulbSwitch(int n) {
        return n<=1 ? n : sqrt(n);
    }
};