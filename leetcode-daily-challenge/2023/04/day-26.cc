class Solution {
public:
    int addDigits(int num) {
        if(num % 9 == 0)
            return num == 0 ? 0 : 9;
        return num % 9;

    }
};

//class Solution {
//public:
//    int addDigits(int num) {
//        if(num < 10) return num;
//        int sum = 0;
//        while(num > 0) {
//            sum += num % 10;
//            num /= 10;
//        }
//
//        return addDigits(sum);
//    }
//};