class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
    HashMap<Integer, List<String>> hash = new HashMap<>();
    //每个字母对应一个质数
    int[] prime = { 103, 3, 2,  5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
    for (int i = 0; i < strs.length; i++) {
        int key = 1;
        //累乘得到 key
        for (int j = 0; j < strs[i].length(); j++) {
            key *= prime[strs[i].charAt(j) - 96];
        } 
         List<String>  temp = hash.getOrDefault(key,new ArrayList<String>());
 temp.add(strs[i]);
  hash.put(key, temp);

    }
    return new ArrayList<List<String>>(hash.values());
}
}