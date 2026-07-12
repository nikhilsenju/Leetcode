class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int n = arr.length;
        TreeSet<Integer> st = new TreeSet<>();
        HashMap<Integer,Integer> mp = new HashMap<>();
        for(int i=0;i<n;i++){
            st.add(arr[i]);
        }
        int cnt = 1;
        for(int x:st){
            mp.put(x,cnt);
            cnt++;
        }
        int[] ans = new int[n];
        for(int i=0;i<n;i++){
            ans[i]=mp.get(arr[i]);
        }
        return ans;
    }
}