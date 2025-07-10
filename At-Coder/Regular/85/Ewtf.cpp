#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bitset<101> bs[101];
vector<int> cv;
vector<ll> v;
int mx = 33, n;

ll mn = 0;
void check(){
    bitset<101> cb;
    for(auto x : cv) cb |= bs[x];
    //gonna check now.
    //this is not ideal, but ...
    ll cur = 0;
    for(int i=1;i<=n;i++){
        if(i >= 68){
            if(i % 2){  //69 71 73 ...
                if(cb[i]) cur += v[i];
                else cur += min(0LL, v[i]);
            }
        }else if(i >= 34){ //34, 35, ..., 67
            if(2*i <= n){ //(34, 68), (35, 70), (36, 72), ... (49, 98)
                if(cb[i]){
                    cur += v[i] + v[2*i];
                }else if(cb[2*i]){
                    cur += v[2*i];
                    if(v[i] < 0) cur += v[i];
                }else{
                    cur += min({0LL, v[i] + v[2*i], v[2*i]});
                }
            }else{
                if(cb[i]) cur += v[i];
                else cur += min(0LL, v[i]);
            }
        }else{
            if(cb[i]) cur += v[i];
        }
    }
    mn = min(cur, mn);


    int bg = cv.size() ? cv.back() + 1 : 1;
    for(int i=bg; i <= mx; i++){
        if(cb[i]) continue;
        cv.push_back(i);
        check();
        cv.pop_back();
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=1;i<=100;i++){
        for(int j=i;j<=100;j+=i){
            bs[i][j] = 1;
        }
    }
    cin >> n;
    v.resize(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    check();
    ll sum = 0;
    for(int i=1;i<=n;i++) sum += v[i];
    cout << sum - mn << "\n";
}
