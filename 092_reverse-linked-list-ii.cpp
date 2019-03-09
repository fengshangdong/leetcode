#include<vector>
#include<cstdio>
#include<cstdlib>

using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    /* 额外插入一个头结点,便于取前置结点prev */
    ListNode res(0);
    ListNode *res_ptr = &res;
    res_ptr->next = head;

    /* prev为m位置的前置结点 */
    ListNode *prev = NULL;
    for (int i = 0; i < m; i++) {
      prev = res_ptr;
      res_ptr = res_ptr->next;
    }
    /* new_head是m..n的逆置后的头 */
    /* new_tail是m..n的逆置后的尾 */
    ListNode *new_tail = res_ptr;
    ListNode *new_head = NULL;
    for (int j = m; j <= n; j++) {
      ListNode *next = res_ptr->next;
      res_ptr->next = new_head;
      new_head = res_ptr;
      res_ptr = next;
    }

    /* 连接前,中,后三个部分的链表  */
    /* 此时的head是n位置的后置结点 */
    prev->next = new_head;
    new_tail->next = res_ptr;

    return res.next;        
  }
};

void printList(ListNode *head) {
  while(head) {
    printf("%d ", head->val);
    ListNode *next = head->next;
    head = next;
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
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  node4.next = &node5;
  printList(&node1);

  Solution solve;
  ListNode *NewList = solve.reverseBetween(&node1, 2, 4);
  printList(NewList);
}
