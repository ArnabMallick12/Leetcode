class Solution {
public:
    int merge(int l,int m,int h,vector<int>& arr){
        int n1 =m-l+1;
        int n2 = h-m;
        int ans=0;
        int i=l;
        int j =m+1;
        while(i<=m && j<=h){
            if(arr[i]>2LL*arr[j]){
                ans+=(m-i)+1;
                j++;
            }
            else{
                i++;
            }
        }
        vector<int> temp;
         i=0;
         j=0;
        while(i<n1 && j<n2){
            if(arr[l+i]<=arr[m+j+1]){
                temp.push_back(arr[l+i]);
                i++;
            }
            else{
                temp.push_back(arr[m+j+1]);
                j++;
            }
        }
        while(i<n1){
            temp.push_back(arr[l+i]);
            i++;
        }
        while(j<n2){
            temp.push_back(arr[m+j+1]);
            j++;
        }
        for(int k=0;k<temp.size();k++){
            arr[l+k] = temp[k];
        }
       
        return ans; 
        
    }
    int mergesort(int l, int h,vector<int>& nums){
        if(l >= h) return 0;
        int m = (l+h)/2;
        long long p1 = mergesort(l,m,nums);
        long long p2 = mergesort(m+1,h,nums);
        long long p3 =  merge(l,m,h,nums);
        return p1+p2+p3;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(0,nums.size()-1,nums);
    }
};