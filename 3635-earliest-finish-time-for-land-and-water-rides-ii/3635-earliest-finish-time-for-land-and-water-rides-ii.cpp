class Solution {
public:
    int earliestFinishTime(vector<int>& landStart, vector<int>& landDur,
                           vector<int>& waterStart, vector<int>& waterDur) {
        
        int n = landStart.size();
        int m = waterStart.size();
        
        vector<pair<int,int>> water;
        for(int i=0;i<m;i++){
            water.push_back({waterStart[i], waterDur[i]});
        }
        
        sort(water.begin(), water.end());
        
        vector<int> suffixMin(m), prefixMin(m);
        
        // suffix: min(start + duration)
        suffixMin[m-1] = water[m-1].first + water[m-1].second;
        for(int i=m-2;i>=0;i--){
            suffixMin[i] = min(suffixMin[i+1],
                               water[i].first + water[i].second);
        }
        
        // prefix: min(duration)
        prefixMin[0] = water[0].second;
        for(int i=1;i<m;i++){
            prefixMin[i] = min(prefixMin[i-1],
                               water[i].second);
        }
        
        int ans = INT_MAX;
        
        for(int i=0;i<n;i++){
            int finishLand = landStart[i] + landDur[i];
            
            // binary search
            int l = 0, r = m-1, idx = m;
            while(l <= r){
                int mid = (l+r)/2;
                if(water[mid].first >= finishLand){
                    idx = mid;
                    r = mid-1;
                } else l = mid+1;
            }
            
            // option A: later water
            if(idx < m){
                ans = min(ans, suffixMin[idx]);
            }
            
            // option B: earlier water
            if(idx > 0){
                ans = min(ans, finishLand + prefixMin[idx-1]);
            }
        }
        
        // Repeat for reverse (water → land)
        vector<pair<int,int>> land;
        for(int i=0;i<n;i++){
            land.push_back({landStart[i], landDur[i]});
        }
        
        sort(land.begin(), land.end());
        
        vector<int> sufL(n), preL(n);
        
        sufL[n-1] = land[n-1].first + land[n-1].second;
        for(int i=n-2;i>=0;i--){
            sufL[i] = min(sufL[i+1],
                          land[i].first + land[i].second);
        }
        
        preL[0] = land[0].second;
        for(int i=1;i<n;i++){
            preL[i] = min(preL[i-1],
                          land[i].second);
        }
        
        for(int i=0;i<m;i++){
            int finishWater = waterStart[i] + waterDur[i];
            
            int l = 0, r = n-1, idx = n;
            while(l <= r){
                int mid = (l+r)/2;
                if(land[mid].first >= finishWater){
                    idx = mid;
                    r = mid-1;
                } else l = mid+1;
            }
            
            if(idx < n){
                ans = min(ans, sufL[idx]);
            }
            
            if(idx > 0){
                ans = min(ans, finishWater + preL[idx-1]);
            }
        }
        
        return ans;
    }
};