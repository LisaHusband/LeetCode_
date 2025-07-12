class Solution {
    public int ladderLength(String startWord, String targetWord, List<String> wordList) {
        //create a queue for bfs
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(startWord,1)); //start at level 1
        //add elements to set 
        Set<String> seen = new HashSet<>();
        int n = wordList.size();
        for(int i = 0 ; i < n ; i++){
            seen.add(wordList.get(i));
        }
        seen.remove(startWord);
        //removes the visited kinda thing relate man 
        while(!q.isEmpty()){
            String word = q.peek().first;
            int cnt = q.peek().second;
            q.remove();
            if(word.equals(targetWord) == true){
                return cnt;
            }
            //for hot
            for(int i = 0 ; i < word.length() ;i++){
                //check for aot,bot,cot...zot i == 0
                //check for hat , hbt , ...hzt i == 1
                //check for hoa,hob,hoc,hod, ...hoz i ==2 
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    char[] temp = word.toCharArray();
                    temp[i] = ch;
                    //char array to string
                    String repword = new String(temp);
                    //check if it exists
                    if(seen.contains(repword)){
                        q.add(new Pair(repword,cnt+1));
                        seen.remove(repword);
                    }
                }

            }
        }
        return 0;

    }

    public class Pair{
        String first;
        int second;
        public Pair(String s , int x){
            this.first = s;
            this.second = x;
        }
    }
}