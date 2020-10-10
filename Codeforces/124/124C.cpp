#include <bits/stdc++.h>
using namespace std;

vector<char> isprime(1011,true);
vector<int> primes;
int qt[26];

void init(){
    for(int i=2;i<=1010;i++){
        if(isprime[i]){
            primes.push_back(i);
            for(int j=i;j<=1010;j+=i){
                isprime[j] = false;
            }
        }
    }
}

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
init();
vector<char> freepos(1005,false);
vector<int>::iterator it;
string s,ans;
char maxc;
cin >> s;
int qtmax=-1,qtfp=1;
ans = s;
for(int i=0;i<s.size();i++){
    qt[s[i]-'a']++;
    if(qtmax<qt[s[i]-'a']) {
        qtmax = qt[s[i]-'a'];
        maxc = s[i];
    }
}
it = primes.begin();
freepos[0]=true;
while(true){
    int value = s.size() / (*it);
    if(value==0) break;
    if(value==1) freepos[(*it)-1]=true,qtfp++;
    it++;
}
int minfreepos = s.size() - qtmax;
if(minfreepos>qtfp){
    cout << "NO";
}else{
    cout << "YES\n";
    for(int i=0;i<s.size();i++){
        if(!freepos[i]){
            if(s[i]!=maxc){
                for(int j=0;j<s.size();j++){
                    if(s[j]==maxc && freepos[j]){
                        swap(s[i],s[j]);
                    }
                }
            }
        }

    }
    cout << s;
}


}



