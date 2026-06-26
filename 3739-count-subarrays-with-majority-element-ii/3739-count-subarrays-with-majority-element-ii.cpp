class Fenwick {
public:
    vector<int> bit;
    int n;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        Fenwick ft(2 * n + 5);
        int offset = n + 1;

        long long ans = 0;
        int pref = 0;

        // Empty prefix sum = 0
        ft.update(offset + 1, 1);

        for (int x : nums) {
            if (x == target)
                pref++;
            else
                pref--;

            // Count previous prefix sums strictly smaller than current
            ans += ft.query(pref + offset);

            // Insert current prefix
            ft.update(pref + offset + 1, 1);
        }

        return ans;
    }
};