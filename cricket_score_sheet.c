#include<stdio.h>
#include<stdlib.h>

//Structs for batsmen and bowlers
struct batsmen {
   char name[25];
   int runs, balls, tot_runs, tot_balls, ones, twos, threes, fours, sixes;
   int max_sixes, max_runs, max_fours;
} batsman_t1[6], batsman_t2[6], batsmen;


struct bowlers {
   char name[25];
   int runs_given, wickets, overs;
   int max_wickets;
} bowler_t1[6], bowler_t2[6], bowlers;

//Function declarations: 
void get_team1_details(int x, int y);
void get_team2_details(int x, int y);
void print_team1_details(int x, int y);
void print_team2_details(int x, int y);
void print_summary();

// main method
int main() {
	int response;
	int t1_bat, t1_bowl; //number of batsmen in team1
	int t2_bat, t2_bowl; //number of bowlers in team2
	printf("\t\t=o=o=o=o=o=o CRICKET SCORE SHEET PROGRAM o=o=o=o=o=o=\n\n");
	
    printf("Enter number of batsmen in team 1: ");
    scanf("%d", &t1_bat);
	printf("Enter number of bowlers in team 1: ");
    scanf("%d", &t1_bowl);

    printf("Enter number of batsmen in team 2: ");
    scanf("%d", &t2_bat);
    printf("Enter number of batsmen in team 2: ");
    scanf("%d", &t2_bowl);
	
	system("clear");
	
	printf("\n\t\t\t*************** INNING - 1 ***************\n");
	get_team1_details(t1_bat, t1_bowl);
	system("clear");
	
	printf("\n\t\t\t*************** INNING - 2 ***************\n");
	get_team2_details(t2_bat, t2_bowl);
	system("clear");
	
	do {
		printf("[1] : Team 1 details\n");
		printf("[2] : Team 2 details\n");
		printf("[3] : Match Summary\n");
		printf("[4] : Quit\n");
		printf("Enter a response: ");
        scanf("%d", &response);
		system("clear");
		switch(response) {
			case 1: printf("~~~~~~~~~~~~~~~~~~~~~~~> TEAM 1 DETAILS <~~~~~~~~~~~~~~~~~~~~~~~");
				print_team1_details(t1_bat, t1_bowl);
			break;
			case 2: printf("~~~~~~~~~~~~~~~~~~~~~~~> TEAM 2 DETAILS <~~~~~~~~~~~~~~~~~~~~~~~");
				print_team2_details(t1_bat, t1_bowl);
			break;
			case 3: printf(" ~~~~~~~~~~~~~~~~~~~~~~~> MATCH SUMMARY <~~~~~~~~~~~~~~~~~~~~~~~");
				print_summary();
			break;
		}
	} while(response != 4);
	printf("Exiting...\nBye :)\n");
	return 0;
}

