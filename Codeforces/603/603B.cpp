#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
const ll MOD = 1e9+7;
vector<char> visited(1000005,0);

ll fexp(ll a, ll b, ll m = MOD) {
  ll r=1;
  for (a %= m; b; b>>=1, a=(a*a)%m) if (b&1) r=(r*a)%m; //mulmod for a  > 2e9
  return r;
}

int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
ll bp=1,p,k,cp,cont=0;
cin >> p >> k;
while(bp<p && k!=0){
    cont++;
    while(!visited[bp]){
        visited[bp]=true;
        bp = (bp*k)%p;
    }
    while(visited[bp]) bp++;
}
if(k==1) cont++;
if(k==0) cont=p-1;
cout << fexp(p,cont);
}
