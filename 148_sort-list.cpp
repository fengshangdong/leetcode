#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode *fast = head, *slow = head, *pre = head;
    while (fast && fast->next) {
      pre = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    pre->next = NULL;
    return merge(sortList(head), sortList(slow));
  }

  ListNode* merge(ListNode* left, ListNode* right) {
    if (!left) return right;
    if (!right) return left;

    ListNode head(-1);
    ListNode *pre = &head;
    while (left && right) {
      if (left->val < right->val) {
        pre->next = left;
        left = left->next;
        pre = pre->next;
      }
      else {
        pre->next = right;
        right = right->next;
        pre = pre->next;
      }
    }

    if (!left) pre->next = right;
    if (!right) pre->next = left;
    return head.next;
  }
};

void printList(ListNode* p) {
  while (p) {
    printf("%d ",p->val);
    p = p->next;
  }
  printf("\n");
}

int main() {
  ListNode head(4);
  ListNode node1(3);
  ListNode node2(2);
  ListNode node3(5);
  ListNode node4(1);
  ListNode node5(6);
  ListNode node6(0);

  head.next = &node1;
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  node4.next = &node5;
  node5.next = &node6;

  printList(&head);
  Solution solv;
  ListNode* p = solv.sortList(&head);
  printList(p);
}
