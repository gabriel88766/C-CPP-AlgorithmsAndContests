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
    string s, t;
    cin >> s >> t;
    int c1 = 0, c2 = 0;
    vector<int> cnt1(26), cnt2(26);
    for(auto c : s){
        if(c >= 'a' && c <= 'z') cnt1[c-'a']++;
        else c1++;
    }
    for(auto c : t){
        if(c >= 'a' && c <= 'z') cnt2[c-'a']++;
        else c2++;
    }
    bool ok = true;
    for(int i=0;i<26;i++){
        if(cnt1[i] != cnt2[i]){
            char c = i + 'a';
            bool cok = false;
            for(auto x : "atcoder") if(c == x) cok = true;
            if(cok){
                if(cnt1[i] > cnt2[i]){
                    if(c2 >= cnt1[i] - cnt2[i]){
                        c2 -= cnt1[i] - cnt2[i];
                    }else{
                        cok = false;
                    }
                }else{
                    if(c1 >= cnt2[i] - cnt1[i]){
                        c1 -= cnt2[i] - cnt1[i];
                    }else{
                        cok = false;
                    }
                }
            }
            if(!cok){ //if still ok will not entry here
                ok = false;
                cout << "No\n";
                break;
            }
        }
    }
    if(ok) cout << "Yes\n";
}
