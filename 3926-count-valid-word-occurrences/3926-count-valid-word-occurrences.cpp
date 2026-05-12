class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s="";
        for(auto i : chunks){
            s +=i;
        }
        unordered_map<string,int> mp;
        string temp="";
        // cout<<s<<endl;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z'){
                temp+=s[i];
                // cout<<s[i];
            }
            else if(s[i]=='-' && (i>0 && i<s.size() && (s[i-1]>='a' && s[i-1]<='z') && (s[i+1]>='a' && s[i+1]<='z'))){
                temp+=s[i];
                // cout<<s[i];
            }
            else{
                mp[temp]++;
                // cout<<" ";
                // cout<<temp<<" ";
                temp="";
            }
        }
        mp[temp]++;
        vector<int> ans;
        for(auto i : queries){
            if(mp.find(i)!=mp.end()){
                ans.push_back(mp[i]);
            }
            else{
                ans.push_back(0);
            }
        }
        return ans;
    }
};