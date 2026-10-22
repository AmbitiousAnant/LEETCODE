class CustomStack {
    vector<int> a;
    int c;
    int mx;
public:
    CustomStack(int maxSize) {
        mx=maxSize;
        a.resize(mx);
        c=0;
    }
    
    void push(int x) {
        if(c<mx){
            a[c]=x;
            c++;
        }
    }
    
    int pop() {
        if(c==0){
            return -1;
        }
        c--;
        return a[c];
    }
    
    void increment(int k, int val) {
        int lim=min(c,k);
        for(int i=0;i<lim;i++){
            a[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */