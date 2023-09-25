
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int pointer;
int faults ,hits;
void print(int frame_size,int frame[])
{
	int k;
	//printf("Printing the Frames: ");
	for(k=0;k<frame_size;k++)
	{
		if(frame[k]==-1)
			printf("- ");
		else
			printf("%d ",frame[k]);
	}

	printf("\n");
}

int predict(int reference_length, int references[], int page_no ,int frame_size,int frame[], int start)
{
	int pos = -1, farthest = start, k;
	for(k=0;k<frame_size;k++)
	{
		int m;
		for(m=start;m<reference_length;m++)
		{
			if(frame[k]==references[m])
			{
				if(m>farthest)
				{
					farthest=m;
					pos=k;
				}
				break;
			}
		}
		if(m==page_no)
			return k;
	}
	if(pos == -1)
		return 0;
	else
		return pos;
}

void add_reference(int frame_size,int frame[], int reference, int current_position,int reference_length, int references[])
{
	int k;
	bool allocated=false;
	for(k=0;k<frame_size;k++)
	{

		if(frame[k]==reference)
		{
			printf("  Hit for %d | ", reference);
			hits++;
			allocated = true;
			break;
		}
		else if(frame[k]==-1)
		{
			frame[k] = reference;
			printf("Fault for %d | ", reference);
			faults++;
			allocated = true;
			break;
		}
	}
	if(allocated==false)
	{
		int j = predict(reference_length,references,current_position,frame_size,frame,current_position+1);

		frame[j] = reference;
		printf("Fault for %d | ", reference);
		faults++;
	}
	print(frame_size, frame);
}

int main()
{
	int frame_size,k,number_of_references;
	printf("Enter frame size: ");
	scanf("%d",&frame_size);
	int frame[frame_size];
     //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	for(k=0;k<frame_size;k++)
	{
		frame[k] = -1;
	}

	print(frame_size,frame);

	printf("Enter the number of references: ");
	scanf("%d",&number_of_references);
	int reference[number_of_references];

	for(k=0;k<number_of_references;k++)
	{
		scanf("%d",&reference[k]);
		add_reference(frame_size,frame,reference[k],k,number_of_references,reference);
	}
	printf("\nNumber of faults: %d \nNumber of hits: %d\n",faults,hits );
}
