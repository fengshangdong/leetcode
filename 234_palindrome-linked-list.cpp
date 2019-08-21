#include <stdio.h>

/* Definition for singly-linked list. */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void printNode(ListNode *head) {
  while(head) {
    printf("%d ", head->val);
    ListNode *next = head->next;
    head = next;
  }
  printf("\n");
}

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    if (!head) return true;

    ListNode *slow = head, *fast = head;
    while (slow && fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *new_head = NULL, *rhead = slow;
    while (rhead) {
      ListNode *next = rhead->next;
      rhead->next = new_head;
      new_head = rhead;
      rhead = next;
    }

    while (head && new_head) {
      if (head->val != new_head->val) return false;
      head = head->next;
      new_head = new_head->next;
    }

    return true;
  }
};

int main() {
  ListNode head(0);
  ListNode node1(1);
  ListNode node2(2);
  ListNode node3(3);
  ListNode node4(2);
  ListNode node5(1);
  ListNode node6(0);

  head.next = &node1;
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  node4.next = &node5;
  node5.next = &node6;

  printNode(&head);
  Solution solv;
  int ret = solv.isPalindrome(&head);
  printf("ret=%d\n",ret);
}
