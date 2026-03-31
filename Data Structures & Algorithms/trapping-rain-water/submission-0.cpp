class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> MaxLeft(height.size()), MaxRight(height.size()) , result(height.size());
        MaxLeft[0]=0; MaxRight[height.size()-1]=0;

        for (int i =1 ; i < height.size(); i++){
            MaxLeft[i] = std::max(height[i-1], MaxLeft[i-1]);

        }

        for(int i = height.size()-2; i>= 0; i--){
            MaxRight[i] = std::max(height[i+1],MaxRight[i+1]);
        }

        for (int i= 0; i < height.size(); i++){
            result[i] = std::min(MaxLeft[i], MaxRight[i]) - height[i];
        }
        int sum= 0;

        for (int i= 0; i < height.size(); i++){
            if (result[i]> 0) sum+= result[i];

        }
        return sum;



        
    }
};
