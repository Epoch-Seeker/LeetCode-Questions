class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 1;
        int j = 0;

        while(k>0){
            if(j < arr.size() && arr[j] == i){
                j++;
            }else {
                k--;
                if(k ==0)break;
            }
            i++;
        }

        return i;
    }
};