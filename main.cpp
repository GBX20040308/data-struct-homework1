#include <iostream>

using namespace std;
#define Elemtype int
#define MAXSIZE 200

//-------------------------------------------顺序表----------------------------------------------------------------------

// 顺序表
typedef struct {
    Elemtype* data;
    int length;
} SSQList,*SQList;


// 顺序表 L 的初始化
SQList InitSQLList()
{   SQList L=new SSQList;
    L->data = new Elemtype[MAXSIZE];
    if (!L->data)
        exit(-1);
    else {
        L->length = 0;
    }
    return L;
}

// 顺序表的销毁
void DestroySQList(SQList L) {
    delete[] L->data;
}

// 顺序表的清空
void ClearSQList(SQList L) {
    L->length = 0;
}

// 求顺序表的长度
int GetLengthSQList(SQList L) {
    return L->length;
}

// 判断顺序表是否为空
bool IsEmptySQList(SQList L) {
    if (L->length) {
        return false;
    }
    else {
        return true;
    }
}

// 顺序表值的获取
Elemtype GetElemSQList(SQList L, int i) {
    if (i < 1 || i > L->length) {
        cout << "你越界了" << endl;
        return 0;
    }

    return L->data[i - 1];
}

// 顺序表的给值查找
int LocateElem(SQList L, Elemtype e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i;
        }
    }

    cout << "找不到对象" << endl;
}

// 顺序表的插入
void InsertSQList(SQList L, int i, Elemtype e) {
    if (i < 1 || i > L->length + 1) {
        cout << "你越界了" << endl;
        exit;
    }
    if (L->length == MAXSIZE) {
        cout << "存不下了" << endl;
        exit;
    }

    for (int j = L->length - 1; j >= i - 1; j--) {
        L->data[j + 1] = L->data[j];
    }
    L->data[i - 1] = e;
    L->length++;
}

// 顺序表的末尾插入
void PushSQList(SQList L, Elemtype e) {
    InsertSQList(L, L->length + 1, e);
}


//顺序表的遍历
void ShowSQList(SQList L) {
    for (int i = 0; i < L->length; i++) {
        cout << L->data[i] << " ";
    }
    cout << endl;
}


//顺序表的删除
void DeleteElemSQList(SQList L,int i)
{
    i--;
    if(i<1||i> GetLengthSQList(L))
    {
        cout<<"顺序表删除元素：越界"<<endl;
    }

    for(int j=i;j<= GetLengthSQList(L);j++)
    {
        L->data[j]=L->data[j+1];
    }
    L->length--;
}

//------------------------------------单链表(带表头）----------------------------------------------------------------------

//链表
typedef struct LNode{
    Elemtype data;
    LNode *next;

}LNode,*NodeList;



//链表的初始化
NodeList InitList()
{
    NodeList L;
    L=new LNode;
    L->next= nullptr;
    return L;

}

//链表的判空
bool IsEmptyList(NodeList L)
{
    if(L->next== nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }


}

//链表的销毁
int DestroyList(NodeList L)
{
    NodeList p;
    while(L)
    {
        p=L;
        L=L->next;
        delete p;//一个一个往后删完
    }
    return 1;
}

//链表的清空
int ClearList(NodeList L)
{
    NodeList p;
    NodeList q;
    q=L->next;
    while(q)
    {
        p=q;
        delete(p);
        q=q->next;
    }
    L->next= nullptr;
}

//求单链表的表长
int GetLengthList(NodeList L)
{
    int sum=0;
    NodeList p;
    p=L->next;
    while(p)
    {
        sum++;
        p=p->next;
    }
    return sum;
}

//获取第i个元素
Elemtype GetElemList(NodeList L,int i)
{
    if(i<1||i>GetLengthList(L))
    {
        cout<<"获取元素：越界"<<endl;
    }
    NodeList p;
    p=L;
    for(int j=1;j<=i;j++)
    {
        p=p->next;
    }
    return p->data;
}

