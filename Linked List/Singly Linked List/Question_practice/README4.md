<h1>5. Swap Nodes in Pairs</h1>
<h2>Question Link</h2>
<h3>https://leetcode.com/problems/swap-nodes-in-pairs/</h3>
<h2>Solution</h2>

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
class Solution{
    public:
 ListNode* swapPairs(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
                return head;
        
        ListNode *temp = head->next->next;
        ListNode *HEAD = head->next;
        head->next->next = head;
        head->next = swapPairs(temp);
        
        return HEAD;
        
 }
};
```