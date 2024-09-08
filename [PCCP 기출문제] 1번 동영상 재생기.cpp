#include <iostream>
#include <vector>
#include <string>
using namespace std;

int timeToSeconds(const string& time) {
    int minutes = stoi(time.substr(0, 2));
    int seconds = stoi(time.substr(3, 2));
    
    return minutes * 60 + seconds;
}

string secondsToTime(int totalSeconds) {
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    string mm = minutes < 10 ? "0" + to_string(minutes) : to_string(minutes);
    string ss = seconds < 10 ? "0" + to_string(seconds) : to_string(seconds);
    
    return mm + ":" + ss;
}

string solution(string videoLen, string pos, string opStart, string opEnd, vector<string> commands) {
    int videoLength = timeToSeconds(videoLen);
    int currentPosition = timeToSeconds(pos);
    int openingStart = timeToSeconds(opStart);
    int openingEnd = timeToSeconds(opEnd);
    
    if (currentPosition >= openingStart && currentPosition <= openingEnd) 
    {
        currentPosition = openingEnd;
    }
    
    for (string command : commands) 
    {
        if (command == "prev") 
        {
            currentPosition -= 10;
            
            if (currentPosition < 0) 
            {
                currentPosition = 0;
            }
        } 
        else if (command == "next") 
        {
            
            currentPosition += 10;
            
            if (currentPosition > videoLength) 
            {
                currentPosition = videoLength;
            }
        }
        
        if (currentPosition >= openingStart && currentPosition <= openingEnd) 
        {
            currentPosition = openingEnd;
        }
    }

    return secondsToTime(currentPosition);
}
