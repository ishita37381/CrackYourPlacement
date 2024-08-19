class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> frequencies;
        for (char task : tasks) {
            frequencies[task]++;
        }
        vector<int> sortedFrequencies;
        for (auto& pair : frequencies) {
            sortedFrequencies.push_back(pair.second);
        }
        sort(sortedFrequencies.begin(), sortedFrequencies.end());
        int maxFreq = sortedFrequencies.back();
        sortedFrequencies.pop_back();
        int idleTime = (maxFreq - 1) * n;
        while (!sortedFrequencies.empty() && idleTime > 0) {
            idleTime -= min(maxFreq - 1, sortedFrequencies.back());
            sortedFrequencies.pop_back();
        }

        idleTime = max(0, idleTime);

        return tasks.size() + idleTime;
    }
};
