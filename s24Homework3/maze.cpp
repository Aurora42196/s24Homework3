//
//  maze.cpp
//  s24Homework3
//
//  Created by Cameron Maiden on 5/7/24.
//
//For this part of the homework, you will turn in one file named maze.cpp that contains the Coord class (only if you use it) and the pathExists function and nothing more.

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

