#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    string s, ans;
    cin >> n >> s;
    int ind;
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            ans = s.substr(i, n-i);
            ind = i;
            break;
        }
    }
    
    if(ans.size() == 0){
        cout << "0";
        return 0;
    }

    int ind0 = -1;
    for(int i=ind;i<n;i++){
        if(s[i] == '0'){
            ind0 = i;
            break;
        }
    }
    if(ind0 == -1) cout << ans;
    else{
        //try all possibilities.
        ll maxi = -1;
        pair<int,int> best;
        for(int i=ind;i<ind0;i++){ //begin substr
            for(int j=i+1;j<=ind0;j++){ //begin or
                ll curi = 0;
                for(int k=0;k<=60;k++){
                    curi <<= 1;
                    if(k+j < n && s[k+j] == '0' && s[k+i] == '1') curi++;
                }
                if(curi > maxi){
                    maxi = curi;
                    best = {i, j-ind};
                }
            }
        }
        for(int i=best.first;i<n;i++){
            if(best.second+i-best.first >= ans.size()) break;
            if(s[i] == '1') ans[best.second+i-best.first] = '1';
        }
        cout << ans;
    }
}
