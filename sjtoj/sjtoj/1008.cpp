#include <iostream>
#include <cmath>

using std::endl;
using std::cout;
using std::cin;

/**
 *data struct
 **/
bool debug = true;

typedef struct Date {
    int year;
    int month;
    int day;
} Date;

typedef struct DateSeg {
    Date begin;
    Date end;
} DateSeg;

int DATE[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int LEAPDATE[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int MAGICCODE[12] = {6,2,2,5,0,3,5,1,4,6,2,4};
int LEAPMAGICCODE[12] = {5,1,2,5,0,3,5,1,4,6,2,4};


/**
 * test func
 **/
void testInput(int n,DateSeg datelist[]){
    for (int i = 0; i < n; i++) {
        cout<<datelist[i].begin.year<<datelist[i].begin.month<<datelist[i].begin.day<<" - "<<datelist[i].end.year<<datelist[i].end.month<<datelist[i].end.day<<endl;
    }
}


/**
 * tool func
 **/
inline bool isLeap(int year){
    bool result =  year % 4 == 0 || year % 400 == 0? true:false;
    return result;
}

int todayIs(Date date){
    int year = date.year % 100;
    year = (year/4+year)%7;
    cout<<year<<" year"<<endl;
    int month = MAGICCODE[date.month-1];
    int day = date.day;
    return (year+month+day)%7;
}

/**
 *count days from begin to end. attention! it's must be in a year
 **/
int countdaysInYear(DateSeg dateseg){
    int result(0);
    int monthbegin = dateseg.begin.month;
    int daybegin = dateseg.begin.day;
    int monthend = dateseg.end.month;
    int dayend = dateseg.end.day;
    int *table =  isLeap(dateseg.begin.year)?LEAPDATE:DATE;
    
    if(monthbegin == monthend){return dayend-daybegin+1;}
    
    for (int i = (monthbegin); i<(monthend-1); i++) {
        result = result + table[i];
    }
    result = table[monthbegin-1]+dayend-daybegin+1;
    
    return result;
}

/**
 *
 **/

DateSeg* splitTime(DateSeg dateseg){
    int gap;
    gap = dateseg.end.year - dateseg.begin.year < 1?0:dateseg.end.year - dateseg.begin.year;
    DateSeg* splitedSeg = new DateSeg[gap+1];
    if(!gap){splitedSeg[0] = dateseg;return splitedSeg;}
    for (int i = 0; i <= gap; i++) {
        DateSeg splitedDate;
        
        splitedDate = dateseg;
        if(i != 0){
            splitedDate.begin.year = dateseg.begin.year+i;
            splitedDate.begin.month = 1;
            splitedDate.begin.day = 1;
        }
        if(i != gap){
            splitedDate.end.year = dateseg.begin.year+i;
            splitedDate.end.month = 12;
            splitedDate.end.day = 31;
        }
        splitedSeg[i] = splitedDate;
    }
    return splitedSeg;
}

int rmweekend(DateSeg dateseg){
    int result(0);
    int today = todayIs(dateseg.begin);
    int lastday = todayIs(dateseg.end);
    int total = countdaysInYear(dateseg);
    //in a weekend
    if(dateseg.begin.month == dateseg.end.month && total<=7){
        for(int i = dateseg.begin.day;i<=dateseg.end.day;i++){
            Date day ={
                dateseg.begin.year,
                dateseg.begin.month,
                i
            };
            int resultday = todayIs(day);
            if(resultday==0||resultday==6){
                result = result+1;
            }
        }
        return result;
    }
    if(today == 1){
        return total/7;
    }else{
        8-today+lastday;//移动days 算weekend
    }
    
    return result;
}

/**
 * per seg has how much weekdays
 **/
int getWeekday(DateSeg dataseg){
    int days = 0;
    days = rmweekend(dataseg);
//    getSpecilday();
    //specialIsweekend()
    
    return days;
}

void dealPerSeg(DateSeg*splitedSeg,int length){
    //test
    if(debug){
        testInput(length, splitedSeg);
    }
    int total = 0;
    //todo
    for (int i = 0; i<length; i++) {
        total = total + getWeekday(splitedSeg[i]);
    }
    
}

int main(){
    /**
     * input date group
     *
     **/
    int n(0);
    cin>>n;
    DateSeg datelist[356];
    for (int i = 0; i < n; i++) {
        DateSeg dateseg;
        char bound;
        cin>>dateseg.begin.year>>bound>>dateseg.begin.month>>bound>>dateseg.begin.day>>dateseg.end.year>>bound>>dateseg.end.month>>bound>>dateseg.end.day;
        datelist[i] = dateseg;
    }
    //test func
    if(0){
        testInput(n,datelist);
    }
    
    for (int i = 0; i<n; i++) {
        DateSeg* splitedSeg = splitTime(datelist[i]);
        int gap =  datelist[i].end.year - datelist[i].begin.year;
        dealPerSeg(splitedSeg,gap+1);
    }
    
    //test
    if(0){
    Date testdata = {
        2010,
        4,
        25
    };
    cout<<todayIs(testdata)<<endl;
    }
    
    //test
    if (debug) {
        DateSeg testseg = {
            {2010,5,25},
            {2010,5,28},
        };
        cout<<countdaysInYear(testseg)<<" days"<<endl;
    }
    return 0;
}