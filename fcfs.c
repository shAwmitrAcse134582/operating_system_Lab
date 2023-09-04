/*
	Disk Scheduling
	First Come First Serve
*/
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
int main()
{
	int i,no_of_requests,initial_head;
	printf("Enter the number of requests: ");
  freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	scanf("%d",&no_of_requests);
    printf("%d\n",no_of_requests);
	int request[no_of_requests];
	printf("Enter the requests: ");
    
    
	for (i = 0; i < no_of_requests; ++i)
	{
		scanf("%d",&request[i]);
        printf("%d ",request[i]);
	}
    printf("\n");
	printf("Enter initial position of R/W head: ");
	scanf("%d",&initial_head);
	int seek_time=0;
	printf("%d -> ",initial_head );
	for(i=0;i<no_of_requests;i++)
	{
		if(i == no_of_requests-1)
			printf("%d\n", request[i] );
		else
			printf("%d -> ", request[i] );
		seek_time += abs(request[i] - initial_head);
		initial_head = request[i];
	}
	printf("Seek Time: %d\n", seek_time);
}
