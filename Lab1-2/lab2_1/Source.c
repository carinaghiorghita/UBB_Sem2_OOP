#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define maxNrOfDaysBetweenDates 10000
#define maxNrOfCharactForDate 12
#define yearIsDivBy4 4
#define yearIsDivBy100 100
#define yearIsDivBy400 400
#define numberOfDaysInYear 365
#define February 2
#define numberOfDaysIn28DayMonth 28
#define numberOfDaysIn30DayMonth 30
#define numberOfDaysIn31DayMonth 31


//beacuse tm_year gets the number of years since 1900, we'll have to add 1900 to the current year
#define addToCurrentYear 1900


int monthsWith30Days[] = { 4,6,9,11 };


int main()
{
	
	char readDate[maxNrOfCharactForDate], dateCopy[maxNrOfCharactForDate],* currentWord;
	int month, readDay, readMonth, readYear, numberOfWordRead, currentDay, currentMonth, currentYear, numberOfDaysForCurrentDate, numberOfDaysForReadDate, numberofLeapYears, numberofLeapYearsUntilReadYear, numberOfDaysInCurrentMonth, numberOfDaysInReadMonth;
	bool foundMonth = false;

	time_t timeVar;
	struct tm* current_time;

	timeVar = time(NULL);

	current_time = localtime(&timeVar);

	//get the current day,month and year
	currentDay = current_time->tm_mday;
	currentMonth = current_time->tm_mon + 1;
	currentYear = current_time->tm_year + addToCurrentYear;

	//get the number of leap years since year 0 
	if (currentMonth > 2)numberofLeapYears = currentYear / yearIsDivBy4 - currentYear / yearIsDivBy100 + currentYear / yearIsDivBy400;
	else numberofLeapYears = (currentYear - 1) / yearIsDivBy4 - (currentYear - 1) / yearIsDivBy100 + (currentYear - 1) / yearIsDivBy400;
	if (currentMonth == February)numberOfDaysInCurrentMonth = numberOfDaysIn28DayMonth;
	else
	{
		for (month = 0; month <= 3 && !foundMonth; ++month)
			if (monthsWith30Days[month] == currentMonth)foundMonth = true;
		if (foundMonth) numberOfDaysInCurrentMonth = numberOfDaysIn30DayMonth;
		else numberOfDaysInCurrentMonth = numberOfDaysIn31DayMonth;
	}
	//get the total number of days since year 0
	numberOfDaysForCurrentDate = numberOfDaysInYear * currentYear + numberOfDaysInCurrentMonth * currentMonth + currentDay + numberofLeapYears;
	while (1)
	{
		scanf("%s", &readDate);
		//if the input word is 'exit', the program ends
		if (strcmp(readDate, "exit") == 0)return 0;
		else
		{
			
			numberOfWordRead = 0;
			strcpy(dateCopy, readDate);
			currentWord = strtok(readDate, ".- ");
			while (currentWord)
			{
				if (numberOfWordRead == 0)readDay = atoi(currentWord);
				else
				{
					if (numberOfWordRead == 1)readMonth = atoi(currentWord);
					else readYear = atoi(currentWord);
				}
				numberOfWordRead++;
				currentWord = strtok(NULL, "- ");
			}

			//count leap years
			if (readMonth > 2)numberofLeapYearsUntilReadYear = readYear / yearIsDivBy4 - readYear / yearIsDivBy100 + readYear / yearIsDivBy400;
			else numberofLeapYearsUntilReadYear = (readYear - 1) / yearIsDivBy4 - (readYear - 1) / yearIsDivBy100 + (readYear - 1) / yearIsDivBy400;
			if (readMonth == February)numberOfDaysInReadMonth = numberOfDaysIn28DayMonth;
			else
			{
				foundMonth = false;
				for (month = 0; month <= 3 && !foundMonth; ++month)
					if (monthsWith30Days[month] == readMonth)foundMonth = true;
				if (foundMonth) numberOfDaysInReadMonth = numberOfDaysIn30DayMonth;
				else numberOfDaysInReadMonth = numberOfDaysIn31DayMonth;
			}
			numberOfDaysForReadDate = numberOfDaysInYear * readYear + numberOfDaysInReadMonth * readMonth + readDay + numberofLeapYearsUntilReadYear;
			if (numberOfDaysForCurrentDate - numberOfDaysForReadDate <= maxNrOfDaysBetweenDates) printf("%s\n", dateCopy);
		}
	}
	return 0;
}