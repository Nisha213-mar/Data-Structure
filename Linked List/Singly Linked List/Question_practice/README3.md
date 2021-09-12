<h1>3. Merge k Sorted Lists</h1>
<h2>Question Link</h2>
</h3>https://leetcode.com/problems/merge-k-sorted-lists/</h3>
<h2>solution</h2>

```
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
    ListNode* merge(vector<ListNode*>& lists,int left,int right) {
        if(left==right)
            return lists[left];
        int k=right-left+1;
        ListNode *head,*h1,*h2,*ptr;
        head=h1=h2=NULL;
        h1=merge(lists,left,left+k/2-1);
        h2=merge(lists,left+k/2,right);
        if(!h1 && !h2)
            return head;
        else if(!h1)
            return h2;
        else if(!h2)
            return h1;
        if(!h1 or (h1 and h1->val>h2->val)){
            head=h2;h2=h2->next;
        }
        else{
            head=h1;h1=h1->next;
        }
        ptr=head;
        while(h1 ||h2){
            if(!h1){
                ptr->next=h2;h2=h2->next;ptr=ptr->next;
            }
            else if(!h2){
                ptr->next=h1;h1=h1->next;ptr=ptr->next;
            }
            else if(h1->val<h2->val){
                ptr->next=h1;h1=h1->next;ptr=ptr->next;
            }
            else{
                ptr->next=h2;h2=h2->next;ptr=ptr->next;
            }
            return head;
};
```