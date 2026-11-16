class Solution {
public:
    vector<int> mult(string num1, string num2){
        int n1=num1.length();
        int n2=num2.length();
        vector<int>sum(n1+n2,0);
        for(int i=n2-1;i>=0;i--){
            int j=n1-1;
            int carry=0;
            for(;j>=0;j--){
                int mul = (num1[j] - '0') * (num2[i] - '0');
                int pos1 = i + j;
                int pos2 = i + j + 1;
                int total = mul + sum[pos2] + carry;
                sum[pos2] = total % 10;
                carry = total / 10;
                sum[pos1] += carry;
                carry = 0; // reset after pushing into pos1
            }    
        }
        return sum;
    }
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0"){
            return "0";
        }
        vector<int>ans=mult(num1,num2);
        string s;
        int i=0;
        for(;i<ans.size();){
            if(ans[i]==0){
                i++;
            }
            else{
                break;
            }
        }
        for(int j=i;j<ans.size();j++){
            s.push_back(ans[j] + '0');
        }
        return s;
        
    }
};