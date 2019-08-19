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
    if (!head->next) return true;

    int len = listLen(head);
    int half = (len+1)/2;
    ListNode* halfHead = head;
    while (half) {
      halfHead = halfHead->next;
      half--;
    }

    ListNode* rhalfHead = reverse(halfHead);
    while (rhalfHead) {
      if (head->val != rhalfHead->val) return false;
      head = head->next;
      rhalfHead = rhalfHead->next;
    }

    return true;
  }

  ListNode* reverse(ListNode* head) {
    ListNode* newHead = NULL;
    while (head) {
      ListNode* next = head->next;
      head->next = newHead;
      newHead = head;
      head = next;
    }
    return newHead;
  }

  int listLen(ListNode* head) {
    int len = 0;
    while (head) {
      len++;
      head = head->next;
    }
    return len;
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
