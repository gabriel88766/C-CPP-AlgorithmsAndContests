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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> c1(n+1, 0), c2(n+1, 0);
        for(int i=0;i<n;i++){
            int x, y;
            cin >> x >> y;
            c1[x]++;
            if(y == 1) c2[x]++;
        }


        vector<pair<int,int>> qt;
        for(int i=1;i<=n;i++){
            if(c1[i]){
                qt.push_back({c1[i], c2[i]});
            }
        }
        sort(qt.begin(), qt.end(), greater<pair<int,int>> ());
        int ans1 = 0, ans2 = 0;

        vector<int> sx;
        int ladd = qt[0].first;
        sx.push_back(ladd);
        ans1 += ladd;
        for(int i=1;i<qt.size();i++){
            if(ladd == 1) break;
            if(qt[i].first >= (ladd-1)){
                ladd--;
            }else{
                ladd = qt[i].first;
            }
            ans1 += ladd;
            sx.push_back(ladd);
        }
        priority_queue<int> pq;
        int p = 0;
        for(auto x : sx){
            while(p < qt.size() && qt[p].first >= x){
                pq.push(qt[p].second);
                p++;
            }
            assert(pq.size());
            ans2 += min(pq.top(), x);
            pq.pop();
        }
        cout << ans1 << " " << ans2 << "\n";
    }
}
