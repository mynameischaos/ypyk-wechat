#define SAMPLE_RATE_IN_HZ 44100
#define M_PI 3.1415926536

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
string getPCM(vector<int> &patterns, double frequency, double signalStrength)
{
    //采样周期时长
    string pcmdata;
    double samplePeriod = 1000000.0f / SAMPLE_RATE_IN_HZ;
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
int main(int argc, char** argv)
{
    string encoding_type = argv[1];
    string ircode = argv[2];
    double frequency = atof(argv[3])/2.0;
    double signalStrength = atof(argv[4]);
    PatternGen *pattern = new PatternGen();
    pattern->genPattern(encoding_type,ircode);
    vector<int> patterns = pattern->patterns();
    string pcmData = getPCM(patterns,frequency,signalStrength);
    cout << encoding_type;
    return 0;
}
