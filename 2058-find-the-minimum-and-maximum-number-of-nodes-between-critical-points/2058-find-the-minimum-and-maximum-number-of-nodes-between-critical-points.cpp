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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;
        ListNode* p = head;
        ListNode* c = head->next;
        int i = 1;
        
        while (c->next) {
            if ((c->val > p->val && c->val > c->next->val) || (c->val < p->val && c->val < c->next->val)) {
                v.push_back(i);
            }
            p = c;
            c = c->next;
            i++;
        }
        
        int s = v.size();
        if (s < 2) {
            return {-1, -1};
        }
        
        int mn = INT_MAX;
        int mx = v[s - 1] - v[0];
        
        for (int j = 1; j < s; j++) {
            int d = v[j] - v[j - 1];
            if (d < mn) {
                mn = d;
            }
        }
        
        return {mn, mx};
    }
};