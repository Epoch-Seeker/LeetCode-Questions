class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string temp;
        
        for(int i=0 ;i < num; i++){
            for(int k = 9 ; k >=0; k--){
                if(sum - k >= 0){
                    sum -= k;
                    temp.push_back(k + '0');
                    break;
                }
            }
            // cout<<d<<" "<<sum<<" "<<temp<<endl;
        }

        if(sum)return "";
        return temp;
    }
};