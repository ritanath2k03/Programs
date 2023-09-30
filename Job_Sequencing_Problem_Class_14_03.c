#include<stdio.h>

#define RANGE 6

void JOBSequenceProblem();
int findmaxDeadline();
typedef struct JOBSequence{
    char id;
    int deadline;
    int profit;
int selected;
}JOB;

JOB jobs[6];
int timeslot[10];

int minValue(int x ,int y){
	if(x<y){
		return x;
	}
	return y;
}
int main(){
    jobs[0].id='a';
	jobs[0].deadline=5;
	jobs[0].profit=200;
    jobs[0].selected=0;
	jobs[1].id='b';
	jobs[1].deadline=3;
	jobs[1].profit=180;
    jobs[1].selected=0;
	jobs[2].id='c';
	jobs[2].deadline=3;
	jobs[2].profit=190;
    jobs[2].selected=0;
	jobs[3].id='d';
	jobs[3].deadline=2;
	jobs[3].profit=300;
    jobs[3].selected=0;
	jobs[4].id='e';
	jobs[4].deadline=4;
	jobs[4].profit=120;
    jobs[4].selected=0;
	jobs[5].id='f';
	jobs[5].deadline=2;
	jobs[5].profit=100;
    jobs[5].selected=0;
int i,j,vtemp;
char stemp;
    	for(i=0;i<RANGE;i++){
		for(j=0;j<RANGE-i;j++){
			if(jobs[j+1].profit>jobs[j].profit){
				vtemp = jobs[j].profit;
				jobs[j].profit = jobs[j+1].profit;
				jobs[j+1].profit = vtemp;

                vtemp = jobs[j].deadline;
				jobs[j].deadline = jobs[j+1].deadline;
				jobs[j+1].deadline = vtemp;

                stemp = jobs[j].id;
                jobs[j].id = jobs[j+1].id;
                jobs[j+1].id = stemp;
				
			}
		}
	}

    printf("\nThe Job,Deadline,profit(profit in decreasing order):\n");
	for(i=0;i<RANGE;i++){
		printf("%c %d %d\n",jobs[i].id,jobs[i].deadline,jobs[i].profit);
	}
    JOBSequenceProblem();
}

void JOBSequenceProblem(){

int maxDeadline=findmaxDeadline();
int deadlinearr[maxDeadline];

for(int i=0;i<maxDeadline;i++){
		timeslot[i] = -1;
	}
int min=999999,filledtimeslot=0;
        for(int i=0;i<RANGE;i++){
		min = minValue(maxDeadline,jobs[i].deadline);
		while(min>0){
			if(timeslot[min-1] == -1){
			timeslot[min-1] = i;
			filledtimeslot++;
			break;
		}
		min--;
		}
		
		if(filledtimeslot == maxDeadline){
			break;
		}

	}
	printf("\nRequired Jobs:");
	for(int i=0;i<maxDeadline;i++){
		printf("%c",jobs[timeslot[i]].id);
        jobs[timeslot[i]].selected=1;
		
		if(i<maxDeadline-1){
			printf(" --> ");
		}
	}
    	int maxprofit = 0;
	for(int i=0;i<maxDeadline;i++){
		maxprofit += jobs[timeslot[i]].profit;
	}
	printf("\nMaxprofit:%d",maxprofit);
printf("\nNot Resuired Jobs are \n");
    for(int i=0;i<RANGE;i++){
if(jobs[i].selected==0)printf("%c \t",jobs[i].id);

    }

}


int findmaxDeadline(){
    int maxdeadline=-1;
    for(int i=0;i<RANGE;i++){
if(maxdeadline<jobs[i].deadline)
maxdeadline=jobs[i].deadline;
    }
    return maxdeadline;
}