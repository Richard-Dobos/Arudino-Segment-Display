#include "SegmentDisplay.h"
void SegmentDisplay::Init(byte A, byte B, byte C, byte D, byte E, byte F, byte G, byte DP)
{
    m_A = A;
    m_B = B;
    m_C = C;
    m_D = D;
    m_E = E;
    m_F = F;
    m_G = G;
    m_DP = DP;

    byte Numbers[10][7] =
    {
        { m_A, m_B, m_F, m_E, m_C, m_D, m_A },    // 0
        { m_B, m_C, m_B, m_B, m_B, m_B, m_B },    // 1
        { m_A, m_B, m_G, m_E, m_D, m_A, m_A },    // 2
        { m_A, m_B, m_G, m_C, m_D, m_A, m_A },    // 3   
        { m_F, m_G, m_C, m_B, m_F, m_F, m_F },    // 4
        { m_A, m_F, m_G, m_C, m_D, m_A, m_A },    // 5
        { m_A, m_F, m_G, m_C, m_E, m_D, m_A },    // 6
        { m_A, m_B, m_C, m_A, m_A, m_A, m_A },    // 7
        { m_A, m_B, m_F, m_E, m_C, m_D, m_G },    // 8
        { m_F, m_A, m_G, m_B, m_C, m_F, m_F }     // 9
    };

    for (byte i = 0; i < 10; i++)
    {
        for (byte n = 0; n < 7; n++)
        {
            m_Numbers[i][n] = Numbers[i][n];
        }
    }

    delete Numbers;

    pinMode(m_A, OUTPUT);
    pinMode(m_B, OUTPUT);
    pinMode(m_C, OUTPUT);
    pinMode(m_D, OUTPUT);
    pinMode(m_E, OUTPUT);
    pinMode(m_F, OUTPUT);
    pinMode(m_G, OUTPUT);
    pinMode(m_DP, OUTPUT);
}

void SegmentDisplay::DisplayNumber(byte number)
{
    SetNumber(number);
}


void SegmentDisplay::DisplayNumber(byte number, long duration)
{
    SetNumber(number);
    delay(duration);
    ResetNumberDisplay();
}

void SegmentDisplay::ResetNumberDisplay()
{
    digitalWrite(m_A, LOW);
    digitalWrite(m_B, LOW);
    digitalWrite(m_C, LOW);
    digitalWrite(m_D, LOW);
    digitalWrite(m_E, LOW);
    digitalWrite(m_F, LOW);
    digitalWrite(m_G, LOW);
    digitalWrite(m_DP, LOW);
}

void SegmentDisplay::SetNumber(byte number)
{
    for (byte i = 0; i < (sizeof(m_Numbers[number]) / sizeof(byte)); i++)
    {
        digitalWrite(m_Numbers[number][i], HIGH);
    }
}

void SegmentDisplay::Test()
{
    digitalWrite(m_A, HIGH);
    digitalWrite(m_B, HIGH);
    digitalWrite(m_C, HIGH);
    digitalWrite(m_D, HIGH);
    digitalWrite(m_E, HIGH);
    digitalWrite(m_F, HIGH);
    digitalWrite(m_G, HIGH);
    digitalWrite(m_DP, HIGH);
}
