#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        vector<ll> l(26, 0), nl(26);
        for(int i=0;i<n;i++) l[s[i]-'a']++;
        
        if(s.size() == 1) {
            cout << "0\n" << s << "\n";
            continue;
        }
        vector<int> divisors;
        for(int i=1;i<min(400, n); i++){
            if(!(n % i)){
                if(i < n/i) divisors.push_back(i);
                if(n/i > i) divisors.push_back(n/i);
                if(i == n/i) divisors.push_back(i);
            }
        }
        sort(divisors.begin(), divisors.end());


        vector<int> ind(26, 1), ord(26);
        for(int i=0;i<26;i++){
            int maxpos, maxnum = -1;
            for(int j=0;j<26;j++){
                if(ind[j] == 0) continue;
                if(l[j] > maxnum){
                    maxpos = j;
                    maxnum = l[j];
                }
            }
            ind[maxpos] = 0;
            ord[i] = maxpos;
        }



        ll bd, minop = INF_LL;
        for(int i=0; i<divisors.size(); i++){
            int k = n / divisors[i]; //total letters;
            if(k > 26) continue;
            nl.assign(26, 0);
            ll cursum=0;
            for(int j=0;j<k;j++){
                nl[ord[j]] = divisors[i];
            }
            for(int j=0;j<26;j++){
                cursum += abs(nl[j] - l[j]);
            }
            cursum /= 2;
            if(cursum < minop){
                minop = cursum;
                bd = divisors[i];
            }
        }

        nl.assign(26, 0);
        for(int j=0;j<n/bd;j++){
            nl[ord[j]] = bd;
        }

        for(int i=0;i<s.size();i++){
            if(l[s[i]-'a'] > nl[s[i] - 'a']){
                for(int j=0;j<26;j++){
                    if(nl[j] > l[j]){
                        l[j]++;
                        l[s[i]-'a']--;
                        s[i] = 'a' + j;
                        break;
                    }
                }
            }
        }

        cout << minop << "\n" << s << "\n";

    }
}
