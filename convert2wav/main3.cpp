#define SAMPLE_RATE_IN_HZ 44100
#define M_PI 3.14159265
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>
#include "patternGen.h"

using namespace std;
vector<string> split(std::string str,std::string pattern)
{
    std::string::size_type pos;
    std::vector<std::string> result;
    str+=pattern;//扩展字符串以方便操作
    long size=str.size();

    for(long i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            std::string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
    return result;
}
string getPCM(vector<int> &patterns, float frequency, int signalStrength)
{
    //采样周期时长
    string pcmdata;
    double samplePeriod = 1000000.0f / SAMPLE_RATE_IN_HZ;
//	int pattern_array[]={
//	    1000,570,600,570,600,1470,600,1470,600,570,600,1470,600,570,600,1470,600,600,600,1470,600,1470,600,10510,
//	    1000,570,600,570,600,1470,600,1470,600,570,600,1470,600,570,600,1470,600,600,600,1470,600,1470,600,100000};
//	size_t count=sizeof(pattern_array)/sizeof(int);
//	vector<int> patterns(pattern_array,pattern_array+count);
    frequency = 19000;
    int prePattern = 25000;
    int totalDataLength = (int) (prePattern / samplePeriod + 0.5);
    for (int i = 0; i < patterns.size(); i++) {
        totalDataLength += (int) (patterns[i] / samplePeriod + 0.5);
    }

    int period;
    int index = 0;
    for (int i = 0; i <= patterns.size(); i++){
        if (i == 0) {
            period = prePattern;
        } else {
            period = patterns[i-1];
        }
        int dataLength = (int) (period / samplePeriod + 0.5);
        if (dataLength == 0) {
            continue;
        }
        int isHigh;
        if (i % 2 == 0) {
            isHigh = 0;
        } else {
            isHigh = 1;
        }
        signalStrength = 1;
        for (int j = 0; j < dataLength; j++) {
            int bit_data_l = 0;
            int bit_data_r = 0;
            if (isHigh == 1) {
                double phase_l = (2.0 * j + 1) * M_PI * frequency / SAMPLE_RATE_IN_HZ;
                double phase_r = phase_l + M_PI;
                bit_data_l = (unsigned short)(32767.0 * sin(phase_l) * signalStrength);
                bit_data_r = (unsigned short)(32767.0 * sin(phase_r) * signalStrength);
            }
            ostringstream oss;
            oss << setfill('0') << setw(4) << hex << bit_data_l << setfill('0') << setw(4) << hex << bit_data_r;
            pcmdata += oss.str();
            index++;
        }
    }
    return pcmdata;
}
int main()
{
    string encoding_type = "MiBox";
    //string ircode = "0F 33 3C";
    string ir = "0F 33 3C,0E 50 92,05 E0 92,0C 70 92,08 30 92,02 90 92,09 20 92,06 D0 92,0A 10 92,00 B0 92,04 F0 92";
    string btn = "POWER=UP=LEFT=OK=RIGHT=DOWN=HOME=RETURN=MENU=VOLUP=VOLDOWN";
    vector<string> ircodeAll = split(ir,",");
    vector<string> btnNameAll = split(btn,"=");
    for(int i = 0; i < btnNameAll.size(); i++) {
        string ircode = ircodeAll[i];
        string btnName = btnNameAll[i];
        PatternGen *pattern = new PatternGen();
        pattern->genPattern(encoding_type,ircode);
        vector<int> patterns = pattern->patterns();
        string pcmData = getPCM(patterns,1.0,1);

        string pathHeader = "/Users/Anccerson/Documents/Work/YipaiRemote/Assist/WAV/";
        string brand = "Xiaomi";

        string mkdir = "mkdir -p " + pathHeader + "/" + brand;
        system(mkdir.data());

        string rawData = pathHeader + "/" + brand + "/" + btnName;
        string pcmFile = pathHeader + "/" + brand + "/" + btnName +".pcm";
        ofstream fout(rawData);
        fout << pcmData;
        fout.close();
        string xxd = "xxd -r -p "+ rawData + " " + pcmFile;
        system(xxd.data());
        string wavFile = pathHeader + brand + "/" + btnName +".wav";
        string ffmpeg = "ffmpeg -y -f s16be -ar 44.1k -ac 2 -i " + pcmFile + " " + wavFile;
        system(ffmpeg.data());
    }

    return 0;
}
