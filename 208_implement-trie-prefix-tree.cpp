#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

struct Node {
  int num;
  bool isword;
  Node* child[26];
  Node() :isword(false){
    num = 0;
    for(int i = 0;i < 26;i++){
      child[i] = NULL;
    }
  }
};

class Trie {
public:
  /** Initialize your data structure here. */
  Trie() {
    root =  new Node();
  }

  ~Trie() {
    destroy(root);
    root = NULL;
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    if(word == "") return;
    Node* p = root;
    for(int i = 0; i < word.size(); ++i){
      if(p->child[word[i]-'a'] == NULL){
        Node *node = new Node();
        p->child[word[i]-'a'] = new Node();
      }
      p = p->child[word[i]-'a'];
    }

    p->isword = true;
    root->num++;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    if("" == word || NULL == root)
      return false;

    Node* temp = root;
    for(int i = 0; i<word.size(); ++i)
      if(NULL == temp->child[word[i]-'a'])
        return false;
      else
        temp = temp->child[word[i]-'a'];

    if(temp->isword)
      return true;
    else
      return false;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    if("" == prefix || NULL == root) return false;
    Node* temp = root;
    for(int i = 0;i < prefix.size();i++)
      if (temp->child[prefix[i] - 'a'] == NULL)
        return false;
      else 
        temp = temp->child[prefix[i]-'a'];

    return true;
  }

  int wordCount() {
    return root->num;
  }

private:
  void destroy(Node *root) {
    if (!root)
      return;

    for(int i = 0;i < 26;i++)
      destroy(root->child[i]);

    printf(" * ");
    delete root;
  }

private:
  Node* root;
};

int main() {
  string word1 = "hello";
  string word2 = "helloworld";
  string word3 = "hello-world";

  Trie* obj = new Trie();
  obj->insert(word1);
  obj->insert(word2);
  obj->insert(word3);
  int ret = obj->wordCount();
  printf("count=%d\n",ret);
  bool param_2 = obj->search("hell");
  bool param_3 = obj->startsWith("hell");
  printf("param_2=%d\nparam_3=%d\n",param_2,param_3);
  delete obj;
  printf("\n");
  return 0;
}
