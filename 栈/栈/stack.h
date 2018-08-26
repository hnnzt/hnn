#pragma once
#include <assert.h>
#include <stdio.h>
#include<string.h>

//typedef int DataType;
typedef char DataType;

typedef struct Position
{
	int _x;
	int _y;
}Position;

//typedef Position DataType;

#define  MAX_SIZE 10

typedef struct Stack
{
	DataType _array[MAX_SIZE];
	int _size;
}Stack;


typedef enum { ADD, SUB, MUL, DIV, DATA }OPERATOR;

typedef struct Cell//��׺���ʽ
{
	OPERATOR _op;//������
	int _data;//ֵ
}Cell;

//��׺���ʽ�ĸ��Ʒ�ʽ��Cell RPN[] = { { DATA, 12 }, { DATA, 3 }, { DATA, 4 }, { ADD, 0 },
//{ MUL, 0 }, { DATA, 6 }, { SUB, 0 }, { DATA, 8 }, { DATA, 2 }, { DIV, 0 },
//{ ADD, 0 } };



/////////////////////////////////////////////////////////
//  Stack.h
void StackInit(Stack* s);
void StackPush(Stack* s, DataType data);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
int StackSize(Stack* s);
int StackEmpty(Stack* s);

//����ƥ��
int IsBracket(char ch);
int MatchBrackets(const char* pStr);

//��׺���ʽ
int CalcRPN(Cell* RPN, int size);
