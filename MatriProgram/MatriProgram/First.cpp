#include<atlstr.h>
#include<iostream>
#include<string>
using namespace std;
//��������
float **Creat(int n)
{
    float **array=new float*[n];
    for(int i=0;i<n;i++)
    {
        array[i]=new float[n];
    }
    printf("���������\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>array[i][j];
        }
    }
    return array;
}
//������ʽ��ֵ��
float Value(float **array,int n)
{
    float Result=0;
    if(n==1) return array[0][0];
    float **temp=new float*[n-1];
    for(int i=0;i<n-1;i++)
    {
        temp[i]=new float[n-1];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            for(int k=0;k<n-1;k++)
            {
                int flag;
                if(j<i)  flag=0;
                else flag=1;
                temp[j][k]=array[j+flag][k+1];
            }
        }
        int flag2=-1;
        if(i%2==0) flag2=1;
        Result+=flag2*array[i][0]*Value(temp,n-1);
    }
    return Result;
}
//������� �����������ʽ��ֵ��������ʽ��ֵ
float **GetMarin(float **array,int n)
{
    float **resultMarin=array;
    float resultSum=Value(array,n);
    float **temp=new float*[n-1];
    for(int i=0;i<n-1;i++)
    {
        temp[i]=new float[n-1];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n-1;k++)
            {
                for(int m=0;m<n-1;m++)
                {
                    int flag1=0;
                    int flag2=0;
                    if(k<i) flag1=0;
                    else flag1=1;
                    if(m<j) flag2=0;
                    else flag2=1;
                    temp[k][m]=array[k+flag1][m+flag2];
                }
            }
            int flag3=-1;
            if((i+j)%2==0) flag3=1;
            resultMarin[j][i]=(float)flag3*Value(temp,n-1)/resultSum;
        }
    }
    return resultMarin;
}
//����Ӽ�
float **GetAdd(float **array1,float **array2,int rowCount,int columCount,float v)
{
	float **result=new float*[rowCount];
	for(int i=0;i<rowCount;i++)
	{
		result[i]=new float[columCount];
	}
	for(int i=0;i<rowCount;i++)
	{
		for(int j=0;j<columCount;j++)
		{
			 result[i][j]=array1[i][j]+v*array2[i][j];
		}
	}
	return result;
}
//��������
float **Matrixk(float **arry,int rowCount,int columCount,int k)
{
	float **result=new float*[rowCount];
	for(int i=0;i<rowCount;i++)
	{
		result[i]=new float[columCount];
	}
	for(int i=0;i<rowCount;i++)
	{
		for(int j=0;j<columCount;j++)
		{
			 result[i][j]=k*(arry[i][j]);
		}
	}
	return result;
}
//��������
float **MatrixCheng(float **arry1,float **arry2,int rowCount1,int columCount1,int rowCount2,int columCount2)
{
	if(columCount1!=rowCount2)
	{
		return NULL;
	}
	float **result=new float*[rowCount1];
	for(int i=0;i<rowCount1;i++)
	{
		result[i]=new float[columCount2];
	}
	//��������
	for(int i=0;i<rowCount1;i++)
	{
		for(int j=0;j<columCount2;j++)
		{
			float temp=0;
			for(int k=0;k<columCount1;k++)
			{
				temp+=arry1[i][k]*arry2[k][j];
			}
			result[i][j]=temp;
		}
	}
	return result;
}
/***********������в��ԣ�Ϊ�˷��㣬ȫ�����õķ���**********/
void OutPut(float **array,int n)
{
    printf("��������\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%f ",array[i][j]);
        }
        printf("\n");
    }
}
void test()
{
	printf("������������е�����:\n1.������ʽֵ\n2.�������\n3.����Ӽ�����\n4.������������\n");
	int choise=0;
	cin>>choise;
	if(choise==1)
	{
		   printf("�����������������Ľ�����");
			int n;
		  cin>>n;
		  float **array=Creat(n);
		 float Result=Value(array,n); 
		 printf("����ʽ��ֵ=%f\n",Result);
	}
	else if(choise==2)
	{
		   printf("�����������������Ľ�����");
			int n;
		  cin>>n;
		  float **array=Creat(n);
		 float Result=Value(array,n); 
		   if(Result==0) 
		   {
			printf("�þ���û�������\n");
		   }
		else
		{
		  float **resultMarin=GetMarin(array,n);
		  OutPut(resultMarin,n);
		}
	}
	else if(choise==3)
	{
		  printf("�����������������1�Ľ�����");
			int n1;
		  cin>>n1;
		  float **array1=Creat(n1);
	     printf("�����������������2�Ľ�����");
			int n2;
		  cin>>n2;
		  float **array2=Creat(n2);
		  printf("����������ϵ����");
		  float opreation=0;
		  cin>>opreation;
		  float **resultMarin=GetAdd(array1,array2,n1,n1,opreation);
	  	  OutPut(resultMarin,n1);
	}
	else if(choise==4)
	{
		   printf("�����������������1�Ľ�����");
			int n1;
		  cin>>n1;
		  float **array1=Creat(n1);
	     printf("�����������������2�Ľ�����");
			int n2;
		  cin>>n2;
		  float **array2=Creat(n2);
		  float **resultMarin=MatrixCheng(array1,array2,n1,n1,n2,n2);
	  	  OutPut(resultMarin,n1);
	}
	else
	{
		printf("------------");
	}
    test();
}
void main()
{
    test();
}