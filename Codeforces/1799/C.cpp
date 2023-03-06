#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string best(vector<int> &qt, int cur){
    string ans1, ans2;
    for(int i=cur;i<26;i++){
        for(int j=0;j<qt[i]/2;j++){
            ans1 += (char)('a'+ i);
            ans2 += (char)('a'+ i);
        }
        if(qt[i] % 2){
            int cnt = 0, ind;
            for(int j=i+1;j<26;j++){
                if(qt[j]){
                    cnt++;
                    ind = j;
                }
            }
            if(cnt == 0){
                ans1 += (char)('a'+ i);
                break;
            }else if(cnt == 1){
                if(qt[ind] % 2){
                    for(int j=0;j<qt[ind]/2;j++){
                        ans1 += (char)('a'+ ind);
                        ans2 += (char)('a'+ ind);
                    }
                    ans1 += (char)('a'+ ind);
                    ans2 += (char)('a'+i);
                }else{
                    for(int j=0;j<qt[ind]/2;j++){
                        ans1 += (char)('a'+ ind);
                        ans2 += (char)('a'+ ind);
                    }
                    ans1 += (char)('a' + i);
                }
            }else{
                ans2 += (char)('a'+i);
                for(int j=i+1;j<26;j++){
                    for(int k=0;k<qt[j];k++){
                        ans1 += (char)('a'+j);
                    }
                }
            }
            break;
         }
    }
    reverse(ans2.begin(), ans2.end());
    return ans1 + ans2;
 }



void solve(){
    vector<int> qt(26,0);
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        qt[s[i]-'a']++;
    }
    cout << best(qt, 0) << "\n";
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    while(n--){
        solve();
    }
}
