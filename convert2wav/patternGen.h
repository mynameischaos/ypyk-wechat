//
// Created by Anccerson on 3/3/16.
//

#ifndef CONVERT2WAV_PATTERNGEN_H
#define CONVERT2WAV_PATTERNGEN_H
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "encodingInterface.h"

#ifndef _PATTERN_GEN_H_
#define _PATTERN_GEN_H_



class PatternGen {
public:
    enum ACDataIndex {
        kIndexButtonId = 0,
        kIndexAdditional = 2,
        kIndexMode = 4,
        kIndexPower = 5,
        kIndexWind = 6,
        kIndexVerSwept = 7,
        kIndexHorSwept = 8,
        kIndexSleep = 9,
        kIndexTemp = 10,
        kIndexSuper = 11,
        kIndexLight = 12,
        kIndexHealthy = 13,
        kIndexDry = 14,
        kIndexVentilate = 15,
        kIndexEnergy = 16,
        kIndexTimer = 17,
        kIndexUndef = 19
    };

    enum ACButtonID {
        kMode = 0x0, 				//* button_id = 0 --> mode flag
        kPower = 0x1,				//* button_id = 1 --> power
        kWind = 0x2,				//* button_id = 2 --> wind velocity
        kVerSwept = 0x3, 			//* button_id = 3 --> top bottom swept
        kHorSwept = 0x4,			//* button_id = 4 --> left right swept
        kSleep = 0x5,				//* button_id = 5 --> sleeping
        kSuper = 0x6,				//* button_id = 6 --> super
        kLight = 0x7,				//* button_id = 7 --> light
        kHealthy = 0x8,			//* button_id = 8 --> healthy
        kDry = 0x9,				//* button_id = 9 --> dry
        kPPT = 0x0A,				//* button_id = A --> push to talk
        kTimer = 0x0B,			//* button_id = B --> timer
        kHeat = 0x0C,				//* button_id = C --> auxiliary heat
        kSmart = 0x0D,			//* button_id = D --> smart
        kVentilate = 0x10,		//* button_id = 10 --> ventilate
        kEnergy = 0x11,			//* button_id = 11 --> energy Saving
        kTempUp = 0x12,			//* button_id = 12 --> temperature+
        kTempDown = 0x13,			//* button_id = 13 --> temperature-
        kUndefine = 0x14
    };

    enum ACMode {
        kModeAuto = 0x0,			// auto
        kModeCool = 0x1,			// cool
        kModeWet  = 0x2,			// wet
        kModeWind = 0x3, 			// wind
        kModeHot  = 0x4,			// hot
        kModeUndef= 0x5
    };

    enum ACWind {
        kWindAuto = 0x0,
        kWindStrong = 0x1,
        kWindSlight = 0x2,
        kWindBreeze = 0x3,
        kWindUndef = 0x4
    };

    enum ACSwept {
        kSweptAuto = 0x0,
        kSweptAngle15 = 0x1,
        kSweptAngle45 = 0x2,
        kSweptAngle75 = 0x3,
        kSweptUndef = 0x4
    };
public:
    PatternGen() {
        mEncodingType = UNKOWN;
        mCarrierFrequency = 38000;
        mBit0Patterns = new int[4];
        mBit0Patterns[0] = mBit0Patterns[1] = 0;
        mBit1Patterns = new int[4];
        mBit1Patterns[0] = mBit1Patterns[1] = 0;
        mLsbFirst = true;
        mIrCodeLength = 0;
        mIrCodeReserveLength = 16;
        mIrCodes = new char[mIrCodeReserveLength];
        mControlCode = 0;
        mUserCodeLength = 0;
        mUserCodeReserveLength = 4;
        mUserCodes = new int[mUserCodeReserveLength];
        mDataCodeLength = 0;
        mDataCodeReserveLength = 4;
        mDataCodes = new int[mDataCodeReserveLength];
        mFrameWidth = 108000;
        mPatternId = 0;
        mPostProcess = true;
        mCurrentState = std::string("");
    }

    ~PatternGen() {
        if (mBit0Patterns) delete mBit0Patterns;
        if (mBit1Patterns) delete mBit1Patterns;
        if (mIrCodes) delete mIrCodes;
        if (mUserCodes) delete mUserCodes;
        if (mDataCodes) delete mDataCodes;
    }

public:
    void setPostProcess(bool flag) {
        mPostProcess = flag;
    }

    int carrier_frequency() {
        return mCarrierFrequency;
    }

    std::string getState() {
        return mCurrentState;
    }

    int pattern(int i) {
        return mPatterns[i];
    }

    std::vector<int>& patterns() {
        return mPatterns;
    }

