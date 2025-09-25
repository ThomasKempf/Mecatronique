/*
 * Burning Cells cellular automaton
 */
#include <stdio.h>  // For printf, fflush, stdout
#include <stdlib.h> // For rand
#include <unistd.h> // For usleep
#include <time.h>   // For time


#define W_WIDTH     100
#define W_HEIGHT    50

#define PERIOD_US   100000 // Loop period in us

#define TREE_PROB   0.1 // Probability of a new tree in an empty cell
#define BURN_PROB   0.01 // Probability of a tree burning spontaneously

#define FOR_X       for(int x = 0; x < W_WIDTH; x++)
#define FOR_Y       for(int y = 0; y < W_HEIGHT; y++)
#define FOR_YX      FOR_Y FOR_X
#define CHANCE(x)   (rand() < RAND_MAX * x) //rand() returns a number between 0 and RAND_MAX


enum { empty = 0, tree = 1, fire = 2};  // Possible state of each cell
const char *disp[] = {" ", "\033[32m@\033[m", "\033[07;31m@\033[m"};    //ANSI escape codes for empty, tree and burning cell


void display_universe(const int univ[W_HEIGHT][W_WIDTH]);
int check_neighbors(const int univ[W_HEIGHT][W_WIDTH], int x, int y);


// ----------- MAIN FUNCTION -----------
int main() {
	srand(time(0));     //random seed

	int univ[W_HEIGHT][W_WIDTH]={0}, next_univ[W_HEIGHT][W_WIDTH]={0};  //declare array for universe at time t and t+1
	FOR_YX next_univ[y][x] = univ[y][x] = CHANCE(TREE_PROB) ? tree : empty;     //generate initial universe

	printf("\033[H\033[2J");    //clear screen and move cursor to upper-left

    while(1) {
        display_universe(univ);

        FOR_YX {        //loop through each cell
            switch (univ[y][x]) {
                case fire:
                    next_univ[y][x] = empty;
                    break;
                case empty:
                    if (CHANCE(TREE_PROB)) next_univ[y][x] = tree;
                    break;
                default:    // cell with a tree
                    if(check_neighbors(univ, x, y) == fire)
                        next_univ[y][x] = fire;

                    if (next_univ[y][x] == tree && CHANCE(BURN_PROB))   //spontaneous ignition!
                        next_univ[y][x] = fire;
            }
        }

        FOR_YX { univ[y][x] = next_univ[y][x]; }    //update universe
        usleep(PERIOD_US);
    }
}
// -------------------------------------

void display_universe(const int univ[W_HEIGHT][W_WIDTH]){
    printf("\033[H");   // Move the cursor to the upper-left corner of the screen.
    FOR_Y {             //print universe
        FOR_X printf("%s",disp[univ[y][x]]);
        printf("\033[E");   // same as "\n" but don't go further than the bottom of console window
    }
    fflush(stdout);     //refresh screen
}

// The function returns "fire" if one or more of the neighbors is in fire, 0 otherwise.
int check_neighbors(const int univ[W_HEIGHT][W_WIDTH], int x, int y){

    for (int x_neighbors = -1; x_neighbors <= 1; x_neighbors++)
    {
        for (int y_neighbors = -1; y_neighbors < 1; y_neighbors++)
        {
            if (!(y_neighbors == 0 && x_neighbors == 0))
            {
                if (univ[y + y_neighbors][x + x_neighbors] == fire)
                {
                    return fire;
                }
            } 
        } 
    }
    

	return 0;
}

