class Solution {
public:
    bool isAlpha(char c) {
        c = tolower(c);
        return c >= 97 && c <= 122;
    }
    string reverseOnlyLetters(string s) {
        int l = 0;
        int h = s.size() - 1;
        while (l < h) {
            if (isAlpha(s[l]) == 0) {
                l++;
            }
            else if (isAlpha(s[h]) == 0){
                h--;
            }
            else {
                swap(s[l++],s[h--]);
            }
        }
        return s;
    }
};
