// http://uva.onlinejudge.org/external/4/469.html
// Runtime: 0.108s
// Tag: Dfs

/*
 * File:   main.cpp
 * Author: shahab
 * [modified for CS315  by NFM, and]
 * [further modified by JWJ to make explicit calls to dfs]
 * Created on March 29, 2011, 8:39 PM
 * Reviewed for class: November 6, 2019
 */

// @BEGIN_OF_SOURCE_CODE

#include <iostream> 
#include <string>
//#include <strncpy>
#include <fstream>
#include <cstring>

#include <sstream>
#include <algorithm>// memset, strncpy

using namespace std;

char matrix[100 + 5][100 + 5];
bool visited[100 + 5][100 + 5];
// size of matrix
int row;
int col;

// Row and column deltas for each direction we can visit.
//            n    e   s   w  ne  se  sw  nw
//int dr[8] = {-1,  0,  1,  0, -1,  1,  1, -1};
//int dc[8] = { 0,  1,  0, -1,  1,  1, -1, -1};


int dfs(int r, int c)
{
    if (r == row || r < 0 || c == col || c < 0
        || matrix[r][c] == 'L' || visited[r][c])
    {
        return 0;
    }

    int cnt = 1; // number of connected water cells (including this one)
    visited[r][c] = true;
//Start traversing with DFS
        cnt += dfs (r, c + 1); //E
	cnt += dfs (r+1, c); //S
 	cnt += dfs(r+1, c+1); //SE
	cnt += dfs(r-1, c); //north
	cnt += dfs(r-1, c-1);//nw
	cnt += dfs(r, c-1); //w
	cnt += dfs(r-1, c+1); //ne
	cnt+= dfs(r+1, c-1); //sw	





    return cnt;
}

int main() {
    int instances;
    cin >> instances;
    string line;
    getline(cin, line); // read newline after number of instances
    getline(cin, line); // read blank line after number of instances

    // Print a blank line before this instance?
    bool blank = false;

    while (cin && instances--) {
        row = col = 0;

        if (blank)
            cout << endl;
        blank = true;

        while (getline(cin, line) && line.size() > 0 ) {
            if (line[0] == 'L' || line[0] == 'W') {
                // this line is a map row.
                strncpy(matrix[row], line.c_str(), sizeof(matrix[row]));
                col = line.size();
                row++;
            } else {
                // not a map row, must be a query.
                int r, c;
                istringstream line_in(line);
                line_in >> r >> c;

                cout << dfs(r - 1, c - 1) << endl;

                // Mark everything as unvisited for next query.
                memset(visited, 0, sizeof(visited));

            }
        }
    }

    return 0;
}

// @END_OF_SOURCE_CODE
/*
Sample input:
1
  
LLLLLLWWLLLWWLLWLL
LLWWLLWLLLLWWLLWLL
LWWLLLLLLLLLWLLLL
LWWWLWWLLLLWWLLWLL
LLLWWWLLLLLLWWWLL
LWWWLLLLLLLWWLLWLL
LLLWWLLWLLLLLLLLL
LLWLWLLLLLLWWLLWLL
LLLLWWWLLLWWLLLLL
LLLLLLLLLLLWWLLWLL
LLWWLLWLLLLLWLLLL
LWWLLLLLLLLWWLLWLL
LWWWLWWLLLLLWLLLL
LLLWWWLLLLLWWWLWLL
LLLLLWWWLLWWLLLLL
LLLWWLLWLLLWWLLWLL
LLWLWLLWWWWWWLLWLL
LLLWWLLLLLLWWWLWLL
2 13
7 5
6 3
9 11
*/
