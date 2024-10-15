#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int sum = 0;
    vector<vector<int>> vec(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> vec[i][j];
            sum += vec[i][j];
        }
    }

    int res = INT_MAX;
    // pengding

}