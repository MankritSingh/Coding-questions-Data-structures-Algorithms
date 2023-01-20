
/*Question link:https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1
Analysis:
We read Roman numericals in the following way
1)if the next character is of same value or lower simply add
eg I,II,III,VVIII and so
2)if the the next character is bigger than the previous one,simply subtract it from the bigger value.
*/
class Solution {
  public:
    int romanToDecimal(string &str) {
        map<char,int>m;
        m.insert({'I',1});
        m.insert({'V',5});
        m.insert({'X',10});
        m.insert({'L',50});
        m.insert({'C',100});
        m.insert({'D',500});
        m.insert({'M',1000});
        int ans=0;
        for(int i=0;i<str.length();i++){
            if(i!= str.length()-1 && m[str[i]]<m[str[i+1]]){
                ans+= m[str[i+1]]-m[str[i]];
                i++;
            }
            else{
                ans+=m[str[i]];
            }
        }
        return ans;
        
    }
};
