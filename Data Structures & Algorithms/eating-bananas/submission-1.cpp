class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile{*std::max_element(piles.begin(), piles.end())};

        int lptr{1};
        int rptr{maxPile};

        int result{maxPile};

        while (lptr <= rptr) {
            int k{(lptr + rptr) / 2};
            long long hours{0};

            for (int i{0}; i < piles.size(); i++) {
                hours += std::ceil(static_cast<double>(piles[i]) / k);
            }

            if (hours <= h) {
                rptr = k - 1;
                result = k;
            }
            else {
                lptr = k + 1;
            }
        }

        return result;
    }
};