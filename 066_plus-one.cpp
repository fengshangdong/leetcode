#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    if (digits.empty()) return digits;

    for (int i = digits.size()-1; i >= 0; i--) {
      if (digits[i] != 9) {
        digits[i]++;
        return digits;
      }
      digits[i] = 0;
    }
    vector<int> res(digits.size()+1);
    res[0] = 1;
    return res;
  }
};

int main() {
  vector<int> v1;
  vector<int> v2;
  v1.push_back(2);
  v1.push_back(1);
  v1.push_back(0);
  v2.push_back(9);
  v2.push_back(9);
  v2.push_back(9);
  Solution solv;
  vector<int> res1 = solv.plusOne(v1);
  vector<int> res2 = solv.plusOne(v2);
  for (int i = 0; i < res1.size(); i++)
    printf("%d ",res1[i]);
  printf("\n");
  for (int i = 0; i < res2.size(); i++)
    printf("%d ",res2[i]);
  printf("\n");
}
