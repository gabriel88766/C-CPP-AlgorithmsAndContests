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
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string s1 = s;
    string s2 = t;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if(s1 != s2) cout << "-1\n";
    else{
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(s[i] == t[i]) continue;
            else{
                int ind = -1;
                for(int j=i;j<n;j++){
                    if(s[j] == t[i]){
                        ind = j;
                        break;
                    }
                }
                for(int j=ind;j>=i+1;j--){
                    ans.push_back(j);
                    swap(s[j-1], s[j]);
                }
            }
        }

        cout << ans.size() << "\n";
        for(auto x : ans) cout << x <<  " ";
        cout << "\n";
    }
}
