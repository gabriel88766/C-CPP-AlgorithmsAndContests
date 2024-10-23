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
        ll tt = 0;
        vector<vector<ll>> vec(3, vector<ll>(n+1));
        for(int i=1;i<=n;i++){
            cin >> vec[0][i];
            tt += vec[0][i];
            vec[0][i] += vec[0][i-1];
        }
        for(int i=1;i<=n;i++){
            cin >> vec[1][i];
            vec[1][i] += vec[1][i-1];
        }
        for(int i=1;i<=n;i++){
            cin >> vec[2][i];
            vec[2][i] += vec[2][i-1];
        }
        ll tt3 = (tt+2)/3;
        vector<int> perm = {0, 1, 2};
        bool ok = false;
        vector<pair<int,int>> ans(3);
        do{
            int r0 = -1, r1 = -1;
            auto it = lower_bound(vec[perm[0]].begin(), vec[perm[0]].end(), tt3);
            r0 = it - vec[perm[0]].begin();
            auto it2 = lower_bound(vec[perm[1]].begin(), vec[perm[1]].end(), tt3 + vec[perm[1]][r0]);
            if(it2 != vec[perm[1]].end()){
                r1 = it2 - vec[perm[1]].begin();
                auto it3 = lower_bound(vec[perm[2]].begin(), vec[perm[2]].end(), tt3 + vec[perm[2]][r1]);
                if(it3 != vec[perm[2]].end()){
                    ok = true;
                    ans[perm[0]] = {1, r0};
                    ans[perm[1]] = {r0+1, r1};
                    ans[perm[2]] = {r1+1, n};
                    break;
                }
            }
        }while(next_permutation(perm.begin(), perm.end()));

        if(!ok) cout << -1 << "\n";
        else{
            for(auto x : ans) cout << x.first << " " << x.second << " ";
            cout << "\n";
        }

    }
}
