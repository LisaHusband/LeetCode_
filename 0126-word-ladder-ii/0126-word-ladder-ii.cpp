#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> res;

        if (wordSet.find(endWord) == wordSet.end()) return res;

        unordered_map<string, vector<string>> graph; // 记录每个单词的前驱
        unordered_map<string, int> visited;          // 记录单词最早出现的层数
        queue<string> q;

        q.push(beginWord);
        visited[beginWord] = 0;

        bool found = false;
        int step = 0;

        // ---------- BFS 建图 ----------
        while (!q.empty() && !found) {
            int sz = q.size();
            ++step;
            unordered_set<string> localVisited; // 本轮新加入的词

            for (int i = 0; i < sz; ++i) {
                string word = q.front(); q.pop();
                string original = word;

                for (int j = 0; j < word.size(); ++j) {
                    char old = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == old) continue;
                        word[j] = c;
                        if (wordSet.find(word) != wordSet.end()) {
                            // 只在第一次遇到该单词时加入队列（最短路径）
                            if (visited.find(word) == visited.end()) {
                                localVisited.insert(word);
                                q.push(word);
                                visited[word] = step;
                                graph[word].push_back(original);
                            } else if (visited[word] == step) {
                                graph[word].push_back(original); // 同一层允许多个前驱
                            }
                            if (word == endWord) found = true;
                        }
                    }
                    word[j] = old;
                }
            }

            // 加入本层访问的单词
            for (const string& w : localVisited) {
                wordSet.erase(w); // 避免重复访问
            }
        }

        // ---------- DFS 回溯 ----------
        if (found) {
            vector<string> path{endWord};
            dfs(endWord, beginWord, graph, path, res);
        }

        return res;
    }

private:
    void dfs(const string& word, const string& beginWord,
             unordered_map<string, vector<string>>& graph,
             vector<string>& path, vector<vector<string>>& res) {
        if (word == beginWord) {
            vector<string> cur(path.rbegin(), path.rend());
            res.push_back(cur);
            return;
        }

        for (const string& prev : graph[word]) {
            path.push_back(prev);
            dfs(prev, beginWord, graph, path, res);
            path.pop_back(); // 回溯
        }
    }
};
