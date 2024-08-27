#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll C[51][51];


void init(){
    C[0][0] = 1;
    for(int i=1;i<=50;i++){
        C[i][0] = 1;
        for(int j=1;j<50;j++){
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
        C[i][i] = 1;
    }
}

ll getkth(ll K, ll k){
    if(k == 0) return 0; //specific...
    //get kth number with K bits.
    ll ans = 0;
    ll sum = 0;
    int us = 0;
    for(int i=49;i>=0;i--){
        if(sum + C[i][K-us] < k && us < K){
            ans |= (1LL << i);
            sum += C[i][K-us];
            us++;
            
        }
    }
    return ans;
}



//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int n, K;
    cin >> n >> K;
    vector<ll> w(n);
    for(int i=0;i<n;i++) cin >> w[i];
    sort(w.begin(), w.end());
    ll A, B;
    cin >> A >> B;
    ll lo = 0, hi = C[n][K];
    ll ans1, ans2;
    while(lo != hi){
        ll mid = lo + (hi - lo + 1)/2;
        ll aux = getkth(K, mid);
        ll sum = 0;
        for(int i=0;i<n;i++){
            if(aux & (1LL << i)) sum += w[i];
        }
        if(sum < A) lo = mid;
        else hi = mid - 1;
    }
    ans1 = lo;
    lo = 0, hi = C[n][K];
    while(lo != hi){
        ll mid = lo + (hi - lo + 1)/2;
        ll aux = getkth(K, mid);
        ll sum = 0;
        for(int i=0;i<n;i++){
            if(aux & (1LL << i)) sum += w[i];
        }
        if(sum <= B) lo = mid;
        else hi = mid - 1;
    }
    ans2 = lo;
    cout << ans2 - ans1 << "\n";
}
