import java.util.*;
class Solution {
    public int maxNumberOfBalloons(String text) {
        HashMap<Character,Integer> mp = new HashMap<>();
        for(char ch:text.toCharArray()){
            mp.put(ch,mp.getOrDefault(ch, 0)+1);
        }
        int mini = Integer.MAX_VALUE;
        mini = Math.min(mini,mp.getOrDefault('b', 0));
        mini = Math.min(mini,mp.getOrDefault('a', 0));
        mini = Math.min(mini,mp.getOrDefault('l', 0)/2);
        mini = Math.min(mini,mp.getOrDefault('o', 0)/2);
        mini = Math.min(mini,mp.getOrDefault('n', 0));
        return mini;
    }
}