#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//TODO
//Implement the below function
//Simulate one particle moving n steps in random directions
//Use a random number generator to decide which way to go at every step
//When the particle stops at a final location, use the memory pointed to by grid to 
//record the number of particles that stop at this final location
//Feel free to declare, implement and use other functions when needed


double sqroot(double square)
{
    double root=square/3;
    int i;
    if (square <= 0) return 0;
    for (i=0; i<32; i++)
        root = (root + square / root) / 2;
    return root;
}





void xyzinitilizer(int n, int **p){

int i,x,y,z,end=0;

for (x = -n; x <= n; x++) {
        for (y = -n; y <= n; y++) {
            for (z = -n; z <= n; z++) {
                p[end][0] = x;
                p[end][1] = y;
                p[end][2] = z;
                end += 1;
                if (end >= ((n+n+1)*(n+n+1)*(n+n+1))){
                    break;
                }
            }  
        }                
}


}







void one_particle(int **grid, int n)
{
	int x=0,y=0,z=0,r,i,t=n;

	while (t != 0) {
 		r = rand() % 6;

		if (r == 0) {
			if (x != -n) {
				x = x - 1;
			}
		}
		else if (r == 1) {
			if (x != n) {
			x = x + 1;
			}
		}
		else if (r == 2) {
			if (y != n) {
			y = y + 1;
			}
		
		}
		else if (r == 3) {
			if (y != -n) {
			y = y - 1;
			}
		}
		else if (r == 4) {

			if (y != n) {
			z = z + 1;
			}
		
		}
		else if (r == 5) {
			if (y != -n) {
			z = z - 1;
			}
		}
		
		t = t - 1; 
	}

	for (i=0;((n+n+1)*(n+n+1)*(n+n+1))>i;i++){
		if ((grid[i][0] == x) && (grid[i][1] == y) && (grid[i][2] == z)){
			grid[i][3] = grid[i][3] + 1;
		}	
	}

	//for (i=0; ((n+n+1)*(n+n+1)*(n+n+1))>i; i++) {

	//printf("%d ---- %d ---- %d rrrrrrr----- value %d\n",grid[i][0],grid[i][1],grid[i][2],grid[i][3]);

	//}







}

//TODO
//Implement the following function
//This function returns the fraction of particles that lie within the distance
//r*n from the origin (including particles exactly r*n away)
//The distance used here is Euclidean distance
//Note: you will not have access to math.h when submitting on Mimir
double density(int **grid, int n, double r)
{
int i;
double r1;
double cr = ((r*n)*(r*n));
int total = 0;
int sumtotal = 0;


for (i=0; ((n+n+1)*(n+n+1)*(n+n+1))>i; i++) {
	r1 = (grid[i][0] * grid[i][0]) + (grid[i][1] * grid[i][1]) + (grid[i][2] * grid[i][2]);
	if (cr >= r1) {
	total = total + grid[i][3];	
	}
}

for (i=0; ((n+n+1)*(n+n+1)*(n+n+1))>i; i++) {
	sumtotal = sumtotal + grid[i][3];
}


return (((double)total/sumtotal));

}

//use this function to print results
void print_result(int **grid, int n)
{
    printf("radius density\n");
    for(int k = 1; k <= 20; k++)
    {
        printf("%.2lf   %lf\n", 0.05*k, density(grid, n, 0.05*k));
    }
}

//TODO
//Finish the following function
//See the assignment decription on Piazza for more details
void diffusion(int n, int m)
{
	int i;

	int **grid = (int **)calloc(((n+n+1)*(n+n+1)*(n+n+1)),sizeof(int*));

	for (i=0; ((n+n+1)*(n+n+1)*(n+n+1))>i; i++) {
    	grid[i] = (int *)calloc(4, sizeof(int));
	}
	xyzinitilizer(n, grid);



	//fill in a few line of code below
	for(int i = 1; i<=m; i++) {
		one_particle(grid, n);
		}

	print_result(grid, n);
	//fill in some code below


}

int main(int argc, char *argv[])
{
	
	if(argc != 3)
	{
		printf("Usage: %s n m\n", argv[0]);
		return 0; 
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	assert(n >= 1 && n <=50);
	assert(m >= 1 && m <= 1000000);
	srand(12345);
	diffusion(n, m);
	return 0;
}