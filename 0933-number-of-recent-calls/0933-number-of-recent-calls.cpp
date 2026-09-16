class RecentCounter {
    vector<int> v;

    int count(int i, int m) {
        if (i < 0 || v[i] < m) return 0;
        return 1 + count(i - 1, m);
    }

public:
    RecentCounter() {}
    
    int ping(int t) {
        v.push_back(t);
        return count(v.size() - 1, t - 3000);
    }
};
/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */