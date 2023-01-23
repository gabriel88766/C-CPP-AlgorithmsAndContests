#include <bits/stdc++.h>
 
using namespace std;
 
 const int N=1e5+3;
const int M=18; //log2(N)
int v[N];
int n,k,ans=1,bp,ep;
int sparse[N][M];
int sparse2[N][M];
 
void build() {
  for(int i = 0; i < n; i++)
    sparse[i][0] = v[i];
 
  for(int j = 1; j < M; j++)
    for(int i = 0; i < n; i++)
      sparse[i][j] = 
        i + (1 << j - 1) < n
        ? min(sparse[i][j - 1], sparse[i + (1 << j - 1)][j - 1]) 
        : sparse[i][j - 1];
}
 
int query(int a, int b){
  int pot = 32 - __builtin_clz(b - a) - 1;
  return min(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}
 
void build2() {
  for(int i = 0; i < n; i++)
    sparse2[i][0] = v[i];
 
  for(int j = 1; j < M; j++)
    for(int i = 0; i < n; i++)
      sparse2[i][j] = 
        i + (1 << j - 1) < n
        ? max(sparse2[i][j - 1], sparse2[i + (1 << j - 1)][j - 1]) 
        : sparse2[i][j - 1];
}
 
int query2(int a, int b){
  int pot = 32 - __builtin_clz(b - a) - 1;
  return max(sparse2[a][pot], sparse2[b - (1 << pot) + 1][pot]);
}
 
 
 
 
 
int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
cin >> n >> k;
for(int i=0;i<n;i++){
    cin >> v[i];
}
build();
build2();
vector<pair<int,int>> vp;
bp = 0;
ep = 0;
while(ep<n){
    int dif;
    if(ep!=bp) dif = abs(query2(bp,ep)-query(bp,ep));
    else dif = 0;
    if(dif>k){
        bp++;
    }else{
        ans = max(ans,ep-bp+1);
        ep++;
    } 
}
if(ans>1){
    for(int i=0;i<=(n-ans);i++){
        if(abs(query(i,i+ans-1)-query2(i,i+ans-1)) <= k){
            vp.push_back(make_pair(i+1,i+ans));
        }
    }
}else{
    for(int i=0;i<=(n-ans);i++){
        vp.push_back(make_pair(i+1,i+1));
    }
}
cout << ans << " " << vp.size() << " " << endl;
for(int i=0;i<vp.size();i++){
    cout << vp[i].first << " " << vp[i].second << endl;
}
}