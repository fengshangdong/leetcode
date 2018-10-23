#include<stack>
#include<string>
#include<cstdio>
#include<iostream>

using namespace std;

class Solution {
public:
    int calculate(string s) {
		stack<int> nums, ops;
		int num = 0;
		int rst = 0;
		int sign = 1;
		/* 遍历字符串,如果是数字就累计为num,如果是运算符就计算之前的结果为rst */
		/* 如果是'('就把之前的结果和 '('前的正负运算符压栈 */
		/* 如果是')'就取栈中的结果和正负运算符 */
		for (int i = 0; i < s.size(); i++) {
			if ('0' <= s[i] && s[i] <= '9') {
				num = num * 10 + s[i] - '0';
			}
			else {
				rst += sign * num;
				num = 0;
				if (s[i] == '-') sign = -1;
				if (s[i] == '+') sign = 1;
				if (s[i] == '(') {
					nums.push(rst);
					ops.push(sign);
					rst = 0;
					sign = 1;
				}
				if (s[i] == ')' && ops.size()) {
					rst = rst * ops.top() + nums.top();
					nums.pop(); ops.pop();
				}
			}
		}

		/* 为了计算 1-2 这里的 -2 */
		rst += sign * num;
		return rst;
	}
};

int main()
{
	string s = "-1 + (15 - 6)";
	Solution solve;
	cout<< s <<endl;
	printf("%d\n", solve.calculate(s));
}
