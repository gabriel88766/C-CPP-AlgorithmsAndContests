#include <bits/stdc++.h>
using namespace std;

int main(){
int curmax,maxt=-1;
string s;
cin >> s;
curmax=1;
for(int i=1;i<s.size();i++){
    if(s[i]==s[i-1]) curmax++;
    else{
        if(curmax>maxt) maxt=curmax;
        curmax=1;
    }
}
if(curmax>maxt) maxt=curmax;
cout << maxt;
}
