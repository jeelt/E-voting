//header files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
 typedef struct candidates//structure for storing candidates' information
  {
      char last[20],first[30],gender[10];
      int age;
      char address[100],nationality[10],party[20];
  };
struct candidates candidate;
 typedef struct voters//structure for storing voters' information
  {
      char last[20],first[30];
      char gender[10];
      char roll[10];
      char address[100],nationality[10];
	  int age;
  };
struct voters voter;

int main()//main function
{
    start();//calling start function
    return 0;
}
void start()
{
   system("cls");//clearing the console

   printf("\n\n\n\n\t\tWelcome to Voting System\n\n\n\n\n");
   printf("\n\n\t\tMade By::");
   printf("\n\t\t\tJeel Tolia 19BCE283");
   printf("\n\n\n\n\n\n\n\t\tPress Enter Key To Continue\t");
   char a;
  if (a=getchar())
  {
      menu();
  }
}

void menu()
{
   int a;
   system("cls");
   printf("1.Voter Management\n");//for voters
   printf("2.Candidate Management\n");//for candidates
   printf("3.Start Voting\n\n");//for voting

  choose:
   printf("\t\tChoose an Option: ");
   scanf("%d", &a);

   switch (a)
   {
     case 1:
       voterMgmt();
       break;
     case 2:
       candidateMgmt();
       break;
     case 3:
       voting();
       break;
     default:
      {
         printf("Enter valid option\n");
         goto choose;
      }
   }
}

void candidateMgmt()
{
   system("cls");
        printf("\n1.Add Candidate");
      	printf("\n2.Search Candidate");
      	printf("\n3.See Canditates' list");
      	printf("\n4.Delete All Candidate Record");
      	printf("\n5.Return to Menu");
        printf("\nChoose Option\n\n");
     int k;
     candidate: //for goto statement
     scanf("%d", &k); //get key
   switch (k)
  {
    case 1://Add candidate
      {
         system("cls");
         newcandidate();
      }
      break;

   	case 2://search candidate
      search_candidates();
      break;

    case 3:
      cand_list();//see candidates list
      break;

    case 4:
      delete_candidates();//delete candidates
      break;

    case 5:
      menu();//return to menu

   default:
      {
         printf("\n\nInvalid option");
         goto candidate;
      }
   }
}

void newcandidate()//to add new candidate
{
   FILE *ptr = fopen("candidatesInfo.txt", "ab+");
   if (ptr == NULL)
   {
      printf("Error");
   }
   fflush(stdin);
    printf("Enter Candidates lastname :\n");
    scanf("%s", candidate.last);

  	printf("Enter Candidates firstname :\n");
   	scanf("%s", candidate.first);

   	printf("Enter gender(M/F) :\n");
   	scanf("%s", candidate.gender);

    printf("Enter address :\n");
    scanf("%s", candidate.address);

	printf("Enter Candidates party name :\n");
   	scanf("%s", candidate.party);

	printf("Enter age :\n");
    scanf("%d", &candidate.age);
	if(candidate.age<25 || candidate.age>60)
	{
		printf("Not a valid age for contesting election");
		candidateMgmt();
	}

   printf("Enter Nationality :\n");
   scanf("%s", candidate.nationality);

   fwrite(&candidate, sizeof(candidate), 1, ptr);//storing information in text file
   fclose(ptr);

   printf("\nThe record is sucessfully added.\n");
   candidateMgmt();

}


