#ifndef __DBF_H__
#define __DBF_H__

#include "pch.h"

#define dBase3 0x03
#define dBase3WM 0x83
#define dBase4 0x04
#define dBase4WM 0x8B
#define dBase5 0x05
#define dBase7 0x07

#define FIELD_CHAR 0x43
#define FIELD_NUMERIC 0x4e
#define FIELD_LOGIC 0x4c
#define FIELD_DATE 0x44
#define FIELD_TIME '@'

struct DB_HEADER {
    unsigned char version;
    unsigned char last_update[3];
    unsigned int  records;
    unsigned short     header_length;
    unsigned short     record_length;
    unsigned char reserved01[2];
    unsigned char transaction;
    unsigned char encryption;
    unsigned char reserved02[12];
    unsigned char mdx;
    unsigned char language;
    unsigned char reserved03[2];
    unsigned char driver_name[32];
    unsigned char reserved04[4];
};

struct DB_FIELD {
    unsigned char field_name[32];
    unsigned char field_type;
    unsigned char length_binary;
    unsigned char dec_count_binary;
    unsigned char reserved1[2];
    unsigned char mdx;
    unsigned char reserved2[2];
    unsigned long next_auto_inc;
    unsigned long reserved3;
};

#endif
