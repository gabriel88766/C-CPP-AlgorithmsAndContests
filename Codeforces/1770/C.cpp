#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

bool used[100][100];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(used, 0, sizeof(used));
        vector<ll> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        ll curdif = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ll dif = v[j] - v[i];
                for(auto x : primes){
                    if(!(dif % x)){
                        ll curused = ((dif % x) + x - (curdif % x)) % x;
                        used[x][curused] = true;
                    }
                }
            }
            if(i!=(n-1)) curdif += (v[i+1]-v[i]);
        }
        bool ok = true;
        for(auto x : primes){
            bool ok2 = false;
            for(int j=0;j<x;j++) if(!used[x][j]) ok2 = true;
            if(!ok2){
                ok = false;
                break;
            }
        }
        for(int i=1;i<n;i++) if(v[i] == v[i-1]) ok = false;
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
