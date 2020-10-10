
#include <bits/stdc++.h>

using namespace std;

bool func(string a,string b){
   string s1,s2;
   s1 = a+b;
   s2 = b+a;
   return s1 < s2;

}


int main(){
int n;
string s;
vector<string> v;
cin >> n;
while(n--){
    cin >> s;
    v.push_back(s);
}
sort(v.begin(),v.end(),func);
for(int i=0;i<v.size();i++){
    cout << v[i];
}
}

