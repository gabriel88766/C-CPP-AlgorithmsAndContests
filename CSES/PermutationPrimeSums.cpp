#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
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

pair<vector<int>, vector<int>> ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int mx = 0,cx = 0;
    for(int i=1;i<N;i++){
        if(p[i] == 0) cx = 0;
        else cx++;
        mx = max(cx, mx);
    }
    assert(cx <= 100);
    sieve();
    for(int i=1;i<=100;i++){ //there is no 2 primes lower than 200000 with distance > 100
        bool ok = false;
        for(int j=1;j<=i;j++){
            if(p[i+j] == 0){
                ok = true;
                for(int k=j;k<=i;k++){
                    int an = i + j - k;
                    ans[i].first.push_back(k);
                    ans[i].second.push_back(an);
                }
                for(int k=0;k<j-1;k++){
                    ans[i].first.push_back(ans[j-1].first[k]);
                    ans[i].second.push_back(ans[j-1].second[k]);
                }
                break;
            }
        }
        if(!ok){
            cout << i << "\n";
            assert(false);
            break;
        }
    }
    int n;
    cin >> n;
    for(int j=1;j<=n;j++){
        if(p[n+j] == 0){
            for(int k=j;k<=n;k++){
                int an = n + j - k;
                ans[n].first.push_back(k);
                ans[n].second.push_back(an);
            }
            for(int k=0;k<j-1;k++){
                ans[n].first.push_back(ans[j-1].first[k]);
                ans[n].second.push_back(ans[j-1].second[k]);
            }
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout << ans[n].first[i] << " ";
    }
    cout << "\n";
    for(int i=0;i<n;i++){
        cout << ans[n].second[i] << " ";
    }
    cout << "\n";
}