    bool isEncodingTypeSupported(EncodingInterface encoding_type);
    bool genPattern(std::string encoding, std::string ir_code);

private:
    int total_pattern_width();
    bool genPattern(EncodingInterface encoding_type, std::string ir_code);
    void init();
    bool parseIRCode(std::string ir_code);
    int findStepToNextSpaceOrEnd(std::string string, int index);
    void genBytePattern(int code, int bit_count, bool use_inverse_code);
    void genDoubleBytesPattern(int code, int bit_count, bool use_inverse_code);
    std::string HexToChar(int c, bool inverse = false);
    int charToValue(char c);
    void postProcess();

private:
    void gen6121Pattern();
    void genTC9012Pattern();
    void gen7461MPattern();
    void genLR3715MPattern();
    void genIX0773CEPattern();
    void genM3004CarrierPattern();
    void genM3004FlashPattern();
    void gen3010_RC5Pattern();
    void gen6124Pattern();
    void genSAA1250Pattern();
    void gen50560Pattern();
    void gen50560B1Pattern();
    void genKonkaPattern();
    void gen34280Pattern();
    void genRecs80Pattern();
    void genPanasonicPattern();
    void genGeminiPattern();
    void genGeminiC6P317Pattern();
    void genRCAPattern();
    void genThomsonPattern();
    void genIRT1250C5D6Pattern();
    void genIRT1250C5D7Pattern();
    void genM7080Pattern();
    void genHtsC5D6PPattern();
    void genPhilipsPattern();
    void genSDA2208Pattern();
    void genM58480Pattern();
    void genSAF1039Pattern();
    void genC8D8Pattern();
    void genWuxiPattern();
    void genIRMediaMousePattern();
    void genMn6014Pattern();
    void genUpd1986Pattern();
    void genM50119LPattern();
    void genM50119PPattern();
    void genVictorC8D8Pattern();
    void genMn6014wC5D6Pattern();
    void genMitC8D8Pattern();
    void genMv50002Pattern();
    void genCL311Unknown7Pattern();
    void genTc9012ffPattern();
    void genRC6BPattern();
    void genGeminiC1710Pattern();
    void genUpd1986ccPattern();
    void genYIPAI321Pattern();
    void genYIPAI331Pattern();
    void genM584802Pattern();
    void genGrundigDvdPattern();
    void genSZMGPattern();
    void genXiaomiPattern();

private:
    void genGree9Pattern();
    void genKelon2Pattern();
    void genKelon4Pattern();
    void genToshiba1Pattern();
    void genDaikin3Pattern();
    void genMhi09nvPattern();

private:
    void genPatternDVB40BIT();
    void genPatternDVBPanSamsung();

    void genPatternGemini();

    void genPatternJQ16_018();

    void genPatternKonka();

    void genPatternLC7461M();
    void genPatternLC7461MPanasonic();
    void genPatternLG3004();

    void genPatternM3004Carrier();
    void genPatternM50119P();
    void genPatternM50462();
    void genPatternM50560();
    void genPatternM9148();
    void genPatternMiBox();
    void genPatternMITC8D8();
    void genPatternMN6014A();
    void genPatternMN6014W_C5D6();

    void genPatternPhilips();
    void genPatternPhilipsRC6();
    void genPatternPioneer();
    void genPatternPT2268();

    void genPatternRCA56K();

    void genPatternSAA3010RC5();
    void genPatternSAF1039();
    void genPatternSharp();

    void genPatternT36();
    void genPatternTC9012();
    void genPatternTC9012F();
    void genPatternThomson();
    void genPatternTOPWAY();

    void genPatternuPD6124();
    void genPatternuPD6124_D7C8();
    void genPatternuPD6124_D7C13();
    void genPatternuPD6121F();
    void genPatternuPD6121G();
    void genPatternuPD6121G001();

    void genPatternVictorC8D8();

    void genPatternXYJaecs();

private:
    EncodingInterface mEncodingType;
    int mCarrierFrequency;
    int* mBit0Patterns;
    int* mBit1Patterns;
    bool mLsbFirst; // lsb_first ?
    char *mIrCodes; // std::string format, each char is 4 bit
    int mIrCodeLength;
    int mUserCodeLength;
    int mDataCodeLength;
    int mIrCodeReserveLength;

    int mControlCode;
    // mike: below should be an "unsigned char", but this is not support in java,
    // have to use int instead, but i only use last 8 bits
    int *mUserCodes; // binary format, each char is 8 bit
    int mUserCodeReserveLength;
    // mike: below should be an "unsigned char", but this is not support in java,
    // have to use int instead, but i only use last 8 bits
    int *mDataCodes; // binary format, each char is 8 bit
    int mDataCodeReserveLength;
    int mFrameWidth;

    std::vector<int> mPatterns;
    int mPatternId;

    bool mPostProcess;

    std::string mCurrentState;
};

#endif

#endif //CONVERT2WAV_PATTERNGEN_H
