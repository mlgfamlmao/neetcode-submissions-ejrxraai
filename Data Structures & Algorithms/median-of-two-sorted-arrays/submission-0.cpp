class Solution {
public:
    double findMedianSortedArrays(
        std::vector<int>& nums1,
        std::vector<int>& nums2
    ) {

        std::vector<int> A = nums1;
        std::vector<int> B = nums2;
        if (A.size() > B.size()) {
            std::swap(A, B);
        }

        int total{static_cast<int>(A.size() + B.size())};
        int leftSize{(total + 1) / 2};

        int left{0};
        int right{static_cast<int>(A.size())};

        while (left <= right) {

            int partitionA{(left + right) / 2};
            int partitionB{leftSize - partitionA};

            

            int Aleft;
            int Aright;
            int Bleft;
            int Bright;

            if (partitionA == 0)
                Aleft = INT_MIN;
            else
                Aleft = A[partitionA - 1];

            if (partitionA == A.size())
                Aright = INT_MAX;
            else
                Aright = A[partitionA];

            if (partitionB == 0)
                Bleft = INT_MIN;
            else
                Bleft = B[partitionB - 1];

            if (partitionB == B.size())
                Bright = INT_MAX;
            else
                Bright = B[partitionB];


            
            if (Aleft <= Bright && Bleft <= Aright) {

                
                if (total % 2 == 1) {
                    return std::max(Aleft, Bleft);
                }

                
                else {
                    int leftMax{std::max(Aleft, Bleft)};
                    int rightMin{std::min(Aright, Bright)};

                    return (leftMax + rightMin) / 2.0;
                }
            }

            
            else if (Aleft > Bright) {
                right = partitionA - 1;
            }

            
            else {
                left = partitionA + 1;
            }
        }

        return 0.0;
    }
};