class Solution {
public:// this is a problem that i .ll be dine 
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            vector<int > v(26 , 0);
            int dif  = 0;
            for(int j = i;j<n;j++) {
               v[s[j] - 'a']++;
               int maxi = INT_MIN;
               int mini = INT_MAX;
               for(auto it: v){
                 if(it > 0) {
                    mini = min(it, mini);
                    maxi = max(maxi , it);

                 }
               }
               
               dif = maxi - mini;
               if(dif >0) sum += dif;

            }
        }
        return sum;
        
    }
};
// leme tell u my intuion -> firstly  generate alll the substring and then count for max and amin freq of character int that substring if  diff .> 0 , y will add it to sum and at last return the sum to get the answer 