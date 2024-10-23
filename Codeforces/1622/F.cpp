#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6+1;
const int HASH = 2;
int p[N];
vector<vector<int>> vh(N, vector<int>(HASH)); //number hash
vector<vector<int>> hf(N, vector<int>(HASH)); //fatorial hash
vector<pair<vector<int>, int>> v1;
void sieve(int n){
    for(int i=2;i<=n;i++){
        if(!p[i]){
            for(int j=0;j<HASH;j++){
                vh[i][j] = uniform_int_distribution<int>(1, 2*((1 << 30) - 1) + 1)(rng); //32 bits
            }
            for(int j=2*i;j<=n;j+=i){
                if(!p[j]) p[j] = 1;
                int aux = j;
                while(!(aux % i)){
                    for(int k=0;k<HASH;k++){
                        vh[j][k] = vh[j][k] ^ vh[i][k];
                    }
                    aux /= i;
                }
            }
        }
    }
    v1.push_back({hf[0], 0});
    for(int i=2;i<=n;i++){
        for(int k=0;k<HASH;k++){
            hf[i][k] = hf[i-1][k] ^ vh[i][k];
        }
        v1.push_back({hf[i], i});
    }
    sort(v1.begin(), v1.end());

}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    vector<int> cur(HASH);
    int n;
    cin >> n;
    sieve(n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<HASH;j++){
            cur[j] ^= hf[i][j];
        }
    }
    int ans = -1;
    vector<int> oka(n+1, true);
    vector<pair<vector<int>, int>> v2;

    for(int i=0;i<=n;i++){
        vector<int> curt(HASH);
        for(int j=0;j<HASH;j++){
            curt[j] = cur[j] ^ hf[i][j];
        }
        v2.push_back({curt, i});
    }
    sort(v2.begin(), v2.end());
    int p0 = 0, p1 = 0;
    while(p0 < v1.size() && p1 < v2.size()){
        if(v1[p0].first == v2[p1].first){
            int u = v1[p0].second, v = v2[p1].second;
            ans = n;
            if(u != 0){
                ans--;
                oka[u] = false;
            }
            if(v != 0){
                ans--;
                oka[v] = false;
            }
            break;
        }else if(v1[p0].first < v2[p1].first) p0++;
        else p1++;
    }

    if(ans == -1){
        //ans = 3 and n is odd
        oka[n] = false;
        oka[n/2] = false;
        oka[2] = false;
        ans = n-3;
    }
    cout << ans << "\n";
    for(int i=1;i<=n;i++){
        if(oka[i]) cout << i << " ";
    }
    cout << "\n";


}
