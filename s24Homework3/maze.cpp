//
//  maze.cpp
//  s24Homework3
//
//  Created by Cameron Maiden on 5/7/24.
//

#include <iostream>
#include <stack>

using namespace std;

///////////////////////////////////////////////////////////////////////////
//  Function declarations
///////////////////////////////////////////////////////////////////////////

bool pathExists(char maze[][10], int sr, int sc, int er, int ec);
         // Return true if there is a path from (sr,sc) to (er,ec)
         // through the maze; return false otherwise

bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
/// If the start location is equal to the ending location, then we've
///     solved the maze, so return true.
/// Mark the start location as visted.
/// For each of the four directions,
///     If the location one step in that direction (from the start
///         location) has no wall and is unvisited,
///             then if calling pathExists starting from that location
///                         (and ending at the same ending location as in
///                         the current call) returns true,
///                      then return true.
/// Return false.
///
    if(sr == er && sc == ec)
        return true;
    maze[sr][sc] = '#';
    cerr << "Searching Coordinate: [" << sr << "],[" << sc << "]" << endl;
    //EAST
    if(maze[sr][sc+1] != 'X' && maze[sr][sc+1] != '#')
        if(pathExists(maze, sr, sc+1, er, ec))
            return true;
    //SOUTH
    if(maze[sr+1][sc] != 'X' && maze[sr+1][sc] != '#')
        if(pathExists(maze, sr+1, sc, er, ec))
            return true;
    //WEST
    if(maze[sr][sc-1] != 'X' && maze[sr][sc-1] != '#')
        if(pathExists(maze, sr, sc-1, er, ec))
            return true;
    //NORTH
    if(maze[sr-1][sc] != 'X' && maze[sr-1][sc] != '#')
        if(pathExists(maze, sr-1, sc, er, ec))
            return true;
    
    return false;
}

///////////////////////////////////////////////////////////////////////////
//  main function (COMMENT THE FUNCTION OUT BEFORE TURNING IT IN!!!!!!)
///////////////////////////////////////////////////////////////////////////

int main()
{
    char maze[10][10] = {
        // 0   1   2   3   4   5   6   7   8   9
        { 'X','X','X','X','X','X','X','X','X','X' }, // 0
        { 'X','.','.','.','X','.','.','X','.','X' }, // 1
        { 'X','.','X','X','X','.','.','.','.','X' }, // 2
        { 'X','.','X','.','X','X','X','X','.','X' }, // 3
        { 'X','X','X','.','.','.','.','.','.','X' }, // 4
        { 'X','.','.','.','X','.','X','X','.','X' }, // 5
        { 'X','.','X','.','X','.','.','X','.','X' }, // 6
        { 'X','.','X','X','X','X','.','X','.','X' }, // 7
        { 'X','.','.','X','.','.','.','X','.','X' }, // 8
        { 'X','X','X','X','X','X','X','X','X','X' }  // 9
    };
    
    if (pathExists(maze, 4,3, 1,8))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
    
}
