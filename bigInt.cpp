#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;
 string add(string a,string b){
    string ans;
    int dgt,carry=0;
    for(int i=a.size()-1,j=b.size()-1;i>=0||j>=0;i--,j--){
        if(i<0) dgt=carry+b[j]-'0';
        else if(j<0) dgt=carry+a[i]-'0';
        else dgt=a[i]-'0'+b[j]-'0'+carry;
        carry=dgt/10;
        ans+=dgt%10+'0';
    }
    if(carry) ans+='1';
    reverse(ans.begin(),ans.end());
    return ans;
}
int compare(string a,string b)
{
    if(a.size()>b.size()) return 1;
    if(a.size()<b.size()) return -1;
    for(int i=0; i<=a.size()-1; i++){
        if(a[i]>b[i]) return 1;
        if(a[i]<b[i]) return -1;
    }
    return 0;}
string remove_leading_zeros(string str)
{
    int zero=0;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='0') zero++;
        else break;
    }
    if(zero==str.size()) return "0";
    return str.substr(zero);
}
string subtraction(string a,string b)
{    string ans;
    int cmp=compare(a,b);
    if(cmp==0) return "0";
    if(cmp==-1) swap(a,b);
    int tmp,borrow=0;
    for(int i=a.size()-1,j=b.size()-1; i>=0||j>=0; i--,j--){
        if(j<0) tmp=a[i]-'0';
        else tmp=a[i]-b[j];
        if(borrow)
        {   tmp--;
            borrow=0;}
        if(tmp<0)
        {tmp+=10;
            borrow=1;
        }
        ans+=tmp+'0';
    }
    reverse(ans.begin(),ans.end());
    ans=remove_leading_zeros(ans);
    if(cmp==-1) ans="-"+ans;
    return ans;
}
class addition{
public:
    string a,b,result;
    friend istream& operator >>(istream &in,addition &ob){
    cout<<"Enter the numbers :\n1st number "<<endl;
    in>>ob.a;
    cout<<"\n2nd number  ";
    in>>ob.b;}
    string calculate(void){
    result=add(a,b);
    cout<<"\nThe result is ";
    return result;
    }
    };
class subtract{
public:
    string a,b,result;
    friend istream& operator>>(istream &in,subtract &ob){
    cout<<"Enter the numbers :"<<endl;
    cout<<"1st number : ";
    in>>ob.a;
    cout<<"\n";
    cout<<"2nd number : ";
    in>>ob.b;
    }
string calculate(void)
{
    result=subtraction(a,b);
    cout<<"The result is ";
        return result;;
}};
class multiply{
public:
    string a,b,ans,str;
    friend istream& operator>>(istream &in,multiply &ob){
    cout<<"Enter the numbers :"<<endl;
    cout<<"1st number : ";
    in>>ob.a;
    cout<<"\n";
    cout<<"2nd number : ";
    in>>ob.b;
    }
    string calculate(void)
{   int tmp,carry;
    for(int i=a.size()-1; i>=0; i--){
        str="";
        for(int k=0; k<a.size()-i-1; k++) str+='0';
        carry=0;
        for(int j=b.size()-1; j>=0; j--)
        {   tmp=carry+(a[i]-'0')*(b[j]-'0');
            carry=tmp/10;
            tmp=tmp%10;
            str+=tmp+'0';
        }
        if(carry) str+=carry+'0';
        reverse(str.begin(),str.end());
        if(i==a.size()-1) ans=str;
        else ans=add(ans,str);
    }
    cout<<"\n The result is : "<<endl;
    return ans;
}};
class mods{
public:
     string a,b,ans,temp,mod;
    long long div;
    friend istream& operator>>(istream &in,mods &ob){
    cout<<"Enter the numbers :"<<endl;
    cout<<"Devidend : ";
    in>>ob.a;
    cout<<"\n";
    cout<<"Divisor : ";
    in>>ob.b;
    }
    string calculate(void){
    int cmp=compare(a,b);
    if(cmp==0){
        mod="0";
        div='1';
        return mod;
    }
    else if(cmp==-1){
        mod=a;
        div='0';
        return mod;
    }
     else {
    long long i;
    i++;
    temp=b;
    while(cmp==1){
    temp=add(temp,b);
    cmp=compare(a,temp);
    if(cmp==1) {
    ans=temp;
   i++;}
    if(i>1){
    mod=subtraction(a,ans);}
    else {mod=subtraction(a,b);}
    div=i+'0';
    return mod;
    }}
   long long division(void){
    return div;
    }}

    };
main()
{
    addition *ad;  subtract *sb; multiply *ml;mods *md;
    int choice;
   do{
        cout<<"\n\n\t\t\t###  Choose an option ###"<<endl;
        cout<<"1.addition\n2.subtraction\n3.multiplication\n4.division\n5.exit\nyour option "<<endl;
        cin>>choice;
        switch(choice){
    case 1:
        ad=new addition;
        cin>>*ad;
        cout<<ad->calculate();
        break;
    case 2:
        sb=new subtract;
        cin>>*sb;
        cout<<sb->calculate();
        break;
    case 3:
        ml=new multiply;
        cin>>*ml;
        cout<<ml->calculate();
        break;
    case 4:
        md=new mods;
        cin>>*md;
        cout<<" modulus  "<<md->calculate();
        cout<<"\n Quotient "<<md->division();
        break;
    default:
        cout<<"\nThank you"<<endl;
        cout<<"\t\t\t\t***************"<<endl;
       break;
        }
        }while(choice<5);
   return 0;
}
