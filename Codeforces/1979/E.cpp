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
        int n, d;
        cin >> n >> d;
        map<int, vector<pair<int,int>>> mp1, mp2;
        vector<pair<int,int>> vp(n+1);
        for(int i=1;i<=n;i++){
            cin >> vp[i].first >> vp[i].second;
            //y = x + k, k = y-x
            //or y = k - x, k = y+x
            mp1[vp[i].second - vp[i].first].push_back({vp[i].first, i});
            mp2[vp[i].second + vp[i].first].push_back({vp[i].first, i});
        }
        for(auto &[k, v] : mp1){
            sort(v.begin(), v.end());
        }
        for(auto &[k, v] : mp2){
            sort(v.begin(), v.end());
        }
        bool ok = false;
        for(int i=1;i<=n;i++){
            auto it1 = lower_bound(mp1[vp[i].second - vp[i].first].begin(), mp1[vp[i].second - vp[i].first].end(), make_pair(vp[i].first + d/2, 0));
            auto it2 = lower_bound(mp2[vp[i].second + vp[i].first].begin(), mp2[vp[i].second + vp[i].first].end(), make_pair(vp[i].first + d/2, 0));
            if(it1 != mp1[vp[i].second - vp[i].first].end() && it1->first == vp[i].first + d/2){
                int aux = vp[i].second - vp[i].first;
                int aux2 = aux + d;
                if(mp1.count(aux2)){
                    auto it3 = lower_bound(mp1[aux2].begin(), mp1[aux2].end(), make_pair(vp[i].first - d/2, 0));
                    if(it3 != mp1[aux2].end() && it3->first <= vp[i].first){
                        ok = true;
                        cout << i << " " << it1->second << " " << it3->second << "\n";
                        break;
                    }
                }
                aux2 = aux - d;
                if(mp1.count(aux2)){
                    auto it3 = lower_bound(mp1[aux2].begin(), mp1[aux2].end(), make_pair(vp[i].first + d/2, 0));
                    if(it3 != mp1[aux2].end() && it3->first <= vp[i].first + d){
                        ok = true;
                        cout << i << " " << it1->second << " " << it3->second << "\n";
                        break;
                    }
                }
            }
            if(it2 != mp2[vp[i].second + vp[i].first].end() && it2->first == vp[i].first + d/2){
                int aux = vp[i].second + vp[i].first;
                int aux2 = aux + d;
                if(mp2.count(aux2)){
                    auto it3 = lower_bound(mp2[aux2].begin(), mp2[aux2].end(), make_pair(vp[i].first + d/2, 0));
                    if(it3 != mp2[aux2].end() && it3->first <= vp[i].first + d){
                        ok = true;
                        cout << i << " " << it2->second << " " << it3->second << "\n";
                        break;
                    }
                }
                aux2 = aux - d;
                if(mp2.count(aux2)){
                    auto it3 = lower_bound(mp2[aux2].begin(), mp2[aux2].end(), make_pair(vp[i].first - d/2, 0));
                    if(it3 != mp2[aux2].end() && it3->first <= vp[i].first){
                        ok = true;
                        cout << i << " " << it2->second << " " << it3->second << "\n";
                        break;
                    }
                }
            }
        }
        if(!ok) cout << "0 0 0\n";
    }
}
