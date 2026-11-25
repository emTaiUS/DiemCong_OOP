#include "eztrans.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

std::string Captain:: dec_to_bin(int x,int n){
    string res="";
    while(x!=0){
        res=res+to_string(x%2);
        x/=2;
    }
    while((int)res.length()<n){
        res+='0';
    }
    reverse(res.begin(),res.end());
    return res;
}


std::string Captain :: encode(std::string time){
    for(auto& x:time){
        if(x==':') x=' ';
    }
    stringstream ss(time);

    string res="";
    string temp;
    
    ss >> temp;
    res=res+dec_to_bin(stoi(temp),5);
    
    ss >> temp;
    res=res+dec_to_bin(stoi(temp),6);
    
    ss >> temp;
    res=res+dec_to_bin(stoi(temp),6);
    
    return res;
}

Soldier :: Soldier():id(-1){}

Soldier :: Soldier(int id):id(id){}

std::string Soldier :: bin_to_dec(std::string x,int n){
    int res=0;
    int a=1;
    for(int i=n-1;i>=0;i--){
        if(x[i]=='1') res+=a;
        a*=2;
    }
    string ans=to_string(res);
    if(ans.length()!=2) ans ="0"+ans ;
    return ans;
}

std::string Soldier ::split_bin(std::string x,int l,int r){
    string res="";
    for(int i=l;i<=r;i++){
        res+=x[i];
    }
    return res;
}

std::string Soldier:: decode(std::string s){
    string hh=split_bin(s,0,4);
    string mm=split_bin(s,5,10);
    string ss=split_bin(s,11,16);

    hh=bin_to_dec(hh,5);
    mm=bin_to_dec(mm,6);
    ss=bin_to_dec(ss,6);

    string res=hh+":"+mm+":"+ss;
    return res;
}

Captain ::Captain() {};

// int main(){
//     Captain a;
//     Soldier b(1);

//     string bin=a.encode("12:05:36");
//     string res=b.decode(bin);

//     cout <<bin<<'\n'<<res<<'\n';

// }