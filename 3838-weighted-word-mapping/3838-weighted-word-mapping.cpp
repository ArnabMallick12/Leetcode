class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;

        for(auto &s : words){
            int wsum = 0;

            for(char c : s){
                wsum += weights[c - 'a'];
            }

            int rem = wsum % 26;
            ans.push_back('z' - rem);
        }

        return ans;
    }
};