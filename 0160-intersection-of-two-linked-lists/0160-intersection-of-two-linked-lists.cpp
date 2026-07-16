class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int len1 = 0, len2 = 0;

        ListNode* dummy1 = headA;
        ListNode* dummy2 = headB;

        while(dummy1){
            len1++;
            dummy1 = dummy1->next;
        }

        while(dummy2){
            len2++;
            dummy2 = dummy2->next;
        }

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        int diff = abs(len1 - len2);

        if(len1 > len2){
            while(diff--){
                temp1 = temp1->next;
            }
        }
        else{
            while(diff--){
                temp2 = temp2->next;
            }
        }

        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return temp1;   
    }
};