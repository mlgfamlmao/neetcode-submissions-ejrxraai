class Solution {
public:
    int maxArea(vector<int>& heights) {
        int MaxArea = 0;
        int l = 0, r = heights.size() - 1;

        while (l < r) {
            int area = min(heights[l], heights[r]) * (r - l);  
            MaxArea = max(MaxArea, area);
            if (heights[l] < heights[r]) l++;
            else r--;
        }

        return MaxArea;
    }
};