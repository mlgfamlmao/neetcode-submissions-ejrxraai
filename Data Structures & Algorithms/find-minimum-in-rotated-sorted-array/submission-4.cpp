class Solution {
public:
    int findMin(vector<int>& nums) {
        int leftptr{0};
        int rightptr{static_cast<int>(nums.size()) - 1};

        while (leftptr < rightptr) {
            int middleIndex{(leftptr + rightptr) / 2};

            if (nums[middleIndex] > nums[rightptr]) {
                leftptr = middleIndex + 1;
            }
            else {
                rightptr = middleIndex;
            }
        }

        return nums[leftptr];
    }
};