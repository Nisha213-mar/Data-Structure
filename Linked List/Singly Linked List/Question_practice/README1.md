<h1>2. Remove Nth Node From End of List</h1>
<h2>Question Link</h2>
<h3>https://leetcode.com/problems/remove-nth-node-from-end-of-list/</h3>
<h2>See my Code Here</h2>

```cpp
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
    ListNode* removeNthFromEnd(ListNode* head,int n){
        ListNode* h=head;
        int k,c;
        while(h!=NULL){
            h=h->next;
            c++;
        }
        k=c-n+1;
        h=head;
        if(k==1){
            head=head->next;
            return head;
            }
        while(k>2 && head!=NULL){
            h=h->next;
            k--;
        }
        h->next=h->next->next;
        return head;
    }
};
```