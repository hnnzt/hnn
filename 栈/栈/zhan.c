#include"stack.h"

typedef struct Stack
{
	DataType _array[MAX_SIZE];
	int _size;
}Stack;


void StackInit(Stack* s)//ջ�ĳ�ʼ��
{
	assert(s);
	s->_size = 0;
}
void StackPush(Stack* s, DataType data)//��ջ��ѹ��Ԫ��
{
	assert(s);
	if (StackSize == MAX_SIZE)
	{
		printf("ջ����");
		return;
	}
	s->_array[s->_size] = data;
	s->_size++;
}
void StackPop(Stack* s)//ջ�ڵ�Ԫ�س�ջ
{
	assert(s);
	if (StackEmpty(&s))
	{
		printf("ջ�ѿ�");
		return;
	}
	s->_size--;

}
DataType StackTop(Stack* s)//ȡջ��Ԫ��
{
	assert(s);
	if (StackEmpty(&s))
	{
		return;
	}
	return s->_array[s->_size - 1];
}
int StackSize(Stack* s)//ջ����ЧԪ�ظ���
{
	assert(s);
	return s->_size;

}
int StackEmpty(Stack* s)//�п�
{
	assert(s);
	if (s->_size == 0)
	{
		return 1;
	}
	return 0;

}


//����ƥ��

int IsBracket(char ch)//�ַ��Ƿ�������
{
	if (ch == '(' || ch == ')'
		|| ch == '[' || ch == ']'
		|| ch == '{' || ch == '}')
	{
		return 1;
	}
	return 0;

}
int MatchBrackets(const char* pStr)//�����Ƿ�ƥ��,ջ��Ҫ���������ŵĽ���
{
	int len = strlen(*pStr);
	Stack s;
	StackInit(&s);
	for (int i = 0; i < len;i++)
	{
		if (!IsBracket(pStr[i]))//���������������ĸ�������к����ѭ����ֱ�������
		{
			continue;
		}
		else//������
		{
			if (pStr[i] == '(' || pStr[i] == '[' || pStr[i] == '{')//����������ţ�����ջ��
			{
				StackPush(&s, pStr[i]);
			}
			else//������ǣ���ô�ͺ�ջ��Ԫ�ؽ���ƥ��
			{
				if (StackEmpty(&s))
				{
					printf("�����Ŷ�\n");
					return 0;
				}
				char ch = StackTop(&s);
				if (ch == '('&&pStr[i] == ')' ||
					ch == '['&&pStr[i] == ']' ||
					ch == '{'&&pStr[i] == '}')
				{
					StackPop(&s);//ƥ��ɹ������������ų�ջ
				}
				else
				{
					printf("����ƥ�䲻��ȷ");
					return 0;
				}
			}
		}
		if (!StackEmpty(&s))
		{
			printf("�����ű������Ŷ�");
			return 0;
		}
		else
		{
			printf("����ƥ����ȷ\n");
			return 1;
		}
     }
}

//��׺���ʽ


int CalcRPN(Cell* RPN, int size)//������ʽ�Ľ��,ջ�������ֵĴ�ź�ȡ��
{
	Stack s;
	StackInit(&s);

	for (int i = 0; i < size; i++)
	{
		if (RPN[i]._op == DATA)//�����ǰ�������֣�ѹ��ջ��
		{
			StackPush(&s, RPN[i]._data);
		}
		else//����������Ƿ��ţ�����ҪԪ�س�ջ��������
		{
			int right = StackTop(&s);//ȡ�����в�������ֵ����ֵ
			StackPop(&s);
			int left = StackTop(&s);
			StackPop(&s);
			switch (RPN[i]._op)//����ͬ�Ĳ�������
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
					printf("�Ƿ�����\n");
					break;
				}
				else
				{
					StackPush(&s, left / right);
				}
				
			default:
				printf("�޷�����ķ���\n");
			}

		}
	}
		return StackTop(&s);//��󷵻�ջ����Ԫ��
		StackPop(&s);
}








