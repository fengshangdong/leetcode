#include<vector>
#include<set>
#include<map>
#include<string>
#include<cstdio>

using namespace std;

class Solution {
public:
	vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
		map<string, vector<string> > graph;
		graph_construct(beginWord, wordList, graph);
		vector<Qitem> Q;
		vector<int> end_word_pos;
		graph_BFS(beginWord, endWord, graph, Q, end_word_pos);
		vector<vector<string> > result;

		for (int i = 0; i < end_word_pos.size(); i++) {
			int pos = end_word_pos[i];
			vector<string> path;
			while (pos != -1) {
				path.push_back(Q[pos].node);
				pos = Q[pos].parent_pos;
			}

			result.push_back(vector<string>());
			for(int j = path.size()-1; j >= 0; j--) {
				result[i].push_back(path[j]);
			}
		}

		return result;
	}

private:
	/* Qitem是队列元素
	 * node		  - 字符串 
	 * parent_pos - 前驱结点在字典所在的位置
	 * step		  - 到达当前结点的步数 
	 * */
	struct Qitem {
		string node;
		int parent_pos;
		int step;
		Qitem(string _node, int _parent_pos, int _step)
			: node(_node), parent_pos(_parent_pos), step(_step){
			}
	};

	/* 判断字典中字符串是否只有一位不同 */
	static bool graph_connect(string& str1, string& str2)
	{
		int count = 0;
		for (int i = 0; i < str1.size(); i++)
		{
			if(str1[i] != str2[i])
				count++;
		}

		return count == 1;
	}

	/* 将字典中只有一位不同的字符串俩俩连接成图 */
	void graph_construct(string& beginWord, vector<string>& wordList, map<string, vector<string> >& graph)
	{
		/* flag用于处理字典中重复出现beginWord的情况 */
		int flag = 0;
		for (int i = 0; i < wordList.size(); i++) {
			if (wordList[i] == beginWord) {
				flag = 1;
			}
			graph[wordList[i]] = vector<string>();
		}

		for (int i = 0; i < wordList.size(); i++) {
			for (int j = i+1; j < wordList.size(); j++) {
				if (graph_connect(wordList[i], wordList[j])) {
					graph[wordList[i]].push_back(wordList[j]);
					graph[wordList[j]].push_back(wordList[i]);
				}
			}

			if (flag == 0 && graph_connect(beginWord, wordList[i])) {
				graph[beginWord].push_back(wordList[i]);
			}
		}
	}

	/* 记录路径的广度优先搜索 */
	void graph_BFS(string& beginWord, string& endWord, map<string, vector<string> >& graph,
			vector<Qitem>& Q, vector<int>& end_word_pos)
	{
		map<string, int> visit;
		int min_step = 0;
		Q.push_back(Qitem(beginWord, -1, 1));
		visit[beginWord] = 1;
		int front = 0;
		while(front != Q.size()) {
			const string& node = Q[front].node;
			int step = Q[front].step;

			/* 当 step > min_step 时,所有搜索完成 */
			if (min_step != 0 && step > min_step) {
				break;
			}

			/* 当搜索到结果时, 记录到终点的最小步数 */
			if (node == endWord) {
				min_step = step;
				end_word_pos.push_back(front);
			}

			const vector<string>& neighbors = graph[node];
			for (int i = 0; i < neighbors.size(); i++) {
				if (visit.find(neighbors[i]) == visit.end() || visit[neighbors[i]] == step + 1) {
					Q.push_back(Qitem(neighbors[i], front, step+1));
					visit[neighbors[i]] = step + 1;
				}
			}

			front++;
		}
	}
};

int main()
{
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList;
	wordList.push_back("hot");
	wordList.push_back("dot");
	wordList.push_back("dog");
	wordList.push_back("lot");
	wordList.push_back("log");
	wordList.push_back("cog");

	Solution solve;
	vector<vector<string> > result = solve.findLadders(beginWord, endWord, wordList);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%s]\t", result[i][j].c_str());
		}
		printf("\n");
	}

	return 0;
}
