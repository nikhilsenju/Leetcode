import java.util.*;

class Solution {
    public int minLights(int[] lights) {
        ArrayList<ArrayList<Integer>> v = new ArrayList<>();
        ArrayList<ArrayList<Integer>> nv = new ArrayList<>();
        int n = lights.length;
        for(int i=0;i<n;i++){
            if(lights[i]!=0){
                int left = Math.max(0,i-lights[i]);
                int right = Math.min(n-1,i+lights[i]);
                ArrayList<Integer> tmp = new ArrayList<>();
                tmp.add(left);
                tmp.add(right);
                v.add(tmp);
            }
        }
        Collections.sort(v,(a,b)->a.get(0)-b.get(0));
        if(v.size()==0){
            return (n+2)/3;
        }
        int st = v.get(0).get(0);
        int end = v.get(0).get(1);
        for(int i=1;i<v.size();i++){
            int ns = v.get(i).get(0);
            int ne = v.get(i).get(1);
            if(end>=ns){
                end = Math.max(end,ne);
            }
            else{
                ArrayList<Integer> temp = new ArrayList<>();
                temp.add(st);
                temp.add(end);
                nv.add(temp);
                st = ns;
                end = ne;
            }
        }
        ArrayList<Integer> temp = new ArrayList<>();
       temp.add(st);
        temp.add(end);
        nv.add(temp);
        int ans = 0;
        for(int i=0;i<nv.size();i++){
            if(i==0){
                int len = nv.get(0).get(0);
                ans+=(len+2)/3;
            }
            else{
                int len = (nv.get(i).get(0)-nv.get(i-1).get(1)-1);
                ans+=(len+2)/3;
            }
        }
        ans+=(n-nv.get(nv.size()-1).get(1)+1)/3;
        return ans;

    }
}