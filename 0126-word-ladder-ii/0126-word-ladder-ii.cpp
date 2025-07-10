#define x first
#define y second
typedef unordered_map <string,vector<string>> mymap;
typedef unordered_set <string> myset;
typedef queue <pair<string,int>> PII;



class Solution {
public:
    //& 引用就是直接使用，而不是创建副本（耗时间）
    void trace_back(vector<string> &path,vector<vector<string>> &res,mymap &pre,string& now,string& beginword){
        path.push_back(now);

        if(now == beginword){
            reverse(path.begin(),path.end());
            res.push_back(path);
            reverse(path.begin(),path.end());
        }
        else{
            for(string index : pre[now]){
                trace_back(path,res,pre,index,beginword);
            }
        }
        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        myset s(wordList.begin(),wordList.end());
        vector<vector<string>> res;
        mymap prev;
        myset should_remove;
        PII q; 
        vector<string> path;
        int layer_ing = 1;

        //如果wordlist中有beginWord，提前删除
        s.erase(beginWord);

        q.push({beginWord,1});
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            
            string temp = t.x;
            
            //当所有最短路径生成后 （这里表示所有最短路径生成后，才会开始拓展endword后面的结点）
            if(t.x == endWord){
                //回溯路径
                trace_back(path,res,prev,t.x,beginWord);
                return res;
            }
            //进入下一层时
            if(layer_ing < t.y){
                //删除已经经过的结点
                for(auto index = should_remove.begin();index != should_remove.end();index++){
            
                    s.erase(*index);

                }
                should_remove.clear();
                layer_ing = t.y;
            }

            //完成一个结点的拓展
            for(int i = 0;i < temp.size();i++){
                for(char j = 'a' ; j <= 'z';j++){
                    temp[i] = j;
                    if(s.find(temp) != s.end()){
                        //第一次遇到该结点才需要入队
                        if(should_remove.emplace(temp).y){
                            //如果再次遇到该结点，无需入队，只需记录前驱
                            
                            q.push({temp,t.y+1});
                        }
                        //记录前驱,      （直接使用prev[temp]会默认插入一个空vector<string>）
                        prev[temp].push_back(t.x) ;
                    }
                    temp = t.x; 
                        
                }
            }

            


            
        }
        return res;
    }
};

// 作者：Frosty Diffie9wJ
// 链接：https://leetcode.cn/problems/word-ladder-ii/solutions/3719449/bfshui-su-by-frosty-diffie9wj-w7u6/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。