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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr) 
            return {-1, -1};

        ListNode* temp = head->next;
        ListNode* prev = head;
        ListNode* next = temp->next;

        int prevind = -1;
        int ind = 1;
        int firstind = -1;

        int mindist = INT_MAX;
        int maxdist = -1;

        while (next != nullptr) {

            // Check whether temp is a critical point
            if ((temp->val > prev->val && temp->val > next->val) ||
                (temp->val < prev->val && temp->val < next->val)) {

                // First critical point
                if (firstind == -1) {
                    firstind = ind;
                }

                // If this is not the first critical point
                if (prevind != -1) {
                    mindist = min(mindist, ind - prevind);
                }

                // Current critical point becomes previous critical point
                prevind = ind;
            }

            ind++;
            prev = temp;
            temp = temp->next;
            next = temp->next;
        }

        // Need at least two critical points
        if (prevind == firstind || firstind == -1) {
            return {-1, -1};
        }

        maxdist = prevind - firstind;

        return {mindist, maxdist};
    }
};