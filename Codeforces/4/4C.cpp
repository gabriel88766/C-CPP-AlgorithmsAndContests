//multiset = TLE
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0);
int n,cont;
cin >> n;
string s;
map<string,int> st;
for(int i=0;i<n;i++){
    cin >> s;
    cont = st.count(s);
    if(cont==0){
        cout << "OK"<< endl;
        st[s] = 1;
    }else{
       cout << s << st[s] << endl;
       st[s]++;
    }
}

}
