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
private:
    // Helper function to merge two sorted linked lists using two pointers
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        // Append the remaining nodes from either list
        tail->next = l1 ? l1 : l2;
        
        return dummy.next;
    }

    // Divide and Conquer manager function
    ListNode* divideAndConquer(std::vector<ListNode*>& lists, int start, int end) {
        // Base Case 1: The current range is empty
        if (start > end) return nullptr;
        
        // Base Case 2: Only one list in the range
        if (start == end) return lists[start];
        
        // Calculate the middle point to split the range
        int mid = start + (end - start) / 2;
        
        // Divide: Independently solve left and right segments
        ListNode* leftMerged = divideAndConquer(lists, start, mid);
        ListNode* rightMerged = divideAndConquer(lists, mid + 1, end);
        
        // Conquer: Merge the two sorted results together
        return mergeTwoLists(leftMerged, rightMerged);
    }

public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return divideAndConquer(lists, 0, lists.size() - 1);
    }
};
