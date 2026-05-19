class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        q.push({beginWord,1});

        while(!q.empty()){
            string s = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(s==endWord) return steps;
            for(int i=0;i<s.size();i++){
                char c = s[i];
                for(char ch = 'a';ch<='z';ch++){
                    s[i]=ch;
                    if(st.find(s)!=st.end()){
                        st.erase(s);
                        q.push({s,steps+1});
                    }
                }
                s[i]=c;
            }
        }
        return 0;
    }
};