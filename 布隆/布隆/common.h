#pragma once

typedef unsigned long size_t;

unsigned long GetNextPrime(unsigned long num);
size_t HashFuncDef(int data);
size_t BKDRHash(const char * str);
size_t RSHash(const char *str);
size_t APHash(const char *str);
size_t JSHash(const char *str);
size_t DEKHash(const char* str);

typedef size_t(*PHF)(DataType);