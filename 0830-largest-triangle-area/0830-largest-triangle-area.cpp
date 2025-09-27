class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& p) {
        int n = p.size();
        double maxans = 0.0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    double x1 = p[i][0];double y1 = p[i][1];
                    double x2 = p[j][0];double y2 = p[j][1];
                    double x3 = p[k][0];double y3 = p[k][1];
                    double ans = 0.5*(abs(x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1));
                    maxans = max(maxans,ans);
                }
            }
        }
        return maxans;

    }
};