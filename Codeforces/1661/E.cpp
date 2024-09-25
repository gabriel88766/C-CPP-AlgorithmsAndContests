#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int adj[8][8]; //how many components this transition will increase
vector<int> tr[8][8];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=0;i<8;i++){
        for(int j=1;j<8;j++){
            bool ok = false;
            for(int k=0;k<3;k++){
                if(j & (1 << k)){
                    if(i & (1 << k)) ok = true;
                }
            }
            if(!ok) adj[i][j] = 1;
        }
    }
    adj[1][5] = adj[3][5] = adj[4][5] = adj[6][5] = 1;
    adj[0][5] = adj[2][5] = 2;
    int n;
    cin >> n;
    vector<int> v;
    string s[3];
    for(int i=0;i<3;i++){
        cin >> s[i];
    }
    for(int i=0;i<n;i++){
        int cur = 0;
        for(int j=0;j<3;j++) if(s[j][i] == '1') cur |= (1 << j);
        v.push_back(cur);
        if(i != 0){
            tr[v[i-1]][v[i]].push_back(i-1);
        }
    }

    vector<pair<int,int>> t5 = {{-1, -1}};
    int b5 = -1;
    for(int i=0;i<n;i++){
        if(v[i] == 5){
            if(b5 == -1) b5 = i;
        }else{
            if(b5 != -1) t5.push_back({b5, i-1});
            b5 = -1;
        }
    }
    if(b5 != -1) t5.push_back({b5, n-1});
    vector<int> ps(t5.size());
    for(int j=1;j<t5.size();j++){
        auto [a, b] = t5[j];
        ps[j] = ps[j-1];
        if(b < n-1 && v[b+1] == 7 && (a == 0 || v[a-1] != 7)){
            ps[j]--;
        }
    }


    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        int l, r;
        cin >> l >> r;
        --l, --r;
        ll ans = 0;
        for(int j=0;j<8;j++){
            for(int k=0;k<8;k++){
                if(adj[j][k] == 0) continue;
                auto tt = lower_bound(tr[j][k].begin(), tr[j][k].end(), r) - lower_bound(tr[j][k].begin(), tr[j][k].end(), l);
                ans += tt * adj[j][k];
            }
        }
        ans += adj[0][v[l]];
        auto it = lower_bound(t5.begin(), t5.end(), make_pair(l, 0));
        auto it2 = prev(lower_bound(t5.begin(), t5.end(), make_pair(r+1, 0)));
        if(prev(it)->second >= l) it = prev(it);
        if(it != t5.end() && it->first <= l){
            if(it->second < r && v[it->second + 1] == 7) ans--;
            it++;
        }
        if(it2->second >= r) --it2;
        int ind2 = it2-t5.begin();
        int ind1 = it-t5.begin();
        if(ind2 >= ind1){
            ans += ps[ind2] - ps[ind1-1];
        }
        cout << ans << "\n";
    }
}
