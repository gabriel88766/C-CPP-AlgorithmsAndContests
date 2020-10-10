#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int n,p,q,contp,contq=0,R;
string s;
vector <string> v;
cin >> n >> p >> q;
cin >> s;
contp = n/p;

while(contp!=-1){
    R = contp*p + contq*q;
    if(R==n) break;
    while(R<n){
        contq++;
        R = contp*p + contq*q;
    }
    if(R==n) break;
    else contp--;
}
if(contp==-1) cout << -1;
else{
    int bp = 0;
    while(contp){
        contp--;
        v.push_back(s.substr(bp,p));
        bp+=p;
    }
    while(contq){
        contq--;
        v.push_back(s.substr(bp,q));
        bp+=q;
    }
    cout << v.size() << endl;
    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
    }
}

}
