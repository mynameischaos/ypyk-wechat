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

int PatternGen::total_pattern_width() {
    int width = 0;
    for (int i = 0; i < mPatternId; i++) {
        width += (pattern(i) > 0) ? pattern(i) : -pattern(i);
    }
    return width;
}


bool PatternGen::genPattern(std::string encoding, std::string ir_code) {
    if (strcmp(encoding.c_str(), "DVB-40BIT") == 0) {
        mEncodingType = PANASONIC_1;
        init();
        parseIRCode(ir_code);
        genPatternDVB40BIT();
    } else if (strcmp(encoding.c_str(), "DVB/Pan 7051/SAMSUNG") == 0) {
        mEncodingType = PANASONIC_1;
        init();
        parseIRCode(ir_code);
        genPatternDVBPanSamsung();
    } else if (strcmp(encoding.c_str(), "Gemini-C10 (31.36K)") == 0) {
        mEncodingType = SDA2208_3;
        init();
        parseIRCode(ir_code);
        genPatternGemini();
    } else if (strcmp(encoding.c_str(), "JQ16-018") == 0) {
        mEncodingType = KONKA_Y26;
        init();
        parseIRCode(ir_code);
        genPatternJQ16_018();
    } else if (strcmp(encoding.c_str(), "KONKA KK-Y261") == 0) {
        mEncodingType = KONKA_Y26;
        init();
        parseIRCode(ir_code);
        genPatternKonka();
    } else if (strcmp(encoding.c_str(), "LC7461M-C13") == 0) {
        mEncodingType = LC7461M_C13;
        init();
        parseIRCode(ir_code);
        genPatternLC7461M();
    } else if (strcmp(encoding.c_str(), "LC7464M Panasonic") == 0) {
        mEncodingType = LC7461M_C13;
        init();
        parseIRCode(ir_code);
        genPatternLC7461MPanasonic();
    } else if (strcmp(encoding.c_str(), "LG3004/6C(33K)") == 0) {
        mEncodingType = M3004_CARRIER;
        init();
        parseIRCode(ir_code);
        genPatternLG3004();
    } else if (strcmp(encoding.c_str(), "M3004/6C LAB1") == 0) {
        mEncodingType = M3004_CARRIER;
        init();
        parseIRCode(ir_code);
        genPatternM3004Carrier();
    } else if (strcmp(encoding.c_str(), "M50119P") == 0) {
        mEncodingType = M34280;
        init();
        parseIRCode(ir_code);
        genPatternM50119P();
    } else if (strcmp(encoding.c_str(), "M50462") == 0) {
        mEncodingType = M34280;
        init();
        parseIRCode(ir_code);
        genPatternM50462();
    } else if (strcmp(encoding.c_str(), "M50560") == 0) {
        mEncodingType = M34280;
        init();
        parseIRCode(ir_code);
        genPatternM50560();
    } else if (strcmp(encoding.c_str(), "M50560-001P -003P") == 0) {
        mEncodingType = SC50560_3P;
        init();
        parseIRCode(ir_code);
        gen50560Pattern();
    } else if (strcmp(encoding.c_str(), "M9148") == 0) {
        mEncodingType = UPD6124_D7C13_40K;
        init();
        parseIRCode(ir_code);
        genPatternM9148();
    } else if (strcmp(encoding.c_str(), "MiBox") == 0) {
        mEncodingType = UPD6124_D7C13_40K;
        init();
        parseIRCode(ir_code);
        genPatternMiBox();
    } else if (strcmp(encoding.c_str(), "MIT-C8D8") == 0) {
        mEncodingType = UPD6124_D7C13_40K;
        init();
        parseIRCode(ir_code);
        genPatternMITC8D8();
    } else if (strcmp(encoding.c_str(), "MN6014A/W-C6D6") == 0) {
        mEncodingType = MN6014AW_C6D6;
        init();
        parseIRCode(ir_code);
        genPatternMN6014A();
    } else if (strcmp(encoding.c_str(), "MN6014W-C5D6") == 0) {
        mEncodingType = MN6014AW_C6D6;
        init();
        parseIRCode(ir_code);
        genPatternMN6014W_C5D6();
    } else if (strcmp(encoding.c_str(), "PHILIPS") == 0) {
        mEncodingType = PHILIPS_RC6;
        init();
        parseIRCode(ir_code);
        genPatternPhilips();
    } else if (strcmp(encoding.c_str(), "PHILIPS RC-6") == 0) {
        mEncodingType = RC_6B;
        init();
        parseIRCode(ir_code);
        genPatternPhilipsRC6();
    } else if (strcmp(encoding.c_str(), "Pioneer") == 0) {
        mEncodingType = PHILIPS_RC6;
        init();
        parseIRCode(ir_code);
        genPatternPioneer();
    } else if (strcmp(encoding.c_str(), "PT2268") == 0) {
        mEncodingType = UPD6124_D7C13_40K;
        init();
        parseIRCode(ir_code);
        genPatternPT2268();
    } else if (strcmp(encoding.c_str(), "RCA (56K)") == 0) {
        mEncodingType = RCA_56K;  // 6-bit
        init();
        parseIRCode(ir_code);
        genPatternRCA56K();
    } else if (strcmp(encoding.c_str(), "SAA3010 RC-5") == 0) {
        mEncodingType = SAA3010_RC5_36K;  // 6-bit
        init();
        parseIRCode(ir_code);
        genPatternSAA3010RC5();
    } else if (strcmp(encoding.c_str(), "SAF1039") == 0) {
        mEncodingType = SAF1039_1;
        init();
        parseIRCode(ir_code);
        genPatternSAF1039();
    } else if (strcmp(encoding.c_str(), "Sharp(IX0773CE)") == 0) {
        mEncodingType = LR3715M;
        init();
        parseIRCode(ir_code);
        genPatternSharp();
    } else if (strcmp(encoding.c_str(), "T36") == 0) {
        mEncodingType = UPD6121G;
        init();
        parseIRCode(ir_code);
        genPatternT36();
    } else if (strcmp(encoding.c_str(), "TC9012") == 0) {
        mEncodingType = UPD6121G;
        init();
        parseIRCode(ir_code);
        genPatternTC9012();
    } else if (strcmp(encoding.c_str(), "TC9012F") == 0) {
        mEncodingType = UPD6121G;
        init();
        parseIRCode(ir_code);
        genPatternTC9012F();
    } else if (strcmp(encoding.c_str(), "THOMSON RCT311") == 0) {
        mEncodingType = THOMSON;
        init();
        parseIRCode(ir_code);
        genPatternThomson();
    } else if (strcmp(encoding.c_str(), "TOPWAY-HDDVB") == 0) {
        mEncodingType = SZMG;
        init();
        parseIRCode(ir_code);
        genPatternTOPWAY();
    } else if (strcmp(encoding.c_str(), "uPD6121F") == 0) {
        mEncodingType = UPD6121G;
        init();
        parseIRCode(ir_code);
        genPatternuPD6121F();
    } else if (strcmp(encoding.c_str(), "uPD6121G") == 0) {
        mEncodingType = UPD6121G;
        init();
        parseIRCode(ir_code);
        genPatternuPD6121G();
    } else if (strcmp(encoding.c_str(), "uPD6121G-001") == 0) {
        mEncodingType = UPD6121G;
        init();
        parseIRCode(ir_code);
        genPatternuPD6121G001();
    } else if (strcmp(encoding.c_str(), "uPD6124") == 0) {
        mEncodingType = UPD6121G;
        init();
        parseIRCode(ir_code);
        genPatternuPD6124();
    } else if (strcmp(encoding.c_str(), "uPD6124-D7C13") == 0) {
        mEncodingType = UPD6121G;
        init();
        parseIRCode(ir_code);
        genPatternuPD6124_D7C13();
    } else if (strcmp(encoding.c_str(), "uPD6124-D7C8") == 0) {
        mEncodingType = UPD6121G;
        init();
        parseIRCode(ir_code);
        genPatternuPD6124_D7C8();
    } else if (strcmp(encoding.c_str(), "Victor-C8D8") == 0) {
        mEncodingType = VICTOR_C8D8;
        init();
        parseIRCode(ir_code);
        genPatternVictorC8D8();
    } else if (strcmp(encoding.c_str(), "XY JAECS") == 0) {
        mEncodingType = XY_JAECS;
        init();
        parseIRCode(ir_code);
        genPatternXYJaecs();
    } else {
        EncodingInterface encoding_type =
                static_cast<EncodingInterface>(atoi(encoding.c_str()));
        return genPattern(encoding_type, ir_code);
    }

    if (mPostProcess) {
        postProcess();
    }
    return true;
}

