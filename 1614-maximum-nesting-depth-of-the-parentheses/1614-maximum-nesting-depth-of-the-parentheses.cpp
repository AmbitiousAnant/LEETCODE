class Solution {
public:
    int maxDepth(string s) {
        int curr=0;
        int maxo=0;
        for(auto i:s){
            if(i=='('){
                curr++;
            }
            if(i==')'){
                curr--;
            }
            else{
                i++;
            }
            maxo=max(maxo,curr);
        }
        return maxo;
    }
};