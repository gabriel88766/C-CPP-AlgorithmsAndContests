#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

void invert(char &c){
    if(c >= 'a' && c <= 'z') c += 'A' - 'a';
    else c += 'a' - 'A';
}

int lb[500005], rb[500005];
string s;
void solve(int l, int r, int inv){
    if(r < l) return;
    if(inv){
        int p = r;
        while(p >= l){
            while(p >= l && s[p] != ')') cout << s[p--];
            if(p >= l){
                int ob = rb[p];
                solve(ob+1, p-1, 0);
                p = ob - 1;
            }
        }
    }else{
        int p = l;
        while(p <= r){
            while(p <= r && s[p] != '(') cout << s[p++];
            if(p <= r){
                int ob = lb[p];
                solve(p+1, ob-1, 1);
                p = ob + 1;
            }
        }
    }
    cout.flush();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    // string s;
    cin >> s;
    int cp = 0;
    stack<int> st;
    for(int i=0;i<s.size();i++){
        auto &c = s[i];
        if(c != '(' && c != ')'){
            if(cp % 2){
                invert(c);
            }
        }else if(c == '('){
            st.push(i);
            cp++;
        }else{
            lb[st.top()] = i;
            rb[i] = st.top();
            st.pop();
            cp--;
        }
    }
    solve(0, s.size()-1, 0);
    cout << "\n";
    cout.flush();
}