#include <bits/stdc++.h>
 
using namespace std;
const int N = 2e5+3;
int st[4*N], v[N], pr[4*N], su[4*N];
vector<int> alln[N];
 
void build(int p, int l, int r) {
  if (l == r) { st[p] = 1; pr[p] = 1; su[p] = 1; return; }
  build(2*p, l, (l+r)/2);
  build(2*p+1, (l+r)/2+1, r);
  st[p] = st[2*p] + st[2*p+1];
  pr[p] = pr[2*p] + pr[2*p+1];
  su[p] = su[2*p] + su[2*p+1];
}
 
void update(int p, int l, int r, int i) {
  if (r < i || l > i) return;
  if (l == r) { st[p] = 0; su[p] = 0; pr[p] = 0; return; }
  update(2*p, l, (l+r)/2, i);
  update(2*p+1, (l+r)/2+1, r, i);
  st[p] = max(su[2*p] + pr[2*p+1], max(st[2*p], st[2*p+1]));
  if(pr[2*p] == ((l+r)/2 - l +1)) pr[p] = pr[2*p] + pr[2*p+1];
  else pr[p] = pr[2*p];
  if(su[2*p+1] == (r - (l+r)/2)) su[p] = su[2*p] + su[2*p+1];
  else su[p] = su[2*p+1];
}
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    long long int ans = -1, cur;
    int n;
    int cont = 0;
    cin >> n;
    build(1,1,n);
    set<int> nums;
    map<int,int> mp;
    for(int i=1;i<=n;i++) {
        cin >> v[i];
        if(!nums.count(v[i])){
            mp[v[i]] = ++cont;
            nums.insert(v[i]);
        }
        alln[mp[v[i]]].push_back(i);
 
    }
 
    build(1,1,n);
    for(auto x: nums){
        cur = x;
        cur *= st[1];
        ans = max(ans, cur);
        for(int i = 0; i < alln[mp[x]].size(); i++){
            update(1 ,1 , n, alln[mp[x]][i]);
        }
    }
    cout << ans;
}