bool PatternGen::genPattern(EncodingInterface encoding_type, std::string ir_code) {
    if (!isEncodingTypeSupported(encoding_type)) {
        return false;
    }
    mEncodingType = encoding_type;
    init();

    parseIRCode(ir_code);

    // special handling
    switch (mEncodingType) {
        case UPD6121G:
        case UPD6121G_F:
        case UPD6121G_001:
            gen6121Pattern();
            break;
        case TC9012:
        case TC9012_2:
        case TC9012_F:
        case TC9012_S:
        case TC9012_A:
            genTC9012Pattern();
            break;
        case LC7461M_C13:
        case LC7461M_C13_F:
            gen7461MPattern();
            break;
        case LR3715M:
            genLR3715MPattern();
            break;
        case IX0773CE:
            genIX0773CEPattern();
            break;
        case M3004_CARRIER:
            genM3004CarrierPattern();
            break;
        case M3004_FLASH:
            genM3004FlashPattern();
            break;
        case SAA3010_RC5_36K:
        case SAA3010_RC5:
        case SC3010_RC5:
            gen3010_RC5Pattern();
            break;
        case UPD6124_40K:
        case UPD6124_D7C8:
        case UPD6124_D7C13_40K:
        case UPD6124_D7C13:
            gen6124Pattern();
            break;
        case SAA1250:
            genSAA1250Pattern();
            break;
        case M50560:
        case M50560_1:
        case SC50560_2P:
        case SC50560_3P:
            gen50560Pattern();
            break;
        case SC50560_B1:
            gen50560B1Pattern();
            break;
        case KONKA_Y26:
            genKonkaPattern();
            break;
        case M34280:
            gen34280Pattern();
            break;
        case RECS80:
            genRecs80Pattern();
            break;
        case PANASONIC_1:
            genPanasonicPattern();
            break;
        case GEMINI_C17:
            genGeminiPattern();
            break;
        case GEMINI_C6_317:
            genGeminiC6P317Pattern();
            break;
        case RCA_56K:
            genRCAPattern();
            break;
        case THOMSON:
            genThomsonPattern();
            break;
        case IRT1250C5D6:
            genIRT1250C5D6Pattern();
            break;
        case IRT1250C5D7:
            genIRT1250C5D7Pattern();
            break;
        case M708_0:
            genM7080Pattern();
            break;
        case HTS_C5D6P:
            genHtsC5D6PPattern();
            break;
        case PHILIPS_RC6:
            genPhilipsPattern();
            break;
        case SDA2208_3:
            genSDA2208Pattern();
            break;
        case M58480:
            genM58480Pattern();
            break;
        case SAF1039:
        case SAF1039_1:
            genSAF1039Pattern();
            break;
        case C8D8_E:
            genC8D8Pattern();
            break;
        case WUXI_STB:
        case APEX_1:
            genWuxiPattern();
            break;
        case XY_JAECS:
            genPatternXYJaecs();
            break;
        case IRMEDIA_MOUSE:
            genIRMediaMousePattern();
            break;
        case MN6014AW_C6D6:
            genMn6014Pattern();
            break;
        case UPD1986C:
            genUpd1986Pattern();
            break;
        case M50119L:
            genM50119LPattern();
            break;
        case M50119P_1_40K:
            genM50119PPattern();
            break;
        case VICTOR_C8D8:
            genVictorC8D8Pattern();
            break;
        case MN6014W_C5D6:
            genMn6014wC5D6Pattern();
            break;
        case MIT_C8D8:
            genMitC8D8Pattern();
            break;
        case MV500_02:
            genMv50002Pattern();
            break;
        case CL311_UNKNOWN_7:
            genCL311Unknown7Pattern();
            break;
        case TC9012_FF:
            genTc9012ffPattern();
            break;
        case RC_6B:
            genRC6BPattern();
            break;
        case GEMINI_C17_10:
            genGeminiC1710Pattern();
            break;
        case UPD1986C_C:
            genUpd1986ccPattern();
            break;
        case YIPAI_321:
            genYIPAI321Pattern();
            break;
        case YIPAI_331:
            genYIPAI331Pattern();
            break;
        case M584802:
            genM584802Pattern();
            break;
        case GRUNDIG_DVD:
            genGrundigDvdPattern();
            break;
        case SZMG:
            genSZMGPattern();
            break;
        case MIBOX:
            genXiaomiPattern();
            break;
        case GREE9:
            genGree9Pattern();
            break;
        case KELON2:
            genKelon2Pattern();
            break;
        case KELON4:
            genKelon4Pattern();
            break;
        case TOSHIBA1:
            genToshiba1Pattern();
            break;
        case DAIKIN3:
            genDaikin3Pattern();
            break;
        case MHI_09NV:
            genMhi09nvPattern();
            break;
        default:
            break;
    }

    if (mPostProcess) {
        postProcess();
    }
    return true;
}

