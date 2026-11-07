class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0;
        while(i < haystack.size()){
            int j = 0;
            bool is = true ; int k = i;
            while(j < needle.size()){
                if(k >= haystack.size() || haystack[k] != needle[j]){
                    is = false;
                    break;
                }
                k++;j++;
            }
            if(is)return i;
            i++;
        }
        return -1;
    }
};