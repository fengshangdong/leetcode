#include<cstdio>

/* Definition for singly-linked list. */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* s1, ListNode* s2) {
    /* 取新头结点head构造新链表 */
    ListNode head(0);
    ListNode *head_ptr = &head;
    /*取s1和s2所有结点*/
    while (s1 || s2) {
      /* 当s1搜索完成且s2有剩余,将s2中剩余的结点插入新链表中*/
      /* 当s2搜索完成且s1有剩余,则将s1中剩余的结点插入新链表中*/
      if (!s1) {
        while (s2) {
          head_ptr->next = s2;
          head_ptr = s2;
          s2 = s2->next;
        }
        continue;
      }
      else if (!s2) {
        while (s1) {
          head_ptr->next = s1;
          head_ptr = s1;
          s1 = s1->next;
        }
        continue;
      }

      /*比较s1和s2中,结点值大小,较小优先插入新链表中*/
      if (s1->val < s2->val) {
        head_ptr->next = s1;
        head_ptr = s1;
        s1 = s1->next;
      }
      else
      {
        head_ptr->next = s2;
        head_ptr = s2;
        s2 = s2->next;
      }
    }

    return head.next;
  }
};

void printList(ListNode *head) {
  while (head) {
    printf("%d ", head->val);
    head = head->next;
  }
  printf("\n");
}

int main()
{
  ListNode node1(1);
  ListNode node2(2);
  ListNode node3(4);
  ListNode node4(1);
  ListNode node5(3);
  ListNode node6(4);
  node1.next = &node2;
  node2.next = &node3;
  node4.next = &node5;
  node5.next = &node6;

  printList(&node1);
  printList(&node4);
  Solution solve;
  printList(solve.mergeTwoLists(&node1, &node4));
}
