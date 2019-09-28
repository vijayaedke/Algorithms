





/*
the Activity Selection problem as our first example of Greedy algorithms. Following is the problem statement.
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Example:

Example 1 : Consider the following 3 activities sorted by
by finish time.
     start[]  =  {10, 12, 20};
     finish[] =  {20, 25, 30};
A person can perform at most two activities. The 
maximum set of activities that can be executed 
is {0, 2} [ These are indexes in start[] and 
finish[] ]

Example 2 : Consider the following 6 activities 
sorted by by finish time.
     start[]  =  {1, 3, 0, 5, 8, 5};
     finish[] =  {2, 4, 6, 7, 9, 9};
A person can perform at most four activities. The 
maximum set of activities that can be executed 
is {0, 1, 3, 4} [ These are indexes in start[] and 
finish[] ]


*/

#include<stdio.h>
#include<stdlib.h>
struct activity{
    int start, finish;
};

int compare(const void *a, const void *b){
    struct activity *a1=(struct activity *)a;
    struct activity *b1=(struct activity *)b;
    
    return a1->finish - b1->finish;
}

void printMaxActivities(struct activity *a1,int n){
    int prev=0;
    
    printf("\nSelected activties are :- \n");
    printf("%d\t%d\n", a1[0].start, a1[0].finish);
    
    for(int i=1; i<n; i++){
        if(a1[i].start >= a1[prev].finish){
            printf("%d\t%d\n", a1[i].start, a1[i].finish);
            prev=i;
        }//if
    }//for
    
} //printMaxActivities

int main() {
    struct activity a1[]={
   
        {5,7},
        {1,2},
        {3,4},
        {0,6},
        {8,9},
        {5,9}
    };
    qsort (a1, 6, sizeof(struct activity), compare);
    // for(int i=0;i<6;i++){
    //     printf("start = %d", a1[i].start);
    //     printf("finish = %d\n", a1[i].finish);
    // }//for

    // int s[] =  {1, 3, 0, 5, 8, 5}; 
    // int f[] =  {2, 4, 6, 7, 9, 9}; 
    int n = 6; 
    printMaxActivities(a1,  n); 
    return 0;
}

/*
output:

Selected activties are :- 
1	2
3	4
5	7
8	9


*/