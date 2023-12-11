#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void calc(map<vector<int>, int> &mp, vector<int> &p){
    queue<vector<int>> q;
    q.push(p);
    mp[p] = 0;
    while(!q.empty()){
        auto v = q.front();
        q.pop();
        for(int i=1;i<p.size();i++){
            auto dst = v;
            swap(dst[i-1], dst[i]);
            if(!mp.count(dst)){
                mp[dst] = mp[v] + 1;
                q.push(dst);
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    map<vector<int>, int> mph;
    map<vector<int>, int> mpw;
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<int>> b(h, vector<int>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> b[i][j];
        }
    }
    vector<int> ph;
    vector<int> pw;
    for(int i=0;i<h;i++) ph.push_back(i);
    for(int i=0;i<w;i++) pw.push_back(i);
    auto x = ph;
    calc(mph, x);
    x = pw;
    calc(mpw, x);
    int ans = INF_INT;
    do{
        do{
            bool ok = true;
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    if(a[ph[i]][pw[j]] != b[i][j]) ok = false;
                }
            }
            if(ok) ans = min(ans, mph[ph] + mpw[pw]);
        }while(next_permutation(pw.begin(), pw.end()));
    }while(next_permutation(ph.begin(), ph.end()));
    if(ans == INF_INT) cout << "-1\n";
    else cout << ans << "\n";
}
