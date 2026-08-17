class TimeMap {

    std::unordered_map<
        std::string,
        std::vector<std::pair<int, std::string>>
    > Timemap;

public:

    TimeMap() {
    }

    void set(std::string key, std::string value, int timestamp) {
        Timemap[key].push_back({timestamp, value});
    }

    std::string get(std::string key, int timestamp) {

        if (Timemap.find(key) == Timemap.end())
            return "";

        
        std::vector<std::pair<int, std::string>>& values = Timemap[key];

        int left{0};
        int right{static_cast<int>(values.size()) - 1};

        std::string result{""};

        
        while (left <= right) {

            int mid{(left + right) / 2};

            if (values[mid].first <= timestamp) {

                result = values[mid].second;
                left = mid + 1;

            }
            else {

                
                right = mid - 1;
            }
        }

        return result;
    }
};