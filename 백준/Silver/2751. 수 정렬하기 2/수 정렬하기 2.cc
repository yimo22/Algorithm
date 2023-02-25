#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v;
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int w;
        cin >> w;
        v.push_back(w);
    }
    sort(v.begin(), v.end());
    for(int w : v){
        cout << w << "\n";
    }
    
    return 0;
}