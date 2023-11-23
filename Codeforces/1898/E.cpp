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
        string s1, s2;
        cin >> n >> m >> s1 >> s2;
        int p1 = 0, p2 = 0;
        set<int> st[26];
        while(p1 < n || p2 < m){
            //cout << p1 << " " << p2 << " " << s1 << "\n";
            int l1 = -1, l2 = -1;
            if(p1 < n) l1 = s1[p1] - 'a';
            if(p2 < m) l2 = s2[p2] - 'a';
            if(p2 < m && st[l2].size()){
                int ind = *st[l2].begin();
                st[l2].erase(st[l2].begin());
                for(int i=l2-1;i>=0;i--){
                    while(st[i].size() && *st[i].begin() < ind){
                        st[i].erase(st[i].begin());
                    }
                }
                p2++;
            }else if(p1 < n && p2 < m && s1[p1] == s2[p2]){
                for(int i=l1;i>=0;i--) st[i].clear();
                p1++, p2++;
            }else if(p1 < n){
                st[l1].insert(p1);
                p1++;
            }else break;
        }
        if(p2 == m) cout << "YES\n";
        else cout << "NO\n";
    }
}
