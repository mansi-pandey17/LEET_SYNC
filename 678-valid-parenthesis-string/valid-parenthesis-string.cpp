class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;   // min possible open '('
        int high = 0;  // max possible open '('

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low = max(0, low - 1);
                high--;
            } else { // c == '*'
                low = max(0, low - 1);
                high++;
            }

            if (high < 0) return false;
        }

        return low == 0;
    }
};