class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int boat = 0;
        int sum = 0;
        int i = 0;
        int j = n - 1;

        sort(people.begin() , people.end());
        while(i <=j) {
            sum = people[i] + people[j];
            if(sum <=limit) {
                i++;
            }
            boat++;
            j--;
        }

        return boat ;
        
    }
};