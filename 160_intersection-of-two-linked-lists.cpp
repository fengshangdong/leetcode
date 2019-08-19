#include<cstdio>

using namespace std;

 /* Definition for singly-linked list. */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int a_len = listLength(headA);
    int b_len = listLength(headB);

    if (a_len > b_len) {
      int diff = a_len - b_len;
      while (diff) {
        headA = headA->next;
        diff --;
      }
    }
    else if (b_len > a_len) {
      int diff = b_len - a_len;
      while (diff) {
        headB = headB->next;
        diff --;
      }
    }

    while (headA) {
      if (headA == headB) {
        return headA;
      }

      headA = headA->next;
      headB = headB->next;
    }

    return NULL;
  }

private:
  int listLength(ListNode *head) {
    int length = 0;
    while (head) {
      head = head->next;
      length++;
    }

    return length;
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
  ListNode headA1(1);
  ListNode headA2(2);
  ListNode headB1(4);
  ListNode headB2(5);
  ListNode headB3(6);
  ListNode node1(17);
  ListNode node2(18);
  ListNode node3(19);

  /* a1, a2, node1, node2, node3 */
  /* b1, b2, b3, node1, node2, node3 */
  headA1.next = &headA2;
  headA2.next = &node1;
  headB1.next = &headB2;
  headB2.next = &headB3;
  headB3.next = &node1;
  node1.next = &node2;
  node2.next = &node3;

  printList(&headA1);
  printList(&headB1);
  Solution solve;
  printf("%d\n", solve.getIntersectionNode(&headA1, &headB1)->val);
}
