#pragma once

#include <Arduino.h>

class SegmentDisplay
{
public:
    SegmentDisplay() {};

    void Init(byte A, byte B, byte C, byte D, byte E, byte F, byte G, byte DP);

    void DisplayNumber(byte number);
    void DisplayNumber(byte number, long duration);
    void ResetNumberDisplay();

    void Debug();
    void Test();
private:
    void SetNumber(byte number);

    static byte m_A, m_B, m_C, m_D, m_E, m_F, m_G, m_DP;
    byte m_Numbers[10][7];

};