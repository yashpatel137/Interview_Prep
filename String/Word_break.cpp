class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

		int n = s.size();
		unordered_set<string> h(begin(wordDict), end(wordDict));
		vector<bool> vec(n + 1, false);
		vec[0] = true;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < i and !vec[i]; ++j) {
				vec[i] = vec[i] or (vec[j] and h.count(s.substr(j, i - j)));
			}
		}
		return vec[n];
    }
};