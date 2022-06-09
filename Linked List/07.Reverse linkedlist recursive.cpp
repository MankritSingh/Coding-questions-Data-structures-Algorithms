/*Question:https://leetcode.com/problems/reverse-linked-list/submissions/
*/
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head; //base condition.If empty list then return Head,if its just one node
      //then it points to itself,and when we reach the last node eg 1->2->3 we reach 3, we will return head and head=2 in that case
        ListNode* temp=reverseList(head->next);//with this we keep on going ahead in linked list till last node is reached
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
};
