#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0, j = 0;
    vector<int> temp;
    while (i < m || j < n) {
      if (i >= m) {
        while (j < n) {
          temp.push_back(nums2[j]);
          j++;
        }
        continue;
      }
      else if (j >= n) {
        while (i < m) {
          temp.push_back(nums1[i]);
          i++;
        }
        continue;
      }

      if (nums1[i] < nums2[j])
        temp.push_back(nums1[i++]);
      else 
        temp.push_back(nums2[j++]);
    }
    nums1 = temp;
  }
};

int main()
{
  vector<int> v1,v2;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  v1.push_back(4);
  v2.push_back(0);
  v2.push_back(2);
  v2.push_back(3);
  v2.push_back(4);
  v2.push_back(5);
  Solution solv;
  solv.merge(v1,4,v2,5);
  for (int i = 0; i < v2.size(); i++)
    cout<<v1[i]<<" ";
  cout<<endl;
}
