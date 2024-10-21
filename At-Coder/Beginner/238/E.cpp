#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> seg[N], rev[N];
bool dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    //gaussian
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=q;i++){
        int l, r;
        cin >> l >> r;
        seg[l].push_back(r);
        rev[r].push_back(l-1);
    }
    dp[0] = 1;
    queue<int> qr;
    qr.push(0);
    while(!qr.empty()){
        auto u = qr.front();
        qr.pop();
        for(auto x : seg[u+1]){
            if(!dp[x]){
                dp[x] = 1;
                qr.push(x);
            }
        }
        for(auto x : rev[u]){
            if(!dp[x]){
                dp[x] = 1;
                qr.push(x);
            }
        }
    }
    if(dp[n]) cout << "Yes\n";
    else cout << "No\n";
}
