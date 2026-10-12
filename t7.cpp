#include <iostream>
using namespace std;

int arr[5] = {2,3,5,6,8};
int chosen[5] = {0};

bool solve(int i, int sum){
    if (sum == 9)
        return true;

    if (i == 5 || sum > 9)
        return false;

    chosen[i] = 1;

    if (solve(i + 1, sum + arr[i]))
        return true;

    chosen[i] = 0;

    if (solve(i + 1, sum))
        return true;

    return false;
}

int main(){
    if (solve(0, 0)){
        for (int i = 0; i < 5; i++){
            if (chosen[i] == 1)
                cout << arr[i] << " ";
        }
    }
    else
        cout << "No subset found";

    return 0;
}

