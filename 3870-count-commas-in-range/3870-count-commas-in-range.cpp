class Solution {
public:
    int countCommas(int n) {
        if(n<=999){
            return 0;}
        if(n<=9999){
            if(n==1000){
                return 1;
            }
            else
            return abs(1000-n)+1;
        }
        else{
            if(n==10000){
                return 1+9000;
            }
            else
            return abs(10000-n)+1+9000;
        }
    }  
};