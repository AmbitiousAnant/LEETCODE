class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        solve(0, intervals, res);
        return res;
    }

    void solve(int idx, vector<vector<int>>& a, vector<vector<int>>& res) {
        if (idx == a.size()) {
            return;
        }
        if (res.empty() || res.back()[1] < a[idx][0]) {
            res.push_back(a[idx]);
        } else {
            res.back()[1] = max(res.back()[1], a[idx][1]);
        }
        solve(idx + 1, a, res);
    }
};