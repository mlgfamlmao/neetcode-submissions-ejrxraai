class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int leftptr{0};
        int rightptr{static_cast<int>(matrix.size()) - 1};
        int outerIndex{-1};
        while (leftptr <= rightptr) {
            int middleIndex{(leftptr + rightptr) / 2};

            int first{matrix[middleIndex][0]};
            int last{matrix[middleIndex][matrix[middleIndex].size() - 1]};

            if (target >= first && target <= last) {
                outerIndex = middleIndex;
                break;
            }
            else if (target < first) {
                rightptr = middleIndex - 1;
            }
            else {
                leftptr = middleIndex + 1;
            }
        }
        if (outerIndex == -1) {
            return false;
        }
       leftptr = 0;
        rightptr = static_cast<int>(matrix[outerIndex].size()) - 1;

        while (leftptr <= rightptr) {
            int middleIndex{(leftptr + rightptr) / 2};

            if (matrix[outerIndex][middleIndex] == target) {
                return true;
            }
            else if (target > matrix[outerIndex][middleIndex]) {
                leftptr = middleIndex + 1;
            }
            else {
                rightptr = middleIndex - 1;
            }
        }

        return false;
    }
};