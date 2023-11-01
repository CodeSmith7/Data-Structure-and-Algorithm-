class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // unordered_map<char,int> first,second;
        // for (auto x: ransomNote) {
        //     first[x]++;
        // }
        // for (auto x: magazine) {
        //     second[x]++;
        // }
        // for (auto it : first) {
        //     if (second.find(it.first) == second.end() || second[it.first] < it.second ) {
        //         return false;
        //     }
        // }
        // return true;

        unordered_map<char,int> mp;
        for (char c : magazine) {
            mp[c]++;
        }
        for (char c : ransomNote) {
            mp[c]--;
            if (mp[c] < 0) {
                return false;
            }
        }
        return true;
    }
};