//单链表的给值查找
int LocateElemList(NodeList L,Elemtype e)
{
    NodeList p;
    p=L->next;
    int i=1;
    while(p)
    {
        i++;
        if(p->data==e)
        {
            return i;
            break;
        }
        p=p->next;
    }
    cout<<"给值查找:找不到对象"<<endl;
}


//向第i个结点插入e值
int InsertList(NodeList L,int i,Elemtype e)
{
    if(i<1||i>GetLengthList(L))
    {
        cout<<"插入：越界"<<endl;
    }
    NodeList p;
    NodeList k;
    p=L;
    for(int j=1;j<=i-1;j++)
    {
        p=p->next;
    }
    //循环结束后，p是i的前一个元素
    k=p->next;//k是第i个元素
    NodeList q=new LNode;
    q->data=e;
    p->next=q;
    q->next=k;
    return 1;

}

//删除单链表中的第i个元素
int DeleteElemList(NodeList L,int i)
{
    if(i<1||i>GetLengthList(L))
    {
        cout<<"删除元素：越界"<<endl;
    }
    NodeList p;
    p=L;
    for(int j=1;j<=i-1;j++)
    {
        p=p->next;
    }
    NodeList q=p->next->next;
    delete(p->next);
    p->next=q;
    return 1;
}

//遍历链表
void ShowList(NodeList L)
{
    NodeList p=L->next;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}


//末尾插入
void PushList(NodeList L,Elemtype e)
{
    NodeList p=L;
    NodeList q;
   while(p)
   {
       q=p;
       p=p->next;
   }
   NodeList k=new LNode;
   k->data=e;
   q->next=k;
   k->next= nullptr;
}


//----------------------------------------------栈（链式）----------------------------------------------------------------
//栈的重定义
NodeList InitStack()
{
    return InitList();
}

//入栈
void PushStack(NodeList L,Elemtype e)
{
    PushList(L,e);
}

//出栈
Elemtype PopStack(NodeList L)
{
    Elemtype q=GetElemList(L, GetLengthList(L));
    DeleteElemList(L, GetLengthList(L));
    return  q;

}

//只读取不出栈
Elemtype peekStack(NodeList L)
{
    return GetElemList(L, GetLengthList(L));
}

//判空
bool IsEmptyStack(NodeList L)
{
    return IsEmptyList(L);
}

//遍历栈
void ShowStack(NodeList L)
{
    ShowList(L);
}



//测试栈：十进制转二进制
string DECtoBIN(int dec)
{
    NodeList L=InitStack();
    int count=0;
    while(1)
    {

        if(dec==0)
        {
            break;
        }
        else
        {
            PushStack(L,(dec%2));
            dec=dec/2;
            count++;

        }


    }
    string bin="";
    while(count--)
    {
        bin.append(to_string(PopStack(L)));
    }
    return bin;



}


//-------------------------------------------------------串------------------------------------------------------------
typedef struct
{
    char *data;
    int len;
}SString,*SSString;



//串的初始化
SSString InitString()
{
    SSString S=new SString ;
    S->data = nullptr;
    S->len=0;
    return S;

}

//串的插入
void AssignString(SSString S,char *data){
    if(S->data)
        free(S->data);
    int len = 0;
    char* temp = data;

    while (*temp){    //*temp用来访问temp指针所指的值
        len ++ ;
        temp++;       //指向原来位置后的一个字符
    }

    if(len == 0){
        S->data = NULL;
        S->len = 0;
    }
    else{
        temp = data;
        S->len = len;
        S->data = (char*)malloc(sizeof(char)*(len+1));  //字符串长度加一位用于标识结束
        for(int i= 0; i<len+1; i++,temp++){
            S->data[i] = *temp;
        }
    }
}

void AssignElemString(SSString S,char e)
{
    int len = S->len;
    S->data = (char*)malloc(sizeof(char)*(len+1));  //字符串长度加一位用于标识结束
    S->data[len]=e;
    S->len++;
}


