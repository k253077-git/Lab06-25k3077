#include <iostream>
using namespace std;

void rev(string str, int i){
    if (i < 0)
        return;

    cout << str[i];
    rev(str, i - 1);
}

int main(){
    string str;
    cout<<"Enter a string: ";
    cin >> str;

    rev(str, str.length() - 1);

    return 0;
}

