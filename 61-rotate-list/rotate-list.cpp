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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        
        // Step 1: Find length and tail
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        
        // Step 2: Effective rotation
        k %= len;
        if (k == 0) return head;
        
        // Step 3: Two pointers with gap k
        ListNode* slow = head;
        ListNode* fast = head;
        
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Step 4: Rotate
        ListNode* newHead = slow->next;
        slow->next = nullptr;
        tail->next = head;
        
        return newHead;
    }
};