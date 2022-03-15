/**
 * @file bitsFieldTest.cpp
 * @author Francisco Armenta L. (sistron@sistron.com.mx)
 * @brief
 * @version 0.1.0
 * @date 2022-02-25
 *
 * @copyright Copyright (c) 2022 SITRN SISTEMAS ELECTRONICOS
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct CONFIG_BITS
{
    uint16_t extPressure : 1;
    uint16_t thermo : 1;
    uint16_t thermo4Wire : 1;
    uint16_t flowChnOne : 1;
    uint16_t flowChnTwo : 1;
    uint16_t manRegulation : 1;
    uint16_t pascalUnits : 1;
    uint16_t negPressure : 1;
    uint16_t userSettingsUnset : 1;
    uint16_t uvControl : 1;
    uint16_t powerOutControl : 1;
    uint16_t summerTime : 1;
    uint16_t blockedScreen : 1;
    uint16_t blockedFan : 1;
};

typedef union
{
    CONFIG_BITS bits;
    uint16_t val;
} CONFIG_DATA;

typedef union
{
    uint32_t v;
    uint16_t w[2];
    uint8_t b[4];
} DATE_REG;

int main()
{
    CONFIG_DATA configData;
    DATE_REG date;
    ios state(nullptr);

    configData.val = 0;
    configData.bits.extPressure = 0;
    configData.bits.blockedFan = 1;

    date.b[0] = 0xF0;
    date.b[1] = 0xF;
    date.b[2] = 0x1;
    date.b[3] = 0x10;

    state.copyfmt(cout); // save current formatting

    cout << "config Bits: " << hex << configData.val << endl;
    cout << "date: " << date.v << endl;
    cout << "date: " << date.w[0] << endl;
    cout << "date: " << date.w[1] << endl;

    state.copyfmt(cout);
}