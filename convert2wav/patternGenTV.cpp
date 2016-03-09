//
// Created by Anccerson on 3/3/16.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "encodingInterface.h"
#include "patternGen.h"

void PatternGen::genVictorC8D8Pattern() {
    mCarrierFrequency = 34000;
    mFrameWidth = 58900;
    mBit0Patterns[0] = 526;
    mBit0Patterns[1] = -526;
    mBit1Patterns[0] = 526;
    mBit1Patterns[1] = -1580;

    const int pattern_length = 36;
    mPatterns.resize(pattern_length, 0);

    //head code
    mPatterns[mPatternId++] = 8420;
    mPatterns[mPatternId++] = -4210;

    //custom code
    int cust_code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(cust_code, 8, false);

    //data code
    int data_code = (charToValue(mIrCodes[2])<<4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 8, false);

    //stop code
    mPatterns[mPatternId++] = 526;
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genMv50002Pattern() {
    mCarrierFrequency = 34000;
    mBit0Patterns[0] = 10;
    mBit0Patterns[1] = -9170;
    mBit1Patterns[0] = 10;
    mBit1Patterns[1] = -13810;

    const int pattern_length = 28;
    mPatterns.resize(pattern_length, 0);

    //sync code
    mPatterns[mPatternId++] = 10;
    mPatterns[mPatternId++] = -21190;

    //data code
    int cust_code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(cust_code, 5, false);

    //sync code
    mPatterns[mPatternId++] = 10;
    mPatterns[mPatternId++] = -28000;

    //data code
    int data_code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(data_code, 5, false);

    //sync code
    mPatterns[mPatternId++] = 10;
    mPatterns[mPatternId++] = -28000;

    //end code
    mPatterns[mPatternId++] = 10;
    mPatterns[mPatternId++] = -50000;
}

void PatternGen::genCL311Unknown7Pattern() {
    mLsbFirst = false;
    mCarrierFrequency = 34000;
    mFrameWidth = 122000;
    mBit0Patterns[0] = 140;
    mBit0Patterns[1] = -4920;
    mBit1Patterns[0] = 140;
    mBit1Patterns[1] = -7450;

    const int pattern_length = 24;
    mPatterns.resize(pattern_length, 0);

    //R code
    mPatterns[mPatternId++] = mBit1Patterns[0];
    mPatterns[mPatternId++] = mBit1Patterns[1];

    //T code
    if (mControlCode == 0) {
        mPatterns[mPatternId++] = mBit1Patterns[0];
        mPatterns[mPatternId++] = mBit1Patterns[1];
        mControlCode = 1;
    } else {
        mPatterns[mPatternId++] = mBit0Patterns[0];
        mPatterns[mPatternId++] = mBit0Patterns[1];
        mControlCode = 0;
    }

    //cust code
    int cust_code = (charToValue(mIrCodes[2])<<4) + charToValue(mIrCodes[3]);
    genBytePattern(cust_code, 3, false);

    //data code
    int data_code = (charToValue(mIrCodes[4])<<4) + charToValue(mIrCodes[5]);
    genBytePattern(data_code, 6, false);

    //stop code
    mPatterns[mPatternId++] = 140;
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genMn6014wC5D6Pattern() {
    mCarrierFrequency = 38000;
    mFrameWidth = 101300;
    mBit0Patterns[0] = 841;
    mBit0Patterns[1] = -841;
    mBit1Patterns[0] = 841;
    mBit1Patterns[1] = -2523;

    const int pattern_length = 48;
    mPatterns.resize(pattern_length, 0);

    //head code
    mPatterns[mPatternId++] = 3370;
    mPatterns[mPatternId++] = -3370;

    //custom code
    int cust_code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(cust_code, 5, false);

    //data code
    int data_code = (charToValue(mIrCodes[2])<<4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 6, false);

    // check code
    genBytePattern(cust_code, 5, true);
    genBytePattern(data_code, 6, true);

    //stop code
    mPatterns[mPatternId++] = 841;
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genMitC8D8Pattern() {
    mCarrierFrequency = 38000;
    mFrameWidth = 55000;
    mBit0Patterns[0] = 380;
    mBit0Patterns[1] = -825;
    mBit1Patterns[0] = 380;
    mBit1Patterns[1] = -2000;

    const int pattern_length = 34;
    mPatterns.resize(pattern_length, 0);

    //custom code
    int cust_code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(cust_code, 8, false);

    //data code
    int data_code = (charToValue(mIrCodes[2])<<4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 8, false);

    //stop code
    mPatterns[mPatternId++] = 380;
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genRC6BPattern() {
    mLsbFirst = false;
    mCarrierFrequency = 38000;
    mFrameWidth = 107500;
    mBit0Patterns[0] = -444;
    mBit0Patterns[1] = 444;
    mBit1Patterns[0] = 444;
    mBit1Patterns[1] = -444;

    const int pattern_length = 78;
    mPatterns.resize(pattern_length, 0);

    // lead code
    mPatterns[mPatternId++] = 2666;
    mPatterns[mPatternId++] = -889;

    // fix code
    mPatterns[mPatternId++] = mBit1Patterns[0];
    mPatterns[mPatternId++] = mBit1Patterns[1];

    // cut code
    int cut_code = charToValue(mIrCodes[1]);
    genBytePattern(cut_code, 3, false);

    // turn code
    mPatterns[mPatternId++] = -889;
    mPatterns[mPatternId++] = 889;

    // coustom code
    int user_code = (charToValue(mIrCodes[2])<<4) + charToValue(mIrCodes[3]);
    genBytePattern(user_code, 8, false);
    user_code = (charToValue(mIrCodes[4])<<4) + charToValue(mIrCodes[5]);
    genBytePattern(user_code, 8, false);

    //control data
    int t = charToValue(mIrCodes[6]);
    if (mControlCode == 0) {
        t ^= 0x08;
        mControlCode = 1;
    } else {
        mControlCode = 0;
    }
    //printf("%c", t);
    user_code = (t<<4) + charToValue(mIrCodes[7]);
    genBytePattern(user_code, 8, false);

    // data code
    user_code = (charToValue(mIrCodes[8])<<4) + charToValue(mIrCodes[9]);
    genBytePattern(user_code, 8, false);

    // stop code
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genTc9012ffPattern() {
    mCarrierFrequency = 38000;
    mFrameWidth = 216000;
    mBit0Patterns[0] = 560;
    mBit0Patterns[1] = -560;
    mBit1Patterns[0] = 560;
    mBit1Patterns[1] = -1680;

    const int pattern_length = 74;
    mPatterns.resize(pattern_length, 0);

    // lead code
    mPatterns[mPatternId++] = 4500;
    mPatterns[mPatternId++] = -4500;

    //custom code
    int cust_code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(cust_code, 8, false);
    genBytePattern(cust_code, 8, true);

    //data code
    int data_code = (charToValue(mIrCodes[2])<<4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 8, false);
    genBytePattern(data_code, 8, true);

    // stop code
    mPatterns[mPatternId++] = 560;
    mPatterns[mPatternId++] = -44608;

    // lead code
    mPatterns[mPatternId++] = 4500;
    mPatterns[mPatternId++] = -4500;

    // check code
    genBytePattern(cust_code, 1, true);

    // stop code
    mPatterns[mPatternId++] = 560;
    mPatterns[mPatternId++] = -96200;
}

void PatternGen::genUpd1986ccPattern() {
    mCarrierFrequency = 38000;
    mBit0Patterns[0] = -818;
    mBit0Patterns[1] = -818;
    mBit1Patterns[0] = 818;
    mBit1Patterns[1] = 818;

    const int pattern_length = 26;
    mPatterns.resize(pattern_length, 0);

    // lead code
    mPatterns[mPatternId++] = 3272;
    mPatterns[mPatternId++] = -1636;
    // data code
    int data_code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(data_code, 5, false);
    // stop code
    int align_val = -24000 + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    // lead code
    mPatterns[mPatternId++] = 3272;
    mPatterns[mPatternId++] = -1636;
    // data code
    genBytePattern(data_code, 5, false);
    // stop code
    align_val = -48000 + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genGeminiC1710Pattern() {
    mCarrierFrequency = 38000;
    mBit0Patterns[0] = 530;
    mBit0Patterns[1] = -530;
    mBit1Patterns[0] = -530;
    mBit1Patterns[1] = 530;

    const int pattern_length = 140;
    mPatterns.resize(pattern_length, 0);

    // leader code
    mPatterns[mPatternId++] = 530;
    mPatterns[mPatternId++] = -2650;
    // user code
    int user_code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 16, false);
    // stop code
    mPatterns[mPatternId++] = -20000;

    // leader code
    mPatterns[mPatternId++] = 530;
    mPatterns[mPatternId++] = -2650;
    // data code
    int data_code = (charToValue(mIrCodes[2])<<12) + (charToValue(mIrCodes[3])<<8) +
                    (charToValue(mIrCodes[4])<<4)  + (charToValue(mIrCodes[5]));
    genBytePattern(data_code, 16, false);
    // stop code
    int align_val = -177500 + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    // leader code
    mPatterns[mPatternId++] = 530;
    mPatterns[mPatternId++] = -2650;
    //data code
    genBytePattern(data_code, 16, false);
    // stop code
    align_val = -314950 + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    // leader code
    mPatterns[mPatternId++] = 530;
    mPatterns[mPatternId++] = -2650;
    // user code
    genBytePattern(user_code, 16, false);
    // stop code
    mPatterns[mPatternId++] = -20000;
}

void PatternGen::genYIPAI321Pattern() {
    mCarrierFrequency = 38000;
    mFrameWidth = 174500;
    mBit0Patterns[0] = 536;
    mBit0Patterns[1] = -536;
    mBit1Patterns[0] = 536;
    mBit1Patterns[1] = -1590;

    const int pattern_length =68;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length * pattern_repeat_count);

    for (int f = 0; f < pattern_repeat_count; ++f) {
        //head code
        mPatterns[mPatternId++] = 8500;
        mPatterns[mPatternId++] = -4250;

        //custom code
        int cust_code = (charToValue(mIrCodes[8*f+2])<<4) + charToValue(mIrCodes[8*f+3]);
        genBytePattern(cust_code, 8, false);
        cust_code = (charToValue(mIrCodes[8*f])<<4) + charToValue(mIrCodes[8*f+1]);
        genBytePattern(cust_code, 8, false);

        //data code
        int data_code = (charToValue(mIrCodes[8*f+6])<<4) + charToValue(mIrCodes[8*f+7]);
        genBytePattern(data_code, 8, false);
        data_code = (charToValue(mIrCodes[8*f+4])<<4) + charToValue(mIrCodes[8*f+5]);
        genBytePattern(data_code, 8, false);

        //stop code
        mPatterns[mPatternId++] = 536;
        if (f == 0) {
            int align_val = -90000 + total_pattern_width();
            mPatterns[mPatternId++] = align_val;
        } else {
            mPatterns[mPatternId++] = -20000;
        }
    }
}

void PatternGen::genYIPAI331Pattern() {
    mCarrierFrequency = 38000;
    mFrameWidth = 123000;
    mBit0Patterns[0] = 10;
    mBit0Patterns[1] = -70;
    mBit1Patterns[0] = 10;
    mBit1Patterns[1] = -180;

    const int pattern_length =28;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length * pattern_repeat_count);

    for (int f = 0; f < pattern_repeat_count; ++f) {
        //head code
        mPatterns[mPatternId++] = 10;
        mPatterns[mPatternId++] = -290;

        //custom code
        int cust_code = (charToValue(mIrCodes[4*f])<<4) + charToValue(mIrCodes[4*f+1]);
        genBytePattern(cust_code, 5, false);

        //data code
        int data_code = (charToValue(mIrCodes[4*f+2])<<4) + charToValue(mIrCodes[4*f+3]);
        genBytePattern(data_code, 6, false);

        //tail code
        mPatterns[mPatternId++] = 10;
        mPatterns[mPatternId++] = -290;

        //stop code
        mPatterns[mPatternId++] = 10;
        int align_val = -mFrameWidth + total_pattern_width();
        mPatterns[mPatternId++] = align_val;
    }
}

void PatternGen::genM584802Pattern() {
    mCarrierFrequency = 38000;
    mFrameWidth = 50000;
    mBit0Patterns[0] = 587;
    mBit0Patterns[1] = -1520;
    mBit1Patterns[0] = 587;
    mBit1Patterns[1] = -3660;

    const int pattern_length =28;
    mPatterns.resize(pattern_length, 0);

    // data code
    int data_code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(data_code, 6, false);

    // stop code
    mPatterns[mPatternId++] = 587;
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    // data code
    genBytePattern(data_code, 6, false);

    // stop code
    mPatterns[mPatternId++] = 587;
    align_val = -2 * mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genGrundigDvdPattern() {
    mCarrierFrequency = 38000;
    mFrameWidth = 52500;

    mBit0Patterns[0] = -2280;
    mBit1Patterns[0] = 1140;
    mBit0Patterns[1] = -1810;
    mBit1Patterns[1] = 583;
    mBit0Patterns[2] = -1140;
    mBit1Patterns[2] = 583;
    mBit0Patterns[3] = -472;
    mBit1Patterns[3] = 583;

    if (mControlCode == 0) {
        mControlCode = 2;
    } else  if (mControlCode == 1) {
        mControlCode = 3;
    } else  if (mControlCode == 2) {
        mControlCode = 1;
    } else {
        mControlCode = 0;
    }

    // deal with original data
    int cust_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    int mix_code = mControlCode;
    for (int b = 0; b < 7; ++b) {
        mix_code <<= 1;
        mix_code |= (data_code & 0x01);
        data_code >>= 1;
    }
    for (int b = 0; b < 7; ++b) {
        cust_code <<= 1;
        mix_code <<= 1;
        int is_one = (cust_code & 0x80) >> 7;
        if (is_one == 0)
            mix_code |= 0x01;
    }

    int data = mix_code;
    int pattern_length = 20;
    for (int i = 0; i < 8; ++i) {
        if ((data & 0x3) != 0) pattern_length += 2;
        data >>= 2;
    }
    mPatterns.resize(pattern_length, 0);

    // leader code
    mPatterns[mPatternId++] = 805;
    mPatterns[mPatternId++] = -2972;
    mPatterns[mPatternId++] = 1333;

    // data and custom code
    for (int i = 7; i >= 0; --i) {
        int two_bits = (mix_code >> 2*i) & 0x3;
        if (two_bits == 0) {
            mPatterns[mPatternId++] = mBit0Patterns[0];
            mPatterns[mPatternId++] = mBit1Patterns[0];
        } else  if (two_bits == 1) {
            mPatterns[mPatternId++] = mBit0Patterns[1];
            mPatterns[mPatternId++] = mBit1Patterns[1];
            mPatterns[mPatternId++] = mBit0Patterns[3];
            mPatterns[mPatternId++] = mBit1Patterns[3];
        } else  if (two_bits == 2) {
            mPatterns[mPatternId++] = mBit0Patterns[2];
            mPatterns[mPatternId++] = mBit1Patterns[2];
            mPatterns[mPatternId++] = mBit0Patterns[2];
            mPatterns[mPatternId++] = mBit1Patterns[2];
        } else  if (two_bits == 3) {
            mPatterns[mPatternId++] = mBit0Patterns[3];
            mPatterns[mPatternId++] = mBit1Patterns[3];
            mPatterns[mPatternId++] = mBit0Patterns[1];
            mPatterns[mPatternId++] = mBit1Patterns[1];
        }
    }

    // stop code
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genSZMGPattern() {
    mCarrierFrequency = 38000;
    mBit0Patterns[0] = 560;
    mBit0Patterns[1] = -560;
    mBit1Patterns[0] = 560;
    mBit1Patterns[1] = -1120;

    const int pattern_length = 86;
    mPatterns.resize(pattern_length, 0);

    // leader code
    mPatterns[mPatternId++] = 6000;
    mPatterns[mPatternId++] = -2000;

    // custom code
    int cust_code_1 = (charToValue(mIrCodes[4])<<4) + charToValue(mIrCodes[5]);
    genBytePattern(cust_code_1, 8, false);
    int cust_code_2 = (charToValue(mIrCodes[2])<<4) + charToValue(mIrCodes[3]);
    genBytePattern(cust_code_2, 8, false);

    // data code
    int data_code = (charToValue(mIrCodes[6])<<4) + charToValue(mIrCodes[7]);
    genBytePattern(data_code, 8, false);

    //separation period
    mPatterns[mPatternId++] = 3640;
    mPatterns[mPatternId++] = -3640;

    // control code
    int cont_code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(cont_code, 8, false);

    // data code
    genBytePattern(data_code, 8, true);

    // stop code
    mPatterns[mPatternId++] = 560;
    mPatterns[mPatternId++] = -100000;
}

void PatternGen::genXiaomiPattern() {
    mCarrierFrequency = 38000;
    mFrameWidth = 29800;

    mBit0Patterns[0] = 600;
    mBit1Patterns[0] = -570;
    mBit0Patterns[1] = 600;
    mBit1Patterns[1] = -870;
    mBit0Patterns[2] = 600;
    mBit1Patterns[2] = -1170;
    mBit0Patterns[3] = 600;
    mBit1Patterns[3] = -1470;


    const int pattern_length = 24;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count);

    //leader code
    mPatterns[mPatternId++] = 1000;
    mPatterns[mPatternId++] = -570;

    //user code
    for (int i = 5; i > 0; --i) {
        int data_code = charToValue(mIrCodes[i]);
        genDoubleBytesPattern(data_code, 4, false);
    }

    //stop code
    mPatterns[mPatternId++] = 600;
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    //repeat code
    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::gen6121Pattern() {
    // bit_0, bit_1 definition
    mBit0Patterns[0] = 564;
    mBit0Patterns[1] = -564;
    mBit1Patterns[0] = 564;
    mBit1Patterns[1] = -1692;

    // pattern length
    int pattern_length = 72;
    if (mEncodingType == UPD6121G_F ||
        mEncodingType == UPD6121G_001) {
        pattern_length = 68;
        mBit0Patterns[0] = 560;
        mBit0Patterns[1] = -560;
        mBit1Patterns[0] = 560;
        mBit1Patterns[1] = -1680;
    }
    mPatterns.resize(pattern_length, 0);

    // frame width
    mFrameWidth = 108000;
    if (mEncodingType == UPD6121G_001) {
        mFrameWidth = 107000;
    }

    // leader code
    mPatterns[mPatternId++] = 9024;
    mPatterns[mPatternId++] = -4512;

    // user code
    int user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 8, false);
    user_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(user_code, 8, false);

    // command pattern
    int data_code = (charToValue(mIrCodes[4]) << 4) + charToValue(mIrCodes[5]);
    genBytePattern(data_code, 8, false);
    if (mEncodingType != UPD6121G_001) {
        genBytePattern(data_code, 8, true); // ����
    } else {
        data_code = (charToValue(mIrCodes[6]) << 4) + charToValue(mIrCodes[7]);
        genBytePattern(data_code, 8, false);
    }

    // ending pattern
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
    if (mEncodingType != UPD6121G_F &&
        mEncodingType != UPD6121G_001) {
        mPatterns[mPatternId++] = 9024;
        mPatterns[mPatternId++] = -2256;
        mPatterns[mPatternId++] = 564;
        align_val = -2 * mFrameWidth + total_pattern_width();
        mPatterns[mPatternId++] = align_val;
    }
}

void PatternGen::genMn6014Pattern() {
    mCarrierFrequency = 36600;
    // bit_0, bit_1 definition
    mBit0Patterns[0] = 840;
    mBit0Patterns[1] = -840;
    mBit1Patterns[0] = 840;
    mBit1Patterns[1] = -2520;

    // pattern length
    int pattern_length = 52;
    mPatterns.resize(pattern_length, 0);

    // frame width
    mFrameWidth = 105000;

    // leader code
    mPatterns[mPatternId++] = 3360;
    mPatterns[mPatternId++] = -3360;

    // user code
    int user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 6, false);

    // command pattern
    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 6, false);

    genBytePattern(user_code, 6, true);
    genBytePattern(data_code, 6, true); // ����

    // ending pattern
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genUpd1986Pattern() {
    mCarrierFrequency = 38000;
    // bit_0, bit_1 definition
    int BIT0 = -1125;
    int BIT1 = 1125;

    // pattern length
    int pattern_length = 9;
    mPatterns.resize(pattern_length, 0);

    // frame width
    mFrameWidth = 36000;

    // leader code
    mPatterns[mPatternId++] = BIT1;
    mPatterns[mPatternId++] = BIT0;
    mPatterns[mPatternId++] = BIT1;

    // user code
    int data_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    for (int j = 0; j < 5; j++) {
        if ((data_code & 1) == 0) {
            mPatterns[mPatternId++] = BIT0;
        } else {
            mPatterns[mPatternId++] = BIT1;
        }
        data_code >>= 1;
    }

    // ending pattern
    mPatterns[mPatternId++] = -27000;
}

void PatternGen::genTC9012Pattern() {
    // bit_0, bit_1 definition
    mBit0Patterns[0] = 560;
    mBit0Patterns[1] = -560;
    mBit1Patterns[0] = 560;
    mBit1Patterns[1] = -1680;

    // pattern length
    int pattern_length = 68;
    mFrameWidth = 108000;
    if (mEncodingType == TC9012_A) {
        pattern_length = 52;
        mFrameWidth = 93000;
    }
    mPatterns.resize(pattern_length, 0);

    // frame width

    // leading pattern
    if (mEncodingType == TC9012) {
        mPatterns[mPatternId++] = 4500;
        mPatterns[mPatternId++] = -4500;
    } else {
        mPatterns[mPatternId++] = 4512;
        mPatterns[mPatternId++] = -4512;
    }

    // user code
    int user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 8, false);
    if (mEncodingType != TC9012_A) {
        genBytePattern(user_code, 8, false); // ͬ��
    }

    // data code
    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 8, false);
    genBytePattern(data_code, 8, true); // ����

    // ending pattern
    if (mEncodingType == TC9012) {
        mPatterns[mPatternId++] = 560;
    } else {
        mPatterns[mPatternId++] = 564;
    }
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::gen50560Pattern() {
    // pattern length
    int pattern_length = 38;
    mPatterns.resize(pattern_length, 0);

    // leading pattern
    switch (mEncodingType) {
        case M50560:
            mCarrierFrequency = 28400;
            mBit0Patterns[0] = 500;
            mBit0Patterns[1] = -500;
            mBit1Patterns[0] = 500;
            mBit1Patterns[1] = -1500;
            mFrameWidth = 55000;
            mPatterns[mPatternId++] = 8000;
            mPatterns[mPatternId++] = -4000;
            break;
        case M50560_1:
            mCarrierFrequency = 40000;
            mBit0Patterns[0] = 500;
            mBit0Patterns[1] = -500;
            mBit1Patterns[0] = 500;
            mBit1Patterns[1] = -1500;
            mFrameWidth = 67800;
            mPatterns[mPatternId++] = 8000;
            mPatterns[mPatternId++] = -4000;
            break;
        case SC50560_2P:
        case SC50560_3P:
            mCarrierFrequency = 37780;
            mBit0Patterns[0] = 500;
            mBit0Patterns[1] = -500;
            mBit1Patterns[0] = 500;
            mBit1Patterns[1] = -1500;
            mFrameWidth = 60000;
            mPatterns[mPatternId++] = 8000;
            mPatterns[mPatternId++] = -4000;
            break;
        default:
            break;
    }

    // user code
    int user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 8, false);

    // cut code
    mPatterns[mPatternId++] = mBit0Patterns[0];
    if (mEncodingType == M50560) {
        mPatterns[mPatternId++] = -4000;
    } else if (mEncodingType == M50560_1) {
        mPatterns[mPatternId++] = -4000;
    } else if (mEncodingType == SC50560_2P
               || mEncodingType == SC50560_3P) {
        mPatterns[mPatternId++] = -4000;
    }

    // data code
    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 8, false);

    // ending patterns
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

}

