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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> vp(n+1);
        vector<int> l(n+1), r(n+1);
        for(int i=1;i<=n;i++){
            cin >> vp[i].first >> vp[i].second;
        }
        vector<tuple<int,int,int>> vt;
        for(int i=1;i<=n;i++){
            vt.push_back({vp[i].first, vp[i].second, i});
        }
        sort(vt.begin(), vt.end());
        multiset<int> ms;
        int p = 0;
        while(p < vt.size()){
            int pi = p, pe = p;
            while(pe+1 < vt.size() && get<0>(vt[pe+1]) == get<0>(vt[pi])) pe++;
            for(int i=pi;i<=pe;i++){
                ms.insert(get<1>(vt[i]));
            }
            for(int i=pi;i<=pe;i++){
                auto [ll, rr, j] = vt[i];
                auto it = ms.lower_bound(rr);
                if(next(it) == ms.end()) r[j] = rr;
                else  r[j] = *next(it);
            }
            p = pe + 1;
        }
        ms.clear();
        sort(vt.begin(), vt.end(), [&](tuple<int,int,int> &a, tuple<int,int,int> &b){
            if(get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);
            else return a < b;
        });
        p = 0;
        while(p < vt.size()){
            int pi = p, pe = p;
            while(pe+1 < vt.size() && get<1>(vt[pe+1]) == get<1>(vt[pi])) pe++;
            for(int i=pi;i<=pe;i++){
                ms.insert(-get<0>(vt[i]));
            }

            for(int i=pi;i<=pe;i++){
                auto [ll, rr, j] = vt[i];
                auto it = ms.lower_bound(-ll);
                if(next(it) == ms.end()) l[j] = ll;
                else l[j] = -(*next(it));
            }
            p = pe + 1;
        }
        for(int i=1;i<=n;i++){
            // cout << l[i] << " " << r[i] << "\n";
            cout << vp[i].first - l[i] + r[i] - vp[i].second << "\n";
        }

    }
}
