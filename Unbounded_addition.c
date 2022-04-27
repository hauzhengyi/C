#include<stdio.h>
#include<iostream>
void jia(struct ddl*, struct ddl*, struct ddl*, struct ddl*, int, int);//声明加法函数
void cheng(struct ddl*, struct ddl*, struct ddl*, int, int);//声明乘法函数
void fun(struct ddl*, struct ddl*);
struct ddl*creat();
struct ddl          //声明一个结构体类型：struct ddl
{
	char num;
	struct ddl*next;//向后指的指针
	struct ddl*before;//向前指的指针
};
int main()
{
	struct ddl*begin = creat();//定义指向struct ddl类型的指针变量begin
	for (fun(begin->next, NULL); begin->num == 0; begin = begin->next);
	for (; begin != NULL; begin = begin->next)//begin指针不断向后指并读出内容直到空指针
		printf("%d", begin->num);
	printf("\n");
	system("pause");
	return 0;
}
struct ddl*creat()//定义函数，返回一个指向链表头的指针
、
{
	struct ddl*p1, *p2, *head;
	p2 = p1 = head = (struct ddl*)malloc(sizeof(struct ddl));
	p1->num = 0, p1->before = NULL;//初始化
	while (p1->num != '\n' - 48)
	{
		p1 = (struct ddl*)malloc(sizeof(struct ddl));
		scanf_s("%c", &p1->num), p1->num -= 48;
		p2->next = p1, p1->before = p2, p2 = p1;//输入并实现存储
	}
	(p1->before)->next = NULL;
	return(head);
}
void fun(struct ddl*p0, struct ddl*pt) //运算函数
{
	struct ddl*p1, *p2, *p;
	int u, a, b;
	for (p = p0->before; p != NULL; p = p->next)//去掉括号
		if (p->num == '(' - 48)
		{
			(p->next)->before = p->before, (p->before)->next = p1 = p->next;
			for (u = 1; u > 0; p = p->next)//遇左括号加一，右括号减一，来寻找对应右括号
				u += ((p->next)->num == '(' - 48) - ((p->next)->num == ')' - 48);
			(p->before)->next = NULL;
			fun(p1, p->next);//函数嵌套，继续去括号
		}
	for (p = (p0->before)->next; p->next != NULL; p = p->next)
		if (p->num == '*' - 48)//乘法先于加法，寻找乘号
		{
			p1 = p2 = p;
			for (a = 0; p1->before != p0->before && (p1->before)->num >= 0 && (p1->before)->num <= 9; a++, p1 = p1->before);
			for (b = 0; p2->next != NULL && (p2->next)->num >= 0 && (p2->next)->num <= 9; b++, p2 = p2->next);
			cheng(p->before, p2, p1, a, b);
		}
	for (p = (p0->before)->next; p->next != NULL; p = p->next)
		if (p->num == '+' - 48)//寻找加号
		{
			p1 = p2 = p;
			for (a = 0; p1->before != p0->before && (p1->before)->num >= 0 && (p1->before)->num <= 9; a++, p1 = p1->before);
			for (b = 0; p2->next != NULL && (p2->next)->num >= 0 && (p2->next)->num <= 9; b++, p2 = p2->next);
			a > b ? jia(p->before, p2, p1, p2, a, b) : jia(p2, p->before, p1, p2, b, a);
		}//大前小后
	for (p = p0->before; p->next != NULL; p = p->next);
	p->next = pt;
	if(pt != NULL) pt->before = p;
}
void cheng(struct ddl*p1, struct ddl*p2, struct ddl*p3, int a, int b)//乘法函数
//p1指向*号前一个字符，p2指向最后一个字符，p3是头，a,b是位数
{
	struct ddl*p, *q, *p0 = p2;
	int i, j;
	p = q = (struct ddl*)malloc(sizeof(struct ddl));
	(p3->before)->next = p, p->before = p3->before, p->num = 0;
	for (i = 0; i < a + b - 1; i++)//a位乘b位结果不超过a+b位
	{
		p = (struct ddl*)malloc(sizeof(struct ddl));
		p->before = q, q->next = p, q = p, p->num = 0;
	}
	p->next = p2->next;
	if (p2->next != NULL) (p2->next)->before = p;
	for (i = 0; i < a; i++, p = p->before, p1 = p1->before)
		for (q = p, p2 = p0, j = 0; j < b; q = q->before, p2 = p2->before, j++)
			q->num += p1->num*p2->num, (q->before)->num += q->num / 10, q->num = q->num % 10;
}
void jia(struct ddl*p1, struct ddl*p2, struct ddl*p3, struct ddl*p4, int a, int b)//加法
{
	struct ddl*p, *q;
	int i;
	p = q = (struct ddl*)malloc(sizeof(struct ddl));
	(p3->before)->next = p, p->before = p3->before, p->num = 0;
	for (i = 0; i < a; i++)
	{
		p = (struct ddl*)malloc(sizeof(struct ddl));
		p->before = q, q->next = p, q = p, p->num = 0;
	}
	p->next = p4->next;
	if (p4->next != NULL) (p4->next)->before = p;
	for (i = 0; i < b; i++)
		p->num = p1->num + p2->num, p1 = p1->before, p2 = p2->before, p = p->before;
	for (; i < a; i++)
		p->num = p1->num, p1 = p1->before, p = p->before;
	for (i = 0; i < a; i++, q = q->before)
		if (q->num > 9)
			q->num -= 10, (q->before)->num++;
}
