
#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< int, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>
# define PI          3.141592653589793238462643383279502884L
//matrix vector<vector<int>> matrix(row,vector<int>(col));

using namespace std;


int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
string s;
map<char,int> m;
char lo,hi,extra=0,print;
for(int i=0;i<26;i++){
    m['a'+i]=0;
}
cin >> s;
for(int i=0;i<s.size();i++){
    m[s[i]]++;
}
hi='z';
lo='a';
if(s.size()%2){
    extra=true;
}
while(hi>lo){
    while(!(m[lo]%2) && hi>lo) lo++;
    while(!(m[hi]%2) && hi>lo) hi--;
    m[hi]--;
    m[lo]++;
}
print= 'a';
string result;
while(print<='z'){
    if(m[print]>1){
        m[print]-=2;
        result+=print;
    }else{
        print++;
    }
}
cout << result;
if(extra){
    cout << lo;
}
for(int i=result.size()-1;i>=0;i--){
    cout << result[i];
}
}
