#include <iostream>
using namespace std;

int graph[4][4] = {
    {0,1,1,0},
    {1,0,1,1},
    {1,1,0,1},
    {0,1,1,0}
};

int color[4] = {-1,-1,-1,-1};

bool solve(int v){
    if (v == 4)
        return true;

    for (int c = 0; c < 3; c++){
        bool safe = true;

        for (int i = 0; i < 4; i++){
            if (graph[v][i] == 1 && color[i] == c)
                safe = false;
        }

        if (safe){
            color[v] = c;

            if (solve(v + 1))
                return true;

            color[v] = -1;
        }
    }

    return false;
}

int main(){
    if (solve(0)){
        for (int i = 0; i < 4; i++)
            cout << char('A' + i) << " = " << color[i] << endl;
    }
    else
        cout << "No solution";

    return 0;
}

