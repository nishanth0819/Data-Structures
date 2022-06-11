/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []*/


//CODE:
 struct compare
    {
        bool operator()(const ListNode* l,const ListNode* m){
        
            return l->val>m->val;
    }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        for(auto head:lists)
        {
            if(head)
                pq.push(head);
        }
        ListNode * newnode=new ListNode(0);
        ListNode* tail=newnode;
        if(pq.empty()==true)
            return NULL;
        while(pq.empty()==false)
        {
            ListNode *nextnode=pq.top();
            tail->next=nextnode;
            tail=tail->next;
            pq.pop();
            if(nextnode->next)
                pq.push(nextnode->next);
        }
        return newnode->next;
    }
