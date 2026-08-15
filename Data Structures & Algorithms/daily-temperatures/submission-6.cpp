class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n {static_cast<int> (temperatures.size())};

        std::vector<int> result(n, 0);
        std::stack<std::pair<int, int>> monotonicDecreasingStk;

        for (int i = 0; i < n; i++) {

            while (!monotonicDecreasingStk.empty() &&
                   temperatures[i] > monotonicDecreasingStk.top().first) {

                int previousIndex {monotonicDecreasingStk.top().second};

                result[previousIndex] = static_cast<int> (i - previousIndex);

                monotonicDecreasingStk.pop();
            }

            monotonicDecreasingStk.push({temperatures[i], i});
        }

        return result;
    }
};