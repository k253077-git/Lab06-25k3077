#include <iostream>
using namespace std;

char grid[4][4] = {
    {'C','A','X','X'},
    {'X','u','X','X'},
    {'X','X','X','X'},
    {'X','X','X','X'}
};

bool visit[4][4] = {false};

bool solve(int r, int c, int i){
    if (i == 3)
        return true;

    if (r < 0 || r >= 4 || c < 0 || c >= 4)
        return false;

    if (visit[r][c] || grid[r][c] != "CAT"[i])
        return false;

    visit[r][c] = true;

    if (solve(r + 1, c, i + 1) || solve(r - 1, c, i + 1) || solve(r, c + 1, i + 1) || solve(r, c - 1, i + 1))
        return true;

    visit[r][c] = false;

    return false;
}

int main(){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if (grid[i][j] == 'C' && solve(i, j, 0)){
                cout << "CAT found";
                return 0;
            }
        }
    }

    cout << "CAT not found";
    return 0;
}
	
