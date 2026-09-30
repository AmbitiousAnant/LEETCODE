class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.length());
        for (int i = 0; i < seq.length(); ++i) {
            res[i] = (seq[i] == '(') ? (i % 2) : (1 - (i % 2));
        }
        return res;
    }
};