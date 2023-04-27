#include <stdio.h>

#define TRIED 2
#define PATH 3


const int num_rows = 5;
const int num_col = 5;
const int end_row = 4;
const int end_col = 4;
int grid[num_rows][num_col];

bool check_position(int x, int y)
{
    bool result = false;

    if((y < num_col && y >=0) &&
    (x < num_rows && x >=0))
    {
        if(grid[x][y] == 1)
            result = true;
    }
    return result;
}

void tried_position(int x, int y)
{
    grid[x][y] = TRIED;
}

bool solved(int x, int y)
{
    return(x == end_row && y == end_col);
}

void mark_path(int x,int y)
{
    grid[x][y] = PATH;
}

bool traverse(int x, int y)
{
    bool done = false;
    if(check_position(x,y))
    {
        tried_position(x,y);
        if(solved(x,y)) {
            done = true;
        }
        else {
            if (!done)
                done = traverse(x - 1, y);
            if (!done)
                done = traverse(x, y - 1);
            if (!done)
                done = traverse(x + 1, y);
            if (!done)
                done = traverse(x, y + 1);

        }
            if(done) {
                mark_path(x, y);
            }
    }
    return done;
}

int main() {


    //column 1
    grid[0][0] = 1;
    grid[1][0] = 1;
    grid[3][0] = 1;

    //column 2
    grid[1][1] = 1;
    grid[2][1] = 1;
    grid[3][1] = 1;
    grid[4][1] = 1;

    //column 3
    grid[1][2] = 1;
    grid[3][2] = 1;

    //column 4
    grid[1][3] = 1;
    grid[3][3] = 1;
    grid[4][3] = 1;

    //column 5
    grid[4][4] = 1;

    for(int i = 0; i < num_rows;i++)
    {
        for(int j = 0; j < num_col;j++)
        {
            printf("%d",grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    traverse(0,0);

    for(int i = 0; i < num_rows;i++)
    {
        for(int j = 0; j < num_col;j++)
        {
            printf("%d",grid[i][j]);
        }
        printf("\n");
    }

}