void PatternGen::gen50560B1Pattern() {
    // bit_0, bit_1 definition
    mBit0Patterns[0] = 520;
    mBit0Patterns[1] = -2080;
    mBit1Patterns[0] = 520;
    mBit1Patterns[1] = -4160;

    // pattern length
    int pattern_length = 12;
    mPatterns.resize(pattern_length, 0);

    // frame_width
    mFrameWidth = 120000;

    // data code
    int data_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(data_code, 5, false);

    // ending patterns
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genLR3715MPattern() {
    //   mCarrierFrequency = 38000;
    mBit0Patterns[0] = 264 + 16;
    mBit0Patterns[1] = -792 - 16;
    mBit1Patterns[0] = 264 + 16;
    mBit1Patterns[1] = -1848 - 16;
    mFrameWidth = 264 * 512 - 168;
    genBytePattern(mUserCodes[0], 5, false);
    genBytePattern(mDataCodes[0], 6, false);
    genBytePattern(mDataCodes[1], 4, false);
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -(mFrameWidth / 2 - total_pattern_width());
    mPatterns[mPatternId++] = align_val;
    genBytePattern(mUserCodes[0], 5, false);
    genBytePattern(mDataCodes[0], 6, true);
    genBytePattern(mDataCodes[1], 3, true);
    mPatterns[mPatternId++] = mBit0Patterns[0];
    mPatterns[mPatternId++] = mBit1Patterns[1];
    mPatterns[mPatternId++] = mBit0Patterns[0];
    align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId] = align_val;
}

