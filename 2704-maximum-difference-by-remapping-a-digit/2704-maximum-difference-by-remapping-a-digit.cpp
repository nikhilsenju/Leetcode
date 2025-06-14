class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxi;
        string mini;
        char ch1 = '.';
        char ch2 = '.';
        for (auto i : s) {
            if (i != '9' && ch1 == '.') {
                ch1 = i;
            }
            if (i != '0' && ch2 == '.') {
                ch2 = i;
            }
        }
        for (auto i : s) {
            if (i == ch1) {
                maxi.push_back('9');
            } else {
                maxi.push_back(i);
            }

            if (i == ch2) {
                mini.push_back('0');
            } else {
                mini.push_back(i);
            }
        }
        return stoi(maxi) - stoi(mini);
    }
};