bool PatternGen::isEncodingTypeSupported(EncodingInterface encoding_type) {
    switch (encoding_type) {
        case UPD6121G:
        case UPD6121G_F:
        case UPD6121G_001:
        case TC9012:
        case TC9012_2:
        case TC9012_F:
        case TC9012_S:
        case TC9012_A:
        case M50560:
        case M50560_1:
        case SC50560_2P:
        case SC50560_3P:
        case SC50560_B1:
        case LC7461M_C13:
        case LC7461M_C13_F:
        case LR3715M:
        case IX0773CE:
        case M3004_CARRIER:
        case M3004_FLASH:
        case SAA1250:
        case SAA3010_RC5:
        case SAA3010_RC5_36K:
        case SC3010_RC5:
        case UPD6124_40K:
        case UPD6124_D7C8:
        case UPD6124_D7C13_40K:
        case UPD6124_D7C13:
        case KONKA_Y26:
        case M34280:
        case RECS80:
        case PANASONIC_1:
        case GEMINI_C17:
        case GEMINI_C6_317:
        case RCA_56K:
        case THOMSON:
        case IRT1250C5D6:
        case IRT1250C5D7:
        case M708_0:
        case HTS_C5D6P:
        case PHILIPS_RC6:
        case SDA2208_3:
        case M58480:
        case SAF1039:
        case SAF1039_1:
        case C8D8_E:
        case WUXI_STB:
        case APEX_1:
        case XY_JAECS:
        case IRMEDIA_MOUSE:
        case MN6014AW_C6D6:
        case UPD1986C:
        case M50119P_1_40K:
        case VICTOR_C8D8:
        case MN6014W_C5D6:
        case MIT_C8D8:
        case MV500_02:
        case RC_6B:
        case CL311_UNKNOWN_7:
        case TC9012_FF:
        case GEMINI_C17_10:
        case UPD1986C_C:
        case YIPAI_321:
        case YIPAI_331:
        case M584802:
        case SZMG:
        case MIBOX:
        case GRUNDIG_DVD:
        case GREE9:
        case KELON2:
        case KELON4:
        case TOSHIBA1:
        case DAIKIN3:
        case MHI_09NV:
        case GZ_50GB:
            return true;
        default:
            return false;
    }
}

