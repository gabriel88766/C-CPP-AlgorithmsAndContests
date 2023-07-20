#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
vector<int> adj[N];

//cout << fixed << setprecision(6)
int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> segs(n+1);
        for(int i=1;i<=n;i++) cin >> segs[i].first >> segs[i].second;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(!(segs[i].first >= segs[j].second || segs[i].second <= segs[j].first)){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    cout << i << " " << j << endl;
                }
            }
        }
    }
}
