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
        vector<ll> v(n);
        ll avg = 0;
        for(int i=0;i<n;i++){
            cin >> v[i];
            avg += v[i];
        }
        if(avg % n) cout << "No\n";
        else{
            avg /= n;
            vector<pair<int,int>> opt1, opt2;
            bool ok = true;
            for(int i=0;i<n;i++){
                int p1 = 0, p2 = 0;
                int goal = v[i] - avg;
                if(!goal) continue;
                while(p2 <= 30 && p1 <= 30){
                    int val = (1 << p2) - (1 << p1);
                    if(val == goal) break;
                    else if(val < goal) p2++;
                    else p1++; 
                }
                if(p2 == 31 || p1 == 31){
                    ok = false; break;
                }
                opt1.push_back({p1, p2});
                p1 = -1, p2 = -1;
                for(int j=0;j<30;j++){
                    if(goal == (1 << j)) p2 = j;
                    if(goal == -(1 << j)) p1 = j;
                }
                opt2.push_back({p1, p2});
            }
            
            if(ok){
                if(opt1.size()){
                    vector<int> qt1(31, 0), qt2(31, 0);
                    vector<int> ord;
                    for(int i=0;i<opt1.size();i++) ord.push_back(i);
                    sort(ord.begin(), ord.end(), [&](int u, int v){
                        if(max(opt1[u].first, opt1[u].second) != max(opt1[v].first, opt1[v].second)){
                            return max(opt1[u].first, opt1[u].second) > max(opt1[v].first, opt1[v].second);
                        }else{
                            return min(opt1[u].first, opt1[u].second) > min(opt1[v].first, opt1[v].second);
                        }
                    });
                    for(int i=0;i<opt1.size();i++){
                        qt1[opt1[i].first]++;
                        qt2[opt1[i].second]++;
                    }
                    for(int i=0;i<opt1.size(); i++){
                        int x = ord[i];
                        int mx = max(opt1[x].first, opt1[x].second);
                        int mn = min(opt1[x].first, opt1[x].second);
                        if(mx != mn+1) continue;
                        if(mx == opt1[x].first){
                            if(qt1[mx] > qt2[mx]){
                                qt1[mx]--;
                                qt1[mn]++;
                                qt2[mn]--;
                            }
                        }else{
                            if(qt1[mx] < qt2[mx]){
                                qt2[mx]--;
                                qt2[mn]++;
                                qt1[mn]--;
                            }
                        }
                    }
                    if(qt1 == qt2) cout << "Yes\n";
                    else cout << "No\n";
                }else cout << "Yes\n";
                
            }else cout << "No\n";
        }
    }
}
