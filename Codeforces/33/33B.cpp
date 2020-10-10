#include <bits/stdc++.h>

using namespace std;
#define INF 0x3f3f3f3f
#define nd second
#define st first

vector<vector<int>> v(26,vector<int>(26));

void init(){
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(i==j) v[i][j]=0;
            else v[i][j] = INF;
        }
    }
}

int main(){
init();
int n,w,S=0,pointer=0,S1,S2,S3;
char a,b,dest;
string s,t,ans;
map<pair<char,char>,int> mp;
cin >> s >> t >> n;
while(n--){
    cin >> a >> b >> w;
    if(v[a-'a'][b-'a']>w){
        v[a-'a'][b-'a']=w;
    }
}

for(int i=0;i<26;i++){
    for(int j=0;j<26;j++){
        for(int k=0;k<26;k++){
            if(v[j][k] > (v[j][i]+v[i][k])){
                v[j][k] =  (v[j][i]+v[i][k]);
            }
        }
    }
}

if(s.size()!=t.size()){
    cout << -1;
    return 0;
}else{
    while(pointer!=s.size()){
        if(s[pointer]==t[pointer]){
            ans+=s[pointer];
            pointer++;
        }else{
            S3=INF;
            a=s[pointer];
            b=t[pointer];
            for(int i=0;i<26;i++){
                if(S3>(v[a-'a'][i]+v[b-'a'][i])){
                    dest = i+'a';
                    S3=(v[a-'a'][i]+v[b-'a'][i]);
                }
            }
            if(S3>=INF){
                cout << -1;
                return 0;
            }else{
                S+=S3;
                ans+=dest;
                pointer++;
            }
        }
    }
    cout << S << endl <<  ans;
}

}
