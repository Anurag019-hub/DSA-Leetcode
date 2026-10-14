class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        long long op1 = (sum)/9;
        if(op1>num) return "";
        long long rem = (sum)%9;
        if(op1==num && rem!=0) return "";
        string s = "";
        for(int i=0;i<op1;i++){
            s+='9';
        }
        if(num>op1)s+=(rem + '0');
        long long mm = num-op1-1;
        for(int i=op1+1;i<num;i++){
            s+='0';
        }
        return s;
    }
};