void PatternGen::init() {
    mCarrierFrequency = 38000;
    mLsbFirst = true;
    mUserCodeLength = 0;
    mDataCodeLength = 0;
    //mControlCode = 0;
    int pattern_length = 0;
    switch (mEncodingType) {
        case UPD6121G:
        case UPD6121G_F:
            mIrCodeLength = 6;
            break;
        case UPD6121G_001:
            mIrCodeLength = 10;
            break;
        case TC9012:
        case TC9012_2:
        case TC9012_F:
        case TC9012_S:
        case TC9012_A:
            mIrCodeLength = 4;
            break;
        case M50560:
        case M50560_1:
        case SC50560_2P:
        case SC50560_3P:
            mIrCodeLength = 4;
            break;
        case SC50560_B1:
            mIrCodeLength = 2;
            break;
        case LC7461M_C13:
        case LC7461M_C13_F:
            mIrCodeLength = 6;
            break;
        case LR3715M:
            mIrCodeLength = 6;
            mUserCodeLength = 1;
            mDataCodeLength = 2;
            pattern_length = 64;
            break;
        case IX0773CE:
            mIrCodeLength = 6;
            mUserCodeLength = 1;
            mDataCodeLength = 2;
            pattern_length = 96;
            break;
        case M3004_CARRIER:
        case M3004_FLASH:
            mLsbFirst = false;
            if (mEncodingType == M3004_FLASH) {
                mCarrierFrequency = 0;
            }
            mIrCodeLength = 4;
            mUserCodeLength = 1;
            mDataCodeLength = 1;
            pattern_length = 24;
            break;
        case SAA1250:
            mIrCodeLength = 6;
            break;
        case SAA3010_RC5_36K:
        case SAA3010_RC5:
        case SC3010_RC5:
            mLsbFirst = false;
            if (mEncodingType == SAA3010_RC5) {
                pattern_length = 28;
            } else {
                pattern_length = 29;
                if (mEncodingType == SAA3010_RC5_36K) {
                    mCarrierFrequency = 36000;
                }
            }
            mIrCodeLength = 6;
            mUserCodeLength = 1;
            mDataCodeLength = 1;
            break;
        case UPD6124_40K:
            mCarrierFrequency = 40000;
            mIrCodeLength = 4;
            mUserCodeLength = 1;
            mDataCodeLength = 1;
            pattern_length = 27;
            break;
        case UPD6124_D7C8:
            mCarrierFrequency = 40000;
            mIrCodeLength = 4;
            mUserCodeLength = 1;
            mDataCodeLength = 1;
            pattern_length = 33;
            break;
        case UPD6124_D7C13_40K:
            mCarrierFrequency = 40000;
            mIrCodeLength = 6;
            mUserCodeLength = 1;
            mDataCodeLength = 2;
            pattern_length = 43;
            break;
        case UPD6124_D7C13:
            mIrCodeLength = 6;
            mUserCodeLength = 1;
            mDataCodeLength = 2;
            pattern_length = 43;
            break;
        case KONKA_Y26:
            mIrCodeLength = 4;
            break;
        case M34280:
            mIrCodeLength = 4;
            mUserCodeLength = 1;
            mDataCodeLength = 1;
            pattern_length = 38;
            break;
        case RECS80:
            mCarrierFrequency = 33300;
            mIrCodeLength = 6;
            mUserCodeLength = 2;
            mDataCodeLength = 1;
            pattern_length = 24;
            break;
        case PANASONIC_1:
            mIrCodeLength = 12;
            mUserCodeLength = 1;
            mDataCodeLength = 5;
            pattern_length = 100;
            break;
        case GEMINI_C17:
            mIrCodeLength = 8;
            mUserCodeLength = 2;
            mDataCodeLength = 2;
            pattern_length = 69;
            break;
        case GEMINI_C6_317:
            mIrCodeLength = 2;
            break;
        case RCA_56K:
            mCarrierFrequency = 38000;
            mIrCodeLength = 4;
            mUserCodeLength = 1;
            mDataCodeLength = 1;
            pattern_length = 52;
            break;
        case THOMSON:
            mIrCodeLength = 4;
            mUserCodeLength = 1;
            mDataCodeLength = 1;
            pattern_length = 26;
            break;
        case IRT1250C5D6:
            mIrCodeLength = 4;
            mUserCodeLength = 1;
            mDataCodeLength = 1;
            pattern_length = 24;
            break;
        case IRT1250C5D7:
            mIrCodeLength = 4;
            break;
        case M708_0:
            mIrCodeLength = 4;
            break;
        case HTS_C5D6P:
            mIrCodeLength = 4;
            break;
        case PHILIPS_RC6:
            mIrCodeLength = 8;
            mUserCodeLength = 1;
            mDataCodeLength = 1;
            pattern_length = 45;
            break;
        case SDA2208_3:
            mIrCodeLength = 8;
            break;
        case M58480:
            mIrCodeLength = 2;
            break;
        case SAF1039:
        case SAF1039_1:
            mIrCodeLength = 2;
            break;
        case C8D8_E:
            mIrCodeLength = 4;
            mUserCodeLength = 1;
            mDataCodeLength = 1;
            pattern_length = 111;
            break;
        case WUXI_STB:
        case APEX_1:
            mIrCodeLength = 10;
            break;
        case XY_JAECS:
            mIrCodeLength = 4;
            break;
        case IRMEDIA_MOUSE:
            mIrCodeLength = 6;
            break;
        case MN6014AW_C6D6:
            mIrCodeLength = 4;
            break;
        case UPD1986C:
            mIrCodeLength = 2;
            break;
        case M50119P_1_40K:
            mIrCodeLength = 4;
            break;
        case VICTOR_C8D8:
            mIrCodeLength = 4;
            break;
        case MN6014W_C5D6:
            mIrCodeLength = 4;
            break;
        case MV500_02:
            mIrCodeLength = 2;
            break;
        case CL311_UNKNOWN_7:
            mIrCodeLength = 6;
            break;
        case MIT_C8D8:
            mIrCodeLength = 4;
            break;
        case TC9012_FF:
            mIrCodeLength = 4;
            break;
        case GEMINI_C17_10:
            mIrCodeLength = 6;
            break;
        case UPD1986C_C:
            mIrCodeLength = 2;
            break;
        case YIPAI_321:
            mIrCodeLength = 16;
            break;
        case YIPAI_331:
            mIrCodeLength = 4;
            break;
        case M584802:
            mIrCodeLength = 2;
            break;
        case GRUNDIG_DVD:
            mIrCodeLength = 4;
            break;
        case SZMG:
            mIrCodeLength = 8;
            break;
        case MIBOX:
            mIrCodeLength = 4;
            break;
        default:
            break;
    }

    if (mIrCodeLength > mIrCodeReserveLength) {
        mIrCodeReserveLength = mIrCodeLength;
        mIrCodes = new char[mIrCodeReserveLength];
    }
    if (mUserCodeLength > mUserCodeReserveLength) {
        mUserCodeReserveLength = mUserCodeLength;
        mUserCodes = new int[mUserCodeReserveLength];
    }
    if (mDataCodeLength > mDataCodeReserveLength) {
        mDataCodeReserveLength = mDataCodeLength;
        mDataCodes = new int[mDataCodeReserveLength];
    }
    mPatterns.resize(pattern_length, 0);
    mPatternId = 0;
}

