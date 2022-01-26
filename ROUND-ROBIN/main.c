//NAMA  : DEOVIE LENTERA H.
//NIM   : 18320037

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, number, x, quantum, total = 0, counter = 0, turnaround_time = 0, wait_time = 0;
    int arrival[10], need[10], temp[10];
    printf("ROUND ROBIN\n");
    printf("Insert number of processes: ");
    scanf("%d", &number);
    printf("\n");

    x = number;

    for(i = 0; i < number; i++)
    {
        printf("Enter details of process[%d]\n", i + 1);
        printf("\nArrival time: ");
        scanf("%d", &arrival[i]);
        printf("Time needed: ");
        scanf("%d", &need[i]);
        printf("\n");
        temp[i] = need[i];
    }

    printf("Insert time quantum: ");
    scanf("%d", &quantum);
    printf("\n");
     printf("\nProcess ID\t\tTime needed\t Turnaround Time\t Waiting Time\n");

    for(total = 0, i = 0; x != 0;)
    {
        if(temp[i] <= quantum && temp[i] > 0)
        {
            total = total + temp[i];
            temp[i] = 0;
            counter = 1;
        }
        else if(temp[i] > 0)
        {
            temp[i] = temp[i] - quantum;
            total = total + quantum;
        }
        if(temp[i] == 0 && counter == 1)
        {
            x--;
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, need[i], total - arrival[i], total - arrival[i] - need[i]);
            wait_time = wait_time + total - arrival[i] - need[i];
            turnaround_time = turnaround_time + total - arrival[i]; //turnaround time = exit time - arrival time
            counter = 0;
        }
        if(i == number - 1)
        {
            i = 0;
        }
        else if(arrival[i + 1] <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    return 0;
}

