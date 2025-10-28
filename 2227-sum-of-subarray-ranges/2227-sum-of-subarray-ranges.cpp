class Solution {
public:

    vector<long long> getLeftGreater(vector<int>& arr, int n) {
        vector<long long> left(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        return left;
    }

    vector<long long> getRightGreater(vector<int>& arr, int n) {
        vector<long long> right(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        return right;
    }

    vector<long long> getLeftSmaller(vector<int>& arr, int n) {
        vector<long long> left(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        return left;
    }

    vector<long long> getRightSmaller(vector<int>& arr, int n) {
        vector<long long> right(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        return right;
    }

    long long sumOfSubarrayMaximums(vector<int>& arr) {
        int n = arr.size();
        vector<long long> left = getLeftGreater(arr, n);
        vector<long long> right = getRightGreater(arr, n);
        long long total = 0;
        for (int i = 0; i < n; i++)
            total += (long long)arr[i] * left[i] * right[i];
        return total;
    }

    long long sumOfSubarrayMinimums(vector<int>& arr) {
        int n = arr.size();
        vector<long long> left = getLeftSmaller(arr, n);
        vector<long long> right = getRightSmaller(arr, n);
        long long total = 0;
        for (int i = 0; i < n; i++)
            total += (long long)arr[i] * left[i] * right[i];
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumOfSubarrayMaximums(nums) - sumOfSubarrayMinimums(nums);
    }
};