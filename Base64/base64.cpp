#include "base64.h"
char base64Chars[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

char* base64Encode(const char message[], int messageSize)
{
	int encodedSize = 4 * (messageSize / 3) + 1 
					+ 4*((bool)(messageSize%3));
	//encodedSize += (messageSize % 3) ? 4 : 0;
	char* encodedStr = new char[encodedSize];
	encodedStr[encodedSize - 1] = '\0';
	unsigned char source[3];
	unsigned char indices[4];
	int counter = messageSize;
	int sourceIdx = 0;
	int encodedIdx = 0;
	while (counter--)
	{
		source[sourceIdx++] = *(message++);
		if (sourceIdx == 3)
		{
			sourceIdx = 0;
			indices[3] = source[2] & 0x3F;
			indices[2] = (source[2] >> 6) + ((source[1] & 0x0F) << 2);
			indices[1] = (source[1] >> 4) + ((source[0] & 0x03) << 4);
			indices[0] = source[0] >> 2;
			for (int i = 0; i < 4; ++i)
				encodedStr[encodedIdx++] = base64Chars[indices[i]];
		}
	}

	if (sourceIdx != 0)
	{
		for (int i = sourceIdx; i < 3; ++i)
			source[i] = 0;

		indices[3] = source[2] & 0x3F;
		indices[2] = (source[2] >> 6) + ((source[1] & 0x0F) << 2);
		indices[1] = (source[1] >> 4) + ((source[0] & 0x03) << 4);
		indices[0] = source[0] >> 2;

		for (int i = 0; i < sourceIdx + 1; ++i)
			encodedStr[encodedIdx++] = base64Chars[indices[i]];
		while (sourceIdx++ < 3)
			encodedStr[encodedIdx++] = '=';
	}
	return encodedStr;
}