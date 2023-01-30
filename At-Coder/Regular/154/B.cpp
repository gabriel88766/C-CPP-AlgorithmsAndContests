#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
int cnt1[26], cnt2[26];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s,t;
    int n, ans = 0;
    cin >> n >> s >> t;
    for(int i=0;i<n;i++){
        cnt1[s[i]-'a']++;
        cnt2[t[i]-'a']++;
    }
    bool isPos = true;
    for(int i=0;i<26;i++) if(cnt1[i] != cnt2[i]){
        isPos = false;
    } 


    if(!isPos) cout << "-1";
    else{
        int bp1 = n-1, bp2 = n-1;
        while(bp2 != -1){
            if(s[bp1] == t[bp2]) bp1--, bp2--;
            else bp2--;
        }        
        cout << bp1+1;
    }
}
