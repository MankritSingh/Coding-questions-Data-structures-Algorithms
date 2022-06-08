/*Question link:https://leetcode.com/problems/reverse-linked-list/submissions/
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
        ListNode* prev=head;
        if(prev==NULL){
            return head;
        }
        ListNode* curr=head->next;
        while(curr!=NULL){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        head->next=NULL;
        return prev;
    }
};
