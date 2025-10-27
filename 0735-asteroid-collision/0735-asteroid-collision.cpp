class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int a : asteroids) {
            bool destroyed = false;

            // only collide if current asteroid is moving left and top is moving right
            while (!st.empty() && st.back() > 0 && a < 0) {
                if (st.back() < -a) {
                    st.pop_back(); // top asteroid destroyed
                    continue;
                } else if (st.back() == -a) {
                    st.pop_back(); // both destroyed
                }
                destroyed = true;
                break;
            }

            if (!destroyed) st.push_back(a);
        }
        return st;
    }
};
