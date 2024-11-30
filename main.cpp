#include <iostream>

using namespace std;
#define Elemtype int
#define MAXSIZE 200

//-------------------------------------------˳���----------------------------------------------------------------------

// ˳���
typedef struct {
    Elemtype* data;
    int length;
} SSQList,*SQList;


// ˳��� L �ĳ�ʼ��
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

// ˳��������
void DestroySQList(SQList L) {
    delete[] L->data;
}

// ˳�������
void ClearSQList(SQList L) {
    L->length = 0;
}

// ��˳���ĳ���
int GetLengthSQList(SQList L) {
    return L->length;
}

// �ж�˳����Ƿ�Ϊ��
bool IsEmptySQList(SQList L) {
    if (L->length) {
        return false;
    }
    else {
        return true;
    }
}

// ˳���ֵ�Ļ�ȡ
Elemtype GetElemSQList(SQList L, int i) {
    if (i < 1 || i > L->length) {
        cout << "��Խ����" << endl;
        return 0;
    }

    return L->data[i - 1];
}

// ˳���ĸ�ֵ����
int LocateElem(SQList L, Elemtype e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i;
        }
    }

    cout << "�Ҳ�������" << endl;
}

// ˳���Ĳ���
void InsertSQList(SQList L, int i, Elemtype e) {
    if (i < 1 || i > L->length + 1) {
        cout << "��Խ����" << endl;
        exit;
    }
    if (L->length == MAXSIZE) {
        cout << "�治����" << endl;
        exit;
    }

    for (int j = L->length - 1; j >= i - 1; j--) {
        L->data[j + 1] = L->data[j];
    }
    L->data[i - 1] = e;
    L->length++;
}

// ˳����ĩβ����
void PushSQList(SQList L, Elemtype e) {
    InsertSQList(L, L->length + 1, e);
}


//˳���ı���
void ShowSQList(SQList L) {
    for (int i = 0; i < L->length; i++) {
        cout << L->data[i] << " ";
    }
    cout << endl;
}


//˳����ɾ��
void DeleteElemSQList(SQList L,int i)
{
    i--;
    if(i<1||i> GetLengthSQList(L))
    {
        cout<<"˳���ɾ��Ԫ�أ�Խ��"<<endl;
    }

    for(int j=i;j<= GetLengthSQList(L);j++)
    {
        L->data[j]=L->data[j+1];
    }
    L->length--;
}

//------------------------------------������(����ͷ��----------------------------------------------------------------------

//����
typedef struct LNode{
    Elemtype data;
    LNode *next;

}LNode,*NodeList;



//����ĳ�ʼ��
NodeList InitList()
{
    NodeList L;
    L=new LNode;
    L->next= nullptr;
    return L;

}

//������п�
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

//���������
int DestroyList(NodeList L)
{
    NodeList p;
    while(L)
    {
        p=L;
        L=L->next;
        delete p;//һ��һ������ɾ��
    }
    return 1;
}

//��������
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

//������ı�
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

//��ȡ��i��Ԫ��
Elemtype GetElemList(NodeList L,int i)
{
    if(i<1||i>GetLengthList(L))
    {
        cout<<"��ȡԪ�أ�Խ��"<<endl;
    }
    NodeList p;
    p=L;
    for(int j=1;j<=i;j++)
    {
        p=p->next;
    }
    return p->data;
}

//������ĸ�ֵ����
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
    cout<<"��ֵ����:�Ҳ�������"<<endl;
}


//���i��������eֵ
int InsertList(NodeList L,int i,Elemtype e)
{
    if(i<1||i>GetLengthList(L))
    {
        cout<<"���룺Խ��"<<endl;
    }
    NodeList p;
    NodeList k;
    p=L;
    for(int j=1;j<=i-1;j++)
    {
        p=p->next;
    }
    //ѭ��������p��i��ǰһ��Ԫ��
    k=p->next;//k�ǵ�i��Ԫ��
    NodeList q=new LNode;
    q->data=e;
    p->next=q;
    q->next=k;
    return 1;

}

