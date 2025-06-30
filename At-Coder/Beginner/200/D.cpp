#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll v[200];
int ms[200];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    for(int j=0;j<n;j++) cin >> v[j];
    memset(ms, 0xFF, sizeof(ms));
    int msk = (n >= 10 ? 1024 : 1 << n);
    pair<int, int> ans = {-1, -1};
    for(int i=1;i<msk;i++){
        ll cs = 0;
        for(int j=0;(1 << j)<=i;j++){
            if(i & (1 << j)){
                cs += v[j];
            }
        }
        if(ms[cs % 200] != -1){
            ans = {ms[cs % 200], i};
            break;
        }
        ms[cs % 200] = i;
    }
    if(ans != make_pair(-1, -1)){
        cout << "Yes\n";
        cout << __builtin_popcount(ans.first) << " ";
        for(int j=0;(1 << j) <= ans.first;j++){
            if(ans.first & (1 << j)){
                cout << j+1 << " ";
            }
        }
        cout << "\n";
        cout << __builtin_popcount(ans.second) << " ";
        for(int j=0;(1 << j) <= ans.second;j++){
            if(ans.second & (1 << j)){
                cout << j+1 << " ";
            }
        }
        cout << "\n";
    }else cout << "No\n";
}