int PatternGen::findStepToNextSpaceOrEnd(std::string string, int index) {
    int step = 0;
    while (index < string.length()) {
        if (string.at(index) == ' ') {
            break;
        }
        ++step;
        ++index;
    }
    return step;
}

bool PatternGen::parseIRCode(std::string ir_code) {
    int index = 0;
    int j = 0;
    while (index < ir_code.length()) {
        int step = findStepToNextSpaceOrEnd(ir_code, index);
        switch (step) {
            case 0:
                index++;
                break;
            case 1:
                if (mEncodingType == SDA2208_3 ||
                    mEncodingType == GEMINI_C17) {
                    mIrCodes[j++] = '0';
                    mIrCodes[j++] = '0';
                }
                mIrCodes[j++] = '0';
                mIrCodes[j++] = ir_code.at(index++);
                ++index;
                break;
            case 2:
                if (mEncodingType == SDA2208_3 ||
                    mEncodingType == GEMINI_C17) {
                    mIrCodes[j++] = '0';
                    mIrCodes[j++] = '0';
                }
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                ++index;
                break;
            case 3:
                mIrCodes[j++] = '0';
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                ++index;
                break;
            case 4:
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                ++index;
                break;
            case 5:
                mIrCodes[j++] = '0';
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                ++index;
                break;
            case 6:
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                ++index;
                break;
            case 7:
                mIrCodes[j++] = '0';
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                ++index;
                break;
            case 8:
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                mIrCodes[j++] = ir_code.at(index++);
                ++index;
                break;
            default:
                //printf("Read ir_code failed\n");
                return false;
        }
    }
    for (int b = 0; b < mIrCodeLength / 2; b++) {
        if (b < mUserCodeLength) {
            mUserCodes[b] = (charToValue(mIrCodes[2 * b]) << 4)
                            + charToValue(mIrCodes[2 * b + 1]);
        } else if (b < mUserCodeLength + mDataCodeLength) {
            mDataCodes[b - mUserCodeLength] = (charToValue(mIrCodes[2 * b]) << 4)
                                              + charToValue(mIrCodes[2 * b + 1]);
        }
    }
    return true;
}

