class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
       // if(n == 1) return {0, 0 };
        int i = 0;
        int j = n - 1;
        while(i < j) {
            if(numbers[i ] + numbers[j] == target ) return {i+1 , j+1};
            else if(numbers[i] + numbers[j] >  target) j--;
            else i++;
        }
        return {0, 0};
        
    }
};