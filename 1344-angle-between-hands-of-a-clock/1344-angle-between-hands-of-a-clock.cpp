class Solution {
public:
    double angleClock(int hour, int minutes) {
        double degmin = 6*minutes;
        double deghour = hour*30+minutes*0.5;
        double ans1 = abs(degmin-deghour);
        double ans2 = 360-ans1;
        return min(ans1,ans2);
    }
};