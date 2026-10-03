class Solution {
public:
    int check_e(string s){
        int temp = 0;
        for(char ch : s){
            if(ch == 'e' || ch == 'E')temp++;
        }
        return temp;
    }

    pair<string , string> get_num(string s){
        string a , b;

        int i = 0 ;
        bool e = false;

        while(i < s.size() && !e){
            if(s[i] == 'e' || s[i] == 'E'){
                e = true;
            }else {
                a += s[i];
            }
            i++;
        }

        while(i < s.size()){
            b += s[i++];
        }
        return {a , b};
    }

    bool other_letter(string s){
        int i=0, n = s.size();

        while(i<n){
            if(!isdigit(s[i]) && s[i] != '.')return true;
            i++;
        }

        return false;
    }

    int deci(string s){
        int i=0, n = s.size();
        int temp = 0;

        while(i<n){
            if( s[i++] == '.')temp++;
        }

        return temp;
    }
 
    bool isNumber(string s) {
        // if(s == ".")return false;
        string a , b;
        // check e
        if(check_e(s) > 1)return false;

        auto t = get_num(s);
        
        // get number
        a = t.first;
        b = t.second;

        if(a.front() == '-' || a.front() == '+')a = a.substr(1);
        if(b.front() == '-' || b.front() == '+')b = b.substr(1);
        if(check_e(s) == 1 && (a.empty() || b.empty()))return false;
        if(other_letter(a) || other_letter(b))return false;

        if(a == ".")return false;

        if(deci(b) > 0 || deci(a) > 1 )return false;

        if(a.empty() && b.empty())return false;

        return true;
    }
};