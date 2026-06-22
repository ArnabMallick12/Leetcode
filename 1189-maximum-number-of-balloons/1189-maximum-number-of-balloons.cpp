class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> freq;
        for(char ch :text){
            if(ch == 'b' || ch == 'a' || ch == 'l' || ch == 'o' || ch == 'n'){
                freq[ch]++;
            }
        }
        return min({freq['b'],freq['a'],freq['l']/2,freq['o']/2,freq['n']});
    }
};