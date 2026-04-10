import java.util.*;
class Solution {
    public int minimumDistance(int[] nums) {
        int n = nums.length;
        Map<Integer,List<Integer>> mp = new HashMap<>();
        for(int i = 0;i < n;i++){
            if(!mp.containsKey(nums[i])){
                mp.put(nums[i],new ArrayList<>());
            }
            mp.get(nums[i]).add(i);
        }
        Integer mini = Integer.MAX_VALUE;
        for(List<Integer> list:mp.values()){
            for(int j=2;j<list.size();j++){
                int a = list.get(j);
                int b = list.get(j-1);
                int c = list.get(j-2);
                int dist = Math.abs(a-b)+Math.abs(b-c)+Math.abs(a-c);
                mini = Math.min(mini,dist);
            }
        }
        return mini == Integer.MAX_VALUE?-1:mini;
    }
}