class Solution {
public:
    int search(vector<int>& nums, int target) {
        int leftptr{0};
        int rightptr{static_cast<int>(nums.size()-1)};

        while (leftptr <= rightptr) {
            int middleIndex{(leftptr + rightptr) / 2};
            int middle{nums[middleIndex]};

            if (middle == target) {
                return middleIndex;
            }
            else if (target > middle) {
                leftptr = middleIndex + 1;
            }
            else {
                rightptr = middleIndex - 1;
            }
        }

        return -1;
    }
};