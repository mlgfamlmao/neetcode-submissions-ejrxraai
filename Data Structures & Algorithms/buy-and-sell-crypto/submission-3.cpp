class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int leftptr{0};
        int rightptr{1};

        int maxP{0};

        while (rightptr < prices.size()){
            if (prices[leftptr] < prices[rightptr]){
                int profit{prices[rightptr]- prices[leftptr]};
                maxP = std::max(maxP, profit);

            }
            else{
                leftptr = rightptr;
            }
            rightptr++;

        }
        return maxP;
        
    }
};