void search_candidates() {//searching a particular candidate
   system("cls");
   printf("Search Candidate Record\n\n");
   char rec[25]; //
   int isFound = 0;
   printf("\t\tEnter a candidate's name to Search: ");
   fflush(stdin);
   gets(rec);
   FILE *fptr;
   FILE *ptr = fopen("candidatesInfo.txt", "rb");

   while (fread(&candidate, sizeof(candidate), 1, ptr) == 1)
   {
      if (strcmp(rec, candidate.first) == 0)
      {
         isFound = 1;
         break;
      }
   }

   if (isFound == 1)
   {
      printf("Record Found::\n\n");
      printf("last: %s\n", candidate.last);
      printf("first: %s\n", candidate.first);
      printf("gender: %s\n", candidate.gender);
	  printf("party name: %s\n", candidate.party);
      printf("Address: %s\n", candidate.address);
	  printf("Age: %d\n",candidate.age);
      printf("Nationality: %s\n", candidate.nationality);
     Sleep(1000);
     candidateMgmt();
   }
  else
  {
      printf("Not found");
     Sleep(1000);
    candidateMgmt();
  }

   fclose(ptr);
}
void delete_candidates()//deleting all candidates
{
   system("cls");

      FILE *ptr;
      ptr = fopen("candidatesInfo.txt", "ab+");
      fflush(stdin);
      fclose(ptr);
      remove("candidatesInfo.txt");
      fflush(stdin);
      FILE *fp = fopen("candidatesInfo.txt", "ab+");
      printf("The records were sucessfully deleted");
      candidateMgmt();
      fclose(fp);

}
void cand_list()//view all candidates list
{
   system("cls");
   int count = 0;
   FILE *ptr;
   ptr = fopen("candidatesInfo.txt", "r");
   printf("Candidate List\n");

  while (fread(&candidate, sizeof(candidate), 1, ptr) == 1)
   {
      count++;
      printf("\n\nCandidate %d:\n\n",count);
      printf("firstname: %s\n",candidate.first);
      printf("lastname: %s\n",candidate.last);
      printf("gender: %s\n",&candidate.gender);
      printf("party name: %s\n", candidate.party);
      printf("Address: %s\n",candidate.address);
	  printf("Age: %d\n",candidate.age);
      printf("Nationality: %s\n\n",candidate.nationality);
   }

   if (count == 0)
   {
      printf("No Candidate record :\n");
     candidateMgmt();
   }
  else
  {
      char ch;
      printf("\tPress Enter Key to goto main Menu:");
      ch = getchar();

    if (getchar())
    {
      candidateMgmt();
  	}
    else
    {
         system("cls");
         candidateMgmt();
    }
   }
   fclose(ptr);
}

