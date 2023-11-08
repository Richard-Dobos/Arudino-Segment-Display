#include <Arduino.h>

class MultiSegmentDisplay
{
 public:
	void Init(byte A, byte B, byte C, byte D, byte E, byte F, byte G, byte DP, byte GN1, byte GN2, byte GN3, byte GN4);

	void DisplayNumber(short number, long duration);

	void ResetNumberDisplay();

	void Test();
private:
	void SetNumber(short number, byte digit, short delay);

	byte m_A, m_B, m_C, m_D, m_E, m_F, m_G, m_DP;
	byte m_GN[4];
	byte m_Numbers[10][7];
};