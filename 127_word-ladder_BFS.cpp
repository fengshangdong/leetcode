#include<set>
#include<map>
#include<vector>
#include<queue>
#include<string>
#include<cstdio>
#include<utility>

using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    map<string, vector<string> > graph;
    graph_construct(beginWord, endWord, wordList, graph);
    return graph_BFS(beginWord, endWord, wordList, graph);
  }

private:
  /* 判断字典中字符串是否只有一位不同 */
  static bool graph_connect(string str1, string str2)
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
  void graph_construct(string beginWord, string endWord, vector<string>& wordList, map<string, vector<string> >& graph)
  {
    wordList.push_back(beginWord);

    for (int i = 0; i < wordList.size(); i++) {
      for (int j = i+1; j < wordList.size(); j++) {
        if (graph_connect(wordList[i], wordList[j])) {
          graph[wordList[i]].push_back(wordList[j]);
          graph[wordList[j]].push_back(wordList[i]);
        }
      }
    }
  }

  /* 广度优先搜索图graphh得到最短距离 */
  int graph_BFS(string beginWord, string endWord, vector<string>& wordList, map<string, vector<string> >& graph)
  {
    queue<pair<string, int> > Q;
    Q.push(make_pair(beginWord, 1));
    set<string> visit;
    visit.insert(beginWord);

    while(!Q.empty()) {
      string& node = Q.front().first;
      int step = Q.front().second;
      Q.pop();

      if (node == endWord)
        return step;

      vector<string>& neighbor = graph[node];
      for (int i = 0; i < neighbor.size(); i++) {
        if (visit.find(neighbor[i]) == visit.end()) {
          visit.insert(neighbor[i]);
          Q.push(make_pair(neighbor[i], step + 1));
        }
      }
    }

    return 0;
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
  wordList.push_back("cog");
  wordList.push_back("hot");

  Solution solve;
  printf("%d\n", solve.ladderLength(beginWord, endWord, wordList));
}
