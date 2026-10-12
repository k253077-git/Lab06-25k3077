#include <iostream>
using namespace std;

void permute(string s, int i){
    if (i == s.length()){
        cout << s << endl;
        return;
    }

    for (int j = i; j < s.length(); j++){
        swap(s[i], s[j]);
        permute(s, i + 1);
        swap(s[i], s[j]);
    }
}

int main(){
    permute("ABCD", 0);
    return 0;
}

