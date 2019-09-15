#include <string>
#include <vector>
#include <stack>
using namespace std;

#if 0
class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> numbers;
    for(int i = 0 ; i < tokens.size() ;++i){
      if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
        int res;
        int n2 = numbers.top();
        numbers.pop();
        int n1 = numbers.top();
        numbers.pop();

        if(tokens[i] == "+")
          res = n1 + n2;
        else if(tokens[i] == "-")
          res = n1 - n2;
        else if(tokens[i] == "/")
          res = n1 / n2;
        else
          res = n1 * n2;
        numbers.push(res);
      }else{
        numbers.push(stoi(tokens[i]));
      } 
    }
    return numbers.top();
  }
};

#endif

int main() {
  return 0;
}
