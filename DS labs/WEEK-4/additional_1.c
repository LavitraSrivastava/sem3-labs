#include<stdio.h>
int main(){
	int no_of_cand, no_of_voters;
	printf("Enter no of voters = ");
	scanf("%d", &no_of_voters);
	char cand[no_of_cand][50];
	printf("Enter no of candidates = ");
	scanf("%d", &no_of_cand);
	int arr_votes[no_of_cand];
	for (int i=0; i<no_of_cand; i++)
		arr_votes[i]=0;
	printf("Enter candidate names:-\n");
	for (int i=0;i<no_of_cand;i++){
		printf("Candidate %d: ", i);
		scanf("%s", cand[i]);
	}
	int temp;
	printf("\nVoting shall start now. Enter 1 to continue: ");
	scanf("%d", &temp);
	int choice;
	printf("\nStart voting\n");
	for (int j=0; j<no_of_voters;j++){
		printf("\nCandidates:-\n");
		for (int i=0; i<no_of_cand;i++){
			printf("Candidate %d: %s\n", i, cand[i]);
		}
		printf("Vote for: ");
		scanf("%d", &choice);
		arr_votes[choice]++;
		printf("\nVote counted. Enter 1 to continue: ");
		scanf("%d", &temp);
		for (int i=0; i<100;i++)
			printf("\n");
	}
	printf("Enter 1 to announce winner: ");
	scanf("%d", &temp);
	int winner=0;
	for (int i=0;i<no_of_cand;i++){
		if (arr_votes[i]>arr_votes[winner])
			winner=i;
	}
	printf("Winner is %s\n", cand[winner]);

	return 0;
}