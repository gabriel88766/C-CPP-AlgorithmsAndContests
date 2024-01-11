#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1002*1002; //substrings of a string of len 1505

int cntn = 0;
int trie[N][26];
int val[N];
string str[N];
void add(int node, char c, int v, string s){
    c -= 'a';
    ++cntn;
    val[cntn] = v;
    str[cntn] = s;
    trie[node][c] = cntn;
}

int pi[1000015]; //Lenght of greatest prefix also suffix of substr (0, i) 

//Knuth-Morris-Pratt
void kmp_pre(const string &s){
    pi[0] = 0;
    for(int i=1;i<s.size();i++){
        int j = pi[i-1];
        while(j && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.size();
    if(s.size() <= 10){
        for(int i=0;i<q;i++){
            string t;
            cin >> t;
            string cur = s + t;
            kmp_pre(cur);
            for(int j=s.size();j<cur.size();j++){
                cout << pi[j] << " ";
            }
            cout << "\n";
        }
        return 0;
    }
    //preprocessing
    kmp_pre(s);
    queue<pair<int,int>> qp;
    qp.push({0, 0});
    val[0] = pi[n-1];
    while(!qp.empty()){
        auto [u, d] = qp.front();
        qp.pop();
        if(d == 10) continue;
        string cstr = str[u];
        auto gs = [&](int ps){
            if(ps >= n) return cstr[ps - n];
            else return s[ps];
        };
        int cur = 0;
        for(int i=0;i<cstr.size();i++){
            cur = trie[cur][cstr[i]-'a'];
            pi[n+i] = val[cur];
        }
        assert(cur == u);
        for(char a = 'a'; a <= 'z'; a++){
            cstr += a;
            int j = pi[n+cstr.size()-2];
            while(j && a != gs(j)) j = pi[j-1];
            if(a == gs(j)) j++;
            if(j){
                add(u, a, j, cstr);
                qp.push({cntn, d+1});
            }
            cstr.pop_back();
        }
    }



    while(q--){
        string t;
        cin >> t;
        int cur = 0;
        int pf = 0;
        for(int i=0;i<t.size();i++){
            if(cur != -1){
                if(trie[cur][t[i]-'a']){
                    cur = trie[cur][t[i]-'a'];
                    cout << val[cur] << " ";
                }else{
                    cur = -1;
                    cout << "0 ";
                }
            }else{
                int j = pf;
                while(j && t[i] != s[j]) j = pi[j-1];
                if(t[i] == s[j]) j++;
                cout << j << " ";
                pf = j;

            }
        }
        cout << "\n";
    }
}
