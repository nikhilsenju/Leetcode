class Solution {
    public List<List<Integer>> filterOccupiedIntervals(int[][] oi, int fs, int fe) {
        int n = oi.length;
        List<List<Integer>> mi = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(oi,(a,b)->Integer.compare(a[0],b[0]));
        int st = oi[0][0];
        int en = oi[0][1];
        for(int i=1;i<n;i++){
            int curs = oi[i][0];
            int cure = oi[i][1];
            if(en>=curs-1){
                en = Math.max(en,cure);
            }
            else{
                List<Integer> tmp= new ArrayList<>();
                tmp.add(st);
                tmp.add(en);
                mi.add(tmp);
                st = curs;
                en = cure;
            }
        }  
        List<Integer> tmp= new ArrayList<>();
        tmp.add(st);
        tmp.add(en);
        mi.add(tmp); 
        n = mi.size();
        for(int i=0;i<n;i++){
            int curs = mi.get(i).get(0);
            int cure = mi.get(i).get(1);
            if(fs<=curs && fe>=cure){
            
                continue;
            }
            if(curs<fs && cure>fe){
             
                List<Integer> tmp1 = new ArrayList<>();
                List<Integer> tmp2 = new ArrayList<>();
                tmp1.add(curs);
                tmp1.add(fs-1);
                ans.add(tmp1);
                tmp2.add(fe+1);
                tmp2.add(cure);
                ans.add(tmp2);
            }
            else if(cure<fs || fe<curs){
           
                List<Integer> tmp1 = new ArrayList<>();
                tmp1.add(curs);
                tmp1.add(cure);
                ans.add(tmp1);
            }
            else{
                List<Integer> tmp1 = new ArrayList<>();
                if(fs<=cure && cure<=fe){
               
                    tmp1.add(curs);
                    tmp1.add(fs-1);
                    ans.add(tmp1);
                }
                else if(fe>=curs && curs>=fs){
               
                    tmp1.add(fe+1);
                    tmp1.add(cure);
                    ans.add(tmp1);
                }
            }
        }
        return ans;

    }
}