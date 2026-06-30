class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        vector<int> freq(37);   // 0...36 is enough for n <= 9999
        int mx = 0;

        for (int i = 1; i <= n; i++) {
            int s = digitSum(i);
            freq[s]++;
            mx = max(mx, freq[s]);
        }

        int ans = 0;
        for (int x : freq) {
            if (x == mx)
                ans++;
        }

        return ans;
    }
};