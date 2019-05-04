    #include<iostream>  
    using namespace std;  
    #include<cstring>  
int main(void)  
{  
    int *m = new int[100001];  
    int *exist = new int[100001];  
    memset(m, -1, sizeof(m));  
    memset(exist, -1, sizeof(exist));  
    int sum;  
    int a, b;  
    scanf("%d %d %d", &a, &b, &sum);  
    m[a] = -1;  
    m[b] = -1;  
  
    for (int i = 0; i < sum; i++)  
    {  
        char tmp[10];  
        int pre, next;  
        scanf("%d %s %d", &pre, tmp, &next);  
        m[pre] = next;  
    }  
    int head = a;  
    while (head != -1)  
    {//把第一个链表存进哈希表 exist中  
        exist[head] = 1;  
        head = m[head];  
    }  
    head = b;  
    while (head != -1)  
    {  
        if (exist[head] == 1)  
        {  
            break;  
        }  
        head = m[head];  
    }  
    if (head != -1)  
        printf("%05d\n", head);  
    else  
        printf("%d\n", head);  
  
    return 0;  
}  
