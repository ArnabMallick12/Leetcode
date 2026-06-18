class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> freq;
            unordered_map<int,int> cntfreq;
            for(int j=i;j<n;j++){
                int oldfreq = freq[nums[j]];
                if(oldfreq>0){
                    cntfreq[oldfreq]--;
                    if(cntfreq[oldfreq]==0) cntfreq.erase(oldfreq);
                }
                freq[nums[j]]++;
                cntfreq[freq[nums[j]]]++;
                if(freq.size()==1){
                    ans = max(ans,j-i+1);
                    continue;
                }
                 
                if(cntfreq.size()==2){
                    auto it = cntfreq.begin();
                    int f1 = it->first;
                    it++;
                    int f2 = it->first;
                    if(f1 == 2*f2 || f2 == 2*f1){
                        ans = max(ans,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};