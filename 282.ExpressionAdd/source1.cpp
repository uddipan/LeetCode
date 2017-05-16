class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if(num.size()==0)   return result;
        help(result, "", num, target, 0, 0, 0);
        return result;
    }
    
    // DP for solving
    void help(vector<string> &result, string path, string num, int target, int pos, long cur, long prev){
        if(pos==num.size()){
            if(cur==target)   result.push_back(path);
            return;
        }
        for(int i=pos; i<num.size(); i++){
            if(num[pos]=='0' && i>pos) break;
            
            // the first string before the first operation
            string _str=num.substr(pos, i-pos+1);
            long _value=stol(_str);
            if(pos==0)  {
                help(result, path+_str, num, target, i+1, _value, _value);
            }
            else{
                help(result, path+"+"+_str, num, target, i+1, cur+_value, _value);
                help(result, path+"-"+_str, num, target, i+1, cur-_value, -_value);
                help(result, path+"*"+_str, num, target, i+1, cur-prev+prev*_value, prev*_value);
            }
        }
    }
};