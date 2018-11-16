//字符串的乘法
//实现了两个函数
//add的第一功能是字符串的加法
// add 的第二个功能是多个相同字符串相加 
//multiply 是字符串乘法 
 



#include<iostream>
#include <algorithm>
#include <string.h>


using namespace std;

    
 class Solution {
public:
    
    
    
 string add(string num1,string num2)
    {
        string ret;
        int len1=num1.size();
        int len2=num2.size();
        reverse(num1.begin(),num1.end());//逆置字符串
        reverse(num2.begin(),num2.end());//逆置字符串
        int i=0;
        int next=0;//进位
        int n1=0;
        int n2=0;
        while(i<len1||i<len2)
        {
            if(i<len1)
            {
                n1=num1[i]-48;
            }
            else
            {
                n1=0;
            }
            if(i<len2)
            {
                n2=num2[i]-48;
            }
            else
            {
                n2=0;
            }
            next=n1+n2+next;//加上上一位的进位
            ret.push_back(next%10+48);
            next/=10;//如果大于9就有进位 
            
            i++;
        }
        if(next)
        {
            ret.push_back('1');//如果循环结束还有进位
        }
        reverse(num1.begin(),num1.end());//逆置字符串
        reverse(num2.begin(),num2.end());//逆置字符串
        reverse(ret.begin(),ret.end());
        return ret;
    }

   string add(string num1,int n)
    {
        string ret;
        int len1=num1.size();
        reverse(num1.begin(),num1.end());//逆置字符串 
        int i=0;
        int next =0;//进位
        int n1=0;
        while(i<len1)
        {
            n1=num1[i]-48;
            next=n1*n+next;//加上上一位的进位
            ret.push_back(next%10+48);
            next/=10;//计算出进位
            i++;
        }
        if(next)
        {
            ret.push_back(next+48); 
        }
         reverse(ret.begin(),ret.end());
        reverse(num1.begin(),num1.end());//逆置字符串   还原 
        return ret;
    }

	
	    
    string multiply(string num1, string num2) {
        
        if(!strcmp(num1.c_str(),"0")||!strcmp(num2.c_str(),"0"))
        {
            return string("0");
        }
        string ret;
        int i=0;
        int len1 = num1.size();             
        while(i<len1)
        {
        	ret.push_back('0');  
            string tmp = add(num2,num1[i]-48);
            ret =add(tmp,ret);
			i++;       
        }
        return ret;
    }
};
	
int main()
{
	string str1("1234");
	string str2("1111");
	string str3 = Solution().add(str1,str2);
	string str4 = Solution().add(str1,2);
	string str5 = Solution().multiply(str1,str2);
	cout<<str3<<endl;
    cout<<str4<<endl;
    cout<<str5<<endl;
	return 0;
} 
