class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        std::vector<int> maxLeft(n);
        std::vector<int> maxRight(n);
        std::vector<int> minLeftRight(n);
        std::vector<int> solution(n);
        int sum{0};

        int currentLeftMax{0};
        int currentRightMax{0};

        for (int i{0}; i < height.size(); i++ ){
            if (currentLeftMax < height[i]){
                currentLeftMax = height[i];
            }
            maxLeft[i] = currentLeftMax;
        }
        
        for (int i{(int)height.size() - 1}; i >= 0; i-- ){
            if (currentRightMax < height[i]){
                currentRightMax = height[i];
            }
            maxRight[i] = currentRightMax;
        }

        for (int i{0}; i < height.size(); i++){
            minLeftRight[i] = std::min(maxLeft[i], maxRight[i]);
        }

        for (int i{0}; i < height.size(); i++){
            solution[i] = minLeftRight[i] - height[i];
            sum += solution[i];
        }
        return sum;
    }
};