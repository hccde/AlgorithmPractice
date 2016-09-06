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
int LEAPDATE[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

void testInput(int n,DateSeg datelist[]){
    for (int i = 0; i < n; i++) {
        cout<<datelist[i].begin.year<<datelist[i].begin.month<<datelist[i].begin.day<<" - "<<datelist[i].end.year<<datelist[i].end.month<<datelist[i].end.day<<endl;
    }
}

inline bool isLeap(int year){
    bool result =  (year % 4 == 0&&year % 100!=0) || year % 400 == 0? true:false;
    return result;
}

int todayIs(Date date){//Zeller
    int year = date.year;
    int mon = date.month;
    int day = date.day;
    
    if (mon ==1 || mon == 2) { //判断月份是否为1或2
        year--;
        mon += 12;
    }
   int  c = year / 100;
    year = year - c * 100;
    int w = (c / 4) - 2 * c + (year + year / 4) + (13 * (mon + 1) / 5) + day - 1;
    while (w < 0) w += 7;
    w %= 7;
    return w;
}

int countdaysInYear(DateSeg dateseg){
    int result(0);
    int monthbegin = dateseg.begin.month;
    int daybegin = dateseg.begin.day;
    int monthend = dateseg.end.month;
    int dayend = dateseg.end.day;
    int *table =  isLeap(dateseg.begin.year)?LEAPDATE:DATE;
    
    if(monthbegin == monthend){return dayend-daybegin+1;}
    
    for (int i = (monthbegin-1); i<(monthend-1); i++) {
        result = result + table[i];
    }
    result = result+dayend-daybegin+1;
    
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

        return (total - result);
    }
    if(today == 1){
        if((total) % 7 == 6) result = result+1;
        result = (total / 7)*2+result;

        return (total - result);
        
    }else{
        if(today==0) today = 7;
        int beforeMon = 8-today;
        int weekend(0);
        for (int i = 0; i<beforeMon; i++) {
            if(today+i>5){
                weekend = weekend+1;
            }
        }

        int otherweekend = (total - beforeMon) / 7;

        if((total - beforeMon) % 7 == 6) result = result+1;

        result =  otherweekend*2+weekend+result;//返回指定时间段的所有周末的天数
    }

    return (total - result);
}

int specilday(DateSeg dataseg){//是周末的特殊节日不算
    int result(0);
    int today;
    if (dataseg.begin.month == 1 && dataseg.begin.day == 1 ) {
        today = todayIs({dataseg.begin.year,1,1});
        if(today!=0 && today!=6) result = result+1;
    }
    if(dataseg.begin.month <= 5 && dataseg.end.month >= 5){
        int hash[3]={0};
        for (int i=1; i<=3; i++) {
            int tem = todayIs({dataseg.begin.year,5,i});
            if(tem !=0 && tem != 6) hash[i-1]=1;
        }

        if(dataseg.end.month == 5 && dataseg.end.day < 3){
            //在5月3之前结束
            if(dataseg.end.day==2){
                result = result+hash[0]+hash[1];
            }else{
                result = result+hash[0];
            }
        }else{
            //大于5月3
            for(int i=0;i<3;i++){
                result = result+hash[i];
            }
        }
    }
    if(dataseg.begin.month <= 10 && dataseg.end.month >= 10){
        int hash[7]={0};
        for (int i=1; i<=7; i++) {
            int tem = todayIs({dataseg.begin.year,7,i});
            if(tem !=0 && tem != 6) hash[i-1]=1;
        }
        
        if(dataseg.end.month == 10&&dataseg.end.day<=7){

            for (int i=1; i <= dataseg.end.day; i++) {
                result = result+hash[i-1];
            }
        }else{

            for (int i=0; i<7; i++) {
                result = result+hash[i];
            }
        }
    }
    return result;
}

int getWeekday(DateSeg dataseg){
    int days = 0;
    days = rmweekend(dataseg);
    days = days - specilday(dataseg);
    return days;
}

int  dealPerSeg(DateSeg*splitedSeg,int length){
    int total = 0;
    for (int i = 0; i<length; i++) {
        total = total + getWeekday(splitedSeg[i]);
    }
    return total;
}

int main(){
    int n(0);
    cin>>n;
    DateSeg datelist[356];
    for (int i = 0; i < n; i++) {
        DateSeg dateseg;
        char bound;
        cin>>dateseg.begin.year>>bound>>dateseg.begin.month>>bound>>dateseg.begin.day>>dateseg.end.year>>bound>>dateseg.end.month>>bound>>dateseg.end.day;
        datelist[i] = dateseg;
    }

    int total(0);

    for (int i = 0; i<n; i++) {
        DateSeg* splitedSeg = splitTime(datelist[i]);
        int gap =  datelist[i].end.year - datelist[i].begin.year;
        total = dealPerSeg(splitedSeg,gap+1);
        delete[] splitedSeg;
        splitedSeg = NULL;
        cout<<total<<endl;
    }
    return 0;
}
