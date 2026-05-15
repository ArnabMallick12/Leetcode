class Solution {
public:

    ListNode* kthnode(ListNode* node, int k) {
        while (node && k > 0) {
            node = node->next;
            k--;
        }
        return node;
    }

    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || k == 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *temp = head;
        ListNode *gprev = dummy;

        while (temp) {

            ListNode* kth = temp;
            for (int i = 1; i < k && kth; i++) {
                kth = kth->next;
            }

            if (!kth) break;

            ListNode* gnext = kth->next;

            kth->next = nullptr;

            ListNode* newHead = reverse(temp);

            gprev->next = newHead;

            temp->next = gnext;

            gprev = temp;

            temp = gnext;
        }

        return dummy->next;
    }
};