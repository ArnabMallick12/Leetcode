class Solution {
public:
    int count_digit(int num) {
        int ans = 0;
        while (num != 0) {
            ans += num % 10;
            num /= 10;
        }
        return ans;
    }

    int maximumSum(vector<int>& nums) {
        map<int, pair<int, int>> m;
        int ans = -1;

        for (int num : nums) {
            int digitSum = count_digit(num);
            
            if (m.find(digitSum) != m.end()) {
                int first = m[digitSum].first;
                int second = m[digitSum].second;

                if (num > first) { 
                    second = first;
                    first = num;
                } else if (num > second) { 
                    second = num;
                }

                m[digitSum] = {first, second};

                if (second != -1) { 
                    ans = max(ans, first + second);
                }
            } else {
                m[digitSum] = {num, -1};
            }
        }

        return ans;
    }
};
