#include<stdio.h>
#include<stdlib.h>

//Structs for batsmen and bowlers
struct batsmen {
   char name[25];
   int runs, balls, tot_runs, tot_balls, ones, twos, threes, fours, sixes;
   int max_sixes, max_runs, max_fours;
} batsmen_t1[6], batsmen_t2[6];


struct bowlers {
   char name[25];
   int runs_given, wickets, overs;
   int max_wickets;
} bowlers_t1[6], bowlers_t2[6];

//Function declarations: 
void get_team1_details(int n);
void get_team2_details(int n);
void print_team1_details(int n);
void print_team2_details(int n);

int main() {
	int n;	//number of players in each team
	printf("\t\t=o=o=o=o=o=o CRICKET SCORE SHEET PROGRAM o=o=o=o=o=o=\n\n");
	
	printf("Enter the number of players in the two teams : ");
	scanf("%d", &n);

	printf("\t\t\t********** INNING - 1 **********\n");
	get_team1_details(n);
	
	printf("\t\t\t********** INNING - 2 **********\n");
	get_team2_details(n);

	return 0;
}

//Funtion dfinitions:
void get_team1_details(int n) {
	
}
void get_team2_details(int n) {

}
void print_team1_details(int n) {

}
void print_team2_details(int n) {

}
