#include <bits/stdc++.h>
using namespace std;

int counter = 0;
//hard way
bool next_permut(string &s){
    int sizest = s.size(), index = -1;
    reverse(s.begin(), s.end()); //make things easy
    for(int i=1;i<sizest; i++){
        if(s[i] < s[i-1]){
            index = i;
            break;
        }
    }
    if(index == -1) return false;

    for(int i= (index-1);i >= 0; i--){
        if(s[i] > s[index]){
            if(!i){
                swap(s[index],s[i]);
                break;
            }else continue;
        }else{
            swap(s[index], s[i+1]);
            break;
        }
    }
    // reverse between 0 and index-1
    counter++;
    reverse(s.begin(), s.begin()+index);
    reverse(s.begin(), s.end()); //make things easy
    return true;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    vector<string> v;
    cin >> s;
    sort(s.begin(),s.end());
    do{
        v.push_back(s);
    }while(next_permut(s));
    cout << v.size() << endl;
    for(int i=0;i<v.size();i++){
        cout << v[i] << endl;
    }
}


/*easy way
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    vector<string> v;
    while(next_permutation(s.begin(),s.end()));
    do{
        v.push_back(s);
    }
    while(next_permutation(s.begin(),s.end()));
    cout << v.size() << "\n";
    for(int i=0;i<v.size();i++){
        cout << v[i] << "\n";
    }
}

*/