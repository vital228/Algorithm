#include<iostream>
#include<string>
#include<vector>


using namespace std;

enum Day{
    monday,
    tuesday, 
    wednesday, 
    thursday, 
    friday, 
    saturday, 
    sunday
};

struct Ticket{
    int timeStart;
    int timeEnd;
};

const int week = 60*24*7;

int timeToInt(string day, string t){
    int time=0;
    if (day == "tuesday"){
        time+=60*24;
    }
    if (day == "wednesday"){
        time+=2*60*24;
    }
    if (day == "thursday"){
        time+=3*60*24;
    }
    if (day == "friday"){
        time+=4*60*24;
    }
    if (day == "saturday"){
        time+=5*60*24;
    }
    if (day == "sunday"){
        time+=6*60*24;
    }
    time+=((t[0]-'0')*10+t[1]-'0')*60+(t[3]-'0')*10+t[4]-'0';
    return time;
}



int main(){
    string startDay,startTime, endDay, endTime;
    cin>>startDay>>startTime>>endDay>>endTime;
    Ticket event;
    event.timeStart=timeToInt(startDay,startTime);
    event.timeEnd=timeToInt(endDay, endTime);
    if (event.timeStart > event.timeEnd) {
        event.timeEnd += week;
    }
    int n,m;
    cin>>n>>m;
    vector<Ticket> toMoscow(n),toYar(m);
    for (int i=0;i<n;i++){
        string startDay,startTime, endDay, endTime;
        cin>>startDay>>startTime>>endDay>>endTime;
        toMoscow[i].timeStart=timeToInt(startDay,startTime);
        toMoscow[i].timeEnd=timeToInt(endDay, endTime);
        if (toMoscow[i].timeStart > toMoscow[i].timeEnd) {
            toMoscow[i].timeStart -= week;
        }
        if (toMoscow[i].timeEnd>event.timeStart){
            toMoscow[i].timeStart-=week;
            toMoscow[i].timeEnd-=week;
        }
    }
    for (int i=0;i<m;i++){
        string startDay,startTime, endDay, endTime;
        cin>>startDay>>startTime>>endDay>>endTime;
        toYar[i].timeStart=timeToInt(startDay,startTime);
        toYar[i].timeEnd=timeToInt(endDay, endTime);
        if (toYar[i].timeStart > toYar[i].timeEnd) {
            toYar[i].timeEnd += week;
        }
        while (toYar[i].timeStart<event.timeEnd){
            toYar[i].timeStart+=week;
            toYar[i].timeEnd+=week;
        }
    }
    int max = 4*week;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (toYar[j].timeEnd-toMoscow[i].timeStart<max){
                max=toYar[j].timeEnd-toMoscow[i].timeStart;
            }
        }
    }
    cout<<max;

    return 0;
}