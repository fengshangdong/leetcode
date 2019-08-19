#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
  int romanToInt(string s) {
    int total = 0;
    int arr[7] = {1,5,10,50,100,500,1000};
    int temp_last = -1;
    int temp = 0;
    int size = s.size();
    for (int i=size-1; i >= 0; i--) {
      if (s[i] == 'I') {
        temp = 0;
      }
      else if (s[i] == 'V') {
        temp = 1;
      }
      else if (s[i] == 'X') {
        temp = 2;
      }
      else if (s[i] == 'L') {
        temp = 3;
      }
      else if (s[i] == 'C') {
        temp = 4;
      }
      else if (s[i] == 'D') {
        temp = 5;
      }
      else if (s[i] == 'M') {
        temp = 6;
      }

      if (temp >= temp_last) {
        total += arr[temp];
        temp_last = temp;
      }
      else if (temp < temp_last) {
        total -= arr[temp];
        temp_last = temp;
      }
    }
    return total;
  }
};

int main()
{
  Solution solve;
  string s1("III");
  string s2("IX");
  string s3("LVIII");
  string s4("MCMXCIV");
  int ret1 = solve.romanToInt(s1);
  int ret2 = solve.romanToInt(s2);
  int ret3 = solve.romanToInt(s3);
  int ret4 = solve.romanToInt(s4);

  printf("ret1=%d\n",ret1);
  printf("ret2=%d\n",ret2);
  printf("ret3=%d\n",ret3);
  printf("ret4=%d\n",ret4);
}
