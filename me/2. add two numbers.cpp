/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x = 0;
    	ListNode *a = new ListNode((l1->val+l2->val+x)%10);
    	x = (l1->val+l2->val+x)/10;
    	ListNode *head = a;
        while(l1->next&&l2->next){
    		l1 = l1->next;
    		l2 = l2->next;
           	a->next = new ListNode((l1->val+l2->val+x)%10);
    		a = a->next;
    		x = (l1->val+l2->val+x)/10;
		}
		while(l1->next){
			l1 = l1->next;
			a->next = new ListNode((l1->val + x)%10);
            a = a->next;
			x = (l1->val+x)/10;
		}
		while(l2->next){
			l2 = l2->next;
		    a->next = new ListNode((l2->val + x)%10);
			a = a->next;
			x = (l2->val+x)/10;
		}
		if(!l1->next&&!l2->next){
		    if(x == 1) {
		        a->next = new ListNode(1);
		        a = a->next;
		    }
		}
		return head;
    }
};