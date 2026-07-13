class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
        String st = String.valueOf(low);
        String end = String.valueOf(high);

        List<Integer> ans = new ArrayList<>();

        for (int i = st.length(); i <= end.length(); i++) {

            StringBuilder tmp = new StringBuilder("1");

            for (int j = 0; j < i - 1; j++) {
                tmp.append('0');
            }

            while (true) {
                int fl = 0;
                for (int j = 1; j < tmp.length(); j++) {
                    if ((tmp.charAt(j - 1) == '9')) {
                        fl = 1;
                        break;
                    }
                    tmp.setCharAt(j, (char) (tmp.charAt(j - 1) + 1));
                }

                if (Integer.parseInt(tmp.toString()) > high || fl == 1) {
                    break;
                }
                if (Integer.parseInt(tmp.toString()) >= low) {
                    ans.add(Integer.parseInt(tmp.toString()));
                }
                tmp.setCharAt(0, (char) (tmp.charAt(0) + 1));

            }

        }

        return ans;
    }
}