void PatternGen::genIX0773CEPattern() {
    mBit0Patterns[0] = 260;
    mBit0Patterns[1] = -780;
    mBit1Patterns[0] = 260;
    mBit1Patterns[1] = -1820;
    mFrameWidth = mBit0Patterns[0] * 768;
    genBytePattern(mUserCodes[0], 5, false);
    genBytePattern(mDataCodes[0], 6, false);
    genBytePattern(mDataCodes[1], 4, false);
    mPatterns[mPatternId++] = mBit0Patterns[0];
    mPatterns[mPatternId++] = -44000;
    genBytePattern(mUserCodes[0], 5, false);
    genBytePattern(mDataCodes[0], 6, true);
    genBytePattern(mDataCodes[1], 3, true);
    mPatterns[mPatternId++] = mBit1Patterns[0];
    mPatterns[mPatternId++] = mBit1Patterns[1];
    mPatterns[mPatternId++] = mBit0Patterns[0];
    mPatterns[mPatternId++] = -44000;
    genBytePattern(mUserCodes[0], 5, false);
    genBytePattern(mDataCodes[0], 6, false);
    genBytePattern(mDataCodes[1], 4, false);
    mPatterns[mPatternId++] = mBit0Patterns[0];
    mPatterns[mPatternId++] = -44000;
}

