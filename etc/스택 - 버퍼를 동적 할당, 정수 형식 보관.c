 
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Stack //Stack 구조체 정의
{
    int *buf;//저장소
    int ssize;//저장소 크기
    int top; //가장 최근에 보관한 인덱스
}Stack;
 
void InitStack(Stack *stack, int ssize);//스택 초기화
int IsFull(Stack *stack); //스택이 꽉 찼는지 확인
int IsEmpty(Stack *stack); //스택이 비었는지 확인
void Push(Stack *stack, int data); //스택에 보관
int Pop(Stack *stack); //스택에서 꺼냄
void DisposeStack(Stack *stack);//스택 해제화
int main(void)
{
    int i;
    Stack stack;
 
    InitStack(&stack, 10);//스택 초기화
    for (i = 1; i <= 5; i++)//1~5까지 스택에 보관
    {
        Push(&stack, i);
    }
    while (!IsEmpty(&stack))//스택이 비어있지 않다면 반복
    {
        printf("%d ", Pop(&stack));//스택에서 꺼내온 값 출력
    }
    printf("\n");
    DisposeStack(&stack);//스택 해제화
    return 0;
}
void InitStack(Stack *stack, int ssize)
{
    stack->buf = (int *)malloc(sizeof(int)*ssize);
    stack->ssize = ssize;
    stack->top = -1; //스택 초기화에서는 top을 -1로 설정
}
int IsFull(Stack *stack)
{
    return (stack->top + 1) == stack->ssize;//top+1 이 스택 크기와 같으면 꽉 찬 상태
}
int IsEmpty(Stack *stack)
{
    return stack->top == -1;    //top이 -1이면 빈 상태   
}
void Push(Stack *stack, int data)
{
    if (IsFull(stack))
    {
        printf("스택이 꽉 찼음\n");
        return;
    }
    stack->top++; //top을 1 증가
    stack->buf[stack->top] = data;   //데이터 보관
}
int Pop(Stack *stack)
{
    int re = 0;
    if (IsEmpty(stack))
    {
        printf("스택이 비었음\n");
        return re;
    }
    re = stack->buf[stack->top];//top 인덱스에 보관한 값을 re에 설정
    stack->top--;//top을 1 감소
    return re;
}
void DisposeStack(Stack *stack)
{
    free(stack->buf);
}
