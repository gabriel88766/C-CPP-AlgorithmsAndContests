#include <bits/stdc++.h>

using namespace std;
const int N = 200005;
const int M = 19;
int sparse[N][M];
int n,vs[N];

void build() {
for(int i = 0; i < n; i++)
    sparse[i][0] = vs[i];
 for(int j = 1; j < M; j++)
  for(int i = 0; i + (1 << j) <= n; i++)
  sparse[i][j] = max(sparse[i][j - 1], sparse[i + (1 << j - 1)][j - 1]); // If sum, "+"
}



int query(int a, int b){ // RMQ O(1)
 int pot = a == b ? 0 : 32 - __builtin_clz(b - a) - 1; //fixed bug for query(a,a)
return max(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}




int main(){
ios_base::sync_with_stdio(0),cin.tie(0);
int t,k,aux,ans;
cin >> t;
while(t--){
    cin >> n >> k;
    ans = -1;
    if(n==1){
        cin >> aux >> aux;
       cout << 1 << endl;
       continue;
    } else if(n==2){
        cin >> aux >> aux >> aux >> aux;
        cout << 2 << endl;
        continue;
    }
    vector<int> v(n,0);
    int dp1[n],bp=0,ep=n-1;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }for(int i=0;i<n;i++){
        cin >> aux;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        while((v[i]-v[bp]) > k) bp++;
        dp1[i] = i-bp+1;
    }
    for(int i=(n-1);i>=0;i--){
        while((v[ep]-v[i]) > k) ep--;
        vs[i] = ep-i+1;
    }

    build();

    for(int i=0;i<n;i++){
        auto it = lower_bound(v.begin(),v.end(),v[i]+1);
        int num = it-v.begin();
        if(it!=v.end()){
            ans = max(ans,dp1[i]+query(num,n-1));
        }else{
            ans = max(ans,dp1[i]);
        }
    }
    cout << ans << endl;
}


}