void PatternGen::genM3004CarrierPattern() {
    mBit0Patterns[0] = 70;
    mBit0Patterns[1] = -4990;
    mBit1Patterns[0] = 70;
    mBit1Patterns[1] = -7520;
    mFrameWidth = 121650;
    mPatterns[mPatternId++] = mBit1Patterns[0];
    mPatterns[mPatternId++] = mBit1Patterns[1];
    genBytePattern(mControlCode, 1, false);
    if (mControlCode == 0) {
        mControlCode = 1;
    } else {
        mControlCode = 0;
    }
    genBytePattern(mUserCodes[0], 3, false);
    genBytePattern(mDataCodes[0], 6, false);
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genM3004FlashPattern() {
    mBit0Patterns[0] = 140;
    mBit0Patterns[1] = -4920;
    mBit1Patterns[0] = 140;
    mBit1Patterns[1] = -7450;
    mFrameWidth = 121600;

    genBytePattern(mControlCode, 2, false);
    if (mControlCode == 0) {
        mControlCode = 2;
    } else if (mControlCode == 1) {
        mControlCode = 3;
    } else if (mControlCode == 2) {
        mControlCode = 1;
    } else if (mControlCode == 3) {
        mControlCode = 0;
    }

    genBytePattern(mUserCodes[0], 3, false);
    genBytePattern(mDataCodes[0], 6, false);
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genSAA1250Pattern() {
    mCarrierFrequency = 34000;
    mBit0Patterns[0] = 10;
    mBit0Patterns[1] = -70;
    mBit1Patterns[0] = 10;
    mBit1Patterns[1] = -180;
    mFrameWidth = 260000;

    // pattern length
    int pattern_length = 56;
    mPatterns.resize(pattern_length, 0);

    // leader code
    mPatterns[mPatternId++] = mBit1Patterns[0];
    mPatterns[mPatternId++] = -290;

    // user & data code
    int user_code0 = charToValue(mIrCodes[0]);
    int user_code1 = charToValue(mIrCodes[1]);
    genBytePattern(user_code0, 1, false);
    genBytePattern(user_code1, 4, false);
    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 6, false);

    // ending code
    mPatterns[mPatternId++] = mBit1Patterns[0];
    mPatterns[mPatternId++] = -290;
    mPatterns[mPatternId++] = mBit1Patterns[0];
    mPatterns[mPatternId++] = -121000;


    // leader code
    mPatterns[mPatternId++] = mBit1Patterns[0];
    mPatterns[mPatternId++] = -290;

    // user & data code
    genBytePattern(user_code0, 1, false);
    if (mControlCode == 0) { //FIXME : One click sends two or more singles.
        genBytePattern(user_code1, 4, false);
        //mControlCode = 1;
    } else {
        genBytePattern(user_code1, 4, true);
        mControlCode = 0;
    }

    data_code = (charToValue(mIrCodes[4]) << 4) + charToValue(mIrCodes[5]);
    genBytePattern(data_code, 6, false);

    // ending code
    mPatterns[mPatternId++] = mBit1Patterns[0];
    mPatterns[mPatternId++] = -290;
    mPatterns[mPatternId++] = mBit1Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::gen3010_RC5Pattern() {
    if (mEncodingType == SC3010_RC5) {
        mBit0Patterns[0] = 844;
        mBit0Patterns[1] = -844;
        mBit1Patterns[0] = -844;
        mBit1Patterns[1] = 844;
    } else {
        mBit0Patterns[0] = 889;
        mBit0Patterns[1] = -889;
        mBit1Patterns[0] = -889;
        mBit1Patterns[1] = 889;
    }
    // mFrameWidth = mBit0Patterns[0] * 2 * 64;
    switch (mEncodingType) {
        case SAA3010_RC5_36K:
            mFrameWidth = 95000;
            break;
        case SAA3010_RC5:
            mFrameWidth = 114000;
            break;
        case SC3010_RC5:
            mFrameWidth = 128000;
            break;
        default:
            break;
    }
    int start_code = charToValue(mIrCodes[1]);
    genBytePattern(start_code, 2, false);
    genBytePattern(mControlCode, 1, false);
    if (mControlCode == 0) {
        mControlCode = 1;
    } else {
        mControlCode = 0;
    }
    int system_code = charToValue(mIrCodes[2]);
    genBytePattern(system_code, 1, false);
    system_code = charToValue(mIrCodes[3]);
    genBytePattern(system_code, 4, false);
    int data_code = charToValue(mIrCodes[4]);
    genBytePattern(data_code, 2, false);
    data_code = charToValue(mIrCodes[5]);
    genBytePattern(data_code, 4, false);
    if (mEncodingType == SAA3010_RC5_36K) {
        mPatterns[mPatternId++] = -70108;
    } else if (mEncodingType == SC3010_RC5) {
        mPatterns[mPatternId++] = -104368;
    }
    // mPatterns[mPatternId++] = -844;
}

void PatternGen::gen6124Pattern() {
    mBit0Patterns[0] = 600;
    mBit0Patterns[1] = -600;
    mBit1Patterns[0] = 1200;
    mBit1Patterns[1] = -600;
    mFrameWidth = 45000;

    // leading code
    mPatterns[mPatternId++] = 2400;
    mPatterns[mPatternId++] = -600;

    // device code
    int data_code = mUserCodes[0];
    genBytePattern(data_code, 7, false);

    // user code
    int align_val = 0;
    switch (mEncodingType) {
        case UPD6124_40K:
            genBytePattern(mDataCodes[0], 5, false);
            align_val = -mFrameWidth + total_pattern_width();
            mPatterns[mPatternId++] = -100000;
            break;
        case UPD6124_D7C8:
            genBytePattern(mDataCodes[0], 8, false);
            align_val = -mFrameWidth + total_pattern_width();
            mPatterns[mPatternId++] = -100000;
            break;
        case UPD6124_D7C13_40K:
            genBytePattern(mDataCodes[1], 8, false);
            genBytePattern(mDataCodes[0], 5, false);
            mPatterns[mPatternId++] = -100000;
            break;
        case UPD6124_D7C13:
            genBytePattern(mDataCodes[1], 8, false);
            genBytePattern(mDataCodes[0], 5, false);
            mFrameWidth = 49000;
            align_val = -mFrameWidth + total_pattern_width();
            mPatterns[mPatternId++] = -100000;
            break;
    }
}

void PatternGen::gen34280Pattern() {
    mCarrierFrequency = 38000;
    mLsbFirst = true;
    mBit0Patterns[0] = 530;
    mBit0Patterns[1] = -530;
    mBit1Patterns[0] = 530;
    mBit1Patterns[1] = -1590;
    mFrameWidth = 64000;

    const int pattern_length = 38;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    mPatterns[mPatternId++] = 8500;
    mPatterns[mPatternId++] = -4250;

    // device pattern
    genBytePattern(mUserCodes[0], 8, false);

    mPatterns[mPatternId++] = mBit0Patterns[0];
    mPatterns[mPatternId++] = -4250;

    // command pattern
    genBytePattern(mDataCodes[0], 8, false);

    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
}

void PatternGen::genRecs80Pattern() {
    mCarrierFrequency = 33300;
    mLsbFirst = false;
    mBit0Patterns[0] = 180;
    mBit0Patterns[1] = -5580;
    mBit1Patterns[0] = 180;
    mBit1Patterns[1] = -8460;
    mFrameWidth = 138000;

    mPatterns[mPatternId++] = mBit1Patterns[0];
    mPatterns[mPatternId++] = mBit1Patterns[1];

    int userCode = charToValue(mIrCodes[1]);
    genBytePattern(userCode, 1, false);
    userCode = charToValue(mIrCodes[3]);
    genBytePattern(userCode, 3, false);
    int dataCode = (charToValue(mIrCodes[4]) << 4) + charToValue(mIrCodes[5]);
    genBytePattern(dataCode, 6, false);

    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genPanasonicPattern() {
    mBit0Patterns[0] = 422;
    mBit0Patterns[1] = -435;
    mBit1Patterns[0] = 417;
    mBit1Patterns[1] = -1310;
    mFrameWidth = 122000;

    mPatterns[mPatternId++] = 3496;
    mPatterns[mPatternId++] = -1773;

    genBytePattern(mUserCodes[0], 8, false);
    genBytePattern(mDataCodes[0], 8, false);
    genBytePattern(mDataCodes[1], 8, false);
    genBytePattern(mDataCodes[2], 8, false);
    genBytePattern(mDataCodes[3], 8, false);
    genBytePattern(mDataCodes[4], 8, false);

    mPatterns[mPatternId++] = 421;
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genGeminiPattern() {
    mBit0Patterns[0] = 530;
    mBit0Patterns[1] = -530;
    mBit1Patterns[0] = -530;
    mBit1Patterns[1] = 530;
    mFrameWidth = 202000;

    mPatterns[mPatternId++] = 530;
    mPatterns[mPatternId++] = -2650;

    genBytePattern(mUserCodes[1], 8, false);
    genBytePattern(mUserCodes[0], 2, false);

    mPatterns[mPatternId++] = -20000;
    mPatterns[mPatternId++] = 530;
    mPatterns[mPatternId++] = -2650;

    genBytePattern(mDataCodes[1], 8, false);
    genBytePattern(mDataCodes[0], 2, false);

    mPatterns[mPatternId++] = -120220;
    mPatterns[mPatternId++] = 530;
    mPatterns[mPatternId++] = -2650;

    genBytePattern(mUserCodes[1], 8, false);
    genBytePattern(mUserCodes[0], 2, false);

    mPatterns[mPatternId++] = -20000;
    //int align_val = -mFrameWidth + total_pattern_width();
    //mPatterns[mPatternId++] = align_val;
}

void PatternGen::genGeminiC6P317Pattern() {
    mCarrierFrequency = 38000;
    mBit0Patterns[0] = -510;
    mBit0Patterns[1] = 510;
    mBit1Patterns[0] = 510;
    mBit1Patterns[1] = -510;
    mFrameWidth = 134200;

    int pattern_length = 18;
    mPatterns.resize(pattern_length, 0);

    // lead code
    mPatterns[mPatternId++] = 510;
    mPatterns[mPatternId++] = -2550;

    // hard code
    genBytePattern(1, 1, false);

    // data code
    int user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 6, false);

    // stop code
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::gen7461MPattern() {
    if (mEncodingType == LC7461M_C13) {
        mBit0Patterns[0] = 560;
        mBit0Patterns[1] = -560;
        mBit1Patterns[0] = 560;
        mBit1Patterns[1] = -1680;
        int pattern_length = 92;
        //      int pattern_length = 88;
        mPatterns.resize(pattern_length, 0);
        mPatterns[mPatternId++] = 9000;
        mPatterns[mPatternId++] = -4500;
    } else {
        mBit0Patterns[0] = 564;
        mBit0Patterns[1] = -564;
        mBit1Patterns[0] = 564;
        mBit1Patterns[1] = -1692;
        int pattern_length = 88;
        mPatterns.resize(pattern_length, 0);
        mPatterns[mPatternId++] = 9024;
        mPatterns[mPatternId++] = -4512;
    }
    mFrameWidth = 108000;

    // device pattern
    int user_code0 = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    int user_code1 = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(user_code1, 8, false);
    genBytePattern(user_code0, 5, false);
    genBytePattern(user_code1, 8, true);
    genBytePattern(user_code0, 5, true);

    // command pattern
    int data_code = (charToValue(mIrCodes[4]) << 4) + charToValue(mIrCodes[5]);
    genBytePattern(data_code, 8, false);
    genBytePattern(data_code, 8, true);

    if (mEncodingType == LC7461M_C13) {
        mPatterns[mPatternId++] = mBit0Patterns[0];
        mPatterns[mPatternId++] = -23380;
        mPatterns[mPatternId++] = 9000;
        mPatterns[mPatternId++] = -4500;
        mPatterns[mPatternId++] = mBit0Patterns[0];
        mPatterns[mPatternId++] = -94050;
    } else {
        mPatterns[mPatternId++] = mBit0Patterns[0];
        mPatterns[mPatternId++] = -22836;
    }
}

void PatternGen::genKonkaPattern() {
    mCarrierFrequency = 38000;
    mBit0Patterns[0] = 500;
    mBit0Patterns[1] = -1500;
    mBit1Patterns[0] = 500;
    mBit1Patterns[1] = -2500;
    mUserCodeLength = 1;
    mDataCodeLength = 1;

    const int pattern_length = 38;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count);

    mPatterns[mPatternId++] = 3000;
    mPatterns[mPatternId++] = -3000;

    // device pattern
    int user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 8, false);

    // command pattern
    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 8, false);

    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -4000;
    mPatterns[mPatternId++] = 500;
    //mPatterns[mPatternId++] = -23000;
    int align_val = -72000 + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::genRCAPattern() {
    mBit0Patterns[0] = 480;
    mBit0Patterns[1] = -960;
    mBit1Patterns[0] = 480;
    mBit1Patterns[1] = -1920;
    mFrameWidth = 64000;

    // leader code
    mPatterns[mPatternId++] = 3800;
    mPatterns[mPatternId++] = -3800;

    // user code
    genBytePattern(mUserCodes[0], 4, false);

    // data code
    genBytePattern(mDataCodes[0], 8, false);

    // inverse user code
    genBytePattern(mUserCodes[0], 4, true);

    // inverse data code
    genBytePattern(mDataCodes[0], 8, true);

    // stop code
    mPatterns[mPatternId++] = 480;
    mPatterns[mPatternId++] = -9000;
}

void PatternGen::genThomsonPattern() {
    mCarrierFrequency = 33300;
    mLsbFirst = false;
    mBit0Patterns[0] = 458;
    mBit0Patterns[1] = -2061;
    mBit1Patterns[0] = 458;
    mBit1Patterns[1] = -4580;
    mFrameWidth = 80000;

    // user code
    genBytePattern(mUserCodes[0], 4, false);

    // control code
    genBytePattern(mUserCodes[0], 1, false);
    /*genBytePattern(mControlCode, 1, false);
      if (mControlCode == 0) {
      mControlCode = 1;
      } else {
      mControlCode = 0;
      }*/

    // data code
    genBytePattern(mDataCodes[0], 7, false);

    // stop code
    mPatterns[mPatternId++] = 458;
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genIRT1250C5D6Pattern() {
    mCarrierFrequency = 34000;
    mBit0Patterns[0] = 175;
    mBit0Patterns[1] = -5590;
    mBit1Patterns[0] = 175;
    mBit1Patterns[1] = -8450;

    // control code
    genBytePattern(mControlCode, 2, false);
    if (mControlCode == 0) {
        mControlCode = 2;
        mFrameWidth = 138200;
    } else if (mControlCode == 1) {
        mControlCode = 3;
        mFrameWidth = 141100;
    } else if (mControlCode == 2) {
        mControlCode = 1;
        mFrameWidth = 141100;
    } else if (mControlCode == 3) {
        mControlCode = 0;
        mFrameWidth = 144000;
    }

    // user code
    genBytePattern(mUserCodes[0], 3, false);

    // data code
    genBytePattern(mDataCodes[0], 6, false);

    // stop code
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genM7080Pattern() {
    mCarrierFrequency = 34000;
    mBit0Patterns[0] = 10;
    mBit0Patterns[1] = -70;
    mBit1Patterns[0] = 10;
    mBit1Patterns[1] = -290;
    mBit0Patterns[2] = 10;
    mBit1Patterns[2] = -180;

    int pattern_length = 30;
    mPatterns.resize(pattern_length, 0);

    // head code
    mPatterns[mPatternId++] = 10;
    mPatterns[mPatternId++] = -410;

    // custom code
    int cust_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(cust_code, 5, false);

    // data code
    int num_one_bit = 0;
    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    for (int j = 0; j < 6; j++) {
        bool is_bit_zero = ((data_code & 1) == 0);
        if (is_bit_zero) {
            mPatterns[mPatternId++] = mBit0Patterns[0];
            mPatterns[mPatternId++] = mBit0Patterns[1];
        } else if (j % 2 == 0){
            mPatterns[mPatternId++] = mBit0Patterns[2];
            mPatterns[mPatternId++] = mBit1Patterns[2];
            num_one_bit += 1;
        } else {
            mPatterns[mPatternId++] = mBit1Patterns[0];
            mPatterns[mPatternId++] = mBit1Patterns[1];
            num_one_bit += 1;
        }
        data_code >>= 1;
    }

    // check code
    if (num_one_bit % 2 == 0) {
        mPatterns[mPatternId++] = mBit0Patterns[2];
        mPatterns[mPatternId++] = mBit1Patterns[2];
    } else {
        mPatterns[mPatternId++] = mBit0Patterns[0];
        mPatterns[mPatternId++] = mBit0Patterns[1];
    }

    // tail code
    mPatterns[mPatternId++] = 10;
    mPatterns[mPatternId++] = -410;

    // stop code
    mPatterns[mPatternId++] = 10;
    mPatterns[mPatternId++] = 121000;
}

void PatternGen::genIRT1250C5D7Pattern() {
    mCarrierFrequency = 34000;
    mBit0Patterns[0] = 10;
    mBit0Patterns[1] = -70;
    mBit1Patterns[0] = 10;
    mBit1Patterns[1] = -290;
    mBit0Patterns[2] = 10;
    mBit1Patterns[2] = -180;

    int pattern_length = 30;
    mPatterns.resize(pattern_length, 0);

    // control code
    if (mControlCode == 0) {
        mControlCode = 1;
    } else {
        mControlCode = 0;
    }

    // head code
    mPatterns[mPatternId++] = 10;
    mPatterns[mPatternId++] = -410;

    // custom code
    int cust_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(cust_code, 5, false);

    // data code
    int num_one_bit = 0;
    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    for (int j = 0; j < 6; j++) {
        bool is_bit_zero = ((data_code & 1) == 0);
        if (mControlCode == 0 || is_bit_zero) {
            mPatterns[mPatternId++] = mBit0Patterns[0];
            mPatterns[mPatternId++] = mBit0Patterns[1];
        } else if (j % 2 == 0){
            mPatterns[mPatternId++] = mBit0Patterns[2];
            mPatterns[mPatternId++] = mBit1Patterns[2];
            num_one_bit += 1;
        } else {
            mPatterns[mPatternId++] = mBit1Patterns[0];
            mPatterns[mPatternId++] = mBit1Patterns[1];
            num_one_bit += 1;
        }
        data_code >>= 1;
    }

    // check code
    if (num_one_bit % 2 == 1) {
        mPatterns[mPatternId++] = mBit0Patterns[2];
        mPatterns[mPatternId++] = mBit1Patterns[2];
    } else {
        mPatterns[mPatternId++] = mBit0Patterns[0];
        mPatterns[mPatternId++] = mBit0Patterns[1];
    }

    // tail code
    mPatterns[mPatternId++] = 10;
    mPatterns[mPatternId++] = -410;

    // stop code
    mPatterns[mPatternId++] = 10;
    mPatterns[mPatternId++] = 121000;
}

void PatternGen::genHtsC5D6PPattern() {
    mCarrierFrequency = 38000;
    mBit0Patterns[0] = 300;
    mBit0Patterns[1] = -1500;
    mBit1Patterns[0] = 300;
    mBit1Patterns[1] = -3000;
    mBit0Patterns[2] = 300;
    mBit1Patterns[2] = -4860;

    int pattern_length = 30;
    mPatterns.resize(pattern_length, 0);

    // lead code
    mPatterns[mPatternId++] = 300;
    mPatterns[mPatternId++] = -6500;

    // custom code
    int cust_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(cust_code, 5, false);

    // data code
    int num_one_bit = 0;
    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    for (int j = 0; j < 6; j++) {
        bool is_bit_zero = ((data_code & 1) == 0);
        if (is_bit_zero) {
            mPatterns[mPatternId++] = mBit0Patterns[0];
            mPatterns[mPatternId++] = mBit0Patterns[1];
        } else if (j % 2 == 1){
            mPatterns[mPatternId++] = mBit0Patterns[2];
            mPatterns[mPatternId++] = mBit1Patterns[2];
            num_one_bit += 1;
        } else {
            mPatterns[mPatternId++] = mBit1Patterns[0];
            mPatterns[mPatternId++] = mBit1Patterns[1];
            num_one_bit += 1;
        }
        data_code >>= 1;
    }

    // check code
    if (num_one_bit % 2 == 1) {
        mPatterns[mPatternId++] = mBit1Patterns[0];
        mPatterns[mPatternId++] = mBit1Patterns[1];
    } else {
        mPatterns[mPatternId++] = mBit0Patterns[0];
        mPatterns[mPatternId++] = mBit0Patterns[1];
    }

    // stop code
    mPatterns[mPatternId++] = 300;
    mPatterns[mPatternId++] = -6500;

    // lead code
    mPatterns[mPatternId++] = 300;
    mPatterns[mPatternId++] = -20000;
}

void PatternGen::genPhilipsPattern() {
    mCarrierFrequency = 38000;
    mLsbFirst = false;
    mBit0Patterns[0] = -444;
    mBit0Patterns[1] = 444;
    mBit1Patterns[0] = 444;
    mBit1Patterns[1] = -444;
    mFrameWidth = 108000;

    // leader code
    mPatterns[mPatternId++] = 2666;
    mPatterns[mPatternId++] = -889;

    //  code
    genBytePattern(charToValue(mIrCodes[1]), 1, false);

    // cut code
    genBytePattern(charToValue(mIrCodes[3]), 3, false);

    // code
    if (mControlCode == 0) {
        mPatterns[mPatternId++] = -889;
        mPatterns[mPatternId++] = 889;
        mControlCode = 1;
    } else {
        mPatterns[mPatternId++] = 889;
        mPatterns[mPatternId++] = -889;
        mControlCode = 0;
    }

    // control code
    //    genBytePattern(0, 1, false);
    //if (mControlCode == 0) {
    //  mControlCode = 1;
    //} else {
    //  mControlCode = 0;
    //}
    //genBytePattern(mControlCode, 1, false);*/

    // user code
    genBytePattern(charToValue(mIrCodes[4]), 4, false);
    genBytePattern(charToValue(mIrCodes[5]), 4, false);

    // data code
    genBytePattern(charToValue(mIrCodes[6]), 4, false);
    genBytePattern(charToValue(mIrCodes[7]), 4, false);

    // stop code
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genSDA2208Pattern() {
    mCarrierFrequency = 31300;
    mLsbFirst = false;
    mBit0Patterns[0] = -512;
    mBit0Patterns[1] = 512;
    mBit1Patterns[0] = 512;
    mBit1Patterns[1] = -512;
    // pattern length
    int pattern_length = 69;
    mPatterns.resize(pattern_length, 0);
    // frame width
    mFrameWidth = 258000;

    // leader code
    mPatterns[mPatternId++] = 512;
    mPatterns[mPatternId++] = -2560;
    mPatterns[mPatternId++] = 512;
    mPatterns[mPatternId++] = -512;

    // user code
    genBytePattern(charToValue(mIrCodes[1]), 1, false);
    genBytePattern(charToValue(mIrCodes[2]), 4, false);
    genBytePattern(charToValue(mIrCodes[3]), 4, false);

    // stop code
    mPatterns[mPatternId++] = -19968;
    mPatterns[mPatternId++] = 512;
    mPatterns[mPatternId++] = -2560;
    mPatterns[mPatternId++] = 512;
    mPatterns[mPatternId++] = -512;

    // data code
    genBytePattern(charToValue(mIrCodes[5]), 1, false);
    genBytePattern(charToValue(mIrCodes[6]), 4, false);
    genBytePattern(charToValue(mIrCodes[7]), 4, false);

    // stop code
    mPatterns[mPatternId++] = -177688;
    mPatterns[mPatternId++] = 512;
    mPatterns[mPatternId++] = -2560;
    mPatterns[mPatternId++] = 512;
    mPatterns[mPatternId++] = -512;

    // data code
    genBytePattern(charToValue(mIrCodes[1]), 1, false);
    genBytePattern(charToValue(mIrCodes[2]), 4, false);
    genBytePattern(charToValue(mIrCodes[3]), 4, false);

    // stop code
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}


void PatternGen::genM58480Pattern() {
    mCarrierFrequency = 40000;
    // bit_0, bit_1 definition
    mBit0Patterns[0] = 500;
    mBit0Patterns[1] = -1500;
    mBit1Patterns[0] = 500;
    mBit1Patterns[1] = -3500;

    // pattern length
    int pattern_length = 14;
    mPatterns.resize(pattern_length, 0);

    // frame width
    mFrameWidth = 48000;

    // user code
    int data_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(data_code, 6, false);

    // ending pattern
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genSAF1039Pattern() {
    mCarrierFrequency = 36000;
    // bit_0, bit_1 definition
    int leader_high = 0;
    int leader_low = 0;
    if (mEncodingType == SAF1039) {
        mBit0Patterns[0] = 450;
        mBit0Patterns[1] = -6750;
        mBit1Patterns[0] = 450;
        mBit1Patterns[1] = -3150;
        leader_high = 450;
        leader_low = -10026;
        // frame width
        mFrameWidth = 110000;
    } else {
        mBit0Patterns[0] = 708;
        mBit0Patterns[1] = -6372;
        mBit1Patterns[0] = 708;
        mBit1Patterns[1] = -2832;
        leader_high = 780;
        leader_low = -9770;
        // frame width
        mFrameWidth = 123000;
    }

    // pattern length
    int pattern_length = 36;
    mPatterns.resize(pattern_length, 0);


    // leader code
    for (int i = 0; i < 3; i++) {
        mPatterns[mPatternId++] = mBit0Patterns[0];
        mPatterns[mPatternId++] = mBit1Patterns[1];
        mPatterns[mPatternId++] = leader_high;
        mPatterns[mPatternId++] = leader_low;
    }
    mPatterns[mPatternId++] = mBit0Patterns[0];
    mPatterns[mPatternId++] = mBit1Patterns[1];

    // data code
    int data_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    for (int j = 0; j < 5; j++) {
        bool is_bit_zero = false;
        is_bit_zero = ((data_code & 1) == 0);
        data_code >>= 1;
        if (is_bit_zero) {
            mPatterns[mPatternId++] = mBit0Patterns[0];
            mPatterns[mPatternId++] = mBit0Patterns[1];
        } else {
            mPatterns[mPatternId++] = mBit1Patterns[0];
            mPatterns[mPatternId++] = mBit1Patterns[1];
            mPatterns[mPatternId++] = mBit1Patterns[0];
            mPatterns[mPatternId++] = mBit1Patterns[1];
        }
    }

    // ending pattern
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
    if (mPatternId < pattern_length) {
        std::vector<int> patterns(mPatternId);
        for (int i = 0; i < mPatternId; i++) {
            patterns[i] = mPatterns[i];
        }
        mPatterns = patterns;
    }
}

void PatternGen::genC8D8Pattern() {
    mLsbFirst = false;
    mBit0Patterns[0] = -500;
    mBit0Patterns[1] = 500;
    mBit1Patterns[0] = 500;
    mBit1Patterns[1] = -500;
    mFrameWidth = 172000;

    // leader code
    mPatterns[mPatternId++] = 480;
    mPatterns[mPatternId++] = -2500;

    // D0
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;

    // 7F
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;

    // stop code
    mPatterns[mPatternId++] = -17020;

    // leader code
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -2500;
    // D0
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;

    // user code
    genBytePattern(mUserCodes[0], 8, false);

    // data code
    genBytePattern(mDataCodes[0], 8, false);

    // stop code
    mPatterns[mPatternId++] = -7800;

    // leader code
    mPatterns[mPatternId++] = 480;
    mPatterns[mPatternId++] = -2500;

    // D0
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;

    // 7F
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -500;

    // stop code
    mPatterns[mPatternId++] = -17020;
}

void PatternGen::genWuxiPattern() {
    mCarrierFrequency = 38000;
    // bit_0, bit_1 definition
    mBit0Patterns[0] = 560;
    mBit0Patterns[1] = -560;
    mBit1Patterns[0] = 560;
    mBit1Patterns[1] = -1120;

    // pattern length
    int pattern_length = 90;
    mPatterns.resize(pattern_length, 0);

    // frame width
    mFrameWidth = 230000;

    // leading pattern
    mPatterns[mPatternId++] = 3640;
    mPatterns[mPatternId++] = -1800;

    // user code
    int user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 8, false);
    user_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(user_code, 8, false);
    user_code = (charToValue(mIrCodes[4]) << 4) + charToValue(mIrCodes[5]);
    genBytePattern(user_code, 8, false);

    // leading pattern
    mPatterns[mPatternId++] = 3640;
    mPatterns[mPatternId++] = -1800;

    // data code
    int data_code = (charToValue(mIrCodes[6]) << 4) + charToValue(mIrCodes[7]);
    genBytePattern(data_code, 8, false);
    data_code = (charToValue(mIrCodes[8]) << 4) + charToValue(mIrCodes[9]);
    genBytePattern(data_code, 8, false);

    // ending pattern
    mPatterns[mPatternId++] = mBit0Patterns[0];
    mPatterns[mPatternId++] = -54000;
    mPatterns[mPatternId++] = 3640;
    mPatterns[mPatternId++] = -3640;
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genIRMediaMousePattern() {
    mLsbFirst = false;

    const int adjust_v = 00;
    const int repeats = 1;
    // bit_0, bit_1 definition
    mBit0Patterns[0] = -600 + adjust_v;
    mBit0Patterns[1] = 600 - adjust_v;
    mBit1Patterns[0] = 600 - adjust_v;
    mBit1Patterns[1] = -600 + adjust_v;

    // pattern length
    int pattern_length = (1 + 17 * 2 + 1) * repeats;
    mPatterns.resize(pattern_length, 0);

    for (int i = 1; i <= repeats; ++i) {
        // header
        mPatterns[mPatternId++] = 600;

        // e code
        int e_code = charToValue(mIrCodes[1]);
        if (e_code > 0) {
            mPatterns[mPatternId++] = 600;
            mPatterns[mPatternId++] = -600;
        } else {
            mPatterns[mPatternId++] = -600;
            mPatterns[mPatternId++] = 600;
        }

        // data code
        int data_code_1 = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
        genBytePattern(data_code_1, 8, false);

        // data code
        int data_code_2 = (charToValue(mIrCodes[4]) << 4) + charToValue(mIrCodes[5]);
        genBytePattern(data_code_2, 8, false);

        // stop code
        mPatterns[mPatternId++] = -5000;
    }
}

void PatternGen::genM50119LPattern() {
    mCarrierFrequency = 37900;
    mBit0Patterns[0] = 260;
    mBit0Patterns[1] = -780;
    mBit1Patterns[0] = 260;
    mBit1Patterns[1] = -1820;

    int pattern_length = 22;
    mPatterns.resize(pattern_length, 0);

    // frame width
    mFrameWidth = 25000;

    // user & data code
    int user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 3, false);
    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 7, false);

    // ending pattern
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genM50119PPattern() {
    mCarrierFrequency = 40000;
    // bit_0, bit_1 definition
    mBit0Patterns[0] = 500;
    mBit0Patterns[1] = -500;
    mBit1Patterns[0] = 500;
    mBit1Patterns[1] = -1500;

    // pattern length
    int pattern_length = 22;
    mPatterns.resize(pattern_length, 0);

    // frame width
    mFrameWidth = 28000;

    // user & data code
    int user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 3, false);
    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 7, false);

    // ending pattern
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;
}


/************************************************************ Little apple support starts from here ****************************************************************/

void PatternGen::genPatternDVB40BIT() {
    mCarrierFrequency = 38000;
    mLsbFirst = true;
    mBit0Patterns[0] = 560;
    mBit0Patterns[1] = -560;
    mBit1Patterns[0] = 560;
    mBit1Patterns[1] = -1180;
    mFrameWidth = 120000;

    //const int pattern_length = 94;
    const int pattern_length = 90;
    mPatterns.resize(pattern_length, 0);

    // lead code
    mPatterns[mPatternId++] = 3600;
    mPatterns[mPatternId++] = -1800;

    // custom code
    int code = (charToValue(mIrCodes[4])<<4) + charToValue(mIrCodes[5]);
    genBytePattern(code, 8, false);
    code = (charToValue(mIrCodes[2])<<4) + charToValue(mIrCodes[3]);
    genBytePattern(code, 8, false);
    code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(code, 8, false);

    // separation period
    mPatterns[mPatternId++] = 3600;
    mPatterns[mPatternId++] = -1800;

    // data code
    code = (charToValue(mIrCodes[8])<<4) + charToValue(mIrCodes[9]);
    genBytePattern(code, 8, false);
    code = (charToValue(mIrCodes[6])<<4) + charToValue(mIrCodes[7]);
    genBytePattern(code, 8, false);

    mPatterns[mPatternId++] = 560;
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    // repeat code
    mPatterns[mPatternId++] = 3600;
    mPatterns[mPatternId++] = -3600;
    mPatterns[mPatternId++] = mBit0Patterns[0];
    mPatterns[mPatternId++] = -100000;
/*  mPatterns[mPatternId++] = 3600;
  mPatterns[mPatternId++] = -3600;
  mPatterns[mPatternId++] = mBit0Patterns[0];
  mPatterns[mPatternId++] = -20000;*/
}

void PatternGen::genPatternDVBPanSamsung() {
    mCarrierFrequency = 38000;
    mLsbFirst = true;
    mBit0Patterns[0] = 421;
    mBit0Patterns[1] = -421;
    mBit1Patterns[0] = 421;
    mBit1Patterns[1] = -1263;
    mFrameWidth = 114000;

    mPatterns[mPatternId++] = 3488;
    mPatterns[mPatternId++] = -1744;

    int code = (charToValue(mIrCodes[6])<<4) + charToValue(mIrCodes[7]);
    genBytePattern(code, 8, false);
    code = (charToValue(mIrCodes[4])<<4) + charToValue(mIrCodes[5]);
    genBytePattern(code, 8, false);
    code = (charToValue(mIrCodes[2])<<4) + charToValue(mIrCodes[3]);
    genBytePattern(code, 8, false);
    code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(code, 8, false);
    code = (charToValue(mIrCodes[10])<<4) + charToValue(mIrCodes[11]);
    genBytePattern(code, 8, false);
    code = (charToValue(mIrCodes[8])<<4) + charToValue(mIrCodes[9]);
    genBytePattern(code, 8, false);

    mPatterns[mPatternId++] = 421;
    mPatterns[mPatternId++] = -100000;
//  int align_val = -mFrameWidth + total_pattern_width();
//  mPatterns[mPatternId++] = align_val;
}

void PatternGen::genPatternGemini() {
    mCarrierFrequency = 31300;
    mLsbFirst = true;
    mBit0Patterns[0] = -510;
    mBit0Patterns[1] = 510;
    mBit1Patterns[0] = 510;
    mBit1Patterns[1] = -510;
    // pattern length
    int pattern_length = 48;
    mPatterns.resize(pattern_length, 0);
    // frame width
    mFrameWidth = 258000;

    // leader code
    mPatterns[mPatternId++] = 510;
    mPatterns[mPatternId++] = -2550;

    // user code
    genBytePattern(charToValue(mIrCodes[3]), 4, false);
    genBytePattern(charToValue(mIrCodes[2]), 4, false);
    genBytePattern(charToValue(mIrCodes[1]), 2, false);

    // stop code
    mPatterns[mPatternId++] = -22600;
    mPatterns[mPatternId++] = 510;
    mPatterns[mPatternId++] = -2550;
    mPatterns[mPatternId++] = 510;
    mPatterns[mPatternId++] = -510;

    // data code
    genBytePattern(charToValue(mIrCodes[7]), 4, false);
    genBytePattern(charToValue(mIrCodes[6]), 4, false);
    genBytePattern(charToValue(mIrCodes[5]), 1, false);

    // stop code
    mPatterns[mPatternId++] = -120000;
}

void PatternGen::genPatternJQ16_018() {
    mCarrierFrequency = 35500;
    mLsbFirst = true;
    mBit0Patterns[0] = 630;
    mBit0Patterns[1] = -1900;
    mBit1Patterns[0] = 1900;
    mBit1Patterns[1] = -630;
    mFrameWidth = 81000;

    const int pattern_length = 50;
    const int pattern_repeat_count = 1;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    // device pattern
    int custom_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(custom_code, 8, false);

    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 8, false);
    data_code = (charToValue(mIrCodes[4]) << 4) + charToValue(mIrCodes[5]);
    genBytePattern(data_code, 8, false);

    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::genPatternKonka() {
    mCarrierFrequency = 38000;
    mLsbFirst = false;
    mBit0Patterns[0] = 500;
    mBit0Patterns[1] = -1500;
    mBit1Patterns[0] = 500;
    mBit1Patterns[1] = -2500;
    mUserCodeLength = 1;
    mDataCodeLength = 1;
    mFrameWidth = 72000;

    const int pattern_length = 38;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count);

    mPatterns[mPatternId++] = 3000;
    mPatterns[mPatternId++] = -3000;

    // device pattern
    int user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 8, false);

    // command pattern
    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 8, false);

    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -4000;
    mPatterns[mPatternId++] = 500;
//  mPatterns[mPatternId++] = -23000;
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;


    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::genPatternLC7461M() {
    mCarrierFrequency = 38000;
    if (mEncodingType == LC7461M_C13) {
        mBit0Patterns[0] = 560;
        mBit0Patterns[1] = -560;
        mBit1Patterns[0] = 560;
        mBit1Patterns[1] = -1680;
        int pattern_length = 92;
        //      int pattern_length = 88;
        mPatterns.resize(pattern_length, 0);
        mPatterns[mPatternId++] = 9000;
        mPatterns[mPatternId++] = -4500;
    } else {
        mBit0Patterns[0] = 564;
        mBit0Patterns[1] = -564;
        mBit1Patterns[0] = 564;
        mBit1Patterns[1] = -1692;
        int pattern_length = 88;
        mPatterns.resize(pattern_length, 0);
        mPatterns[mPatternId++] = 9024;
        mPatterns[mPatternId++] = -4512;
    }
    mFrameWidth = 108000;

    // device pattern
    int user_code0 = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    int user_code1 = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(user_code1, 8, false);
    genBytePattern(user_code0, 5, false);
    genBytePattern(user_code1, 8, true);
    genBytePattern(user_code0, 5, true);

    // command pattern
    int data_code = (charToValue(mIrCodes[4]) << 4) + charToValue(mIrCodes[5]);
    genBytePattern(data_code, 8, false);
    genBytePattern(data_code, 8, true);

    if (mEncodingType == LC7461M_C13) {
        mPatterns[mPatternId++] = mBit0Patterns[0];
        mPatterns[mPatternId++] = -23380;
        mPatterns[mPatternId++] = 9000;
        mPatterns[mPatternId++] = -4500;
        mPatterns[mPatternId++] = mBit0Patterns[0];
        mPatterns[mPatternId++] = -96000;
    } else {
        mPatterns[mPatternId++] = mBit0Patterns[0];
        mPatterns[mPatternId++] = -96000;
    }
}

void PatternGen::genPatternLC7461MPanasonic() {
    mCarrierFrequency = 37500;
    mBit0Patterns[0] = 421;
    mBit0Patterns[1] = -421;
    mBit1Patterns[0] = 421;
    mBit1Patterns[1] = -1263;
    int pattern_length = 100;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);
    mFrameWidth = 132000;

    mPatterns[mPatternId++] = 3368;
    mPatterns[mPatternId++] = -1684;

    // device pattern
    int user_code0 = (charToValue(mIrCodes[4]) << 4) + charToValue(mIrCodes[5]);
    int user_code1 = (charToValue(mIrCodes[6]) << 4) + charToValue(mIrCodes[7]);
    genBytePattern(user_code1, 8, false);
    genBytePattern(user_code0, 8, false);
    user_code0 = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    user_code1 = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(user_code1, 8, false);
    genBytePattern(user_code0, 8, false);

    // command pattern
    int data_code = (charToValue(mIrCodes[8]) << 4) + charToValue(mIrCodes[9]);
    genBytePattern(data_code, 8, false);

    int parity_code = ~(user_code0 ^ user_code1 ^ data_code);
    genBytePattern(parity_code, 8, true);

    mPatterns[mPatternId++] = mBit0Patterns[0];
    mPatterns[mPatternId++] = -74000;

    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::genPatternLG3004() {
    mCarrierFrequency = 33300;
    mLsbFirst = false;
    mBit0Patterns[0] = 175;
    mBit0Patterns[1] = -5590;
    mBit1Patterns[0] = 175;
    mBit1Patterns[1] = -8450;
    mFrameWidth = 138000;

    mPatterns[mPatternId++] = mBit1Patterns[0];
    mPatterns[mPatternId++] = mBit1Patterns[1];

    genBytePattern(mControlCode, 1, false);
    if (mControlCode == 0) {
        mControlCode = 1;
    } else {
        mControlCode = 0;
    }
    int userCode = charToValue(mIrCodes[1]);
    genBytePattern(userCode, 3, false);
    int dataCode = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(dataCode, 6, false);

    mPatterns[mPatternId++] = mBit0Patterns[0];
//  int align_val = -mFrameWidth + total_pattern_width();
//  mPatterns[mPatternId++] = align_val;
    mPatterns[mPatternId++] = -1000000;
}

void PatternGen::genPatternM3004Carrier() {
    mCarrierFrequency = 38110;
    //233,4856,233,7345
    mBit0Patterns[0] = 240;
    mBit0Patterns[1] = -4820;
    mBit1Patterns[0] = 240;
    mBit1Patterns[1] = -7350;
    int pattern_length = 48;  //24
    mPatterns.resize(pattern_length, 0);
    mFrameWidth = 122000;

    mPatterns[mPatternId++] = mBit1Patterns[0];
    mPatterns[mPatternId++] = mBit1Patterns[1];
    genBytePattern(mControlCode, 1, false);
    if (mControlCode == 0) {
        mControlCode = 1;
    } else {
        mControlCode = 0;
    }
    genBytePattern(mUserCodes[0], 3, false);
    genBytePattern(mDataCodes[0], 6, false);
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    for (int i = 0; i < 24; i++) {
        mPatterns[i+24] = mPatterns[i];
    }
    mPatterns[pattern_length-1] = -100000;
}

void PatternGen::genPatternM50119P() {
    mCarrierFrequency = 38020;
    // bit_0, bit_1 definition
    mBit0Patterns[0] = 500;
    mBit0Patterns[1] = -500;
    mBit1Patterns[0] = 500;
    mBit1Patterns[1] = -1500;

    // pattern length
    int pattern_length = 44;
    mPatterns.resize(pattern_length, 0);

    // fram width
    mFrameWidth = 108000;

    // user code
    int user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 3, false);
    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 7, false);
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -13500;

    genBytePattern(user_code, 3, false);
    genBytePattern(data_code, 7, false);
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -100000;
}

