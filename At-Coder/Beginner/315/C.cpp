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
    vector<pair<int, int>> vp;
    for(int i=0;i<n;i++){
        int f, s;
        cin >> f >> s;
        vp.push_back({s, f});
    }
    sort(vp.begin(), vp.end(), greater<pair<int,int>>());
    int op1 = vp[0].first + vp[1].first/2;
    int op2 = vp[0].first;
    for(int i=1;i<n;i++){
        if(vp[i].second != vp[0].second){
            op2 += vp[i].first;
            break;
        }
    }
    cout << max(op1, op2) << "\n";
}
