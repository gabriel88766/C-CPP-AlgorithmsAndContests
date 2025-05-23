#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 200005; 
int sz[2*N];
int len[2][N];
void manacher_odd(string s){
    int n = s.size();
    s = '^' + s + '$';
    int l = 0, r = 1;
    for(int i=1;i<=n; i++){
        if(i >= r){
            while(s[i - sz[i]] == s[i + sz[i]]) sz[i]++;
        }else{
            int p = l + r - i;
            sz[i] = min(sz[p], p - l);
            while(s[i - sz[i]] == s[i + sz[i]]) sz[i]++;
        }
        if(i + sz[i] > r){
            r = i + sz[i];
            l = i - sz[i];
        }
    }
}

void manacher(string s){
    int n = s.size();
    string t;
    for(int i=0;i<n;i++){
        t += '#';
        t += s[i];
    }
    t += '#';
    manacher_odd(t);
    for(int i=1;i<=n;i++){
        len[0][i] = sz[2*i+1]/2;
        len[1][i] = sz[2*i]/2;
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    manacher(s);
    deque<pair<int, int>> dq0, dq1;
    for(int i=1;i<=s.size();i++){
        // cout << len[0][i] << " " << len[1][i] << "\n";
        while(dq0.size() && dq0.front().second < i) dq0.pop_front();
        while(dq1.size() && dq1.front().second < i) dq1.pop_front();
        if(dq0.size() == 0 || dq0.back().second < i + len[0][i]) dq0.push_back({i, i + len[0][i]});
        if(dq1.size() == 0 || dq1.back().second < i + len[1][i] - 1) dq1.push_back({i, i + len[1][i] - 1});
        int ans0 = 2*(i - dq0.front().first);
        int ans1 = 2*(i - dq1.front().first) + 1;
        cout << max(ans0, ans1) << " ";
    }   
    cout << "\n";
}