//串的遍历输出
void ShowString(SSString S)
{
    int len1=S->len;
    for(int i=0;i<len1;i++)
    {
        cout<<S->data[i];
    }
    cout<<endl;
}


//串的链接
int ConcatString(SSString s1, SSString s2, SSString s) {
    if (s1 == NULL || s1->data == NULL || s2 == NULL || s2->data == NULL) {
        fprintf(stderr, "Invalid input strings.\n");
        return -1;
    }

    int totalLen = s1->len + s2->len;
    s->data = (char*)malloc((totalLen + 1) * sizeof(char));
    if (s->data == nullptr) {
        fprintf(stderr, "Memory allocation failed.\n");
        return -1;
    }

    int k = 0;
    for (int i = 0; i < s1->len; i++) {
        s->data[k++] = s1->data[i];
    }
    for (int i = 0; i < s2->len; i++) {
        s->data[k++] = s2->data[i];
    }
    s->data[k] = '\0';
    s->len = k;

    return 1;
}


//串的长度
int GetLengthString(SSString s)
{
    return s->len;
}


//串的截取
SSString SubString(SSString s, int i, int len) {
    if (s == NULL || i < 1 || i > s->len|| len < 0 || i + len - 1 > s->len) {
        return nullptr;
    }

    SSString s2 = InitString();
    s2->data = (char*)malloc(len * sizeof(char));
    s2->len = len;

    for (int j = 0; j < len; j++) {
        s2->data[j] = s->data[j + i - 1];
    }

    return s2;
}

//串的比较
int CmpString(SSString s1,SSString s2)
{
    int sum1=0;
    int sum2=0;
    for(int i=0;i<s1->len;i++)
    {
        sum1+=int(s1->data[i]);
    }

    for(int i=0;i<s2->len;i++) {
        sum2 += int(s2->data[i]);
    }

    if(sum1==sum2)
    {
        return 0;
    }
    else if(sum1<sum2)
    {
        return -1;
    }
    else if(sum1>sum2)
    {
        return 1;
    }

}

//模式匹配
int IndexString(SSString s, SSString t) {
    int sLen = s->len;
    int tLen = t->len;
    if (tLen > sLen) return -1;
    for (int i = 0; i <= sLen - tLen; i++) {
        bool found = true;
        for (int j = 0; j < tLen; j++) {
            if (s->data[i + j]!= t->data[j]) {
                found = false;
                break;
            }
        }
        if (found) return i + 1;
    }
    return -1;
}

//串的插入
void InsertString(SSString s, int i, SSString t) {
    if (i < 1 || i > s->len + 1) {
        // 插入位置不合法
        return;
    }
    int sLen = s->len;
    int tLen = t->len;
    int newLen = sLen + tLen;
    char* newData = new char[newLen + 1];
    // 将 s 中前 i - 1 个字符复制到 newData
    for (int j = 0; j < i - 1; j++) {
        newData[j] = s->data[j];
    }
    // 将 t 的字符复制到 newData
    for (int j = 0; j < tLen; j++) {
        newData[j + i - 1] = t->data[j];
    }
    // 将 s 中剩余字符复制到 newData
    for (int j = i - 1; j < sLen; j++) {
        newData[j + tLen] = s->data[j];
    }
    newData[newLen] = '\0';
    delete[] s->data;
    s->data = newData;
    s->len = newLen;
}


//串的删除
void DeleteString(SSString s, int i, int len) {
    if (i < 1 || i > s->len || len < 0 || len > s->len - i + 1) {
        // 参数不合法
        return;
    }
    int sLen = s->len;
    int newLen = sLen - len;
    char* newData = new char[newLen + 1];
    // 复制 s 中前 i - 1 个字符
    for (int j = 0; j < i - 1; j++) {
        newData[j] = s->data[j];
    }
    // 复制 s 中从 i + len 位置开始的字符
    for (int j = i - 1 + len; j < sLen; j++) {
        newData[j - len] = s->data[j];
    }
    newData[newLen] = '\0';
    delete[] s->data;
    s->data = newData;
    s->len = newLen;
}




