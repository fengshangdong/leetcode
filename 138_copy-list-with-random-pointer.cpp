#include <vector>
#include <string>
#include <algorithm>

class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node() {}

  Node(int _val, Node* _next, Node* _random) {
    val = _val;
    next = _next;
    random = _random;
  }
};

class Solution {
public:
  Node* copyRandomList(Node* head) {
    if (!head)
      return NULL;
    Node* cur = head;
    while (cur) {
      Node* tmp = new Node(cur->val,NULL,NULL);
      tmp->next = cur->next;
      cur->next = tmp;
      cur = cur->next->next;
    }

    cur = head;
    while (cur) {
      if (cur->random)
        cur->next->random = cur->random->next;
      cur = cur->next->next;
    }

    cur = head;
    Node* newhead = head->next;
    while (cur) {
      Node* t = cur->next;
      cur->next = t->next;
      cur = cur->next;
      if (cur)
        t->next = cur->next;
    }
    return newhead;
  }
};

int main() {
  return 0;
}
