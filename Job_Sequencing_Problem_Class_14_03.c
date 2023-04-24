#include<stdio.h>
#define MAX 10
typedef struct Job{
	char id[5];
	int deadline;
	int profit;
}Job;

int minValue(int x ,int y){
	if(x<y){
		return x;
	}
	return y;
}

void JobSequenceOrder(Job jobs[],int range){
	int dmax = 0,i,min,filledtimeslot = 0,j,counter=0;
	int timeslot[MAX];
	for(i=0;i<range;i++){
		if(jobs[i].deadline > dmax){
			dmax = jobs[i].deadline;
		}
	}
	//initializing the empty array
	for(i=0;i<dmax;i++){
		timeslot[i] = -1;
	}
	printf("\nDmax:%d",dmax);
	printf("\nTimeslot:\n");
	for(i=0;i<dmax;i++){
		printf("%d\t",timeslot[i]);	
	}
	for(i=0;i<range;i++){
		min = minValue(dmax,jobs[i].deadline);
		while(min>0){
			if(timeslot[min-1] == -1){
			timeslot[min-1] = i;
			filledtimeslot++;
			break;
		}
		min--;
		}
		
		if(filledtimeslot == dmax){
			break;
		}
	}
	
	printf("\nRequired Jobs:");
	for(i=0;i<dmax;i++){
		printf("%s",jobs[timeslot[i]].id);
		
		if(i<dmax-1){
			printf(" --> ");
		}
	}
	int maxprofit = 0;
	for(i=0;i<dmax;i++){
		maxprofit += jobs[timeslot[i]].profit;
	}
	printf("\nMaxprofit:%d",maxprofit);


}
	
	
int main(){
	Job jobs[6];
	int range,i,j;
	Job temp;
	printf("Enter the job number:");
	scanf("%d",&range);
	printf("Enter job,deadline,profit:\n");
	for(i=0;i<range;i++){
		scanf("%s %d %d",jobs[i].id,&jobs[i].deadline,&jobs[i].profit);
	}
	//sort the array in descending order(according to their profit)
	for(i=0;i<range;i++){
		for(j=0;j<range-i;j++){
			if(jobs[j+1].profit>jobs[j].profit){
				temp = jobs[j];
				jobs[j] = jobs[j+1];
				jobs[j+1] = temp;
			}
		}
	}
	//printing the sorted array in order to profit
	printf("\nThe Job,Deadline,profit(profit in decreasing order):\n");
	for(i=0;i<range;i++){
		printf("%s %d %d\n",jobs[i].id,jobs[i].deadline,jobs[i].profit);
	}
	JobSequenceOrder(jobs , range);
	return 0;
}
