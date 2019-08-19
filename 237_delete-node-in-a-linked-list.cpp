#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/*将next值赋值到删除节点再删除next节点,比较有脑洞*/
class Solution {
public:
  void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next= node->next->next;
  }
};

void printList(ListNode *head) {
  while (head) {
    printf("%d ",head->val);
    head = head->next;
  }
  printf("\n");
}

int main()
{
  ListNode node1(1);
  ListNode node2(2);
  ListNode node3(3);
  ListNode node4(4);
  ListNode node5(5);
  ListNode node6(6);
  ListNode node7(7);
  ListNode node8(8);
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  node4.next = &node5;
  node5.next = &node6;
  node6.next = &node7;
  node7.next = &node8;
  printList(&node1);
  Solution solv;
  solv.deleteNode(&node3);
  printList(&node1);
}
