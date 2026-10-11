class Solution {
    int factorial(int n, std::vector<int> &dpArr){
        if (n <= 2) return n;
        if (dpArr[n] != -1) return dpArr[n];

        return dpArr[n] = factorial(n-1, dpArr) + factorial(n-2,dpArr);


    }
public:
    int climbStairs(int n) {
        std::vector<int> dpArr(n+1,-1);
        
        int prev2{1};
        int prev1{2};
        

        return factorial(n, dpArr);
    }
};
