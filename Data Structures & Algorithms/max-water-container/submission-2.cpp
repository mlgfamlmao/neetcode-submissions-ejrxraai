class Solution {
public:
    int maxArea(vector<int>& heights) {
        int MaxArea = 0;
        int l = 0; int r = heights.size() - 1 ;

        while (l< r){
            int Area = min(heights[l], heights[r]) * (r -l) ;
            MaxArea = max(MaxArea, Area);
            if (heights[l] < heights[r]) l++;
            else r--;
        }

        return  MaxArea;

        
    }
};
