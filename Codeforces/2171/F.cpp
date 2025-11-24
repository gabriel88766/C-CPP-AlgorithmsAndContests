#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N], gr[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1; gr[i] = i;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
    gr[a] = max(gr[a], gr[b]);
}

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
        init(n);
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        set<int> s;
        vector<pair<int, int>> ans;
        for(int i=1;i<=n;i++) s.insert(i);
        int px = n;
        for(int i=1;i<=n;i++){
            int x = v[i];
            s.erase(x); //only numbers that come after.
            while(px >= x){
                if(s.count(px)){
                    assert(get(x) != get(px));
                    unite(x, px);
                    ans.push_back({x, px});
                }
                px--;
            }
            auto it = s.end();
            if(it != s.begin()){
                it = prev(it);
                if(*it >= x){
                    if(get(x) != get(*it)){
                        unite(x, *it);
                        ans.push_back({x, *it});
                    }
                }
            }
        }
        if(ans.size() == n-1){
             cout << "Yes\n";
             for(auto [a, b] : ans) cout << a << " " << b << "\n";
        }
        else cout << "No\n";
    }
}
