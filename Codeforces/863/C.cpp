#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int a[4][4], b[4][4];
ll vis[4][4];
bool cmp(int a, int b){
    if(a == 1 && b == 3) return true;
    if(a == 2 && b == 1) return true;
    if(a == 3 && b == 2) return true;
    return false;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll k, ac, bc;
    cin >> k >> ac >> bc;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin >> b[i][j];
        }
    }
    ll cnt = 0;
    vector<pair<int,int>> vp = {{0, 0}};

    while(!vis[ac][bc]){
        vis[ac][bc] = ++cnt;
        vp.push_back({ac, bc});
        int aa = ac, ab = bc;
        ac = a[aa][ab];
        bc = b[aa][ab];
    }
    ll ansa = 0, ansb = 0;
    for(int i=1;i<min(vis[ac][bc], k+1);i++){
        if(cmp(vp[i].first, vp[i].second)) ansa++;
        if(cmp(vp[i].second, vp[i].first)) ansb++;
    }
    cnt++;
    for(int j=vis[ac][bc]; j<cnt;j++){
        ll mod = cnt - vis[ac][bc];
        if(k >= j){
            ll cur = (k - j + mod) / mod;
            if(cmp(vp[j].first, vp[j].second)) ansa += cur;
            if(cmp(vp[j].second, vp[j].first)) ansb += cur;
        }
    }
    cout << ansa << " " << ansb << "\n";
}
