#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bool infected[2005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, d;
    cin >> n >> d;
    int dsq = d*d;
    vector<pair<int,int>> p(n+1);
    for(int i=1;i<=n;i++){
        cin >> p[i].first >> p[i].second;
    }
    queue<int> q;
    q.push(1);
    infected[1] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(!infected[i]){
                int x = abs(p[u].first-p[i].first);
                int y = abs(p[u].second-p[i].second);
                int distsq = x*x+y*y;
                if(distsq <= dsq){
                    q.push(i);
                    infected[i] = true;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(infected[i]) cout << "Yes\n";
        else cout << "No\n";
    }
}