//ɾ���������еĵ�i��Ԫ��
int DeleteElemList(NodeList L,int i)
{
    if(i<1||i>GetLengthList(L))
    {
        cout<<"ɾ��Ԫ�أ�Խ��"<<endl;
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

//��������
void ShowList(NodeList L)
{
    NodeList p=L->next;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}


//ĩβ����
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


//----------------------------------------------ջ����ʽ��----------------------------------------------------------------
//ջ���ض���
NodeList InitStack()
{
    return InitList();
}

//��ջ
void PushStack(NodeList L,Elemtype e)
{
    PushList(L,e);
}

//��ջ
Elemtype PopStack(NodeList L)
{
    Elemtype q=GetElemList(L, GetLengthList(L));
    DeleteElemList(L, GetLengthList(L));
    return  q;

}

//ֻ��ȡ����ջ
Elemtype peekStack(NodeList L)
{
    return GetElemList(L, GetLengthList(L));
}

//�п�
bool IsEmptyStack(NodeList L)
{
    return IsEmptyList(L);
}

//����ջ
void ShowStack(NodeList L)
{
    ShowList(L);
}



//����ջ��ʮ����ת������
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


//-------------------------------------------------------��------------------------------------------------------------
typedef struct
{
    char *data;
    int len;
}SString,*SSString;



//���ĳ�ʼ��
SSString InitString()
{
    SSString S=new SString ;
    S->data = nullptr;
    S->len=0;
    return S;

}

//���Ĳ���
void AssignString(SSString S,char *data){
    if(S->data)
        free(S->data);
    int len = 0;
    char* temp = data;

    while (*temp){    //*temp��������tempָ����ָ��ֵ
        len ++ ;
        temp++;       //ָ��ԭ��λ�ú��һ���ַ�
    }

    if(len == 0){
        S->data = NULL;
        S->len = 0;
    }
    else{
        temp = data;
        S->len = len;
        S->data = (char*)malloc(sizeof(char)*(len+1));  //�ַ������ȼ�һλ���ڱ�ʶ����
        for(int i= 0; i<len+1; i++,temp++){
            S->data[i] = *temp;
        }
    }
}

void AssignElemString(SSString S,char e)
{
    int len = S->len;
    S->data = (char*)malloc(sizeof(char)*(len+1));  //�ַ������ȼ�һλ���ڱ�ʶ����
    S->data[len]=e;
    S->len++;
}


//���ı������
void ShowString(SSString S)
{
    int len1=S->len;
    for(int i=0;i<len1;i++)
    {
        cout<<S->data[i];
    }
    cout<<endl;
}


//��������
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


//���ĳ���
int GetLengthString(SSString s)
{
    return s->len;
}


//���Ľ�ȡ
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

//���ıȽ�
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

//ģʽƥ��
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

//���Ĳ���
void InsertString(SSString s, int i, SSString t) {
    if (i < 1 || i > s->len + 1) {
        // ����λ�ò��Ϸ�
        return;
    }
    int sLen = s->len;
    int tLen = t->len;
    int newLen = sLen + tLen;
    char* newData = new char[newLen + 1];
    // �� s ��ǰ i - 1 ���ַ����Ƶ� newData
    for (int j = 0; j < i - 1; j++) {
        newData[j] = s->data[j];
    }
    // �� t ���ַ����Ƶ� newData
    for (int j = 0; j < tLen; j++) {
        newData[j + i - 1] = t->data[j];
    }
    // �� s ��ʣ���ַ����Ƶ� newData
    for (int j = i - 1; j < sLen; j++) {
        newData[j + tLen] = s->data[j];
    }
    newData[newLen] = '\0';
    delete[] s->data;
    s->data = newData;
    s->len = newLen;
}


//����ɾ��
void DeleteString(SSString s, int i, int len) {
    if (i < 1 || i > s->len || len < 0 || len > s->len - i + 1) {
        // �������Ϸ�
        return;
    }
    int sLen = s->len;
    int newLen = sLen - len;
    char* newData = new char[newLen + 1];
    // ���� s ��ǰ i - 1 ���ַ�
    for (int j = 0; j < i - 1; j++) {
        newData[j] = s->data[j];
    }
    // ���� s �д� i + len λ�ÿ�ʼ���ַ�
    for (int j = i - 1 + len; j < sLen; j++) {
        newData[j - len] = s->data[j];
    }
    newData[newLen] = '\0';
    delete[] s->data;
    s->data = newData;
    s->len = newLen;
}




//�����滻
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
//ͳ���Ӵ���Ŀ
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
//�ַ����������
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


//�ַ�����λ�Ƚ�
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
    cout<<"-------------------------------------˳���------------------------------------------------------------------"<<endl;
    SQList L= InitSQLList();
    PushSQList(L,1);
    PushSQList(L,2);
    PushSQList(L,3);
    ShowSQList(L);
    cout<<"˳���ĸ���Ϊ"<<GetLengthSQList(L)<<endl;
    cout<<"˳���ֵ�ĵڶ���ֵΪ"<<GetElemSQList(L,2)<<endl;
    InsertSQList(L,2,5);
    cout<<"��ڶ�λ����5"<<endl;
    ShowSQList(L);
    cout<<"ɾ���ڶ�λԪ��"<<endl;
    DeleteElemSQList(L,2);
    ShowSQList(L);

    cout<<"---------------------------------------������----------------------------------------------------------------"<<endl;
    NodeList K=InitList();
    PushList(K,1);
    PushList(K,2);
    PushList(K,3);
    ShowList(K);
    cout<<endl;
    cout<<"˳���ĸ���Ϊ"<<GetLengthList(K)<<endl;
    cout<<"˳���ֵ�ĵڶ���ֵΪ"<<GetElemList(K,2)<<endl;
    InsertList(K,2,5);
    cout<<"��ڶ�λ����5"<<endl;
    ShowList(K);
    cout<<endl;
    cout<<"ɾ���ڶ�λԪ��"<<endl;
    DeleteElemList(K,2);
    ShowList(K);
    cout<<endl;

    cout<<"-----------------------------------------ջ-----------------------------------------------------------------"<<endl;
    int dec=0;
    cout<<"������ʮ������"<<endl;
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