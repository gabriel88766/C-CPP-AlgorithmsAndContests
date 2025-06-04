#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<vector<ll>> multMatrix(vector<vector<ll>> a, vector<vector<ll>> b){
    int size = a.size();
    vector<vector<ll>> ans(size, vector<ll>(size));
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            ll cel = 0;
            for(int k=0;k<size;k++){
                cel = (cel + a[i][k] * b[k][j]);
            }
            ans[i][j] = cel;
        }
    }
    return ans;
}

vector<vector<ll>> rot1 = {{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}};
vector<vector<ll>> rot2 = {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
vector<vector<ll>> tr1 = {{-1, 0, 0}, {0, 1, 0}, {0, 0, 1}}; // tr1[0][2] = 2*p
vector<vector<ll>> tr2 = {{1, 0, 0}, {0, -1, 0}, {0, 0, 1}}; //tr2[1][2] = 2*p


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<pair<ll, ll>> vx(n+1);
    for(int i=1;i<=n;i++){
        cin >> vx[i].first >> vx[i].second;
    }
    int m;
    cin >> m;
    vector<vector<vector<ll>>> tr(m+1);
    tr[0] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    for(int i=1;i<=m;i++){
        vector<vector<ll>> xx;
        int x;
        cin >> x;
        if(x == 1) xx = rot1;
        else if(x == 2) xx = rot2;
        else if(x == 3){
            int p;
            cin >> p;
            tr1[0][2] = 2*p;
            xx = tr1;
        }else{
            int p;
            cin >> p;
            tr2[1][2] = 2*p;
            xx = tr2;
        }
        tr[i] = multMatrix(xx, tr[i-1]);
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        ll a, b;
        cin >> a >> b;
        ll x = tr[a][0][0] * vx[b].first + tr[a][0][1] * vx[b].second + tr[a][0][2];
        ll y = tr[a][1][0] * vx[b].first + tr[a][1][1] * vx[b].second + tr[a][1][2];
        cout << x << " " << y << "\n";

    }
}
 