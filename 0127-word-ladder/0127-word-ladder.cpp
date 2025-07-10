class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet{wordList.begin(), wordList.end()};
        if(wordSet.find(endWord) == wordSet.end()) return 0;
        
        int res = 1;
        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};
        while(!beginSet.empty()){
            res++;
            unordered_set<string> nextSet;
            for(auto & word : beginSet) {
                wordSet.erase(word);
            }
            for(auto & word: beginSet){
                for(int i = 0; i < word.size(); i++){
                    string nextWord = word;
                    for(char j = 'a'; j <= 'z'; j++){
                        nextWord[i] = j;
                        if(endSet.find(nextWord) != endSet.end()) return res;
                        if(wordSet.find(nextWord) != wordSet.end()){
                            nextSet.insert(nextWord);
                        }
                    }
                }
            }
            beginSet = nextSet;
            if(beginSet.size() > endSet.size()){
                swap(beginSet, endSet);
            }
        }
        return 0;
    }
};