void voterMgmt()
{
    int count=0;

   system("cls");
   choose:
      printf("\n1.Add Voter");
      printf("\n2.Search Voters");
      printf("\n3.See Voters' List");
      printf("\n4.Delete all Voters");
      printf("\n5.Return to Main Menu");

   printf("\nEnter your choice:");
   int k;
   ment:
      scanf("%d", &k);

  switch (k)
  {
      system("cls");

    case 1:
      {
         FILE *ptr1 = fopen("votersInfo.txt", "ab+");

        if (ptr1 == NULL)
        {
            printf("Error!!");
        }
         fflush(stdin);
        system("cls");
        printf("Enter Voter lastname:\n");
         scanf("%s", voter.last);

        printf("Enter Voter firstname:\n");
         scanf("%s", voter.first);

        printf("Enter gender(M/F)\n");
         scanf("%s", voter.gender);

        printf("Enter Voter ID :\n");
         scanf("%s", voter.roll);

		 printf("Enter age :\n");
         scanf("%d", &voter.age);
		 if(voter.age<18)
		 {
			 printf("Cannot vote");
			 //system("cls");
             goto choose;
		 }

       printf("Enter address:\n");
         scanf("%s", voter.address);

        printf("Enter Nationality:\n");
         scanf("%s", voter.nationality);

         printf("\r\n");
        fwrite(&voter, sizeof(voter), 1, ptr1);
         fclose(ptr1);
         printf("\nThe record is sucessfully added to votersInfo.txt.\n");
         count++;
         system("cls");
         goto choose;
      }
      break;

   case 2:
      {
         system("cls");
         printf("Search Voters Record::\n\n");
         char rec[25]; //
         int search_counter = 0;
         printf("\t\tEnter Voter Id ::\n");
         fflush(stdin);
         gets(rec);
         FILE *ptr1 = fopen("votersInfo.txt", "rb");

         while (fread(&voter, sizeof(voter), 1, ptr1) == 1)
         {
            if (strcmp(rec, voter.roll) == 0)
            {
               search_counter = 1;
               break;
            }
         }

         if (search_counter == 1)
         {
            printf("Voter Record Found:\n\n");
            printf("lastname: %s\n", voter.last);
            printf("firstname: %s\n", voter.first);
            printf("gender: %s\n", voter.gender);
			printf("age: %d\n", voter.age);
            printf("Voter ID: %s\n", voter.roll);
            printf("Address: %s\n", voter.address);
            printf("Nationality: %s\n", voter.nationality);


            goto choose;
         }

         else
         {
            printf("Sorry, No record found in the database");


            goto choose;
         }
         fclose(ptr1);
      }
      break;

    case 3:
      system("cls");
        count=0;

      FILE *ptr1;
      ptr1 = fopen("votersInfo.txt", "r");
      printf("\nVoters List\n");

      while (fread(&voter, sizeof(voter), 1, ptr1) == 1)
      {
         count++;
         printf("Voter number %d:\n", count);
         printf("Voter Name: %s %s\n", voter.first, voter.last);
         printf("gender: %s\n", voter.gender);
         printf("ID= %s\n",voter.roll);
		 printf("age: %d\n", voter.age);
         printf("Address: %s\n", voter.address);
         printf("Nationality: %s\n\n", voter.nationality);

      }

      if (count == 0)
      {
         printf("No voter found:\n");

         system("cls");
         goto choose;
      }

      else
      {
         char ch;
         printf("\tPress Enter Key to Goto Main Menu:");
         ch = getchar();

        if (getchar())
        {

            goto choose;
         }

         else
         {
            system("cls");
            goto choose;
         }
      }
      fclose(ptr1);
      break;

    case 4:
      {
         system("cls");
            FILE *ptr1;
            ptr1 = fopen("votersInfo.txt", "ab+");
            fflush(stdin);
            fclose(ptr1);
            remove("votersInfo.txt");
            FILE *fp = fopen("votersInfo.txt", "ab+");
           if (fp != NULL)
           {
               fflush(stdin);
               printf("The records were sucessfully deleted");
           }
            system("cls");
            goto choose;
            fclose(fp);
         }
   case 5:
      {
         menu();
      }
   default:
      {
         printf("Invalid Choice");
         goto ment;
      }
   }
}

