#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<ll> fibo = {1, 2};
vector<int> ans, cur;
map<ll, bool> vis;
void fact(ll n){
    vis[n] = true;
    if(n == 1){
        ans = cur;
        return;
    }
    for(int i=fibo.size()-1;i>=1;i--){

        if(!(n % fibo[i])){
            if(!vis[n/fibo[i]]){
                cur.push_back(i);
                fact(n/fibo[i]);
                cur.pop_back();
            }
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    cin >> n;
    for(int i=2;;i++){
        ll fn = fibo[i-1] + fibo[i-2];
        if(fn > 1e15) break;
        fibo.push_back(fn);   
    }
    fact(n);
    if(ans.size()){
        for(auto x : ans){
            for(int j=0;j<x;j++) cout << "A";
            cout << "B";
        }
        cout << "\n";
    }else cout << "IMPOSSIBLE\n";
}
