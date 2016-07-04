#include <CommProto/serialization/Marshal.h>
#include <stdlib.h>
#include <algorithm>



namespace Comnet {
namespace Serialization {
	
	uint32_t packString(string_t data, int16_t len, marshall_t input)
	{
		memcpy(input, data, len);
		return len;		
	}

	void unpackString(string_t data, int16_t len, marshall_t input)
	{
		memcpy(data, input, len);
		return;
	}

	uint32_t packWideString(wideString_t data, int16_t len, marshall_t input)
	{
		for (int x = 0; x < len; x++)
		{
			swap_endian<wchar_t>(data[x]);
		}
		memcpy(input, data, len * 2);
		return len * 2;
		
	}
	void unpackWideString(wideString_t data, int16_t len, marshall_t input)
	{
		memcpy(data, input, len * 2);
		for (int x = 0; x < len; x++)
		{
			swap_endian<wchar_t>(data[x]);
		}
		return;
	}

	uint32_t packByte(uint8_t data, marshall_t input) 
	{
		memcpy(input, &data, 1);
		return NULL;
	}

	uint8_t unpackByte(marshall_t input)
	{
		uint8_t value;
		memcpy(&value, input, 1);
		return value;
	}

	uint32_t packUint16(uint16_t data, marshall_t input)
	{
		swap_endian(data);
		memcpy(input, &data, sizeof(uint16_t));
		return sizeof(uint16_t);
	}

	uint16_t unpackUint16(marshall_t input)
	{
		uint16_t value;
		memcpy(&value, input, sizeof(uint16_t));
		swap_endian(value); 
		return value;
	}

	uint32_t packInt16(int16_t data, marshall_t input)
	{		
		swap_endian(data);
		memcpy(input, &data, sizeof(int16_t));
		return sizeof(int16_t);		
	}

	int16_t unpackInt16(marshall_t input)
	{
		int16_t value;
		memcpy(&value, input, sizeof(int16_t));
		swap_endian(value);
		return value;
	}

	uint32_t packUint32(uint32_t data, marshall_t input)
	{
		swap_endian(data);
		memcpy(input, &data, sizeof(uint32_t));
		return sizeof(uint32_t);
	}

	uint32_t unpackUint32(marshall_t input)
	{
		uint32_t value;
		memcpy(&value, input, sizeof(uint32_t));
		swap_endian(value);
		return value;
	}

	uint32_t packInt32(int32_t data, marshall_t input)
	{
		swap_endian(data);
		memcpy(input, &data, sizeof(int32_t));
		return sizeof(int32_t);
	}

	int32_t unpackInt32(marshall_t input)
	{
		int32_t value;
		memcpy(&value, input, sizeof(int32_t));
		swap_endian(value);
		return value;
	}

	uint32_t packUint64(uint64_t data, marshall_t input)
	{
		swap_endian(data);
		memcpy(input, &data, sizeof(uint64_t));
		return sizeof(uint64_t);
	}

	uint64_t unpackUint64(marshall_t input)
	{
		uint64_t value;
		memcpy(&value, input, 2);
		swap_endian(value);
		return value;
	}

	uint32_t packInt64(int64_t data, marshall_t input)
	{
		swap_endian(data);
		memcpy(input, &data, sizeof(int64_t));
		return sizeof(int64_t);
	}

	int64_t unpackInt64(marshall_t input)
	{
		int64_t value;
		memcpy(&value, input, sizeof(int64_t));
		swap_endian(value);
		return value;
	}

	uint32_t packReal32(real32_t data, marshall_t input)
	{
		swap_endian(data);
		memcpy(input, &data, sizeof(real32_t));
		return sizeof(real32_t);
	}

	real32_t unpackReal32(marshall_t input)
	{
		real32_t value;
		memcpy(&value, input, sizeof(real32_t));
		swap_endian(value);
		return value;
	}

	uint32_t packReal64(real64_t data, marshall_t input)
	{
		swap_endian(data);
		memcpy(input, &data, sizeof(real64_t));
		return sizeof(real64_t);
	}
	real64_t unpackReal64(marshall_t input)
	{
		real64_t value;
		memcpy(&value, input, sizeof(real64_t));
		swap_endian(value);
		return value;
	}

} // Serialization namespace
} // Comnet namespace
