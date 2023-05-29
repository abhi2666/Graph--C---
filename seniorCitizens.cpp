class Solution {
public:

    int isSenior(string s){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'M' || s[i] == 'F' || s[i] == 'O'){
                if(s[i+1] > '6'){
                    return 1;
                }
            }
        }
        return 0;
    }
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(int i = 0; i < details.size(); i++){
            string s = details[i];
            if(isSenior(s)){
                count++;
            }
        }
        return count;
    }
};