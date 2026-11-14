class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(0, nums, res);
        return res;
    }

    void solve(int idx, vector<int>& a, vector<vector<int>>& res) {
        if (idx == a.size()) {
            res.push_back(a);
            return;
        }
        for (int i = idx; i < a.size(); i++) {
            swap(a[idx], a[i]);
            solve(idx + 1, a, res);
            swap(a[idx], a[i]);
        }
    }
};