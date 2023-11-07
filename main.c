/* main.c UOCStadium ticketing software
Guillermo Rubio Gutiérrez, 2023*/

#include <stdio.h>
#include <stdbool.h>

// Global Variables
const int MIN_SUPPORTERS = 1;
const int MAX_SUPPORTERS = 10;
const int BASE_MEMBERSHIP_YEARS = 5;
const int SILVER_MEMBERSHIP_YEARS = 10;

// Enumeration type declarations
enum tMembershipType
{
    BASE = 1,   //  code 1
    SILVER = 2, //  code 2
    GOLD = 3    //  code 3
};

int main()
{
    // DATA INPUT
    // supporters
    int supportersIds[MAX_SUPPORTERS];
    int supporterAges[MAX_SUPPORTERS];
    bool supporterRecords[MAX_SUPPORTERS];
    int supporterMembership[MAX_SUPPORTERS];
    int membershipYears;
    int numSupporters;

    // auxiliary
    int i;
    int temp; 

    // Average age calculation
    float averageSupporterAge;
    int sumOfAges = 0;

    // Membership query
    int membershipTypeToRecover;
    int membersPrinted = 0;

    printf("INPUT DATA\n");
    printf("NUMBER OF SUPPORTERS (1-10)?\n");
    scanf("%i", &numSupporters);
    while (numSupporters < MIN_SUPPORTERS || numSupporters > MAX_SUPPORTERS)
    {
        printf("INVALID DATA, TRY AGAIN!\n");
        printf("NUMBER OF SUPPORTERS (1-10)?\n");
        scanf("%i", &numSupporters);
    }

    // SUPPORTERS DATA INPUT
    for (i = 0; i < numSupporters; i++)
    {
        printf("SUPPORTER #%i\n", i + 1);
        printf("ID (AN INTEGER)?\n");
        scanf("%i", &supportersIds[i]);
        printf("AGE (AN INTEGER)?\n");
        scanf("%i", &supporterAges[i]);
        printf("HAS RECORDS (0-FALSE, 1-TRUE)?\n");
        scanf("%i", &temp);//this could be saved directly to supporterRecords
        supporterRecords[i] = temp;

        // CHECK MEMBERSHIP YEARS TO SAVE MEMBERSHIP TYPE
        printf("MEMBERSHIP YEARS (AN INTEGER)?\n");
        scanf("%i", &membershipYears);
        if (membershipYears <= BASE_MEMBERSHIP_YEARS)
        {
            supporterMembership[i] = BASE;
            continue;
        }
        if (membershipYears <= SILVER_MEMBERSHIP_YEARS)
        {
            supporterMembership[i] = SILVER;
            continue;
        }
        if (membershipYears > SILVER_MEMBERSHIP_YEARS)
        {
            supporterMembership[i] = GOLD;
            continue;
        }
    }

    // SUPPORTERS QUERY BY MEMBERSHIP
    printf("LOOKING FOR SUPPORTERS\n");
    printf("MEMBERSHIP TYPE (1-BASE, 2-SILVER, 3-GOLD)?\n");
    scanf("%i", &membershipTypeToRecover);

    printf("RESULTS\n");
    // CALCULATE AVERAGE AGE
    for (i = 0; i < numSupporters; i++)
    {
        sumOfAges += supporterAges[i];
    }
    averageSupporterAge = (float)sumOfAges / (float)numSupporters;
    printf("AVERAGE SUPPORTER AGE: %.2f\n", averageSupporterAge);

    // LOOP TO PRINT SUPPORTERS
    for (i = 0; i < numSupporters; i++)
    {
        if (!supporterRecords[i] && (supporterMembership[i] == membershipTypeToRecover))
        {
            printf("SUPPORTER ID: %i\n", supportersIds[i]);
            printf("AGE: %i\n", supporterAges[i]);
            printf("HAS RECORDS (0-FALSE, 1-TRUE): %i\n", supporterRecords[i]);
            printf("MEMBERSHIP TYPE (1-BASE, 2-SILVER, 3-GOLD): %i\n", supporterMembership[i]);
            membersPrinted++;
        }
    }

    if (membersPrinted == 0)
    {
        printf("NO SUPPORTERS RECOVERED.\n");
    }
}

