
#include <bits/stdc++.h>

using namespace std;

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int n,m,curmin,aux,ans=0;
cin >> n >> m;
vector<int> minimum;
for(int i=0;i<n;i++){
    curmin=0x3f3f3f3f;
    for(int j=0;j<m;j++){
        cin >> aux;
        curmin = min(curmin,aux);
    }
    minimum.push_back(curmin);
}
for(int i=0;i<n;i++){
    ans = max(ans,minimum[i]);
}
cout << ans;
}
