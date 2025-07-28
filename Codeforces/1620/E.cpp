#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+3;
vector<int> an[N];
int ans[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int q;
    cin >> q;
    int cnt = 0;
    for(int i=0;i<q;i++){
        int tq, x, y;
        cin >> tq;
        if(tq == 1){
            cin >> x;
            an[x].push_back(++cnt);
        }else{
            cin >> x >> y;
            if(x == y) continue;
            if(an[y].size() < an[x].size()){
                an[y].swap(an[x]);
            }
            for(auto u : an[x]) an[y].push_back(u);
            an[x].clear();
        }
    }
    for(int i=1;i<=500000;i++){
        for(auto x : an[i]) ans[x] = i;
    }
    for(int i=1;i<=cnt;i++) cout << ans[i] << " ";
    cout << "\n";
}