void PatternGen::genPatternM50462() {
    mCarrierFrequency = 37870;
    // bit_0, bit_1 definition
    mBit0Patterns[0] = 340;
    mBit0Patterns[1] = -700;
    mBit1Patterns[0] = 340;
    mBit1Patterns[1] = -1650;

    // pattern length
    int pattern_length = 68;
    mPatterns.resize(pattern_length, 0);

    // fram width
    mFrameWidth = 108000;

    // user code
    int user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 8, false);
    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 8, false);
    mPatterns[mPatternId++] = 340;
    mPatterns[mPatternId++] = -28270;

    genBytePattern(user_code, 8, false);
    genBytePattern(data_code, 8, false);
    mPatterns[mPatternId++] = 340;
//  mPatterns[mPatternId++] = -28270;
    mPatterns[mPatternId++] = -100000;
}

void PatternGen::genPatternM50560() {
    mCarrierFrequency = 38000;
    mLsbFirst = true;
    mBit0Patterns[0] = 530;
    mBit0Patterns[1] = -530;
    mBit1Patterns[0] = 530;
    mBit1Patterns[1] = -1590;
    mFrameWidth = 64000;

    const int pattern_length = 38;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    mPatterns[mPatternId++] = 8500;
    mPatterns[mPatternId++] = -4250;

    // custom code
    genBytePattern(mUserCodes[0], 8, false);

    // cut code
    mPatterns[mPatternId++] = mBit0Patterns[0];
    mPatterns[mPatternId++] = -4250;

    // data code
    genBytePattern(mDataCodes[0], 8, false);

    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
//  int align_val = -23430;
    mPatterns[mPatternId++] = align_val;

    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::genPatternM9148() {
    mCarrierFrequency = 38000;
    mBit0Patterns[0] = 422;
    mBit0Patterns[1] = -1267;
    mBit1Patterns[0] = 1267;
    mBit1Patterns[1] = -422;
    mFrameWidth = 53000;

    const int pattern_length = 26;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);
//  mPatterns.resize(pattern_length*pattern_repeat_count+2, 0);

    // device pattern
    int custom_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(custom_code, 3, false);

    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 3, false);

    // command pattern
    data_code = (charToValue(mIrCodes[4]) << 4) + charToValue(mIrCodes[5]);
    genBytePattern(data_code, 6, false);
    mPatterns[mPatternId++] = -33420;

    int j = mPatternId - 1;
    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] =  -100000;

