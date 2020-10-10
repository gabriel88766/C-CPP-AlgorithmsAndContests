#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int n,bp=0,aux;
vector<int> v,ans;
cin >> n;
for(int i=0;i<n;i++){

    cin >> aux;
    v.push_back(aux);
}
sort(v.begin(),v.end());
ans.assign(n,0);
for(int i=0;i<v.size();i+=2){
    ans[i] = v[bp++];
}
for(int i=1;i<v.size();i+=2){
    ans[i] = v[bp++];
}
for(int i=0;i<v.size();i++){
    cout << ans[i] << " ";
}
}

