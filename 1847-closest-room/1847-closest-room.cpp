class Solution {
public:
    int bs(int pref,int msize,vector<vector<int>>& arr){
        int l=0,h=arr.size()-1;
        int idx=-1;

        while(l<=h){
            int m=(l+h)/2;

            if(arr[m][1]>=msize){
                idx=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }

        if(idx==-1) return -1;

        int ans=-1;
        int minabs=INT_MAX;

        for(int i=idx;i<arr.size();i++){
            int diff=abs(arr[i][0]-pref);

            if(diff<minabs){
                minabs=diff;
                ans=arr[i][0];
            }
            else if(diff==minabs){
                ans=min(ans,arr[i][0]);
            }
        }

        return ans;
    }

    vector<int> closestRoom(vector<vector<int>>& rooms,vector<vector<int>>& queries){

        sort(rooms.begin(),rooms.end(),
            [](vector<int>& a,vector<int>& b){
                if(a[1]==b[1]){
                    return a[0]<b[0];
                }
                return a[1]<b[1];
            });

        vector<int> ans;

        for(auto q:queries){
            ans.push_back(bs(q[0],q[1],rooms));
        }

        return ans;
    }
};