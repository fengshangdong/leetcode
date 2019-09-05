#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#if 0
  给定一个嵌套的整型列表。设计一个迭代器，使其能够遍历这个整型列表中的所有整数。
  列表中的项或者为一个整数，或者是另一个列表。
/**
 *  // This is the interface that allows for creating nested lists.
 *  // You should not implement it, or speculate about its implementation
 *  class NestedInteger {
 *    public:
 *      // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *      bool isInteger() const;
 *      
 *      // Return the single integer that this NestedInteger holds, if it holds a single integer
 *      // The result is undefined if this NestedInteger holds a nested list
 *      int getInteger() const;
 *      
 *      // Return the nested list that this NestedInteger holds, if it holds a nested list
 *      // The result is undefined if this NestedInteger holds a single integer
 *      const vector<NestedInteger> &getList() const;
 *  };
 */

class NestedIterator { //看懂题意即可（其实就是列表的嵌套用深搜就行了）
public:
  vector<int> v;
  int index = 0;
  NestedIterator(vector<NestedInteger>& nestedList) {
    dfs(nestedList);
  }     

  int next() { 
    return v[index++];
  }     

  bool hasNext() { 
    if (index==v.size())
      return false;
    else
      return true;
  }     

  void dfs(vector<NestedInteger>& nestedList) {
    for (int i = 0; i < nestedList.size(); i++) {
      if (nestedList[i].isInteger())
        v.push_back(nestedList[i].getInteger());
      else
        dfs(nestedList[i].getList());
    }               
  }     
};

#endif

int main()
{
  return 0;
}
