#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> divs[N], mult[N];
int sub[N];
void init(){
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            divs[j].push_back(i);
            mult[i].push_back(j);
        }
    }
    for(int i=2;i<N;i++){
        int cur = i;
        for(int j=0;j<divs[i].size();j++){
            if(i == divs[i][j]) break;
            cur += divs[i][j];
            cur -= sub[divs[i][j]];
        }
        sub[i] = cur - i;
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        vector<vector<int>> indx(N);
        for(int i=0;i<n;i++){
            for(auto d : divs[v[i]]){
                indx[d].push_back(i);
            }
        }
        ll ans = 0;
        for(int i=1;i<N;i++){
            if(indx[i].size()){
                ll cur = 0;
                for(int j=1;j<indx[i].size();j++){
                    ll chl = j;
                    ll chr = n-1-indx[i][j];
                    cur += chl*chr;
                }
                ans += cur*i - cur*sub[i];
            }
        }
        cout << ans << "\n";
    }
}
