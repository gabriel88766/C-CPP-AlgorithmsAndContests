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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> one, zero;
        one.push_back(-1), one.push_back(n), zero.push_back(-1), zero.push_back(n);
        set<pair<int,int>> ans;
        for(int i=0;i<n;i++){
            if(s[i] == '0') zero.push_back(i);
            else one.push_back(i);
        }
        sort(zero.begin(), zero.end());
        sort(one.begin(), one.end());
        int aux = 0;
        for(int i=0;i<m;i++){
            int l, r;
            cin >> l >> r;
            if(*lower_bound(one.begin(), one.end(), l-1) < *prev(lower_bound(zero.begin(),zero.end(), r))){
                ans.insert({*prev(lower_bound(one.begin(), one.end(), l-1)), *lower_bound(zero.begin(), zero.end(), r)});
            }else{
                aux = 1;
            }
        }
        cout << ans.size()+aux <<  "\n";
    }

}