//  mPatterns[pattern_length*pattern_repeat_count] = 422;
//  mPatterns[pattern_length*pattern_repeat_count+1] = -100000;
}

void PatternGen::genPatternMiBox() {
    mCarrierFrequency = 38000;
    mLsbFirst = false;
    mBit0Patterns[0] = 600;
    mBit1Patterns[0] = -570;
    mBit0Patterns[1] = 600;
    mBit1Patterns[1] = -870;
    mBit0Patterns[2] = 600;
    mBit1Patterns[2] = -1170;
    mBit0Patterns[3] = 600;
    mBit1Patterns[3] = -1470;
    mFrameWidth = 29800;

    const int pattern_length = 24;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count);

    //leader code
    mPatterns[mPatternId++] = 1000;
    mPatterns[mPatternId++] = -570;

    int system_code_offset = 2;
    if (strlen(mIrCodes) == 4) {
        system_code_offset = 0;
    }
    //user code
    int parity_code = 0;
    for (int i = 0; i < 4; i++) {
        int data_code = charToValue(mIrCodes[i+system_code_offset]);
        parity_code ^= data_code;
        int index = data_code >> 2;
        mPatterns[mPatternId++] = mBit0Patterns[index];
        mPatterns[mPatternId++] = mBit1Patterns[index];
        index = data_code & 0x03;
        mPatterns[mPatternId++] = mBit0Patterns[index];
        mPatterns[mPatternId++] = mBit1Patterns[index];
    }

    int index = parity_code >> 2;
    mPatterns[mPatternId++] = mBit0Patterns[index];
    mPatterns[mPatternId++] = mBit1Patterns[index];
    index = parity_code & 0x03;
    mPatterns[mPatternId++] = mBit0Patterns[index];
    mPatterns[mPatternId++] = mBit1Patterns[index];

    //stop code
    mPatterns[mPatternId++] = 600;
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    //repeat code
    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::genPatternMITC8D8() {
    mCarrierFrequency = 38000;
    mLsbFirst = true;
    mBit0Patterns[0] = 380;
    mBit0Patterns[1] = -825;
    mBit1Patterns[0] = 380;
    mBit1Patterns[1] = -2000;
    mFrameWidth = 55000;

    const int pattern_length = 34;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    // device pattern
    int custom_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(custom_code, 8, false);

    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 8, false);

    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::genPatternMN6014A() {
    mCarrierFrequency = 38000;
    mLsbFirst = true;
    mBit0Patterns[0] = 840;
    mBit0Patterns[1] = -840;
    mBit1Patterns[0] = 840;
    mBit1Patterns[1] = -2520;

    // pattern length
    int pattern_length = 52;
    const int pattern_repeat_count = 1;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    // frame width
    mFrameWidth = 102000;

    // leader code
    mPatterns[mPatternId++] = 3360;
    mPatterns[mPatternId++] = -3360;

    // user code
    int user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 6, false);

    // command pattern
    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 6, false);

    genBytePattern(user_code, 6, true);
    genBytePattern(data_code, 6, true); // ����

    // ending pattern
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    int j = mPatternId - 1;
    for (int i = 1; i < pattern_repeat_count; i++) {
        for (j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[j] = -100000;
}

void PatternGen::genPatternMN6014W_C5D6() {
    mCarrierFrequency = 38000;
    mLsbFirst = true;
    mBit0Patterns[0] = 840;
    mBit0Patterns[1] = -840;
    mBit1Patterns[0] = 840;
    mBit1Patterns[1] = -2520;
    mFrameWidth = 45000;

    // pattern length
    int pattern_length = 48;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    // leader code
    mPatterns[mPatternId++] = 3370;
    mPatterns[mPatternId++] = -3370;

    // user code
    int system_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(system_code, 5, false);

    // command pattern
    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 6, false);

    genBytePattern(system_code, 5, true);
    genBytePattern(data_code, 6, true); // ����

    // ending pattern
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -38220;
    mPatterns[mPatternId++] = align_val;

    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] =  -100000;
}