//串的替换
void ReplaceString(SSString s, SSString t, SSString r) {
    if (t->len == 0) return;
    int sLen = s->len;
    int tLen = t->len;
    int rLen = r->len;
    char* newData = new char[sLen * rLen + 1];
    int newIndex = 0;
    for (int i = 0; i < sLen; ) {
        bool found = false;
        for (int j = 0; j < tLen && i + j < sLen; j++) {
            if (s->data[i + j]!= t->data[j]) {
                break;
            }
            if (j == tLen - 1) {
                found = true;
                break;
            }
        }
        if (found) {
            for (int j = 0; j < rLen; j++) {
                newData[newIndex++] = r->data[j];
            }
            i += tLen;
        } else {
            newData[newIndex++] = s->data[i++];
        }
    }
    newData[newIndex] = '\0';
    delete[] s->data;
    s->data = newData;
    s->len = newIndex;
}
//统计子串数目
int CountSubString(SSString S,SSString T)
{
    int sum=0;
    if(IndexString(S,T)==-1)
    {
        return 0;
    }
    while(IndexString(S,T)!=-1)
    {
        sum++;
        DeleteString(S, IndexString(S,T), 1);
    }
    return sum;
}

char GetElemString(SSString S,int i)
{
    return S->data[i-1];
}
//字符串倒序输出
SSString ReversePrintString(SSString S)
{
    char str[10000];
    SSString T=InitString();

    for(int i=0;i< GetLengthString(S);i++)
    {
        str[i]=S->data[GetLengthString(S)-i-1];
    }
    AssignString(T,str);

    return T;
}


//字符串按位比较
bool CompareStringBitwise(SSString S,SSString T)
{
    bool sw=true;
    if(S->len!=T->len)
    {
        return false;
    }

    for(int i=0;i<GetLengthString(S);i++)
    {
        if(S->data[i]==T->data[i])
        {

        }
        else
        {
            sw=false;
        }
    }
    return sw;

}
/*int main()
{
    cout<<"-------------------------------------顺序表------------------------------------------------------------------"<<endl;
    SQList L= InitSQLList();
    PushSQList(L,1);
    PushSQList(L,2);
    PushSQList(L,3);
    ShowSQList(L);
    cout<<"顺序表的个数为"<<GetLengthSQList(L)<<endl;
    cout<<"顺序表值的第二个值为"<<GetElemSQList(L,2)<<endl;
    InsertSQList(L,2,5);
    cout<<"向第二位插入5"<<endl;
    ShowSQList(L);
    cout<<"删除第二位元素"<<endl;
    DeleteElemSQList(L,2);
    ShowSQList(L);

    cout<<"---------------------------------------单链表----------------------------------------------------------------"<<endl;
    NodeList K=InitList();
    PushList(K,1);
    PushList(K,2);
    PushList(K,3);
    ShowList(K);
    cout<<endl;
    cout<<"顺序表的个数为"<<GetLengthList(K)<<endl;
    cout<<"顺序表值的第二个值为"<<GetElemList(K,2)<<endl;
    InsertList(K,2,5);
    cout<<"向第二位插入5"<<endl;
    ShowList(K);
    cout<<endl;
    cout<<"删除第二位元素"<<endl;
    DeleteElemList(K,2);
    ShowList(K);
    cout<<endl;

    cout<<"-----------------------------------------栈-----------------------------------------------------------------"<<endl;
    int dec=0;
    cout<<"请输入十进制数"<<endl;
    cin>>dec;
    cout<<DECtoBIN(dec)<<endl;



}*/

int main()
{
    SSString S=InitString();
    SSString T=InitString();
    char str1[10000];
    cin>>str1;
    AssignString(S,str1);
  
}