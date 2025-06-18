#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 505;
int l[N], r[N], outdg[N], ans[N];
vector<int> adj[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;   
        for(int i=1;i<=n;i++) cin >> l[i] >> r[i];
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(l[i] < l[j] && r[j] < r[i]){
                    adj[i].push_back(j);
                    outdg[j]++;
                }else if(l[j] < l[i] && r[i] < r[j]){
                    //p[j] > p[i];
                    adj[j].push_back(i);
                    outdg[i]++;
                }//else if(max(l[i], l[j]) < min(r[i], r[j])){
                    //intersect
                    //doesnt matter
                //}//else doesnt matter either
            }
        }

        //Course Schedule II - cses
        priority_queue<int> pq;
        vector<int> topo;
        for(int i=1;i<=n;i++) if(outdg[i] == 0) pq.push(i);
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            topo.push_back(u);
            for(auto v : adj[u]){
                outdg[v]--;
                if(outdg[v] == 0) pq.push(v);
            }
        }
        reverse(topo.begin(), topo.end());
        for(int i=0;i<topo.size();i++){
            ans[topo[i]] = i + 1;
        }
        for(int i=1;i<=n;i++) cout << ans[i] << " ";
        cout << "\n";
        //clear
        for(int i=1;i<=n;i++){
            adj[i].clear();
            ans[i] = 0;
        }
    }
}
