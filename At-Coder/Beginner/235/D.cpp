#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1'000'000;
int d[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll a, n;
    cin >> a >> n;
    for(int i=2;i<N;i++) d[i] = INF_INT;
    //1 -> n
    //op1 , do x -> a*x
    //op2 , do x= a1a2a3...ak = aka1a2...ak-1
    //run bfs, digits on number never decrease :) so if more than 7 digits, never less.
    queue<ll> q;
    q.push(1);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        if(u % 10 && u > 10){
            string s = to_string(u);
            string ns = s.back() + s.substr(0, s.size()-1);
            int dst = stoi(ns);
            if(d[dst] > d[u] + 1){
                d[dst] = d[u] + 1;
                q.push(dst);
            }
        }
        ll dst2 = a * u;
        if(dst2 < N && d[dst2] > d[u] + 1){
            d[dst2] = d[u] + 1;
            q.push(dst2);
        }
    }
    if(d[n] != INF_INT) cout << d[n] << "\n";
    else cout << "-1\n";

}
