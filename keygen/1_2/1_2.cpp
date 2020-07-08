//KeyGen Atra 1.2
//Khai bao cac thu vien can dung


#define _CRT_SECURE_NO_WARNINGS
#include "crc.h"
#include <iostream>
#include <string>

using namespace std;

//Khai bao cac source de lay Key
const string alpha = "BDRQKPTVJI";
const string number = "0123456789";

//
const uint32_t Table[8] = { 0xA6, 0x16, 0xAF, 0xFD, 0xD4, 0x07, 0x10, 0xF6 };

// Khoi Tao Mang Hash
const uint32_t Hash_Init[4] = { 0x10325476u, 0x98BADCFEu, 0xEFCDAB89u, 0x67452301u };

//Khoi tao cac ham bo tro
//Kiem tra chuoi nhap vao co hop le khong?
bool CheckSerial1(string a)
{
	if (a.length() != 5)
		return false;
	int alp = 0;
	int num = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			for (int j = 0; j < number.length(); j++)
			{
				if (a[i] == number[j])
				{
					num++;
					if (num > 2)
						return false;
					break;
				}
			}
		}
		else
		{
			for (int j = 0; j < alpha.length(); j++)
			{
				if (a[i] == alpha[j])
				{
					alp++;
					if (alp > 3)
						return false;
					break;
				}
			}
		}
		
	}
	if (alp == 3 && num == 2)
		return true;
	return false;
}
//Ham Hash
uint32_t Hash1(uint32_t mem[])//Ham co san
{
	uint32_t EAX = 0x98BADCFE, ECX = 0x67452301, EDX, EBX = 0x98BADCFE;
	uint32_t  EDI = 0xEFCDAB89, EBP_pos8, EBP_neg4, EBP_posC, EBP_neg8, ESI = 0x67452301;
	uint32_t  ESI_pos4 = 0xEFCDAB89, ESI_pos8 = 0x98BADCFE, ESI_posC = 0x10325476;
	EAX = EAX + mem[0];
	ECX = ECX + EAX;
	EAX = ECX;
	EAX = EAX >> 0x1D;
	ECX = ECX << 0x3;
	EAX = EAX | ECX;
	ECX = EDI;
	EDX = EAX;
	ECX = ECX & EAX;
	EDX = ~EDX;
	EDX = EDX & EBX;
	EBP_pos8 = EAX;
	EDX = EDX | ECX;
	ECX = 0x10325476;
	ECX = ECX + mem[1];
	ECX = ECX + EDX;
	EAX = ECX;
	EAX = EAX >> 0x19;
	ECX = ECX << 0x7;
	EAX = EAX | ECX;
	ECX = EAX;
	EDX = EAX;
	EDX = EDX & EBP_pos8;
	ECX = ~ECX;
	ECX = ECX & EDI;
	ECX = ECX | EDX;
	ECX = ECX + mem[2];
	EBX = EBX + ECX;
	ECX = EBX;
	ECX = ECX >> 0x15;
	EBX = EBX << 0xB;
	ECX = ECX | EBX;
	EBX = EAX;
	EDX = ECX;
	EBX = EBX & ECX;
	EDX = ~EDX;
	EDX = EDX & EBP_pos8;
	EDX = EDX | EBX;
	EBX = ECX;
	EDX = EDX + mem[3];
	EDI = EDI + EDX;
	EDX = EDI;
	EDX = EDX << 0x13;
	EDI = EDI >> 0xD;
	EDX = EDX | EDI;
	EDI = EDX;
	EBX = EBX & EDX;
	EDI = ~EDI;
	EDI = EDI & EAX;
	EBP_neg4 = EDX;
	EDI = EDI | EBX;
	EBX = EBP_pos8;
	EDI = EDI + mem[4];
	EBX = EBX + EDI;
	EDI = EBX;
	EDI = EDI >> 0x1D;
	EBX = EBX << 0x3;
	EDI = EDI | EBX;
	EBP_pos8 = EDI;
	EBX = EDI;
	EDX = EDX & EDI;
	EBX = ~EBX;
	EBX = EBX & ECX;
	EDI = EBP_neg4;
	EBX = EBX | EDX;
	EBX = EBX + mem[5];
	EAX = EAX + EBX;
	EDX = EAX;
	EDX = EDX >> 0x19;
	EAX = EAX << 0x7;
	EDX = EDX | EAX;
	EAX = EDX;
	EBX = EDX;
	EBX = EBX & EBP_pos8;
	EAX = ~EAX;
	EAX = EAX & EDI;
	EAX = EAX | EBX;
	EBX = EDX;
	EAX = EAX + mem[6];
	ECX = ECX + EAX;
	EAX = ECX;
	EAX = EAX >> 0x15;
	ECX = ECX << 0xB;
	EAX = EAX | ECX;
	ECX = EAX;
	EBX = EBX & EAX;
	ECX = ~ECX;
	ECX = ECX & EBP_pos8;
	ECX = ECX | EBX;
	EBX = EAX;
	ECX = ECX + mem[7];
	EDI = EDI + ECX;
	ECX = EDI;
	ECX = ECX << 0x13;
	EDI = EDI >> 0xD;
	ECX = ECX | EDI;
	EDI = ECX;
	EBX = EBX & ECX;
	EDI = ~EDI;
	EDI = EDI & EDX;
	EBP_neg4 = ECX;
	EDI = EDI | EBX;
	EBX = EBP_pos8;
	EDI = EDI + mem[8];
	EBX = EBX + EDI;
	EDI = EBX;
	EDI = EDI >> 0x1D;
	EBX = EBX << 0x3;
	EDI = EDI | EBX;
	EBX = EDI;
	ECX = ECX & EDI;
	EBX = ~EBX;
	EBX = EBX & EAX;
	EBP_pos8 = EDI;
	EBX = EBX | ECX;
	EDI = EBP_neg4;
	EBX = EBX + mem[9];
	EDX = EDX + EBX;
	ECX = EDX;
	ECX = ECX >> 0x19;
	EDX = EDX << 0x7;
	ECX = ECX | EDX;
	EDX = ECX;
	EBX = ECX;
	EBX = EBX & EBP_pos8;
	EDX = ~EDX;
	EDX = EDX & EDI;
	EDX = EDX | EBX;
	EBX = ECX;
	EDX = EDX + mem[10];
	EAX = EAX + EDX;
	EDX = EAX;
	EDX = EDX >> 0x15;
	EAX = EAX << 0xB;
	EDX = EDX | EAX;
	EAX = EDX;
	EBX = EBX & EDX;
	EAX = ~EAX;
	EAX = EAX & EBP_pos8;
	EAX = EAX | EBX;
	EAX = EAX + mem[11];
	EBX = EDX;
	EDI = EDI + EAX;
	EAX = EDI;
	EAX = EAX << 0x13;
	EDI = EDI >> 0xD;
	EAX = EAX | EDI;
	EDI = EAX;
	EBX = EBX & EAX;
	EDI = ~EDI;
	EDI = EDI & ECX;
	EBP_neg4 = EAX;
	EDI = EDI | EBX;
	EBX = EBP_pos8;
	EDI = EDI + mem[12];
	EBX = EBX + EDI;
	EDI = EBX;
	EDI = EDI >> 0x1D;
	EBX = EBX << 0x3;
	EDI = EDI | EBX;
	EBX = EDI;
	EAX = EAX & EDI;
	EBX = ~EBX;
	EBX = EBX & EDX;
	EBX = EBX | EAX;
	EBX = EBX + mem[13];
	ECX = ECX + EBX;
	EBX = ECX;
	EBX = EBX >> 0x19;
	ECX = ECX << 0x7;
	EBX = EBX | ECX;
	EAX = EBX;
	ECX = EBX;
	EAX = ~EAX;
	EAX = EAX & EBP_neg4;
	ECX = ECX & EDI;
	EAX = EAX | ECX;
	EAX = EAX + mem[14];
	EDX = EDX + EAX;
	EAX = EDX;
	EAX = EAX >> 0x15;
	EDX = EDX << 0xB;
	EAX = EAX | EDX;
	EDX = EBX;
	ECX = EAX;
	EDX = EDX & EAX;
	ECX = ~ECX;
	ECX = ECX & EDI;
	ECX = ECX | EDX;
	EDX = EBP_neg4;
	ECX = ECX + mem[15];
	EDX = EDX + ECX;
	ECX = EDX;
	ECX = ECX << 0x13;
	EDX = EDX >> 0xD;
	ECX = ECX | EDX;
	EDX = EAX;
	EBP_neg4 = ECX;
	EDX = EDX | ECX;
	ECX = EAX;
	EDX = EDX & EBX;
	ECX = ECX & EBP_neg4;
	EDX = EDX | ECX;
	EDX = EDX + mem[0];
	EDI = EDI + EDX + 0x5A826999;
	ECX = EDI;
	EDX = EDI;
	EDI = EBP_neg4;
	ECX = ECX >> 0x1D;
	EDX = EDX << 0x3;
	ECX = ECX | EDX;
	EBP_posC = EDI;
	EBP_posC = EBP_posC | ECX;
	EDI = EDI & ECX;
	EDX = EBP_posC;
	EDX = EDX & EAX;
	EDX = EDX | EDI;
	EDX = EDX + mem[4];
	EDX = EBX + EDX + 0x5A826999;
	EBX = EDX;
	EBX = EBX >> 0x1B;
	EDX = EDX << 0x5;
	EBX = EBX | EDX;
	EDX = EBP_posC;
	EDX = EDX & EBX;
	EBP_neg8 = EBX;
	EDX = EDX | EDI;
	EDX = EDX + mem[8];
	EDX = EAX + EDX + 0x5A826999;
	EAX = EDX;
	EAX = EAX >> 0x17;
	EDX = EDX << 0x9;
	EAX = EAX | EDX;
	EDX = EAX;
	EDI = EAX;
	EDX = EDX | ECX;
	EDI = EDI & ECX;
	EDX = EDX & EBX;
	EDX = EDX | EDI;
	EDI = EBP_neg4;
	EDX = EDX + mem[12];
	EDI = EDI + EDX + 0x5A826999;
	EDX = EDI;
	EDX = EDX >> 0x13;
	EDI = EDI << 0xD;
	EDX = EDX | EDI;
	EDI = EAX;
	EDI = EDI | EDX;
	EBP_neg4 = EDX;
	EDI = EDI & EBX;
	EBX = EAX;
	EBX = EBX & EDX;
	EDI = EDI | EBX;
	EBX = EBP_neg8;
	EDI = EDI + mem[1];
	ECX = ECX + EDI + 0x5A826999;
	EDI = ECX;
	EDI = EDI >> 0x1D;
	ECX = ECX << 0x3;
	EDI = EDI | ECX;
	ECX = EDX;
	EBP_neg4 = EBP_neg4 & EDI;
	ECX = ECX | EDI;
	EBP_pos8 = EDI;
	EDI = ECX;
	EDI = EDI & EAX;
	EDI = EDI | EBP_neg4;
	EDI = EDI + mem[5];
	EBX = EBX + EDI + 0x5A826999;
	EDI = EBX;
	EDI = EDI >> 0x1B;
	EBX = EBX << 0x5;
	EDI = EDI | EBX;
	ECX = ECX & EDI;
	ECX = ECX | EBP_neg4;
	ECX = ECX + mem[9];
	ECX = EAX + ECX + 0x5A826999;
	EAX = ECX;
	EAX = EAX >> 0x17;
	ECX = ECX << 0x9;
	EAX = EAX | ECX;
	ECX = EAX;
	EBX = EAX;
	ECX = ECX | EBP_pos8;
	EBX = EBX & EBP_pos8;
	ECX = ECX & EDI;
	ECX = ECX | EBX;
	EBX = EAX;
	ECX = ECX + mem[13];
	EDX = EDX + ECX + 0x5A826999;
	ECX = EDX;
	ECX = ECX >> 0x13;
	EDX = EDX << 0xD;
	ECX = ECX | EDX;
	EDX = EAX;
	EDX = EDX | ECX;
	EBX = EBX & ECX;
	EDX = EDX & EDI;
	EDX = EDX | EBX;
	EBX = EBP_pos8;
	EDX = EDX + mem[2];
	EBX = EBX + EDX + 0x5A826999;
	EDX = EBX;
	EBP_posC = ECX;
	EDX = EDX >> 0x1D;
	EBX = EBX << 0x3;
	EDX = EDX | EBX;
	EBP_neg4 = ECX;
	EBP_posC = EBP_posC | EDX;
	EBP_neg4 = EBP_neg4 & EDX;
	EBP_pos8 = EDX;
	EDX = EBP_posC;
	EDX = EDX & EAX;
	EDX = EDX | EBP_neg4;
	EDX = EDX + mem[6];
	EDI = EDI + EDX + 0x5A826999;
	EDX = EBP_posC;
	EBX = EDI;
	EBX = EBX >> 0x1B;
	EDI = EDI << 0x5;
	EBX = EBX | EDI;
	EDX = EDX & EBX;
	EBP_neg8 = EBX;
	EDX = EDX | EBP_neg4;
	EDX = EDX + mem[10];
	EDX = EAX + EDX + 0x5A826999;
	EAX = EDX;
	EAX = EAX >> 0x17;
	EDX = EDX << 0x9;
	EAX = EAX | EDX;
	EDX = EAX;
	EDI = EAX;
	EDX = EDX | EBP_pos8;
	EDI = EDI & EBP_pos8;
	EDX = EDX & EBX;
	EDX = EDX | EDI;
	EDI = EAX;
	EDX = EDX + mem[14];
	ECX = ECX + EDX + 0x5A826999;
	EDX = ECX;
	EDX = EDX >> 0x13;
	ECX = ECX << 0xD;
	EDX = EDX | ECX;
	ECX = EAX;
	ECX = ECX | EDX;
	EDI = EDI & EDX;
	ECX = ECX & EBX;
	EBP_posC = EDX;
	ECX = ECX | EDI;
	EDI = EBP_pos8;
	ECX = ECX + mem[3];
	EBP_neg4 = EDX;
	EDI = EDI + ECX + 0x5A826999;
	ECX = EDI;
	ECX = ECX >> 0x1D;
	EDI = EDI << 0x3;
	ECX = ECX | EDI;
	EBP_posC = EBP_posC | ECX;
	EBP_neg4 = EBP_neg4 & ECX;
	EDI = EBP_posC;
	EDI = EDI & EAX;
	EDI = EDI | EBP_neg4;
	EDI = EDI + mem[7];
	EDI = EBX + EDI + 0x5A826999;
	EBX = EDI;
	EBX = EBX >> 0x1B;
	EDI = EDI << 0x5;
	EBX = EBX | EDI;
	EDI = EBP_posC;
	EDI = EDI & EBX;
	EBP_neg8 = EBX;
	EDI = EDI | EBP_neg4;
	EDI = EDI + mem[11];
	EAX = EAX + EDI + 0x5A826999;
	EDI = EAX;
	EDI = EDI >> 0x17;
	EAX = EAX << 0x9;
	EDI = EDI | EAX;
	EAX = EDI;
	EAX = EAX | ECX;
	EAX = EAX & EBX;
	EBX = EDI;
	EBX = EBX & ECX;
	EAX = EAX | EBX;
	EBX = EBP_neg8;
	EAX = EAX + mem[15];
	EDX = EDX + EAX + 0x5A826999;
	EAX = EDX;
	EAX = EAX >> 0x13;
	EDX = EDX << 0xD;
	EAX = EAX | EDX;
	EDX = EBX;
	EDX = EDX ^ EDI;
	EDX = EDX ^ EAX;
	EDX = EDX + mem[0];
	ECX = ECX + EDX + 0x6ED9FBA1;
	EDX = ECX;
	EDX = EDX >> 0x1D;
	ECX = ECX << 0x3;
	EDX = EDX | ECX;
	ECX = EDI;
	ECX = ECX ^ EAX;
	ECX = ECX ^ EDX;
	ECX = ECX + mem[8];
	ECX = EBX + ECX + 0x6ED9FBA1;
	EBX = ECX;
	EBX = EBX >> 0x17;
	ECX = ECX << 0x9;
	EBX = EBX | ECX;
	ECX = EBX;
	EBP_pos8 = EBX;
	ECX = ECX ^ EAX;
	ECX = ECX ^ EDX;
	ECX = ECX + mem[4];
	ECX = EDI + ECX + 0x6ED9FBA1;
	EDI = ECX;
	EDI = EDI >> 0x15;
	ECX = ECX << 0xB;
	EDI = EDI | ECX;
	EBP_pos8 = EBP_pos8 ^ EDI;
	ECX = EBP_pos8;
	ECX = ECX ^ EDX;
	ECX = ECX + mem[12];
	ECX = EAX + ECX + 0x6ED9FBA1;
	EAX = ECX;
	EAX = EAX >> 0x11;
	ECX = ECX << 0xF;
	EAX = EAX | ECX;
	ECX = EBP_pos8;
	ECX = ECX ^ EAX;
	ECX = ECX + mem[2];
	EDX = EDX + ECX + 0x6ED9FBA1;
	ECX = EDX;
	ECX = ECX >> 0x1D;
	EDX = EDX << 0x3;
	ECX = ECX | EDX;
	EDX = EDI;
	EDX = EDX ^ EAX;
	EDX = EDX ^ ECX;
	EDX = EDX + mem[10];
	EBX = EBX + EDX + 0x6ED9FBA1;
	EDX = EBX;
	EDX = EDX >> 0x17;
	EBX = EBX << 0x9;
	EDX = EDX | EBX;
	EBX = EDX;
	EBP_pos8 = EDX;
	EBX = EBX ^ EAX;
	EBX = EBX ^ ECX;
	EBX = EBX + mem[6];
	EDI = EDI + EBX + 0x6ED9FBA1;
	EBX = EDI;
	EBX = EBX >> 0x15;
	EDI = EDI << 0xB;
	EBX = EBX | EDI;
	EBP_pos8 = EBP_pos8 ^ EBX;
	EDI = EBP_pos8;
	EDI = EDI ^ ECX;
	EDI = EDI + mem[14];
	EDI = EAX + EDI + 0x6ED9FBA1;
	EAX = EDI;
	EAX = EAX >> 0x11;
	EDI = EDI << 0xF;
	EAX = EAX | EDI;
	EDI = EBP_pos8;
	EDI = EDI ^ EAX;
	EDI = EDI + mem[1];
	EDI = ECX + EDI + 0x6ED9FBA1;
	ECX = EDI;
	ECX = ECX >> 0x1D;
	EDI = EDI << 0x3;
	ECX = ECX | EDI;
	EDI = EBX;
	EDI = EDI ^ EAX;
	EDI = EDI ^ ECX;
	EDI = EDI + mem[9];
	EDX = EDX + EDI + 0x6ED9FBA1;
	EDI = EDX;
	EDI = EDI >> 0x17;
	EDX = EDX << 0x9;
	EDI = EDI | EDX;
	EDX = EDI;
	EBP_pos8 = EDI;
	EDX = EDX ^ EAX;
	EDX = EDX ^ ECX;
	EDX = EDX + mem[5];
	EBX = EBX + EDX + 0x6ED9FBA1;
	EDX = EBX;
	EDX = EDX >> 0x15;
	EBX = EBX << 0xB;
	EDX = EDX | EBX;
	EBP_pos8 = EBP_pos8 ^ EDX;
	EBX = EBP_pos8;
	EBX = EBX ^ ECX;
	EBX = EBX + mem[13];
	EBX = EAX + EBX + 0x6ED9FBA1;
	EAX = EBX;
	EAX = EAX >> 0x11;
	EBX = EBX << 0xF;
	EAX = EAX | EBX;
	EBX = EBP_pos8;
	EBX = EBX ^ EAX;
	EBX = EBX + mem[3];
	EBX = ECX + EBX + 0x6ED9FBA1;
	ECX = EBX;
	ECX = ECX >> 0x1D;
	EBX = EBX << 0x3;
	ECX = ECX | EBX;
	EBX = EDX;
	EBX = EBX ^ EAX;
	ESI = ESI + ECX;
	EBX = EBX ^ ECX;
	EBX = EBX + mem[11];
	EDI = EDI + EBX + 0x6ED9FBA1;
	EBX = EDI;
	EBX = EBX >> 0x17;
	EDI = EDI << 0x9;
	EBX = EBX | EDI;
	EDI = EBX;
	ESI_posC = ESI_posC + EBX;
	EDI = EDI ^ EAX;
	EDI = EDI ^ ECX;
	EDI = EDI + mem[7];
	EDX = EDX + EDI + 0x6ED9FBA1;
	EDI = EDX;
	EDI = EDI >> 0x15;
	EDX = EDX << 0xB;
	EDI = EDI | EDX;
	EDX = EBX;
	EDX = EDX ^ EDI;
	ESI_pos8 = ESI_pos8 + EDI;
	EDX = EDX ^ ECX;
	EDX = EDX + mem[15];
	EAX = EAX + EDX + 0x6ED9FBA1;
	ECX = EAX;
	ECX = ECX >> 0x11;
	EAX = EAX << 0xF;
	ECX = ECX | EAX;
	ESI_pos4 = ESI_pos4 + ECX;
	return (ESI ^ ESI_pos4 ^ ESI_pos8 ^ ESI_posC);
}

