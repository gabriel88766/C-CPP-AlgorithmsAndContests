#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2002*2002; //substrings of a string of len 1505

int cntn = 0;
int trie[N][2];
int fn[N];

int add(int node, char c){
    c -= '0';
    if(trie[node][c]) return trie[node][c];
    else return trie[node][c] = ++cntn;
}

//example add string
void add(string s){
    int curn = 0;
    for(auto c : s) curn = add(curn, c);
    fn[curn] = 1;
}

bool isFinal(string s){
    int curn = 0;
    for(auto c : s) curn = trie[curn][c-'0'];
    return fn[curn];
}

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
        bool h00 = false, h11 = false;
        vector<bool> cu(n+1, true);
        vector<pair<string, int>> v01, v10;
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            if(s[0] == s.back()){
                if(s[0] == '1') h11=true;
                else h00 = true;
            }else{
                add(s);
                if(s[0] == '0') v01.push_back({s, i+1});
                else v10.push_back({s, i+1});
            }
        }
        int q01 = 0, q10 = 0;
        for(auto &[s, j] : v01){
            auto rev = s;
            reverse(rev.begin(), rev.end());
            if(isFinal(rev)) cu[j] = false;
            else q01++;
        }
        for(auto &[s, j] : v10){
            auto rev = s;
            reverse(rev.begin(), rev.end());
            if(isFinal(rev)) cu[j] = false;
            else q10++;
        }
        int ttsz = v01.size() + v10.size();
        if(h00 && h11 && ttsz == 0) cout << "-1\n";
        else{
            vector<int> ans;
            int dif = (abs((int)v01.size() - (int)v10.size()))/2;
            if(v01.size() > v10.size()){
                //need to change 01 to 10
                if(q01 >= dif){
                    for(auto &[s, j] : v01){
                        if(cu[j] && dif){
                            ans.push_back(j);
                            dif--;
                        }
                    }
                    cout << ans.size() << "\n";
                    for(auto x : ans) cout << x << " ";
                    cout << "\n";
                }else assert(1 == 0);
            }else{
                //need to change 10 to 01
                if(q10 >= dif){
                    for(auto &[s, j] : v10){
                        if(cu[j] && dif){
                            ans.push_back(j);
                            dif--;
                        }
                    }
                    cout << ans.size() << "\n";
                    for(auto x : ans) cout << x << " ";
                    cout << "\n";
                }else assert(1 == 0);
            }
        }

        //clear()
        for(int i=0;i<=cntn;i++){
            trie[i][0] = trie[i][1] = fn[i] = 0;
        }
        cntn = 0;
    }
}