void voting()//for starting voting process
{
    int a[26] = {0};//initializing with zero
    int choice_candidate;
    int password;
    char id_num[100];
    int getChoice;

    int voterNumber = 0, voterCount = 0, candidateCount = 0;
     printf("Making sure that the number of voters and the candidates is not zero.");

       //Check for voters:
        FILE *ptr1;
        ptr1 = fopen("votersInfo.txt", "r");

        while (fread(&voter, sizeof(voter), 1, ptr1) == 1)
        {
            voterCount++;
        }
        fclose(ptr1);

       //Check for candidates:

       FILE *ptr;
            ptr = fopen("candidatesInfo.txt", "r");

       while (fread(&candidate, sizeof(candidate), 1, ptr) == 1)
        {
            candidateCount++;
        }
        fclose(ptr);


       printf("\nResult::\n");

       printf("Number of Voters = %d\n", voterCount);

       printf("Number of Candidates = %d\n\n", candidateCount);

    if(voterCount == 0 || candidateCount == 0)
    {
        if(voterCount == 0)
        {
            printf("\nThe number of voters is zero.");
            printf("\nPlease add some voters.\n\n");
        }
        if(candidateCount == 0)
        {
            printf("\nThe number of candidates is zero.");
            printf("\nPlease add some candidates.\n\n");
        }
            Sleep(2500);
            menu();

    }
    voterNumber = voterCount;

    while (voterNumber!=0)
    {
        voting:

        system("cls");

        printf ("WELCOME TO VOTING PROCESS\n\n");
        printf ("\nEnter your ID: ");
        scanf ("%s", id_num);
            system ("cls");
            int count=0;
            FILE *ptr;
            ptr = fopen("candidatesInfo.txt", "r");
            if (ptr == NULL)
            {
                printf("\nERROR\n!");
            }
                printf("Candidate List\n");
                printf ("\n______________________________________________\n");
                while (fread(&candidate, sizeof(candidate), 1, ptr) == 1)
                {
                    count++;
                    printf("\nCandidate %d::", count);
                    printf("%s %s\n", candidate.first, candidate.last);
                    printf("Party Name:%s\n", candidate.party);
                }
            fclose(ptr);

            printf ("\n\n\tEnter Your choice: ");
            scanf ("%d", &choice_candidate);
            switch (choice_candidate)
            {
                case 1:
                    a[0] += 1;
                    break;

                case 2:
                    a[1] += 1;
                    break;

                case 3:
                    a[2] += 1;
                    break;

                case 4:
                    a[3] += 1;
                    break;

                case 5:
                    a[4] += 1;
                    break;

                case 6:
                    a[5] += 1;
                    break;

                case 7:
                    a[6] += 1;
                    break;

                case 8:
                    a[7] += 1;
                    break;

                case 9:
                    a[8] += 1;
                    break;

                case 10:
                    a[9] += 1;
                    break;

                case 11:
                    a[10] += 1;
                    break;

                case 12:
                    a[11] += 1;
                    break;

                case 13:
                    a[12] += 1;
                    break;

                case 14:
                    a[13] += 1;
                    break;

                case 15:
                    a[14] += 1;
                    break;

                case 16:
                    a[15] += 1;
                    break;

                case 17:
                    a[16] += 1;
                    break;

                case 18:
                    a[17] += 1;
                    break;

                case 19:
                    a[18] += 1;
                    break;

                case 20:
                    a[19] += 1;
                    break;

                case 21:
                    a[20] += 1;
                    break;

                case 22:
                    a[21] += 1;
                    break;

                case 23:
                    a[22] += 1;
                    break;

                case 24:
                    a[23] += 1;
                    break;

                case 25:
                    a[24] += 1;
                    break;

                case 26:
                    a[25] += 1;
                    break;

                    printf("\n1.Main Menu");
                    printf("\n2.Result of Voting");
                    printf("Please choose an option:: ");
                    scanf("%d", &getChoice);

                   if(getChoice == 1)
                   {
                       menu();
                   }

                   else if(getChoice == 2)
                    {

                        goto end;
                    }
            }
            voterNumber--;

            printf("\n\n\t\tThank you for voting!\a\n");

        }


   //closes while
 if (voterNumber == 0)
    {
        printf("\n\n\tThe voting process is over.\n");

        goto end;
    }
        end:
           votingResult(a, 26);


}   //closes voting function


void votingResult(int *x, int candidate_no)
{
    int k;
    int choiceResult;
    int i;

    system("cls");

    printf("\nEnter 1 to see result: ");
    scanf("%d", &k);
    if(k == 1)
    {
		   system("cls");
                printf("RESULT OF VOTING:\n");

               FILE *ptr;
               int count=1;

                    ptr = fopen("candidatesInfo.txt", "r");
                     if (ptr == NULL)
                       {
                          printf("\nERROR\n!");
                       }


                while (fread(&candidate, sizeof(candidate), 1, ptr) == 1)
                {

                    printf("Candidate Number: %d\n",count );
                    printf("Name: %s %s \nGender: %s\n", candidate.first, candidate.last, candidate.gender);
                     printf("Number of votes : %d \n\n", x[i]);
                     count++;

                }


                 fclose(ptr);

    }
}
