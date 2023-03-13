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
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += abs(v[i]);
        }
        if(sum % 2) cout << "-1\n";
        else{
            if(sum == 0){
                cout << "1\n1 " << n << "\n";
                continue; 
            }
            vector<pair<int,int>> part, ans;
            int aux = 0, lst = -1;
            for(int i=0;i<n;i++){
                if(v[i]){
                    if(aux){
                        part.push_back({lst+1, i+1});
                        aux = 0;
                    }else{
                        lst = i;
                        aux++;
                    }
                }
            }

            if(part[0].first != 1) ans.push_back({1, part[0].first-1});
            if(part[part.size()-1].second != n) ans.push_back({part[part.size()-1].second+1, n});
            
            for(int i=0;i<part.size()-1;i++){
                if(part[i].second != (part[i+1].first-1)){
                    ans.push_back({part[i].second+1, part[i+1].first-1});
                }
            }

            for(auto x : part){
                if(x.second == (x.first+1)){
                    if(v[x.first-1] == v[x.second-1]) ans.push_back({x.first, x.second});
                    else{ans.push_back({x.first, x.first}); ans.push_back({x.second, x.second});}
                }else{
                    if(v[x.first-1] == v[x.second-1]){
                        int l3 = x.second - 1;
                        int l2 = x.first + 1;
                        if(l2 != l3) ans.push_back({l2, l3-1});
                        ans.push_back({l3, x.second});
                        ans.push_back({x.first, x.first});
                    }else{
                        ans.push_back({x.first, x.first});
                        ans.push_back({x.first+1, x.second-1});
                        ans.push_back({x.second, x.second});
                    }
                }
            }



            sort(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for(auto x : ans) cout << x.first << " " << x.second << "\n";
        }
    }
}
