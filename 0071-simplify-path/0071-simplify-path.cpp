class Solution {
public:
//  strign stram function will specify that if , s[i] == delimeter->> make sure check bw this ->> its not a function which break strgin acc to delimter 
// stringstream tokenise(string path){
//     int n = path.size();
    // string token = "";                       // dont use like this 
//     for(int i = 0; i < n;i++){

//     }
// }
    string simplifyPath(string path) {
        int n  = path.size();
        string token = "";
        vector<string> res ;
        stringstream ss(path);
        while(getline(ss, token , '/')){ //work is stringstream iterate in oath taking path into the token as internally , -> which neglexct / and check something bw two/   /***/ check ***as below 
            if(token == "."|| token == "" ) continue ;
            if(token != "..") {
                res.push_back(token);
            } else if(!res.empty()) res.pop_back();
        }
        if(res.empty()) return "/";
        string finalRes = "";
        for(auto it: res){
            finalRes = finalRes+"/" +it;
        }
        return finalRes;
    }
};