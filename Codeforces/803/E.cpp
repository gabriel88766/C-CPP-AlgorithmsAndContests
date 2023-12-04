#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

string invert(string s){
    for(int i=0;i<s.size();i++){
        if(s[i] == 'L') s[i] = 'W';
        else if(s[i] == 'W') s[i] = 'L';
    }
    return s;
}

string solve(string s, int k){
    //solve for win;
    int cnt = 0;
    stack<int> st;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'W') cnt++;
        if(s[i] == 'L') cnt--;
        if(s[i] == '?') st.push(i);
        if(abs(cnt) == k && i != (s.size()-1)){
            if(st.empty()){
                return "NO";
            }else{
                if(cnt == k){
                    s[st.top()] = 'L';
                    cnt--;
                }else{
                    cnt++;
                    s[st.top()] = 'W';
                }
                st.pop();
            }
        }
    }
    while(cnt != k){
        if(st.empty()) return "NO";
        s[st.top()] = 'W';
        st.pop();
        cnt++;
    }
    for(int i=0;i<s.size();i++) if(s[i] == '?') s[i] = 'D';
    cnt = 0;
    for(int i=0;i<s.size()-1;i++){
        if(s[i] == 'W') cnt++;
        if(s[i] == 'L') cnt--;
        if(abs(cnt) == k) return "NO";
    }
    return s;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string s1 = solve(s, k);
    string s2 = solve(invert(s), k);
    if(s1 != "NO") cout << s1 << "\n";
    else if(s2 != "NO") cout << invert(s2) << "\n";
    else cout << "NO\n";
}
