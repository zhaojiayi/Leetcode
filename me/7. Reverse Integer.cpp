class Solution {
public:
    int reverse(int x) {
        int tmp = x>0?x:-x;
        int y = 0;
        for(;tmp>0;tmp = tmp/10){
            if(y>(INT_MAX-tmp%10)/10)//溢出的情况，思考
            return 0;
            y = y*10+tmp%10;
        }
        y = x>0?y:-y;
        return y;
    }
};