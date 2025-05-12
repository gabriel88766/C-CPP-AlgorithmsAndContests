#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


const int N = 501*1002; //substrings of a string of len 1505

struct Trie{
    int cntn = 0;
    int **trie;
    int *nf;
    bool *isf;
    Trie(){
        trie = new int*[N];
        nf = new int[N]; 
        isf = new bool[N];
        for(int i=0;i<N;i++) trie[i] = new int[26];
    }
    int add(int node, char c){
        c -= 'a';
        if(trie[node][c]) return trie[node][c];
        else return trie[node][c] = ++cntn;
    }
    //example add string
    void add(string s){
        int curn = 0;
        nf[curn] += 1;
        for(auto c : s){
            curn = add(curn, c);
            nf[curn] += 1;
        } 
        isf[curn] = true;
    }
    void erase(string s){
        int curn = 0;
        nf[curn] -= 1;
        for(auto c : s){
            curn = add(curn, c);
            nf[curn] -= 1;
        } 
    }
    int get(string s){
        int curn = 0;
        for(auto c : s){
            if(trie[curn][c-'a']) curn = trie[curn][c-'a'];
            else return 0;
        }
        return curn;
    }
    int getpr(string s){
        int curn = 0;
        for(auto c : s){
            if(isf[curn]) return curn;
            if(trie[curn][c-'a']) curn = trie[curn][c-'a'];
            else return 0;
        }
        if(isf[curn]) return curn;
        else return 0;
    }
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    Trie t1, t2;
    int q;
    cin >> q;
    int ans = 0;
    while(q--){
        int t;
        string s;
        cin >> t >> s;
        if(t == 1){
            t1.add(s);
            int xv = t2.get(s);
            if(xv != 0){
                while(t2.nf[xv]){
                    t2.erase(s);
                    ans--;
                }
                for(int i=0;i<26;i++) t2.trie[xv][i] = 0;
            }
        }else{
            int xv = t1.getpr(s);
            if(xv == 0){
                ans++;
                t2.add(s);
            }
        }
        cout << ans << "\n";
    }
}
