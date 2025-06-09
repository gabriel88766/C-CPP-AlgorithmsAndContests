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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    auto x = a;
    auto y = b;
    bool ok = true;
    sort(x.begin(), x.end()); sort(y.begin(), y.end());
    for(int i=0;i<n;i++) if(x[i] != y[i]) ok = false;
    if(ok){
        int sz = unique(x.begin(), x.end()) - x.begin();
        if(sz == n){
            //greedy...
            vector<int> orda(n+1), ordb(n+1);
            for(int i=0;i<n;i++) orda[a[i]] = i, ordb[b[i]] = i;
            set<int> nus;
            for(int i=1;i<=n;i++) nus.insert(i);
            for(int i=0;i<n-2;i++){
                if(a[i] == b[i]){
                    nus.erase(a[i]);
                    continue;
                }
                assert(nus.size() >= 3);
                int e = *nus.begin(), d = *next(nus.begin()), c = *next(next(nus.begin()));
                int ch;
                if(e != a[i] && e != b[i]){
                    ch = e;
                }else if(d != a[i] && d != b[i]){
                    ch = d;
                }else{
                    ch = c;
                }
                nus.erase(ch);
                int oa = a[i], ob = b[i];
                swap(a[orda[ch]], a[i]);
                swap(b[ordb[ch]], b[i]);
                swap(orda[ch], orda[oa]);
                swap(ordb[ch], ordb[ob]);
            }
            if(a != b) ok = false;
            
        }
    }   
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
