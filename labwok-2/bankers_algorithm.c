#include<stdio.h>
int main() {
    FILE *fp, *fa, *fm, *fal;
    fp = fopen("input.txt", "r");
    fa = fopen("avilable.txt", "r");
    fm = fopen("max.txt", "r");
    fal = fopen("allocation.txt", "r");
    int count = 0, k, j, m, n;
    int max[10][10], alloc[10][10], avail[10], finished[10], safeSeq[10], need[10][10];

    fscanf(fp, "%d", &n);
    fscanf(fp, "%d", &m);

    for(k = 0; k < n; k++) {
        for(j = 0; j < m; j++) {
            fscanf(fm, "%d", &max[k][j]);
        }
    }

    for(k = 0; k < n; k++) {
        for(j = 0; j < m; j++) {
            fscanf(fal, "%d", &alloc[k][j]);
        }
    }

    for(k = 0; k < m; k++) {
        fscanf(fa, "%d", &avail[k]);
    }

    fclose(fp);
    fclose(fa);
    fclose(fm);
    fclose(fal);


    for(k = 0; k < n; k++)
        finished[k] = 0;

    while(count < n) {
        int found = 0;
        for(k= 0; k < n; k++) {
            if(finished[k] == 0) {
                int flag = 0;
                for(j = 0; j < m; j++) {
                    if(max[k][j] - alloc[k][j] > avail[j]){
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0) {
                    safeSeq[count++] = k;
                    for(j = 0; j < m; j++)
                        avail[j] += alloc[k][j];
                    finished[k] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            printf("System is not in safe state");
            return 0;
        }
    }
    printf("Need Matrix :\n");
    for(k = 0; k < n; k++) {
        for(j = 0; j < m; j++) {
            need[k][j]=max[k][j]-alloc[k][j];
            printf("%d ",need[k][j]);
        }
        printf("\n");
    }

    printf("System is in safe state.\nSafe sequence is: ");
    for(k= 0; k < n - 1; k++)
        printf("P%d -> ", safeSeq[k]);
    printf("P%d", safeSeq[n - 1]);

    int immidiate_request;
    printf("\nwant proceed an immidiate request? 1 for yes 0 for no: ");
    scanf("%d",&immidiate_request);
    if (immidiate_request==1)
    {
        FILE *req;
        req = fopen("request.txt", "r");

        int request[10];

        for(k= 0; k < m; k++)
        {
            fscanf(req, "%d", &request[k]);
            avail[k]=avail[k]-request[k];
        }
        fclose(req);
        count = 0;
        for(k= 0; k < n; k++)
        finished[k] = 0;

        while(count < n) {
            int found = 0;
            for(k = 0; k < n; k++) {
                if(finished[k] == 0) {
                    int flag = 0;
                    for(j = 0; j < m; j++) {
                        if(max[k][j] - alloc[k][j] > avail[j]){
                            flag = 1;
                            break;
                        }
                    }

                    if(flag == 0) {
                        safeSeq[count++] = k;
                        for(j = 0; j < m; j++)
                            avail[j] += alloc[k][j];
                        finished[k] = 1;
                        found = 1;
                    }
                }
            }

            if(found == 0) {
                printf("System is not in safe state");
                return 0;
            }
        }
        printf("System is in safe state.\nSafe sequence is: ");
        for(k = 0; k< n - 1; k++)
            printf("P%d -> ", safeSeq[k]);
        printf("P%d", safeSeq[n - 1]);

    }
    else
    {
        for(k= 0; k < m; k++)
        {
            avail[k]=avail[k];
        }
    }

    
}
