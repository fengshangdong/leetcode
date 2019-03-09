#include<cstdio>

/* Definition for singly-linked list. */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *s1 = head;
    ListNode *s2 = head;
    ListNode *meet = NULL;
    /* 保存第一次相遇的结点meet,此时不是环的入口 */
    /* s1的路线 m + x, s2的路线 m + x + s0, 其中s0是环长度 */
    /* 2*(m+x) = m+x+s0 得 s0 = m+x */
    /* 所以s2只要再走m步,就到了环的入口处 */
    while (s1 && s2 && s2->next) {
      s1 = s1->next;
      s2 = s2->next->next;

      if (s1 == s2) {
        meet = s1;
        break;
      }
    }

    /* 同时从头结点和meet出发,一定会在环入口处相遇 */
    while (head && meet) {
      if (head == meet) {
        return meet;
      }

      head = head->next;
      meet = meet->next;
    }

    return NULL;
  }
};

void printList(ListNode *head, int length) {
  while(head && length) {
    printf("%d ",head->val);
    head = head->next;
    length--;
  }
  printf("\n");
}

int main() 
{
  ListNode node(3);
  ListNode node1(2);
  ListNode node2(0);
  ListNode node3(-4);

  /* 2, 3, 4, 5, 6, 7, 5 ... */
  node.next = &node1;
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node;

  int length = 20;
  printList(&node, length);
  Solution solve;
  printf("%d\n", solve.detectCycle(&node)->val);
}
