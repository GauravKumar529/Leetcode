
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) freq[ch]++;

        vector<pair<char, int>> vec;
        for (auto &p : freq) vec.push_back({p.first, p.second});

        sort(vec.begin(), vec.end(), [](pair<char, int> &a, pair<char, int> &b) {
            return a.second > b.second;
        });

        string res = "";
        for (auto &p : vec) {
            res += string(p.second, p.first);
        }
        return res;
    }
};
