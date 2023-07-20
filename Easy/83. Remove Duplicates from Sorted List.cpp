/*
    Given the head of a sorted linked list, delete all duplicates such that each
    element appears only once. Return the linked list sorted as well.  

    Example 1:

    Input: head = [1,1,2]
    Output: [1,2]

    Example 2:

    Input: head = [1,1,2,3,3]
    Output: [1,2,3]
     

    Constraints:

    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.
*/

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void deleteNextNode(ListNode* node) {
        ListNode* nextNode = node->next;
        node->next = nextNode->next;
        delete nextNode;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while (cur && cur->next) {
            while (cur->next && cur->next->val == cur->val) {
                deleteNextNode(cur);
            }
            if (cur->next) {
                cur = cur->next;
            }
        }

        return head;
    }
};

// TC: O(n)
// SC: O(1)
