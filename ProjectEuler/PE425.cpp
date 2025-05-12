#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e7+5;
int p[N]; // 0 if prime, 1 if not prime
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
        }
    }
}
int lp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    p[1] = 1;
    sieve();
    memset(lp, 63, sizeof(lp));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({2, 2});
    lp[2] = 2;
    const int M = 10000000;
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if(lp[u] < d) continue;
        for(int i=1;i<=9;i++){
            string c;
            c += ('0' + i);
            string n1 = c + to_string(u);
            int num1 = stoi(n1);
            if(num1 <= M && p[num1] == 0 && lp[num1] > max(num1, d)){
                lp[num1] = max(num1, d);
                pq.push({lp[num1], num1});
            }
        }
        string s = to_string(u);
        for(int i=0;i<s.size();i++){
            for(int j=0;j<=9;j++){
                if(i == 0 && j == 0) continue;
                string cn = s;
                cn[i] = j + '0';
                int cnn = stoi(cn);
                if(cnn <= M && p[cnn] == 0 && lp[cnn] > max(cnn, d)){
                    lp[cnn] = max(cnn, d);
                    pq.push({lp[cnn], cnn});
                }
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=M;i++) if(p[i] == 0 && lp[i] != i) ans += i;
    cout << ans << "\n";
}
