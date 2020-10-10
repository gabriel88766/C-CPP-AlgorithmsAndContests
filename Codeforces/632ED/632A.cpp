
#include <bits/stdc++.h>

using namespace std;

int main(){
vector<string> v;
string s;
long long int n,p,qt=0,total=0;
cin >> n >> p;
for(int i=0;i<n;i++){
    cin >> s;
    v.push_back(s);
}
reverse(v.begin(),v.end());
for(int i=0;i<n;i++){
    if(v[i]=="halfplus"){
        qt = 2*qt+1;
        total += p/2 * qt;
    }
    else{
        total += p*qt;
        qt = 2*qt;
    }
}
cout << total;
}
