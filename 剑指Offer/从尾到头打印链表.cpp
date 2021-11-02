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
    // 递归
    vector<int> printListReversingly(ListNode* head) {
        if(!head) return {};
        auto res = printListReversingly(head->next);
        res.push_back(head->val);
        return res;
    }
    // 反转
    // vector<int> printListReversingly(ListNode* head) {
    //     if(!head) return {};
    //     vector<int> res;
    //     while(head){
    //         res.push_back(head->val);
    //         head = head->next;
    //     }
        
    //     return vector<int>(rbegin(res), rend(res));
    // }
};