#include"stack.h"

typedef struct Stack
{
	DataType _array[MAX_SIZE];
	int _size;
}Stack;


void StackInit(Stack* s)//栈的初始化
{
	assert(s);
	s->_size = 0;
}
void StackPush(Stack* s, DataType data)//向栈中压入元素
{
	assert(s);
	if (StackSize == MAX_SIZE)
	{
		printf("栈已满");
		return;
	}
	s->_array[s->_size] = data;
	s->_size++;
}
void StackPop(Stack* s)//栈内的元素出栈
{
	assert(s);
	if (StackEmpty(&s))
	{
		printf("栈已空");
		return;
	}
	s->_size--;

}
DataType StackTop(Stack* s)//取栈顶元素
{
	assert(s);
	if (StackEmpty(&s))
	{
		return;
	}
	return s->_array[s->_size - 1];
}
int StackSize(Stack* s)//栈的有效元素个数
{
	assert(s);
	return s->_size;

}
int StackEmpty(Stack* s)//判空
{
	assert(s);
	if (s->_size == 0)
	{
		return 1;
	}
	return 0;

}


//括号匹配

int IsBracket(char ch)//字符是否是括号
{
	if (ch == '(' || ch == ')'
		|| ch == '[' || ch == ']'
		|| ch == '{' || ch == '}')
	{
		return 1;
	}
	return 0;

}
int MatchBrackets(const char* pStr)//括号是否匹配,栈主要用于左括号的进出
{
	int len = strlen(*pStr);
	Stack s;
	StackInit(&s);
	for (int i = 0; i < len;i++)
	{
		if (!IsBracket(pStr[i]))//如果不是括号是字母，不进行后面的循环，直接向后移
		{
			continue;
		}
		else//是括号
		{
			if (pStr[i] == '(' || pStr[i] == '[' || pStr[i] == '{')//如果是左括号，放入栈中
			{
				StackPush(&s, pStr[i]);
			}
			else//如果不是，那么就和栈顶元素进行匹配
			{
				if (StackEmpty(&s))
				{
					printf("右括号多\n");
					return 0;
				}
				char ch = StackTop(&s);
				if (ch == '('&&pStr[i] == ')' ||
					ch == '['&&pStr[i] == ']' ||
					ch == '{'&&pStr[i] == '}')
				{
					StackPop(&s);//匹配成功，就让左括号出栈
				}
				else
				{
					printf("括号匹配不正确");
					return 0;
				}
			}
		}
		if (!StackEmpty(&s))
		{
			printf("左括号比右括号多");
			return 0;
		}
		else
		{
			printf("括号匹配正确\n");
			return 1;
		}
     }
}

//后缀表达式


int CalcRPN(Cell* RPN, int size)//计算表达式的结果,栈用于数字的存放和取出
{
	Stack s;
	StackInit(&s);

	for (int i = 0; i < size; i++)
	{
		if (RPN[i]._op == DATA)//如果当前的是数字，压入栈中
		{
			StackPush(&s, RPN[i]._data);
		}
		else//如果遇到的是符号，则需要元素出栈进行运算
		{
			int right = StackTop(&s);//取出进行操作的左值和右值
			StackPop(&s);
			int left = StackTop(&s);
			StackPop(&s);
			switch (RPN[i]._op)//处理不同的操作符号
			{
			case ADD:
				StackPush(&s, left + right);
			case SUB:
				StackPush(&s, left - right);
			case MUL:
				StackPush(&s, left*right);
			case DIV:
				if (right == 0)
				{
					printf("非法操作\n");
					break;
				}
				else
				{
					StackPush(&s, left / right);
				}
				
			default:
				printf("无法处理的符号\n");
			}

		}
	}
		return StackTop(&s);//最后返回栈顶的元素
		StackPop(&s);
}








