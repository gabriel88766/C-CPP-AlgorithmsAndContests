#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k, q;
    cin >> n >> k >> q;
    multiset<int> ms1, ms2;
    for(int i=1;i<=k;i++) ms1.insert(0);
    for(int i=k+1;i<=n;i++) ms2.insert(0);
    ll sum = 0;
    vector<int> v(n+1, 0);
    for(int i=1;i<=q;i++){
        int x, y;
        cin >> x >> y;
        if(ms1.find(v[x]) != ms1.end()){
            ms1.erase(ms1.find(v[x]));
            sum -= v[x];
        }else{
            ms2.erase(ms2.find(v[x]));
        }
        v[x] = y;
        if(ms2.size() && *prev(ms2.end()) >= v[x]){
            ms2.insert(v[x]);
        }else{
            ms1.insert(v[x]);
            sum += v[x];
        }
        while(ms1.size() > k){
            sum -= *ms1.begin();
            ms2.insert(*ms1.begin());
            ms1.erase(ms1.begin());
        }
        while(ms1.size() < k){
            sum += *prev(ms2.end());
            ms1.insert(*prev(ms2.end()));
            ms2.erase(prev(ms2.end()));
        }   
        cout << sum << "\n";
    }
}
