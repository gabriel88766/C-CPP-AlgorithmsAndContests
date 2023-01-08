#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+6;
 
ll bit[N];
ll v[N];
int n;
 
ll query(int b){ // sum in range [1, b]
    ll ans = 0;
    for(int i = b; i > 0; i -= i & -i){
        ans += bit[i];
    }
    return ans;
}
 
void add(int b, ll value){ //add value to position b
    for(int i = b; i <= n; i += i & -i){
        bit[i] += value;
    }
}
 
void build(){
    for(int i=1;i<=n;i++) add(i, v[i]);
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    build();
    for(int i=0;i<q;i++){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a == 1){
            ll num = query(b) - query(b-1);
            add(b, c-num);
        }else{
            cout << query(c) - query(b-1) << endl; 
        }
    }
}