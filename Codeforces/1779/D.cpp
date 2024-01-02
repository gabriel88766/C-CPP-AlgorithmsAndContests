#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


struct Intervals{
    set<pair<int,int>> s;
    Intervals(int n){
        s.insert({1, n});
    }
    void erase(int n){
        auto it = s.lower_bound({n, INF_INT});
        assert(it != s.begin());
        it = prev(it);
        int l1 = it->first, r1 = n-1;
        int l2 = n+1, r2 = it->second;
        s.erase(it);
        if(l1 <= r1) s.insert({l1, r1});
        if(l2 <= r2) s.insert({l2, r2}); 
    }

    pair<int,int> get(int n){
        auto it = s.lower_bound({n, INF_INT});
        assert(it != s.begin());
        it = prev(it);
        return *it;
    }


};

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
        Intervals in(n);

        bool ok = true;
        vector<int> a(n+1), b(n+1);
        map<int, vector<int>> rev;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++){
            cin >> b[i];
            rev[b[i]].push_back(i);
        }
        int k;
        cin >> k;
        map<int,int> cnt;
        for(int i=0;i<k;i++){
            int aux;
            cin >> aux;
            cnt[aux]++;
        }
        vector<int> bb;
        for(int i=1;i<=n;i++) bb.push_back(b[i]);
        sort(bb.begin(), bb.end(), greater<int>());
        bb.resize(unique(bb.begin(), bb.end()) - bb.begin());

        for(auto x : bb){
            auto &v = rev[x];
            set<pair<int,int>> sp;
            for(int i=0;i<v.size();i++){
                if(a[v[i]] < b[v[i]]){
                    ok = false;
                    break;
                }
                if(a[v[i]] != b[v[i]]){
                    auto p = in.get(v[i]);
                    sp.insert(p);
                }
            }
            if(!ok) break;
            if(sp.size() != 0 && sp.size() > cnt[x]){
                ok = false;
                break;
            }
            for(int i=0;i<v.size();i++){
                in.erase(v[i]); 
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}
