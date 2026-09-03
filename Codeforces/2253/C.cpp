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
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        vector<pair<int, int>> pos = {{n-1, m}, {n, m-1}};
        set<int> s1;
        for(int i=0;i<x;i++){
            int val;
            cin >> val;
            s1.insert(val);
        }
        vector<int> cl, rw, bt;
        for(int i=0;i<y;i++){
            int val;
            cin >> val;
            if(s1.count(val)){
                bt.push_back(val);
                s1.erase(val);
            }else{
                cl.push_back(val);
            }
        }
        for(auto x : s1) rw.push_back(x);
        sort(rw.begin(), rw.end());
        sort(cl.begin(), cl.end());
        sort(bt.begin(), bt.end());
        int srw = rw.size(), scl = cl.size(), sbt = bt.size();
        ll ans = 0;
        vector<ll> pcl(scl + 1), pbt(sbt + 1), prw(srw + 1);
        for(int j = 1; j <= cl.size(); j++){
            pcl[j] = pcl[j-1] + cl[cl.size() - j];
        }
        for(int j = 1; j <= rw.size(); j++){
            prw[j] = prw[j-1] + rw[rw.size() - j];
        }
        for(int j = 1; j <= bt.size(); j++){
            pbt[j] = pbt[j-1] + bt[bt.size() - j];
        }
        for(auto [a, b] : pos){
            ll cans = 0;
            //TODO: SOLVE THIS FUCKING SHIT
            int p2 = 0, p3 = 0;
            for(int j = 0; j <= min(a, (int)bt.size()); j++){
                ll cc = prw[min(srw, a - j)];
                int mb = sbt - j;
                //b - lo <= scl
                //lo >= b - scl 
                int lo = 0, hi = min(mb, b);
                if(hi + scl <= b){
                    cc += pbt[j + hi] + pcl[scl];
                }else{
                    int u = 0;
                    //double bin search
                    for(int jmp = hi; jmp >= 1; jmp /= 2){
                        while(u + jmp <= mb){
                            int val = pbt[j + u + jmp] - pbt[j + u + jmp - 1];
                            int k = 0;
                            for(int sjmp = scl; sjmp >= 1; sjmp /= 2){
                                while(k + sjmp <= scl && pcl[k + sjmp] - pcl[k + sjmp - 1] > val) k += sjmp;
                            }
                            if(k + u + jmp <= b) u += jmp;
                            else break;
                        }
                    } 
                    int k = b - u;
                    cc += pbt[u + j] + pcl[k];
                }
                cans = max(cans, cc);
            }
            ans = max(cans, ans);
        }
        cout << ans << "\n";
    }
}
