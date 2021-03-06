/* 对每个字母向左向右展开，算出回文字符串，最终选出最长的回文串*/

class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0;
        int right = 0;
        int startID = 0;
        int length = 0;
        for(int i = 0; i<s.size()-1;i++){
            if(s[i] == s[i+1]){
                left = i;
                right = i+1;
                findString(s,left,right,startID,length);
            }
            left = i;
            right = i;
            findString(s,left,right,startID,length);
        }
            if(length == 0) length = 1;//针对size为1的字符串，无法进入循环
            return s.substr(startID,length);
    }
    
    void findString(string s,int left,int right,int &startID,int &length){
        int i = 1;
        for(;left-i>=0&&right+i<=s.size()-1;i++){
            if(s[left-i]!=s[right+i]){
                break;
            }
        }
        int width = right-left+2*i-1;
        if(width>length){
            length = width;
            startID = left-i+1;
        }
    }
};