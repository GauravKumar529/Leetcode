
class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        string res = "";
        
        for (char it : s) {
            if (it != ' ') {
                temp.push_back(it);
            } else {
                if (!temp.empty()) {
                    if (!res.empty()) res = temp + " " + res; // prepend with space
                    else res = temp;
                    temp = "";
                }
            }
        }

        // Handle the last word if any
        if (!temp.empty()) {
            if (!res.empty()) res = temp + " " + res;
            else res = temp;
        }

        return res;
    }
};