void PatternGen::genBytePattern(int code, int bit_count, bool use_inverse_code) {
    if (bit_count < 8 && !mLsbFirst) {
        code <<= (8 - bit_count);
    }
    for (int j = 0; j < bit_count; j++) {
        bool is_bit_zero = false;
        if (mLsbFirst) {
            is_bit_zero = ((code & 1) == 0);
            code >>= 1;
        } else {
            is_bit_zero = ((code & 0x80) == 0);
            code <<= 1;
        }
        if (is_bit_zero && !use_inverse_code || !is_bit_zero && use_inverse_code) {
            mPatterns[mPatternId++] = mBit0Patterns[0];
            mPatterns[mPatternId++] = mBit0Patterns[1];
        } else {
            mPatterns[mPatternId++] = mBit1Patterns[0];
            mPatterns[mPatternId++] = mBit1Patterns[1];
        }
    }
}

void PatternGen::genDoubleBytesPattern(int code, int bit_count, bool use_inverse_code) {
    if (!mLsbFirst) {
        printf("genDoubleBytesPattern : unsupported mMsbFirst code\n");
    }
    bit_count /= 2;
    for (int j = 0; j < bit_count; ++j) {
        int index = code & 0x03;
        mPatterns[mPatternId++] = mBit0Patterns[index];
        mPatterns[mPatternId++] = mBit1Patterns[index];
        code >>= 2;
    }
}

