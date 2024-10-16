#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1 << 18;
const int M = 18;
int tp[M+1][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in", "r", stdin); //test input
    int n;
    string s;
    cin >> n >> s;
    int sz = s.size();
    
    for(int i=0;i<=n;i++){
        if(i == 0){
            for(int j=0;j<sz;j++){
                tp[i][j] = s[j] - 'a';
            }
        }else{
            vector<pair<int,int>> nt;
            for(int j=0;j<sz;j++){
                nt.push_back({tp[i-1][j], tp[i-1][j ^ (1 << (i-1))]});
            }
            sort(nt.begin(), nt.end());
            nt.resize(unique(nt.begin(), nt.end()) - nt.begin());
            for(int j=0;j<sz;j++){
                tp[i][j] = lower_bound(nt.begin(), nt.end(), make_pair(tp[i-1][j], tp[i-1][j ^ (1 << (i-1))])) - nt.begin();
            }
        }
    }
    string ans(sz, '.');
    int bst = -1;
    for(int j=0;j<sz;j++) if(tp[n][j] == 0) bst = j;
    assert(bst != -1);
    for(int j=0;j<sz;j++) ans[j] = s[j^bst];
    cout << ans << "\n";
}   
