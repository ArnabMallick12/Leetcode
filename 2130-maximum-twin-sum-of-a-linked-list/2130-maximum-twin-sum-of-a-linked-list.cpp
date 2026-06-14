/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> v;
        ListNode* slow = head, *fast = head;
        if(fast->next->next==nullptr) return slow->val + slow->next->val;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            v.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        v.push_back(slow->val);
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<"-";
        // }
        cout<<endl;
        // cout<<slow->val;
        slow = slow->next;
        for(int i = v.size()-1;i>=0;i--){
            // cout<<v[i]<<" "<<slow->val<<endl;
            v[i] += slow->val;
            slow = slow->next;
        }
        return *max_element(v.begin(),v.end());
    }
};