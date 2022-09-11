#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include<time.h>
#pragma warning(disable:4996)

void startclean()
{

	FILE* f = fopen("MyLog.log", "a");
	fputs("\n", f);
	fclose(f);
}

void Log(char message[100])
{
	
	FILE* f = fopen("MyLog.log", "a");
		time_t t;
		time(&t);
		struct tm* timeinfo;
		timeinfo = localtime(&t);
		char str[130];
		sprintf(str, "%d.%d.%d:%d%d%d - %s", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message);
		fputs("\n", f);
		fputs(str, f);
		fclose(f);
}

void LogError(char message[100])
{
	char addarr[110];
	sprintf(addarr, "Error - %s", message);
	Log(addarr);

}

void LogEvent(char message[100])
{
	char addarr[110];
	sprintf(addarr, "Event - %s", message);
	Log(addarr);
}


int main()
{
	startclean();

	LogEvent("START OF LOG PROJECT");

	int number;
	scanf("%d", &number);
	char numchar[1000];
	sprintf(numchar, " the number is %d", number);
	LogEvent(numchar);

	FILE* f = fopen("UserNumbers.txt", "w");

	if (f)
	{
		LogEvent("File Opened successfully");
		char strr[100000];
		for (int i = 1; i <= number; i++)
		{
			sprintf(strr, "%d\n", i);
			fputs(strr,f);
		}
	}
	else
	{
		LogError("File Opened FAIL");
	}
	fclose(f);

	LogEvent("END OF LOG PROJECT");

	return 0;
}