#include <stdio.h>
int main() {
    int n, bt[20], pr[20], rt[20], i, time = 0, remain, smallest, min;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    remain = n;
    for(i=0;i<n;i++){
        printf("Burst time & Priority for P%d: ", i+1);
        scanf("%d %d",&bt[i],&pr[i]);
        rt[i] = bt[i];
    }
    pr[19] = 9999;
    printf("\nProcess\tWaiting Time\n");
    int wtTotal = 0;
    for(time = 0; remain != 0; time++){
        smallest = 19;
        for(i=0;i<n;i++)
            if(rt[i] > 0 && pr[i] < pr[smallest])
                smallest = i;

        rt[smallest]--;

        if(rt[smallest] == 0){
            remain--;
            int wt = time+1 - bt[smallest];
            wtTotal += wt;
            printf("P%d\t%d\n", smallest+1, wt);
        }
    }
    return 0;
}

