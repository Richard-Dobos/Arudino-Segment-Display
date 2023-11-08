#include "MultiSegmentDisplay.h"

void MultiSegmentDisplay::Init(byte A, byte B, byte C, byte D, byte E, byte F, byte G, byte DP, byte GN1, byte GN2, byte GN3, byte GN4)
{
    m_A = A;
    m_B = B;
    m_C = C;
    m_D = D;
    m_E = E;
    m_F = F;
    m_G = G;
    m_DP = DP;

    m_GN[0] = GN1;
    m_GN[1] = GN2;
    m_GN[2] = GN3;
    m_GN[3] = GN4;

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
    pinMode(m_GN[0], OUTPUT);
    pinMode(m_GN[1], OUTPUT);
    pinMode(m_GN[2], OUTPUT);
    pinMode(m_GN[3], OUTPUT);

    digitalWrite(m_A, LOW);
    digitalWrite(m_B, LOW);
    digitalWrite(m_C, LOW);
    digitalWrite(m_D, LOW);
    digitalWrite(m_E, LOW);
    digitalWrite(m_F, LOW);
    digitalWrite(m_G, LOW);
    digitalWrite(m_DP, LOW);
    digitalWrite(m_GN[0], HIGH);
    digitalWrite(m_GN[1], HIGH);
    digitalWrite(m_GN[3], HIGH);
    digitalWrite(m_GN[2], HIGH);
}

void MultiSegmentDisplay::DisplayNumber(short number,long duration)
{
    Serial.println(number);

    short n1 = number / 1000;
    short n2 = (number % 1000) / 100;
    short n3 = ((number % 1000) % 100) / 10;
    short n4 = (((number % 1000) % 100) % 10) / 1;
    
    long time = 0;

    while(time < duration + 1)
    {
        SetNumber(n1, 1, 2);
        Serial.println(n1);
        SetNumber(n2, 2, 2);
        Serial.println(n2);
        SetNumber(n3, 3, 2);
        Serial.println(n3);
        SetNumber(n4, 4, 2);
        Serial.println(n4);

        time += 8;
    }
}

void MultiSegmentDisplay::ResetNumberDisplay()
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

void MultiSegmentDisplay::Test()
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

void MultiSegmentDisplay::SetNumber(short number, byte digit, short sleep)
{
    digitalWrite(m_GN[digit-1], LOW);

    for (byte i = 0; i < 7; i++)
    {
        digitalWrite(m_Numbers[number][i], HIGH);
    }

    delay(sleep);
    ResetNumberDisplay();
    digitalWrite(m_GN[digit-1], HIGH);
}