void PatternGen::postProcess() {
    if (mPatterns.size() < 2) {
        return;
    }
    int length = mPatterns.size();
    /*std::string pattern;
      for (int i = 0; i < length; ++i) {
      std::string s;
      std::stringstream ss(s);
      ss << mPatterns[i];
      pattern += ss.str() + " ";
      }*/

    std::vector<int> tmp_patterns(length);
    int index = 0;
    if (mPatterns[0] > 0) {
        tmp_patterns[0] = mPatterns[0];
    } else {
        tmp_patterns[0] = 0;
        tmp_patterns[1] = mPatterns[0];
        index = 1;
    }
    for (int i = 1; i < length; i++) {
        if (tmp_patterns[index] >= 0 && mPatterns[i] >= 0
            || tmp_patterns[index] <= 0 && mPatterns[i] <= 0) {
            tmp_patterns[index] += mPatterns[i];
        } else {
            tmp_patterns[++index] = mPatterns[i];
        }
    }

    mPatterns.resize(index + 1);
    for (int i = 0; i < mPatterns.size(); i++) {
        mPatterns[i] = (tmp_patterns[i] > 0) ? tmp_patterns[i] : -tmp_patterns[i];
    }
}

std::string PatternGen::HexToChar(int c, bool inverse) {
    switch (c) {
        case 0:  return "0";
        case 1:  if (inverse) return "8"; else return "1";
        case 2:  if (inverse) return "4"; else return "2";
        case 3:  if (inverse) return "C"; else return "3";
        case 4:  if (inverse) return "2"; else return "4";
        case 5:  if (inverse) return "A"; else return "5";
        case 6:  return "6";
        case 7:  if (inverse) return "E"; else return "7";
        case 8:  if (inverse) return "1"; else return "8";
        case 9:  return "9";
        case 10: if (inverse) return "5"; else return "A";
        case 11: if (inverse) return "D"; else return "B";
        case 12: if (inverse) return "3"; else return "C";
        case 13: if (inverse) return "B"; else return "D";
        case 14: if (inverse) return "7"; else return "E";
        case 15: return "F";
        default: return " ";
    }
}

int PatternGen::charToValue(char c) {
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return (char) (c - '0');
        case 'A':
        case 'B':
        case 'C':
        case 'D':
        case 'E':
        case 'F':
            return (char) (c - 'A' + 10);
        default:
            return (char) (0);
    }
}