void PatternGen::genPatternPhilips() {
    mCarrierFrequency = 36000;
    mLsbFirst = false;
    mBit0Patterns[0] = -444;
    mBit0Patterns[1] = 444;
    mBit1Patterns[0] = 444;
    mBit1Patterns[1] = -444;
    mFrameWidth = 108000;

    int pattern_length = 45;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    for (int i = 0; i < pattern_repeat_count; i++) {
        // leader code
        mPatterns[mPatternId++] = 2666;
        mPatterns[mPatternId++] = -889;

        //  code
        genBytePattern(1, 1, false);

        // cut code
        genBytePattern(charToValue(mIrCodes[1]), 3, false);

        // code
        if (mControlCode == 0) {
            mPatterns[mPatternId++] = -889;
            mPatterns[mPatternId++] = 889;
        } else {
            mPatterns[mPatternId++] = 889;
            mPatterns[mPatternId++] = -889;
        }

        // user code
        genBytePattern(charToValue(mIrCodes[2]), 4, false);
        genBytePattern(charToValue(mIrCodes[3]), 4, false);

        // data code
        genBytePattern(charToValue(mIrCodes[4]), 4, false);
        genBytePattern(charToValue(mIrCodes[5]), 4, false);

        mPatterns[mPatternId++] = -84950;
    }
    mPatterns[mPatternId-1] = -100000;

    // code
    if (mControlCode == 0) {
        mControlCode = 1;
    } else {
        mControlCode = 0;
    }
}

void PatternGen::genPatternPhilipsRC6() {

    mCarrierFrequency = 36000;
    mLsbFirst = false;
    mBit0Patterns[0] = -444;
    mBit0Patterns[1] = 444;
    mBit1Patterns[0] = 444;
    mBit1Patterns[1] = -444;
    mFrameWidth = 108000;

    int pattern_length = 78;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    for (int i = 0; i < pattern_repeat_count; i++) {
        // lead code
        mPatterns[mPatternId++] = 2666;
        mPatterns[mPatternId++] = -889;

        // fix code
        mPatterns[mPatternId++] = mBit1Patterns[0];
        mPatterns[mPatternId++] = mBit1Patterns[1];

        // cut code
        int cut_code = charToValue(mIrCodes[1]);
        genBytePattern(cut_code, 3, false);

        // turn code
        // code
        if (mControlCode == 0) {
            mPatterns[mPatternId++] = -889;
            mPatterns[mPatternId++] = 889;
        } else {
            mPatterns[mPatternId++] = 889;
            mPatterns[mPatternId++] = -889;
        }

        // coustom code
        int user_code = (charToValue(mIrCodes[2])<<4) + charToValue(mIrCodes[3]);
        genBytePattern(user_code, 8, false);
        user_code = (charToValue(mIrCodes[4])<<4) + charToValue(mIrCodes[5]);
        genBytePattern(user_code, 8, false);

        //control data
        //int t = charToValue(mIrCodes[6]);
        int t = 0x0a;
        if (mControlCode == 0) {
            t ^= 0x08;
        }
        user_code = (t<<4) + charToValue(mIrCodes[1]);
        genBytePattern(user_code, 8, false);

        // data code
        user_code = (charToValue(mIrCodes[6])<<4) + charToValue(mIrCodes[7]);
        genBytePattern(user_code, 8, false);

        // stop code
        int align_val = -mFrameWidth * i + total_pattern_width();
        mPatterns[mPatternId++] = align_val;
    }
    mPatterns[mPatternId-1] = -100000;

    // code
    if (mControlCode == 0) {
        mControlCode = 1;
    } else {
        mControlCode = 0;
    }

}

void PatternGen::genPatternPioneer() {
    mCarrierFrequency = 40000;
    mLsbFirst = true;
    mBit0Patterns[0] = 536;
    mBit0Patterns[1] = -536;
    mBit1Patterns[0] = 536;
    mBit1Patterns[1] = -1590;
    mFrameWidth = 90000;

    const int pattern_length = 136;
    const int pattern_repeat_count = 1;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    //head code
    mPatterns[mPatternId++] = 8500;
    mPatterns[mPatternId++] = -4250;

    //custom code
    int system_code = (charToValue(mIrCodes[6])<<4) + charToValue(mIrCodes[7]);
    genBytePattern(system_code, 8, false);
    system_code = (charToValue(mIrCodes[4])<<4) + charToValue(mIrCodes[5]);
    genBytePattern(system_code, 8, false);
    system_code = (charToValue(mIrCodes[2])<<4) + charToValue(mIrCodes[3]);
    genBytePattern(system_code, 8, false);
    system_code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(system_code, 8, false);

    //stop code
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    //head code
    mPatterns[mPatternId++] = 8500;
    mPatterns[mPatternId++] = -4250;

    //data code
    int data_code = (charToValue(mIrCodes[14])<<4) + charToValue(mIrCodes[15]);
    genBytePattern(data_code, 8, false);
    data_code = (charToValue(mIrCodes[12])<<4) + charToValue(mIrCodes[13]);
    genBytePattern(data_code, 8, false);
    data_code = (charToValue(mIrCodes[10])<<4) + charToValue(mIrCodes[11]);
    genBytePattern(data_code, 8, false);
    data_code = (charToValue(mIrCodes[8])<<4) + charToValue(mIrCodes[9]);
    genBytePattern(data_code, 8, false);

    //stop code
    mPatterns[mPatternId++] = mBit0Patterns[0];
    align_val = -2 * mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::genPatternPT2268() {
    mCarrierFrequency = 38000;
    mLsbFirst = true;
    mBit0Patterns[0] = 630;
    mBit0Patterns[1] = -1900;
    mBit1Patterns[0] = 1900;
    mBit1Patterns[1] = -630;
    mFrameWidth = 81000;

    const int pattern_length = 49;
    const int pattern_repeat_count = 1;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    // device pattern
    int custom_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(custom_code, 8, false);

    int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 8, false);
    genBytePattern(data_code, 8, false);

    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::genPatternRCA56K() {
    mCarrierFrequency = 38000;
    mLsbFirst = false;
    mBit0Patterns[0] = 500;
    mBit0Patterns[1] = -1000;
    mBit1Patterns[0] = 500;
    mBit1Patterns[1] = -2000;
    mFrameWidth = 64000;

    const int pattern_length = 52;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count);

    // leader code
    mPatterns[mPatternId++] = 4000;
    mPatterns[mPatternId++] = -4000;

    // user code
    genBytePattern(mUserCodes[0], 4, false);

    // data code
    genBytePattern(mDataCodes[0], 8, false);

    // inverse user code
    genBytePattern(mUserCodes[0], 4, true);

    // inverse data code
    genBytePattern(mDataCodes[0], 8, true);

    // stop code
    mPatterns[mPatternId++] = 500;
    mPatterns[mPatternId++] = -8000;

    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::genPatternSAA3010RC5() {
    mCarrierFrequency = 36000;
    mLsbFirst = false;
    mBit0Patterns[0] = 889;
    mBit0Patterns[1] = -889;
    mBit1Patterns[0] = -889;
    mBit1Patterns[1] = 889;
    mFrameWidth = 108000;

    int pattern_length = 30;
    const int pattern_repeat_count = 1;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    int start_code = 3;
    genBytePattern(start_code, 2, false);
    genBytePattern(mControlCode, 1, false);
    int system_code = charToValue(mIrCodes[0]);
    genBytePattern(system_code, 1, false);
    system_code = charToValue(mIrCodes[1]);
    genBytePattern(system_code, 4, false);
    int data_code = charToValue(mIrCodes[2]);
    genBytePattern(data_code, 2, false);
    data_code = charToValue(mIrCodes[3]);
    genBytePattern(data_code, 4, false);
    mPatterns[mPatternId++] = -108000;

    if (mControlCode == 0) {
        mControlCode = 1;
    } else {
        mControlCode = 0;
    }
}

void PatternGen::genPatternSAF1039() {
    mCarrierFrequency = 36000;
    // bit_0, bit_1 definition
    int leader_high = 0;
    int leader_low = 0;
    if (mEncodingType == SAF1039) {
        mBit0Patterns[0] = 450;
        mBit0Patterns[1] = -6750;
        mBit1Patterns[0] = 450;
        mBit1Patterns[1] = -3150;
        leader_high = 450;
        leader_low = -10026;
        // frame width
        mFrameWidth = 110000;
    } else {
        mBit0Patterns[0] = 755;
        mBit0Patterns[1] = -6560;
        mBit1Patterns[0] = 755;
        mBit1Patterns[1] = -3000;
        leader_high = 755;
        leader_low = -10000;
        // frame width
        mFrameWidth = 123000;
    }

    // pattern length
    int pattern_length = 36;
    mPatterns.resize(pattern_length, 0);

    // leader code
    for (int i = 0; i < 3; i++) {
        mPatterns[mPatternId++] = mBit1Patterns[0];
        mPatterns[mPatternId++] = mBit1Patterns[1];
        mPatterns[mPatternId++] = leader_high;
        mPatterns[mPatternId++] = leader_low;
    }
    mPatterns[mPatternId++] = mBit1Patterns[0];
    mPatterns[mPatternId++] = mBit1Patterns[1];

    // data code
    int data_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    if (strlen(mIrCodes) > 2) {
        data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    }
    for (int j = 0; j < 5; j++) {
        bool is_bit_zero = false;
        is_bit_zero = ((data_code & 1) == 0);
        data_code >>= 1;
        if (is_bit_zero) {
            mPatterns[mPatternId++] = mBit0Patterns[0];
            mPatterns[mPatternId++] = mBit0Patterns[1];
        } else {
            mPatterns[mPatternId++] = mBit1Patterns[0];
            mPatterns[mPatternId++] = mBit1Patterns[1];
            mPatterns[mPatternId++] = mBit1Patterns[0];
            mPatterns[mPatternId++] = mBit1Patterns[1];
        }
    }

    // ending pattern
    mPatterns[mPatternId++] = mBit0Patterns[0];
//  int align_val = -mFrameWidth + total_pattern_width();
    int align_val = -108000;
    mPatterns[mPatternId++] = align_val;
    if (mPatternId < pattern_length) {
        std::vector<int> patterns(mPatternId);
        for (int i = 0; i < mPatternId; i++) {
            patterns[i] = mPatterns[i];
        }
        mPatterns = patterns;
    }
}

void PatternGen::genPatternSharp() {
    mCarrierFrequency = 38000;
    mLsbFirst = true;
    mBit0Patterns[0] = 264;
    mBit0Patterns[1] = -786;
    mBit1Patterns[0] = 264;
    mBit1Patterns[1] = -1846;
    mFrameWidth = 67500;

    const int pattern_length = 64;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count);

    genBytePattern(mUserCodes[0], 5, false);
    genBytePattern(mDataCodes[1], 8, false);
    genBytePattern(mDataCodes[0], 2, false);
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -(mFrameWidth - total_pattern_width());
    mPatterns[mPatternId++] = align_val;

    genBytePattern(mUserCodes[0], 5, false);
    genBytePattern(mDataCodes[1], 8, true);
    genBytePattern(mDataCodes[0], 2, true);
    mPatterns[mPatternId++] = mBit0Patterns[0];
    align_val = -(2 * mFrameWidth - total_pattern_width());
    mPatterns[mPatternId++] = align_val;

    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::genPatternT36() {
    mCarrierFrequency = 38000;
    mLsbFirst = true;
    mBit0Patterns[0] = 500;
    mBit0Patterns[1] = -500;
    mBit1Patterns[0] = 500;
    mBit1Patterns[1] = -1500;
    mFrameWidth = 120000;

    int pattern_length = 78;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    for (int i = 1; i <= pattern_repeat_count; i++) {
        // leader code
        mPatterns[mPatternId++] = 4500;
        mPatterns[mPatternId++] = -4500;

        //  sys_code
        int custom_code = (charToValue(mIrCodes[4]) << 4) + charToValue(mIrCodes[5]);
        genBytePattern(custom_code, 8, false);
        custom_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
        genBytePattern(custom_code, 8, false);

        // separation period
        mPatterns[mPatternId++] = 500;
        mPatterns[mPatternId++] = -4500;

        int product_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
        genBytePattern(product_code, 4, false);

        int data_code = (charToValue(mIrCodes[6]) << 4) + charToValue(mIrCodes[7]);
        genBytePattern(data_code, 8, false);
        genBytePattern(data_code, 8, true);

        // stop code
        mPatterns[mPatternId++] = 500;
        mPatterns[mPatternId++] = -mFrameWidth * i + total_pattern_width();
    }
    mPatterns[mPatternId-1] = -100000;
}

void PatternGen::genPatternTC9012() {
    // bit_0, bit_1 definition
    mBit0Patterns[0] = 560;
    mBit0Patterns[1] = -560;
    mBit1Patterns[0] = 560;
    mBit1Patterns[1] = -1680;

    // pattern length
//  int pattern_length = 68;
    int pattern_length = 74;
    mFrameWidth = 108000;
    mPatterns.resize(pattern_length, 0);

    // leading pattern
    mPatterns[mPatternId++] = 4500;
    mPatterns[mPatternId++] = -4500;


    // user code
    int user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 8, false);
    user_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(user_code, 8, false); // ͬ��

    // data code
    int data_code = (charToValue(mIrCodes[4]) << 4) + charToValue(mIrCodes[5]);
    genBytePattern(data_code, 8, false);
    genBytePattern(data_code, 8, true); // ����

    // ending pattern
    mPatterns[mPatternId++] = 560;
    mPatterns[mPatternId++] = -46920;

    mPatterns[mPatternId++] = 4500;
    mPatterns[mPatternId++] = -4500;
    mPatterns[mPatternId++] = 560;
    if (user_code & 0x1) {
        mPatterns[mPatternId++] = -560;
    } else {
        mPatterns[mPatternId++] = -1680;
    }
    mPatterns[mPatternId++] = 560;
    mPatterns[mPatternId++] = -96200;
}

