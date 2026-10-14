class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string temp;
        int d = 0;
        
        for(int i=0 ;i < num; i++){
            for(int k = 9 ; k >=0; k--){
                if(sum >= d + k){
                    d += k;
                    // sum -= k;
                    temp.push_back(k + '0');
                    break;
                }
            }
            // cout<<d<<" "<<sum<<" "<<temp<<endl;
        }

        if(d != sum)return "";
        return temp;
    }
};