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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<bool> oks(n), okr(n);
        if(s[0] == '1'){
            for(int i=0;i<s.size();i++){ //flip all
                if(s[i] == '0') s[i] = '1';
                else s[i] = '0';
            }
        }
        assert(s[0] == '0');
        //s1s2s3...sp sn sn-1 ... sp-1
        //000011110000 111100001111
        for(int i=0;i<s.size();i++){
            int x = (i/k) % 2;
            if(s[i] == x + '0'){
                oks[i] = true;
            }else break;
        }
        char lc = (((n-1)/k)%2) + '0';
        int idx;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == s.back()) idx = i;
            else break;
        }
        int jp = s.size() - idx;
        if(jp > k){
            cout << "-1\n";
            continue;
        }
        if(s[idx] == lc) okr[idx] = true;
        for(int i=idx-1;i>=0;i--){
            //1 to k
            int x = (((idx - 1 - i)/k) % 2) ^ 1;
            int y = (idx - 1 - i) % k;
            y++;
            if(s.back() == '1') x ^= 1;
            if(s[i] != x + '0') break; 
            if(y == k && s[i] == lc) okr[i] = true;
        }
        // cout << "\n";
        if(oks[n-1]) cout << n << "\n";
        else{
            bool ok = false;
            for(int i=0;i<n-1;i++){
                if(oks[i] && okr[i+1]){
                    cout << i+1 << "\n";
                    ok = true;
                    break;
                }
            }
            if(!ok) cout << "-1\n";
        }
    }
}
