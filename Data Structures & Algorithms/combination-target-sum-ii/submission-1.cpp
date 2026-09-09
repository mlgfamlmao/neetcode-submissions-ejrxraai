class Solution {
    void dfsBacktracker(std::vector<int>& candidates, int target,
                         std::vector<std::vector<int>>& results,
                         std::vector<int>& current, int currentSum, int index) {

        if (currentSum == target) {
            results.push_back(current);
            return;
        }

        if (currentSum > target || index == candidates.size()) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (currentSum + candidates[i] > target) break;

            current.push_back(candidates[i]);
            dfsBacktracker(candidates, target, results, current, currentSum + candidates[i], i + 1);
            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> results;
        std::vector<int> current;

        dfsBacktracker(candidates, target, results, current, 0, 0);

        return results;
    }
};