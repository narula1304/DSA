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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode* current = head;

        while(current && current->next){
            ListNode* nextnode = current->next;

            while(nextnode && nextnode->val == current->val){
                ListNode* duplicate = nextnode;
                nextnode = nextnode->next;
                delete duplicate;
            }

            current->next = nextnode;
            

            current = nextnode;
        }

        return head;
    }
};