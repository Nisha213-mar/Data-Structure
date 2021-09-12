<h1>1.Add Two Numbers in Linked List</h1>
<h2>Question Link</h2>
<h3>https://leetcode.com/problems/add-two-numbers/</h3>
<h2>See my Code here</h2>

```cp/**
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int sum=0;
        ListNode *l3=NULL;
        ListNode **node=&l3;
        while(l1!=0||l2!=0||sum>0){
            if(l1!=0){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=0){
                sum+=l2->val;
                l2=l2->next;
            }
            (*node)=new ListNode(sum%10);
            sum/=10;
            node=&((*node)->next);
        }
        return l3;
    }
};

```
