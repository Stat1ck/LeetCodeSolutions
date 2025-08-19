//You are given two non - empty linked lists representing two non - negative integers.
//The digits are stored in reverse order, and each of their nodes contains a single digit.Add the two numbers and return the sum as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example 1:
//
//Input: l1 = [2, 4, 3], l2 = [5, 6, 4]
//Output: [7, 0, 8]
//Explanation: 342 + 465 = 807.
//
//Example 2:
//
//Input: l1 = [0], l2 = [0]
//Output: [0]
//
//Example 3:
//
//Input: l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
//Output: [8, 9, 9, 9, 0, 0, 0, 1]
//
//Constraints :
//
//The number of nodes in each linked list is in the range[1, 100].
//0 <= Node.val <= 9
//It is guaranteed that the list represents a number that does not have leading zeros.
//
// ************************************************************
//
// Accepted 1569 / 1569 testcases passed
//
// Runtime 0ms
// Beats 100.00%
//
// Memory 76.92MB
// Beats 91.81%
//
// ************************************************************

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = nullptr;
        ListNode* next = nullptr;
        int nextPlus = 0;
        while (true) {
            if (l1 == nullptr && l2 == nullptr && nextPlus == 0) {
                break;
            }

            int sum = (nullptr != l1 ? l1->val : 0) + (nullptr != l2 ? l2->val : 0);

            if (nextPlus > 0) {
                sum += nextPlus;
                nextPlus = 0;
            }

            if (sum > 9) {
                nextPlus += 1;
                sum %= 10;
            }

            l1 = nullptr != l1 ? l1->next : nullptr;
            l2 = nullptr != l2 ? l2->next : nullptr;

            if (nullptr == first) {
                first = new ListNode(sum);
                continue;
            }

            if (nullptr == next) {
                next = new ListNode(sum);
                first->next = next;
                continue;
            }

            next->next = new ListNode(sum);
            next = next->next;
        }

        return first;
    }
};

static ListNode* getNodeTree(int elems[], size_t elemCount) {
    ListNode* first = new ListNode(elems[0]);
    ListNode* prev = nullptr;
    for (int i = 1; i < elemCount; i++) {
        if (nullptr == prev) {
            prev = new ListNode(elems[i]);
            first->next = prev;
            continue;
        }

        prev->next = new ListNode(elems[i]);
        prev = prev->next;
    }

    return first;
}

static void printTree(ListNode* res) {
    while (true) {
        std::cout << res->val << "\t";

        res = res->next;

        if (nullptr == res) {
            std::cout << "\n";
            break;
        }
    }
}

int main_add_two_nambers() {
    Solution solution;
    int l1[3] = { 2, 4, 3 };
    int l2[3] = { 5, 6, 4 };

    ListNode* l1_first = getNodeTree(l1, 3);
    ListNode* l2_first = getNodeTree(l2, 3);

    ListNode* res = solution.addTwoNumbers(l1_first, l2_first);

    printTree(l1_first);
    printTree(l2_first);
    std::cout << "\n";
    std::cout << "Result: " << "\n";
    printTree(res);

    return 0;
}