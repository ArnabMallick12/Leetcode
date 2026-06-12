class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int gind =0;
        int sind=0;
        while(gind<g.size() && sind<s.size()){
            if(s[sind]>=g[gind]){
                gind++;
            }
            sind++;
        }
        return gind;
    }
};