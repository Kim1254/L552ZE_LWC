#ifndef _UTIL_H
#define _UTIL_H

static void get_hex(char* dest, const unsigned char* hex, int len)
{
	char hexstr[4];
	for (const unsigned char* p = hex; p - hex < len; p++)
	{
		sprintf(hexstr, "%02X ", *p);
		strcat(dest, hexstr);
	}
	strcat(dest, "\n");
}

#endif