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
            vector<bool> oki(n+1);
            for(int i=0;i<n;i++) orda[a[i]] = i, ordb[b[i]] = i;
            for(int i=0;i<n;i++) if(a[i] == b[i]) oki[a[i]] = true;
            set<int> nok;
            for(int i=1;i<=n;i++) {if(!oki[i]) nok.insert(i);}
            
                for(int i=0;i<n;i++){
                    if(oki[a[i]]) continue;
                    else{
                        auto x = nok.begin();
                        if(*x == a[i] || *x == b[i]) x++;
                        if(*x == a[i] || *x == b[i]) x++;
                        if(x == nok.end()){
                            ok = false;
                            break;
                        }
                        cout << *x << " ";
                        int v = orda[*x], u = ordb[*x];
                        swap(orda[a[i]], orda[*x]);
                        swap(orda[b[i]], orda[*x]);
                        swap(a[v], a[i]);
                        
                        swap(b[u], b[i]);
                        oki[*x] = true;
                        nok.erase(x);
                    }
                }
                cout << "\n";
                for(auto x: a) cout << x << " ";
                cout << "\n";
                for(auto x : b) cout << x << " ";
            
        }
    }
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
