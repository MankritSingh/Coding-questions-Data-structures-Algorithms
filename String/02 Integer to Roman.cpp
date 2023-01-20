/*Question:Convert Roman numerical to integer numerical

Approach 1:Using if else loop. 
It is long and simple.
Approach 2:Using constraint and number system basics
We know that the max val of number we will deal will be comprising of Max numeric value of M.
So we build 4arrays for each numeric place one,ten,hundered,thousands.
if any place is not be used simply put a blank there.
*/
//Approach 2
class Solution {
public:
    string intToRoman(int num) {
        string thousands[]={"","M","MM","MMM"};
        string hundreds[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string tens[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string ones[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string ans= thousands[num/1000]+ hundreds[(num%1000)/100]+tens[(num%100)/10]+ones[(num%10)];
        return ans;
    }
};

//Approach 1
class Solution{
  public:
    string convertToRoman(int n) {
        string ans="";
        while(n>0){
            if(m[n]!=""){
               ans+= m[n];n=0;
            }
            else if(n>=1000){
                ans+='M'; n-=1000;
            }
            else if(n>=900){
                ans+="CM"; n-=900;
            }
            else if(n>=500){
                ans+='D'; n-=500;
            }
            else if(n>=400){
                ans+="CD"; n-=400;
            }
            else if(n>=100){
                ans+='C'; n-=100;
            }
            else if(n>=90){
                ans+="XC"; n-=90;
            }
            else if(n>=50){
                ans+='L'; n-=50;
            }
            else if(n>=40){
                ans+="XL"; n-=40;
            }
            else if(n>=10){
                ans+='X'; n-=10;
            }
            else if(n>=9){
                ans+="IX"; n-=9;
            }
            else if(n>=5){
                ans+='V'; n-=5;
            }
            else if(n>=4){
                ans+="IV"; n-=4;
            }
            else{
                ans+='I'; n-=1;
            }
        }
        return ans;
    }
};
