#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+3;
int cnt[N];
vector<int> ind[N];
int ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int aux;
        cin >> aux;
        if(aux > m) continue;
        ind[aux].push_back(i);
        cnt[aux]++;
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j+=i){
            ans[j] += cnt[i];
        }
    }
    int rans = 0, lc = 1;
    for(int i=1;i<=m;i++){
        if(ans[i] > rans){
            rans = ans[i];
            lc = i;
        }
    }
    vector<int> vans;
    for(int i=1;i<=lc;i++){
        if(lc % i) continue;
        for(auto x : ind[i]) vans.push_back(x);
    }
    assert(rans == vans.size());
    sort(vans.begin(), vans.end());
    cout << lc << " " << vans.size() << "\n";
    for(auto x : vans) cout << x << " ";
    cout << "\n";
}
