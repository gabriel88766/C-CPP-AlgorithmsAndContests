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
        vector<int> v(n+1);
        for(int i=1;i<=n;i++) cin >> v[i];
        bool ok = true;
        for(int i=2;i<=n;i++) if(v[i] < v[i-1]) ok = false;
        if(ok){
            cout << "0\n";
            continue;
        }
        int neg = 0, pos = 0;
        for(int i=1;i<=n;i++) if(v[i] < 0) neg++; else if(v[i] > 0) pos++;
        vector<pair<int,int>> ans;

        if(pos <= 11 && neg <= 11){
            //9 11, 10 10, 11 9
            int gr = 0, ind;
            for(int i=1;i<=n;i++){
                if(abs(v[i]) > abs(gr)){
                    gr = v[i];
                    ind = i;
                }
            }
            if(gr > 0){
                ans.push_back({1, ind});
                if(v[1] < 0) ans.push_back({1, ind});
                for(int i=2;i<=n;i++){
                    ans.push_back({i, i-1});
                    if(v[i] < 0) ans.push_back({i, i-1});
                }
            }else{
                ans.push_back({n, ind});
                if(v[n] > 0) ans.push_back({n, ind});
                for(int i=n-1;i>=1;i--){
                    ans.push_back({i, i+1});
                    if(v[i] > 0) ans.push_back({i, i+1});
                }
            }
        }else if(pos <= 7 || (pos == 8 && v[n] >= 0)){
            //< 7 and neg something between 12 and 20
            int ind = n;
            while(v[ind] >= 0) ind--;
            if(n-ind >= 2){
                for(int i=ind+1;i<n;i++){
                    ans.push_back({i+1, i});
                }
            }
            for(int i=0;i<5;i++) ans.push_back({ind,ind});
            for(int i=ind-1;i>=1;i--){
                if(v[i] > 0) {ans.push_back({i,i+1}); ans.push_back({i,i+1}); }
                else ans.push_back({i,i+1});
            }
        }else if(neg <= 7 || (neg == 8 && v[1] <= 0)){
            // <7 and pos is something between 12 and 20
            int ind = 1;
            while(v[ind] <= 0) ind++;
            if(ind > 2){
                for(int i=ind-2;i>=1;i--){
                    ans.push_back({i, i+1});
                }
            }
            for(int i=0;i<5;i++) ans.push_back({ind,ind});
            for(int i=ind+1;i<=n;i++){
                if(v[i] < 0) {ans.push_back({i,i-1}); ans.push_back({i,i-1}); }
                else ans.push_back({i,i-1});
            }
        }else{
            // 8 12 or 12 8, worst case
            if(pos > neg){
                if(v[2] > 0){
                    ans.push_back({2,1});
                    for(int i=1;i<=4;i++) ans.push_back({2,2});
                    for(int i=3;i<=n;i++){
                        ans.push_back({i, i-1});
                        if(v[i] < 0) ans.push_back({i,i-1});
                    }
                }else if(abs(v[1]) <= abs(v[2])){
                    int ind = 2;
                    while(v[ind] <= 0) ind++;
                    for(int i=ind-2;i>=1;i--){
                        ans.push_back({i, i+1});
                    }
                    ans.push_back({1,2});
                    for(int i=1;i<=5;i++) ans.push_back({ind,ind});
                    for(int i=ind+1;i<=n;i++){
                        ans.push_back({i, i-1});
                        if(v[i] < 0) ans.push_back({i,i-1});
                    }
                }else{
                    ans.push_back({2,1});
                    for(int i=1;i<=4;i++) ans.push_back({2,2});
                    for(int i=3;i<=n;i++){
                        ans.push_back({i, i-1});
                        if(v[i] < 0) ans.push_back({i,i-1});
                    }
                }
            }else{
                if(v[n-1] < 0){
                    ans.push_back({n-1, n});
                    for(int i=1;i<=4;i++) ans.push_back({n-1,n-1});
                    for(int i=n-2;i>=1;i--){
                        ans.push_back({i, i+1});
                        if(v[i] > 0) ans.push_back({i,i+1});
                    }
                }else if(abs(v[n-1]) >= abs(v[n])){
                    int ind = n-1;
                    while(v[ind] >= 0) ind--;
                    for(int i=ind+1;i<n;i++){
                        ans.push_back({i+1, i});
                    }
                    ans.push_back({n,n-1});
                    for(int i=1;i<=5;i++) ans.push_back({ind,ind});
                    for(int i=ind-1;i>=1;i--){
                        ans.push_back({i, i+1});
                        if(v[i] > 0) ans.push_back({i,i+1});
                    }
                }else{
                    ans.push_back({n-1, n});
                    for(int i=1;i<=4;i++) ans.push_back({n-1,n-1});
                    for(int i=n-1;i>=1;i--){
                        ans.push_back({i, i+1});
                        if(v[i] > 0) ans.push_back({i,i+1});
                    }
                }
            }
        }
        cout << ans.size() << "\n";
        for(auto x: ans){
            cout << x.first << " " << x.second << "\n"; 
        }
    }
}
