#include "base64.h"
const char base64_chars[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

size_t encode_triplet(unsigned char in[3], char* out, size_t length, size_t offset)
{
	char indices[4];
	for (size_t idx = length; idx < 3; ++idx)
		in[idx] = 0;

	indices[0] = in[0] >> 2;
	indices[1] = (in[1] >> 4) + ((in[0] & 0x03) << 4);
	indices[2] = (in[2] >> 6) + ((in[1] & 0x0F) << 2);
	indices[3] = in[2] & 0x3F;

	size_t idx = 0;
	for ( ; idx <= length; ++idx)
		out[offset + idx] = base64_chars[indices[idx]];
	while (length++ < 3)
		out[offset + idx++] = '=';

	return offset + 4;
}

char* base64_encode(const char message[], int message_size)
{
	int encoded_size = 4 * (message_size / 3) + 1 
					+ 4*((bool)(message_size%3));
	//encodedSize += (messageSize % 3) ? 4 : 0;
	char* encoded_str = new char[encoded_size];
	encoded_str[encoded_size - 1] = '\0';
	unsigned char source[3];
	unsigned char indices[4];
	int source_idx = 0;
	int encoded_offset = 0;
	while (message_size--)
	{
		source[source_idx++] = *(message++);
		if (source_idx == 3)
		{	
			encoded_offset = encode_triplet(source, encoded_str, source_idx, encoded_offset);
			source_idx = 0;
		}
	}

	if (source_idx != 0)
		encode_triplet(source, encoded_str, source_idx, encoded_offset);

	return encoded_str;
}
