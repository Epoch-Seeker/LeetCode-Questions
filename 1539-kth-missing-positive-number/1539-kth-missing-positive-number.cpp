class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 1;
        int j = 0;

        while(k>1){
            if(j < arr.size() && arr[j] == i){
                j++;
            }else {
                k--;
            }
            i++;
        }

        for(j ; j <arr.size() ; j++){
            if(arr[j] != i){
                break;
            }else {
                i++;
            }
        }

        return i;
    }
};