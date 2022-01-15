class Solution {
    public:
    vector<string> possibleWords(int a[], int N, int index = 0) {
        vector<vector<string>> keyboard = {
            {},
            {},
            {"a", "b", "c"},
            {"d", "e", "f"},
            {"g", "h", "i"},
            {"j", "k", "l"},
            {"m", "n", "o"},
            {"p", "q", "r", "s"},
            {"t", "u", "v"},
            {"w", "x", "y", "z"}
        };

        if(index == N - 1) {
            return keyboard[a[index]];
        }

        vector<string> ans;
        vector<string> postfixes = possibleWords(a, N, index + 1);

        for(string c: keyboard[a[index]]) {
            for(string s: postfixes) {
                ans.push_back(c + s);
            }
        }

        return ans;
    }
};