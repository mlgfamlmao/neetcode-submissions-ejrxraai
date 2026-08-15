class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea{0};
        int n{static_cast<int>(heights.size())};

        std::stack<std::pair<int, int>> stk;

        for (int i{0}; i < n; i++) {

            int startIndex{i};

            while (!stk.empty() && heights[i] < stk.top().second) {

                int index{stk.top().first};
                int height{stk.top().second};

                stk.pop();

                int width{i - index};

                maxArea = std::max(maxArea, width * height);

                startIndex = index;
            }

            stk.push({startIndex, heights[i]});
        }

        while (!stk.empty()) {

            int index{stk.top().first};
            int height{stk.top().second};

            stk.pop();

            int width{n - index};

            maxArea = std::max(maxArea, width * height);
        }

        return maxArea;
    }
};