class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::stack<double> carFleet;

        int n{static_cast<int>(speed.size())};
        std::vector<std::pair<int, int>> positionSpeed;

        for (int i{0}; i < n; i++) {
            positionSpeed.push_back({position[i], speed[i]});
        }

        std::sort(positionSpeed.begin(), positionSpeed.end(), std::greater<>{});

        for (auto i : positionSpeed) {
            double time{
                static_cast<double>(target - i.first) / i.second
            };

            if (carFleet.empty() || time > carFleet.top()) {
                carFleet.push(time); 
            }
        }

        return carFleet.size();
    }
};