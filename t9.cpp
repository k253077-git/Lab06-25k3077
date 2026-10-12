#include <iostream>
using namespace std;

int grid[4][4] = {
    {1,0,0,4},
    {0,4,1,0},
    {0,1,4,0},
    {4,0,0,1}
};

bool solve(){
    for (int r = 0; r < 4; r++){
        for (int c = 0; c < 4; c++){
            if (grid[r][c] == 0){
                for (int n = 1; n <= 4; n++){
                    bool safe = true;

                    for (int i = 0; i < 4; i++){
                        if (grid[r][i] == n || grid[i][c] == n)
                            safe = false;
                    }

                    int sr = (r / 2) * 2;
                    int sc = (c / 2) * 2;

                    for (int i = sr; i < sr + 2; i++){
                        for (int j = sc; j < sc + 2; j++){
                            if (grid[i][j] == n)
                                safe = false;
                        }
                    }

                    if (safe){
                        grid[r][c] = n;

                        if (solve())
                            return true;

                        grid[r][c] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main(){
    if (solve()){
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++)
                cout << grid[i][j] << " ";

            cout << endl;
        }
    }
    else
        cout << "No solution";

    return 0;
}

