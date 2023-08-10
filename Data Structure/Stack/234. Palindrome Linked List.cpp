/*
    Given the head of a singly linked list, return true if it is a
    palindrome or false otherwise.


    Example 1:


    Input: head = [1,2,2,1]
    Output: true

    Example 2:


    Input: head = [1,2]
    Output: false


    Constraints:

    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9


    Follow up: Could you do it in O(n) time and O(1) space?
*/

#include <iostream>
#include <stack>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* secondHalfHead = findSecondHalfOfList(head);
        // ListNode* reversedSecondHalfHead = reverseList(secondHalfHead);

        // // Compare value of List head & List reversedSecondHalfHead.
        // while (reversedSecondHalfHead) {
        //     if (head->val != reversedSecondHalfHead->val) {
        //         return false;
        //     }
        //     head = head->next;
        //     reversedSecondHalfHead = reversedSecondHalfHead->next;
        // }

        std::stack<ListNode*> st;
        while (secondHalfHead) {
            st.push(secondHalfHead);
            secondHalfHead = secondHalfHead->next;
        }
        while (!st.empty()) {
            if (st.top()->val != head->val) {
                return false;
            }
            st.pop();
            head = head->next;
        }

        return true;
    }

    ListNode* findSecondHalfOfList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->next;
    }

    // ListNode* reverseList(ListNode* head) {
    //     ListNode* pre = nullptr;
    //     ListNode* cur = head;
    //     while (cur) {
    //         ListNode* tmp = cur->next;
    //         cur->next = pre;
    //         pre = cur;
    //         cur = tmp;
    //     }
    //     return pre;
    // }
};

// TC: O(n)
// SC: O(n)
