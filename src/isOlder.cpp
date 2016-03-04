/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int strLength(char *);
int isOlder(char *dob1, char *dob2) {
	int length1 = 0, length2 = 0;
	length1 = strLength(dob1);
	length2 = strLength(dob2);
	if (length1 != 10 || length2 != 10)
		return -1;

	int year1 = 0, year2 = 0;
	year1 = (((dob1[6] - '0') * 1000) + ((dob1[7] - '0') * 100) + ((dob1[8] - '0') * 10) + (dob1[9] - '0'));
	year2 = (((dob2[6] - '0') * 1000) + ((dob2[7] - '0') * 100) + ((dob2[8] - '0') * 10) + (dob2[9] - '0'));

	int mon1 = 0, mon2 = 0;
	mon1 = (((dob1[3] - '0') * 10) + (dob1[4] - '0'));
	mon2 = (((dob2[3] - '0') * 10) + (dob2[4] - '0'));

	int day1 = 0, day2 = 0;
	day1 = (((dob1[0] - '0') * 10) + (dob1[1] - '0'));
	day2 = (((dob2[0] - '0') * 10) + (dob2[1] - '0'));

	//checking for invalid cases
	if (mon1>12 || mon2 > 12)
		return -1;
	//leap year case
	if (year1 % 4 != 0 && mon1 == 2 && day1 > 28)
		return -1;
	if (year2 % 4 != 0 && mon2 == 2 && day2 > 28)
		return -1;


	if (year1<year2)
		return 1;
	else if (year2<year1)
		return 2;
	else if (mon1<mon2)
		return 1;
	else if (mon2<mon1)
		return 2;
	else if (day1<day2)
		return 1;
	else if (day2<day1)
		return 2;
	else
		return 0;
}

int strLength(char *str)
{
	int i = 0, count = 0;
	while (str[i] != '\0')
	{
		i++;
		count++;
	}
	return count;
}