void PatternGen::genPatternTC9012F() {
    // bit_0, bit_1 definition
    mBit0Patterns[0] = 560;
    mBit0Patterns[1] = -560;
    mBit1Patterns[0] = 560;
    mBit1Patterns[1] = -1680;

    // pattern length
    int pattern_length = 136;
    mFrameWidth = 108000;
    mPatterns.resize(pattern_length, 0);

    for (int i = 1; i <= 2; i++) {
        // leading pattern
        mPatterns[mPatternId++] = 4500;
        mPatterns[mPatternId++] = -4500;

        // user code
        int user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
        genBytePattern(user_code, 8, false);
        user_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
        genBytePattern(user_code, 8, false); // ͬ��

        // data code
        int data_code = (charToValue(mIrCodes[4]) << 4) + charToValue(mIrCodes[5]);
        genBytePattern(data_code, 8, false);
        genBytePattern(data_code, 8, true); // ����

        // ending pattern
        mPatterns[mPatternId++] = 564;
        int align_val = -mFrameWidth * i + total_pattern_width();
        mPatterns[mPatternId++] = align_val;
    }
    mPatterns[pattern_length-1] = -96200;
}

void PatternGen::genPatternThomson() {
    mCarrierFrequency = 33300;
    mLsbFirst = false;
    mBit0Patterns[0] = 458;
    mBit0Patterns[1] = -2061;
    mBit1Patterns[0] = 458;
    mBit1Patterns[1] = -4580;
    mFrameWidth = 80000;

    // user code
    genBytePattern(mUserCodes[0], 4, false);

    // control code
    genBytePattern(mUserCodes[0], 1, false);
    /*genBytePattern(mControlCode, 1, false);
      if (mControlCode == 0) {
      mControlCode = 1;
      } else {
      mControlCode = 0;
      }*/

    // data code
    genBytePattern(mDataCodes[0], 7, false);

    // stop code
    mPatterns[mPatternId++] = 458;
//  int align_val = -mFrameWidth + total_pattern_width();
    int align_val = -100000;
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genPatternTOPWAY() {
    mCarrierFrequency = 38000;
    mBit0Patterns[0] = 560;
    mBit0Patterns[1] = -560;
    mBit1Patterns[0] = 560;
    mBit1Patterns[1] = -1120;

    const int pattern_length = 86;
    mPatterns.resize(pattern_length, 0);

    // leader code
    mPatterns[mPatternId++] = 6000;
    mPatterns[mPatternId++] = -2000;

    // custom code
    int cust_code_1 = (charToValue(mIrCodes[4])<<4) + charToValue(mIrCodes[5]);
    genBytePattern(cust_code_1, 8, false);
    int cust_code_2 = (charToValue(mIrCodes[2])<<4) + charToValue(mIrCodes[3]);
    genBytePattern(cust_code_2, 8, false);

    // data code
    int data_code = (charToValue(mIrCodes[6])<<4) + charToValue(mIrCodes[7]);
    genBytePattern(data_code, 8, false);

    //separation period
    mPatterns[mPatternId++] = 3640;
    mPatterns[mPatternId++] = -3640;

    // control code
    int cont_code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(cont_code, 8, false);

    // data code
    genBytePattern(data_code, 8, true);

    // stop code
    mPatterns[mPatternId++] = 560;
    mPatterns[mPatternId++] = -100000;
}

void PatternGen::genPatternuPD6124() {
    mCarrierFrequency = 40000;
    mLsbFirst = true;
    mBit0Patterns[0] = -600;
    mBit0Patterns[1] = 600;
    mBit1Patterns[0] = -600;
    mBit1Patterns[1] = 1200;
    mFrameWidth = 45000;

    const int pattern_length = 26;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    //head code
    mPatterns[mPatternId++] = 2400;

    //custom code
    int data_code = (charToValue(mIrCodes[2])<<4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 7, false);
    int system_code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(system_code, 5, false);

    //stop code
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::genPatternuPD6124_D7C8() {
    mCarrierFrequency = 40000;
    mLsbFirst = true;
    mBit0Patterns[0] = -600;
    mBit0Patterns[1] = 600;
    mBit1Patterns[0] = -600;
    mBit1Patterns[1] = 1200;
    mFrameWidth = 45000;

    const int pattern_length = 32;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    //head code
    mPatterns[mPatternId++] = 2400;

    //custom code
    int data_code = (charToValue(mIrCodes[2])<<4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 7, false);
    int system_code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(system_code, 8, false);

    //stop code
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::genPatternuPD6124_D7C13() {
    mCarrierFrequency = 40000;
    mLsbFirst = true;
    mBit0Patterns[0] = -600;
    mBit0Patterns[1] = 600;
    mBit1Patterns[0] = -600;
    mBit1Patterns[1] = 1200;
    mFrameWidth = 45000;

    const int pattern_length = 42;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    //head code
    mPatterns[mPatternId++] = 2400;

    //custom code
    int data_code = (charToValue(mIrCodes[4])<<4) + charToValue(mIrCodes[5]);
    genBytePattern(data_code, 7, false);
    int custom_code = (charToValue(mIrCodes[2])<<4) + charToValue(mIrCodes[3]);
    genBytePattern(custom_code, 8, false);
    custom_code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(custom_code, 5, false);

    //stop code
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::genPatternuPD6121F() {
    mCarrierFrequency = 38000;
    mLsbFirst = true;
    mBit0Patterns[0] = 560;
    mBit0Patterns[1] = -560;
    mBit1Patterns[0] = 560;
    mBit1Patterns[1] = -1680;
    mFrameWidth = 108000;

    const int pattern_length = 68;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    // leader code
    mPatterns[mPatternId++] = 9000;
    mPatterns[mPatternId++] = -4500;

    // user code
    int user_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(user_code, 8, false);
    user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 8, false);

    // command pattern
    int data_code = (charToValue(mIrCodes[4]) << 4) + charToValue(mIrCodes[5]);
    genBytePattern(data_code, 8, false);
    genBytePattern(data_code, 8, true);

    // ending pattern
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::genPatternuPD6121G() {
    // bit_0, bit_1 definition
    mBit0Patterns[0] = 560;
    mBit0Patterns[1] = -560;
    mBit1Patterns[0] = 560;
    mBit1Patterns[1] = -1680;

    // pattern length
    int pattern_length = 72;
    mPatterns.resize(pattern_length, 0);

    // fram width
    mFrameWidth = 108000;

    // leader code
    mPatterns[mPatternId++] = 9000;
    mPatterns[mPatternId++] = -4500;

    // user code
    int user_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(user_code, 8, false);
    user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 8, false);

    // command pattern
    int data_code = (charToValue(mIrCodes[4]) << 4) + charToValue(mIrCodes[5]);
    genBytePattern(data_code, 8, false);
    genBytePattern(data_code, 8, true);

    // ending pattern
    mPatterns[mPatternId++] = mBit0Patterns[0];
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    mPatterns[mPatternId++] = 9000;
    mPatterns[mPatternId++] = -2250;
    mPatterns[mPatternId++] = 560;
    align_val = -96190;
    mPatterns[mPatternId++] = align_val;
}

void PatternGen::genPatternuPD6121G001() {
    // bit_0, bit_1 definition
    mBit0Patterns[0] = 560;
    mBit0Patterns[1] = -560;
    mBit1Patterns[0] = 560;
    mBit1Patterns[1] = -1680;

    // pattern length
    int pattern_length = 72;
    mPatterns.resize(pattern_length, 0);

    // fram width
    mFrameWidth = 216000;

    // leader code
    mPatterns[mPatternId++] = 9000;
    mPatterns[mPatternId++] = -4500;

    // user code
    int user_code = (charToValue(mIrCodes[4]) << 4) + charToValue(mIrCodes[5]);
    genBytePattern(user_code, 8, false);
    user_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
    genBytePattern(user_code, 8, false);
    user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
    genBytePattern(user_code, 8, false);

    // command pattern
    int data_code = (charToValue(mIrCodes[6]) << 4) + charToValue(mIrCodes[7]);
    genBytePattern(data_code, 8, false);

    mPatterns[mPatternId++] = 560;
    mPatterns[mPatternId++] = -40180;
    mPatterns[mPatternId++] = 9000;
    mPatterns[mPatternId++] = -2250;
    mPatterns[mPatternId++] = 560;
//  int align_val = -mFrameWidth + total_pattern_width();
//  mPatterns[mPatternId++] = align_val;
    mPatterns[mPatternId++] = -100000;
}


void PatternGen::genPatternVictorC8D8() {
    mCarrierFrequency = 38000;
    mLsbFirst = true;
    mBit0Patterns[0] = 526;
    mBit0Patterns[1] = -526;
    mBit1Patterns[0] = 526;
    mBit1Patterns[1] = -1578;
    mFrameWidth = 58900;

    const int pattern_length = 36;
    const int pattern_repeat_count = 1;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    //head code
    mPatterns[mPatternId++] = 8420;
    mPatterns[mPatternId++] = -4210;

    //custom code
    int cust_code = (charToValue(mIrCodes[0])<<4) + charToValue(mIrCodes[1]);
    genBytePattern(cust_code, 8, false);

    //data code
    int data_code = (charToValue(mIrCodes[2])<<4) + charToValue(mIrCodes[3]);
    genBytePattern(data_code, 8, false);

    //stop code
    mPatterns[mPatternId++] = 526;
    int align_val = -mFrameWidth + total_pattern_width();
    mPatterns[mPatternId++] = align_val;

    for (int i = 1; i < pattern_repeat_count; i++) {
        for (int j = pattern_length * i; j < pattern_length * i + pattern_length; j++) {
            mPatterns[j] = mPatterns[j-pattern_length];
        }
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}

void PatternGen::genPatternXYJaecs() {
    // bit_0, bit_1 definition
    mBit0Patterns[0] = 1200;
    mBit0Patterns[1] = -1200;
    mBit1Patterns[0] = 1200;
    mBit1Patterns[1] = -2900;
    mFrameWidth = 112500;

    // pattern length
    const int pattern_length = 36;
    const int pattern_repeat_count = 2;
    mPatterns.resize(pattern_length*pattern_repeat_count, 0);

    for (int i = 1; i <= pattern_repeat_count; ++i) {
        // leading pattern
        mPatterns[mPatternId++] = 2690;
        mPatterns[mPatternId++] = -2560;

        // user & data code
        int user_code = (charToValue(mIrCodes[0]) << 4) + charToValue(mIrCodes[1]);
        genBytePattern(user_code, 8, false);
        int data_code = (charToValue(mIrCodes[2]) << 4) + charToValue(mIrCodes[3]);
        genBytePattern(data_code, 8, false);

        // stop code
        mPatterns[mPatternId++] = mBit0Patterns[0];
        mPatterns[mPatternId++] = -57760;
    }
    mPatterns[pattern_length*pattern_repeat_count-1] = -100000;
}


//Todo: 此处为临时添加的代码，需要找mike看
void PatternGen::genGree9Pattern() {

}

void PatternGen::genKelon2Pattern() {
}

void PatternGen::genKelon4Pattern() {

}
void PatternGen::genDaikin3Pattern() {

}

void PatternGen::genMhi09nvPattern(){

}

void PatternGen::genToshiba1Pattern(){

}