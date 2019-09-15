#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

#if 0
/*
 * 设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构。
 * insert(val)：当元素 val 不存在时，向集合中插入该项。
 * remove(val)：元素 val 存在时，从集合中移除该项。
 * getRandom：随机返回现有集合中的一项。每个元素应该有相同的概率被返回。
 * */

class RandomizedSet {
private:
  unordered_map<int,int> recond;//val->下标
  vector<int> vec;
public:

  /** Initialize your data structure here. */
  RandomizedSet() {

  }

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    if(recond.count(val))//该元素已插入
      return false;

    recond[val]=vec.size();//vec的大小作为该元素的下标
    vec.push_back(val);//该值添加到数组中
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    if(recond.count(val)==0)//该元素不存在
      return false;
    int temp=vec.back();//获得数组的尾元素
    vec[recond[val]]=temp;//将尾元素填充到即将要删除元素
    recond[temp]=recond[val];//将尾元素的下标替换为即将要删除元素的下标
    vec.pop_back();//删除尾元素元素
    recond.erase(val);//删除在hashmap中val的信息
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    return vec[rand()%(vec.size())];
  }
};

#endif


/**
 *  Your RandomizedSet object will be instantiated and called as such:
 *  RandomizedSet* obj = new RandomizedSet();
 *  bool param_1 = obj->insert(val);
 *  bool param_2 = obj->remove(val);
 *  int param_3 = obj->getRandom();
 *  */

int main() {
  return 0;
}