string Hash_part1(string serial1)
{
	uint32_t dkey[4];
	memcpy(dkey, Hash_Init, sizeof(uint32_t) * 4);
	uint8_t mem[64];
	memset(mem, 0, sizeof(uint8_t) * 64);
	for (int32_t i = 0; i < 5; ++i)
		mem[i] = serial1[i];
	mem[5] = 0x80;
	mem[56] = 0x28;
	int32_t eax = Hash1((uint32_t*)mem);
	char hex[9];
	sprintf(hex, "%08X", eax);
	return hex;
}
unsigned int Hash_part2(string serial1)
{
	for (int i = 0; i < 8; i++)
		serial1[i] = serial1[i] ^ Table[i];
	for (int i = 0; i < 8; i++)
	{
		uint32_t temp1 = serial1[i], temp2 = serial1[i];
		serial1[i] = (temp1 << i) | temp2;
	}

	uint32_t c1 = crc(serial1.begin(), serial1.end());
	return c1;
}
int main()
{
	cout <<" Luu y: Phan 1 gom 5 ki tu va phai 3 ki tu thuoc chuoi BDRQKPTVJI va 2 ki tu so thuoc chuoi 0123456789\n";
	string serial1;
	while (CheckSerial1(serial1) == 0)
	{
		cout << "SERIAL PART 1: ";
		cin >> serial1;
	}
	string temp = Hash_part1(serial1);
	uint32_t result = Hash_part2(temp);
	printf("SERIAL PART 2: %08X\n", result);
	system("pause");
	return 0;
}