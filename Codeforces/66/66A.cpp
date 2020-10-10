#include<bits/stdc++.h>

#define INF 0x3f3f3f3f
#define par pair< pair<int, int>, int>
#define st first
#define nd second
#define mp(x,y) make_pair(x,y)
#define sti pair<string,int>

using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
string s;
string maxlld="9223372036854775807";
string maxint="2147483647";
cin >> s;
int n = s.size();
if(n>19){
    cout << "BigInteger";
}else if(n==19){
    if(s<=maxlld){
        cout << "long";
    }else{
        cout << "BigInteger";
    }
}else if(n<19 && n>10) {cout << "long";}
else if(n==10){
    if(s<=maxint){
        cout << "int";
    }else cout << "long";
}else{
    int num = atoi(s.c_str());
    if(num > 32767) cout << "int";
    else if(num > 127) cout << "short";
    else cout << "byte";
}

}
