#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//mp maps current position to original index, c is the class of the prefix

const int N = 4e5+3; 
int ind[N];
vector<int> ans;


void suffix_array(string s){
    s += "$";
    int n = s.size(), c=-1;
    vector<int> mp(n), invmp(n), cnt(max(n, 256)), mp2(256), aux(n), nmp(n); 
    vector<int> l(n), r(n);

    vector<pair<int,int>> cs(n); // class,class <int,int> and pos 
    vector<int> newv(n);

    for(int i=0;i<n;i++) cnt[s[i]]++;
    for(int i=0;i<256;i++){
        if(cnt[i]) mp2[i] = ++c;
        if(i) cnt[i] += cnt[i-1];
    } 

    for(int i=0;i<n;i++) {
        mp[--cnt[s[i]]] = i; 
        invmp[i] = cnt[s[i]];
    }
    c = -1;
    for(int i=0;i<n;i++){
        if(i && s[mp[i]] == s[mp[i-1]] ){
            cs[i].first = c;
        }else{
            cs[i].first = ++c;
        }
    }

    for(int i=0;(1 << i) < 2;i++){
        int offset = 1 << i;
        //memset(r, 0, n * sizeof(int));
        for(int j=0;j<n;j++){
            int mindex = cs[j].second + offset;
            mindex = mindex >= n ? mindex - n : mindex;
            cs[j].second = cs[mp[mindex]].first;
            r[cs[j].second]++;
        }
        //sort(cs.begin(), cs.end());

        //begin
        for(int i=0; i<n; i++) cnt[cs[i].second]++;
        for(int i=1;i<n; i++) cnt[i] += cnt[i-1];
        for(int i=0;i<n;i++) aux[--cnt[cs[i].second]] = i;
        memset(cnt, 0, n*sizeof(int));

        for(int i=0; i< n; i++) cnt[cs[i].first]++;
        for(int i=0;i<(n-1); i++){
            cnt[i+1] += cnt[i];
        }
        for(int i=(v.size()-1);i>=0;i--) nmp[--cnt[cs[aux[i]].first]] = aux[i];
        //end

        for(int j=0;j<n;j++) mp[j] = nmp[j];

        c = -1;
        for(int j=0;j<n;j++){
            if(j && cs[mp[j]] == cs[mp[j-1]]){
                newv[j] = c;
            }else{
                newv[j] = ++c;
            }
        }
        for(int j=0;j<n;j++) cs[j].first = newv[j];
    }
    for(int i=0;i<n;i++) ind[i] = mp[i];
}



//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    string s ="ababba";
    suffix_array(s);
    for(int i=0;i<=s.size();i++){
        cout << ind[i] << " ";
    }
}
