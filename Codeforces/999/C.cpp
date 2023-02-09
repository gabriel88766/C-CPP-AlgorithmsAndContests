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
    //freopen("in", "r", stdin); test input
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> let[26];
    for(int i=(n-1);i>=0;i--){
        let[s[i]-'a'].push_back(i);
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<26;j++){
            if(let[j].size()){
                let[j].pop_back();
                break;
            }
        }
    }
    string ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            if(let[j].size() && let[j].back() == i){
                ans += 'a'+j;
                let[j].pop_back();
                break;
            }
        }
    }
    cout << ans;
}


