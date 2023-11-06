#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void calc(vector<int> &v, int k){
    int n = v.size();
    vector<int> ans(n);
    int cur = 0;
    for(int j=0; j < (1 << k); j++) cur ^= v[j];
    ans[0] = cur;
    int p = (1 << k)%n;
    for(int j=1;j<n;j++){
        cur ^= (v[j-1]);
        cur ^= v[p];
        ans[j] = cur;
        p++;
        if(p >= n) p -= n;
    }
    v = ans;
}
int solve(vector<int> &v){
    int n = v.size();

    for(int i=1;(1 << i)<=n;i++){
        int cur = 0;
        for(int j=0;j<(1 << i); j++) cur ^= v[j];
        if(cur != 0) continue;
        bool ok = true;
        int p = (1 << i)%n;
        for(int j=1;j<n;j++){
            cur ^= (v[j-1]);
            cur ^= v[p];
            if(cur != 0){
                ok = false;
                break;
            }
            p++;
            if(p >= n) p -= n;
        }
        if(!ok) continue;
        if(i != 1){
            calc(v, i-1);
            return ((1 << (i-1))-1) + solve(v);
        }else{
            return 1;
        }   
    }
    return n;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    bool a0 = true;
    for(int i=0;i<n;i++) if(v[i] != 0) a0 = false;
    if(a0) cout << "0\n";
    else cout << solve(v) << "\n";

    
}