//Funtion definitions:
void get_team1_details(int x, int y) {
	batsman_t1->tot_runs = 0;		// intialising total runs as 0
	batsman_t1->tot_balls = 0;		// intialising total balls as 0
	batsman_t1->max_fours = 0;      // initialising max fours scored as 0
	batsman_t1->max_sixes = 0;      // initialising max sixes scored as 0
	batsman_t1->max_runs = 0;       // initialising max runs as 0
	bowler_t1->max_wickets = 0;     // initialising max wickets as 0

	// taking details of batsmen
	printf("\n\t\t---------------> Enter batsman details <---------------\n");
	for(int i = 0; i < x; i++) {
		printf("\nBATSMAN %d :-\n", i + 1);

		printf("Name : ");
		scanf("%s", batsman_t1[i].name);
		
		printf("Ones Scored : ");
		scanf("%d", &batsman_t1[i].ones);
		batsman_t1[i].runs += batsman_t1[i].ones;

		printf("Twos Scored : ");
		scanf("%d", &batsman_t1[i].twos);
		batsman_t1[i].runs += (batsman_t1[i].twos * 2);

		printf("Threes Scored : ");
		scanf("%d", &batsman_t1[i].threes);
		batsman_t1[i].runs += (batsman_t1[i].threes * 3);

		printf("Fours Scored : ");
		scanf("%d", &batsman_t1[i].fours);
		batsman_t1[i].runs += (batsman_t1[i].fours * 4);

		printf("Sixes Scored : ");
		scanf("%d", &batsman_t1[i].sixes);
		batsman_t1[i].runs += (batsman_t1[i].sixes * 6);

		printf("Balls played : ");
		scanf("%d", &batsman_t1[i].balls);
		
		// calculating total runs scored by team 1
		batsman_t1->tot_runs += batsman_t1[i].runs;
		// calculating total balls played by team 1
		batsman_t1->tot_balls += batsman_t1[i].balls;
	}
	
	printf("\n");
	
	// taking details of bowlers
	printf("\n\t\t---------------> Enter bolwer details <---------------\n");
	for(int i = 0; i < y; i++) {
		printf("\nBOWLER %d :-\n", i + 1);
		
		printf("Name : ");
		scanf("%s", bowler_t1[i].name);

		printf("Wickets taken : ");
		scanf("%d", &bowler_t1[i].wickets);
		
		printf("Runs given : ");
		scanf("%d", &bowler_t1[i].runs_given);

		printf("Overs bowled : ");
		scanf("%d", &bowler_t1[i].overs);
	}
	// maximum fours, sixes and runs scored
	for(int i = 0; i < x; i++) {
		if(batsman_t1[i].fours > batsman_t1->max_fours) {
			batsman_t1->max_fours = batsman_t1[i].fours;
		}
		if(batsman_t1[i].sixes > batsman_t1->max_sixes) {
			batsman_t1->max_sixes = batsman_t1[i].sixes;
		}
		if(batsman_t1[i].runs > batsman_t1->max_runs) {
			batsman_t1->max_runs = batsman_t1[i].runs;
		}
	}
	// maximum wickets taken
	for(int i = 0; i < y; i++) {
		if(bowler_t1[i].wickets > bowler_t1->max_wickets) {
			bowler_t1->max_wickets = bowler_t1[i].wickets;
		}	
	}
}
void get_team2_details(int x, int y) {
	batsman_t2->tot_runs = 0;		// intialising total runs as 0
	batsman_t2->tot_balls = 0;		// intialising total balls as 0
	batsman_t2->max_fours = 0;      // initialising max fours scored as 0
	batsman_t2->max_sixes = 0;      // initialising max sixes scored as 0
	batsman_t2->max_runs = 0;       // initialising max runs as 0
	bowler_t2->max_wickets = 0;     // initialising max wickets as 0

	// taking details of batsmen
	printf("\n\t\t---------------> Enter batsman details <---------------\n");
	for(int i = 0; i < x; i++) {
		printf("\nBATSMAN %d :-\n", i + 1);

		printf("Name : ");
		scanf("%s", batsman_t2[i].name);
		
		printf("Ones Scored : ");
		scanf("%d", &batsman_t2[i].ones);
		batsman_t2[i].runs += batsman_t2[i].ones;
        printf("Twos Scored : ");
		scanf("%d", &batsman_t2[i].twos);
		batsman_t2[i].runs += (batsman_t2[i].twos * 2);

		printf("Threes Scored : ");
		scanf("%d", &batsman_t2[i].threes);
		batsman_t2[i].runs += (batsman_t2[i].threes * 3);

		printf("Fours Scored : ");
		scanf("%d", &batsman_t2[i].fours);
		batsman_t2[i].runs += (batsman_t2[i].fours * 4);

		printf("Sixes Scored : ");
		scanf("%d", &batsman_t2[i].sixes);
		batsman_t2[i].runs += (batsman_t2[i].sixes * 6);

		printf("Balls played : ");
		scanf("%d", &batsman_t2[i].balls);
		
		// calculating total runs scored by team 1
		batsman_t2->tot_runs += batsman_t2[i].runs;
		// calculating total balls played by team 1
		batsman_t2->tot_balls += batsman_t2[i].balls;
	}
	
	printf("\n");
	
	// taking details of bowlers
	printf("\n\t\t---------------> Enter bolwer details <---------------\n");
	for(int i = 0; i < y; i++) {
		printf("\nBOWLER %d :-\n", i + 1);
		
		printf("Name : ");
		scanf("%s", bowler_t2[i].name);

		printf("Wickets taken : ");
		scanf("%d", &bowler_t2[i].wickets);
		
		printf("Runs given : ");
		scanf("%d", &bowler_t2[i].runs_given);

		printf("Overs bowled : ");
		scanf("%d", &bowler_t2[i].overs);
	}
	// maximum fours, sixes and runs scored
	for(int i = 0; i < x; i++) {
		if(batsman_t2[i].fours > batsman_t2->max_fours) {
			batsman_t2->max_fours = batsman_t2[i].fours;
		}
		if(batsman_t2[i].sixes > batsman_t2->max_sixes) {
			batsman_t2->max_sixes = batsman_t2[i].sixes;
		}
		if(batsman_t2[i].runs > batsman_t2->max_runs) {
			batsman_t2->max_runs = batsman_t2[i].runs;
		}
	}
	// maximum wickets taken
	for(int i = 0; i < y; i++) {
		if(bowler_t2[i].wickets > bowler_t2->max_wickets) {
			bowler_t2->max_wickets = bowler_t2[i].wickets;
		}	
	}
}
// prints details of players in team 1
void print_team1_details(int x, int y) {
	printf("\n\t\t---------------> Batsmen details <---------------\n");
	printf("==================================================================\n");
	printf("NAME \t ONES \t TWOS \t THREES \t FOURS \t SIXES \t Balls Played\n");
	printf("------------------------------------------------------------------\n");
	for(int i = 0; i < x; i++) {
		printf("%s %5d %7d %9d %10d %8d %12d\n\n", batsman_t1[i].name, batsman_t1[i].ones, batsman_t1[i].twos, batsman_t1[i].threes, batsman_t1[i].fours, batsman_t1[i].sixes, batsman_t1[i].balls);
	}
	printf("==================================================================\n");

	printf("\n\t\t---------------> Bowler details <---------------\n");
	printf("==================================================================\n");
	printf("NAME \t WICKETS \t RUNS GIVEN \t OVERS\n");
	printf("------------------------------------------------------------------\n");
	for(int i = 0; i < y; i++) {
		printf("%s %5d %11d %13d\n\n", bowler_t1[i].name, bowler_t1[i].wickets, bowler_t1[i].runs_given, bowler_t1[i].overs);
	}
	printf("==================================================================\n");
}
// prints details of players in team 2
void print_team2_details(int x, int y) {
	printf("\n\t\t---------------> Batsmen details <---------------\n");
	printf("==================================================================\n");
	printf("NAME \t ONES \t TWOS \t THREES \t FOURS \t SIXES \t Balls Played\n");
	printf("------------------------------------------------------------------\n");
	for(int i = 0; i < x; i++) {
		printf("%s %5d %7d %9d %10d %8d %12d\n\n", batsman_t2[i].name, batsman_t2[i].ones, batsman_t2[i].twos, batsman_t2[i].threes, batsman_t2[i].fours, batsman_t2[i].sixes, batsman_t2[i].balls);
	}
	printf("==================================================================\n");

	printf("\n\t\t---------------> Bowler details <---------------\n");
	printf("==================================================================\n");
	printf("NAME \t WICKETS \t RUNS GIVEN \t OVERS\n");
	printf("------------------------------------------------------------------\n");
	for(int i = 0; i < y; i++) {
		printf("%s %5d %11d %13d\n\n", bowler_t2[i].name, bowler_t2[i].wickets, bowler_t2[i].runs_given, bowler_t2[i].overs);
	}
	printf("==================================================================\n");
}
// Display the summary of the match...
void print_summary(int x, int y) {
	printf("\n#################################################################\n");
	printf("Highest runs scored by team 1 : %d\n", batsman_t1->max_runs);
	printf("Maximum fours scored by team 1 : %d\n", batsman_t1->max_fours);
	printf("Maximum sixes scored by team 1 : %d\n", batsman_t1->max_sixes);
	printf("Maximum wickets taken by team 1 : %d\n", bowler_t1->max_wickets);
	printf("#################################################################\n");
	printf("Highest runs scored by team 1 : %d\n", batsman_t2->max_runs);
	printf("Maximum fours scored by team 1 : %d\n", batsman_t2->max_fours);
	printf("Maximum sixes scored by team 1 : %d\n", batsman_t2->max_sixes);
	printf("Maximum wickets taken by team 1 : %d\n", bowler_t2->max_wickets);
	printf("#################################################################\n");
}
