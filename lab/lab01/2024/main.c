#include <stdio.h>

int isLeapYear(int year);
int daysInMonth(int month, int year);
int totalDays(int day, int month, int year);
int nextDay(int day, int month, int year, int *nextDay, int *nextMonth, int *nextYear);

int main() 
{
    int day1, month1, year1;
    int day2, month2, year2;
    int nextDayVal, nextMonthVal, nextYearVal;

    printf("Enter the first date (day month year): ");
    scanf("%d %d %d", &day1, &month1, &year1);

    printf("Enter the second date (day month year): ");
    scanf("%d %d %d", &day2, &month2, &year2);

    int totalDays1 = totalDays(day1, month1, year1);
    int totalDays2 = totalDays(day2, month2, year2);
    int difference = totalDays2 - totalDays1;

    printf("Total days between the dates: %d\n", difference);

    
    nextDay(day1, month1, year1, &nextDayVal, &nextMonthVal, &nextYearVal);
    printf("The following day of the first date: %d.%d.%d\n", nextDayVal, nextMonthVal, nextYearVal);
    
    return 0;
}

int isLeapYear(int year) 
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0; 
}

int daysInMonth(int month, int year) 
{
    if (month == 2) 
    {
        if (isLeapYear(year))
            return 29; 
        else
            return 28;
    } 
    else if (month == 4 || month == 6 || month == 9 || month == 11) 
        return 30; 
    else 
        return 31; 
}

int totalDays(int day, int month, int year) 
{
    int total = day;
    for (int i = 1; i < month; i++) 
    {
        total += daysInMonth(i, year);
    }
    return total;
}

int nextDay(int day, int month, int year, int *nextDay, int *nextMonth, int *nextYear) 
{
    int daysInCurrentMonth = daysInMonth(month, year);

    if (day < daysInCurrentMonth) 
    {
        *nextDay = day + 1;
        *nextMonth = month;
        *nextYear = year;
    }
    
    else 
    {
        *nextDay = 1;
        
        if (month < 12) 
        {
            *nextMonth = month + 1;
            *nextYear = year;
        } 
        
        else 
        {
            *nextMonth = 1;
            *nextYear = year + 1;
        }
    }

    return 0; 
}