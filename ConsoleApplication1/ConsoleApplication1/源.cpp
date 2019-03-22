#include <stdio.h>  
#include <string.h>  
#include <math.h>  
#include <stdlib.h>  
#include <time.h>  
#define cities 10//���еĸ���  
#define num 10//��Ⱥ�Ĵ�С  
#define MAX 100//����������  
#define pm  0.05//����ĸ���  
#define pc 0.8//����ĸ���  
int distance[cities + 1][cities + 1];
typedef struct node//Ⱦɫ��Ľṹ��Ҳ����һ���  
{
	int city[cities];//ÿһ������Ҳ����10������  
	int adapt;//��������Ӧ��  
	double p;//����Ⱥ���Ҵ�ĸ���  
}node;
node group[num], grouptemp[num];//grouptemp��Ϊ����ѡ������ʱ�洢group�ڵ�����  
void init()
{
	int i, j;
	memset(distance, 0, sizeof(distance));
	srand(time(NULL));
	for (i = 0; i<cities; i++)
		for (j = i + 1; j<cities; j++)
		{
			distance[i][j] = rand() % 100;
			distance[j][i] = distance[i][j];
		}
	printf("���еľ����������:\n");
	for (i = 0; i<cities; i++)
	{
		for (j = 0; j<cities; j++)
			printf("%4d", distance[i][j]);
		printf("\n");
	}

}
void groupproduce()//�ú������������10��n=10��ȫ����,��Ϊ��ʼ��Ⱥ  
{
	int i, j, k, t, flag;
	for (i = 0; i<num; i++)
		for (j = 0; j<cities; j++)
			group[i].city[j] = -1;
	srand(time(NULL));
	for (i = 0; i<num; i++)//���·�������ȫ����  
		for (j = 0; j<cities; j++)
		{
			t = rand() % cities;
			flag = 1;
			for (k = 0; k<j; k++)
				if (group[i].city[k] == t)
				{
					flag = 0;
					break;
				}
			if (flag == 0)
				j--;
			else
				group[i].city[j] = t;
		}
	printf("��ʼ��Ⱥ\n");
	for (i = 0; i<num; i++)
	{
		for (j = 0; j<cities; j++)
			printf("%4d", group[i].city[j]);
		printf("\n");
	}
}
void pingjia()
{
	int i, j;
	int n1, n2;
	int sumdistance1, sumdistance2 = 0;//1�Ǽ���ĳ��Ⱦɫ���ڵ�·��ֵ�ͣ�10�����м����������Ǽ���ĳ����Ⱥ������Ⱦɫ���·��ֵ�ͣ�����1�ĺͣ�  
	double sump = 0;
	for (i = 0; i<num; i++)
	{
		sumdistance1 = 0;
		for (j = 1; j<cities; j++)
		{
			n1 = group[i].city[j - 1];
			n2 = group[i].city[j];
			sumdistance1 += distance[n1][n2];
		}
		group[i].adapt = sumdistance1;
		sumdistance2 += sumdistance1;
	}
	//ע������group[i].adapt�������ÿһ��Ⱦɫ���ϵ�·�����ȣ�����·��Խ�����������ԽС  
	//����취�Ǽ���ÿһ��Ⱦɫ��   1-group[i].adapt/�ܵ�·������  
	//����ȷʵ����·��Խ�̣�������ʸߣ������������������Ⱦɫ����ָ���֮�Ͳ�Ϊ1  
	//�����ٰѳ��ָ�����ͣ���ÿһ�����ʳ����ܺͣ�����ǲ��ǹ�һ������  
	sump = 0;
	for (i = 0; i<num; i++)
	{
		group[i].p = 1 - (double)group[i].adapt / (double)sumdistance2;
		sump += group[i].p;
	}
	for (i = 0; i<num; i++)
		group[i].p = group[i].p / sump;
	for (i = 0; i<num; i++)
		printf("Ⱦɫ��%d��·��֮����������ʷֱ�Ϊ%4d   %.4f\n", i, group[i].adapt, group[i].p);
}
//���ﻹ�����̶�ѡ�񣬼������������һ�����ʣ���0��ʼ�������ۼ�ÿһ��Ⱦɫ�壬һ�����ֺʹ���������ʾ���Ϊ���һ���ӽ�ȥ�����ѡ���ʤ����  
//����Ҫ��֤��Ⱥ��С���䣬����ѡ��num��,ͬʱΪ�˱���ÿһ�ζ��ۼӣ������Ƚ��ۼӽ�����浽gradient��.  
void xuanze()
{
	int i, j, temp;
	double gradient[num];
	double t;
	int xuan[num];
	for (i = 0; i<num; i++)
		gradient[i] = 0.0;
	gradient[0] = group[0].p;//�ȿ�ʼ�ۼ�  
	for (i = 1; i<num; i++)
		gradient[i] = gradient[i - 1] + group[i].p;
	srand(time(NULL));
	for (i = 0; i<num; i++)//Ϊ��֤��Ⱥ��С����  
	{
		t = (rand() % 100);//ÿһ���������1������  
		t = t / 100;
		for (j = 0; j<num; j++)
			if (gradient[j]>t)//�����ӽ�ȥ�Ĵ��  
			{
				xuan[i] = j;//��i��ѡ����ǵ�j��Ⱦɫ��  
				break;
			}
	}
	for (i = 0; i<num; i++)
	{
		grouptemp[i].adapt = group[i].adapt;
		grouptemp[i].p = group[i].p;
		for (j = 0; j<cities; j++)
			grouptemp[i].city[j] = group[i].city[j];
	}
	for (i = 0; i<num; i++)
	{
		temp = xuan[i];
		group[i].adapt = grouptemp[temp].adapt;
		group[i].p = grouptemp[temp].p;
		for (j = 0; j<cities; j++)
			group[i].city[j] = grouptemp[temp].city[j];
	}
}
void jiaopei()
{
	int i, j, k, kk, kkk, flag;
	int t;//���뽻���Ⱦɫ��ĸ���  
	int point1, point2, temp, c, d;//����ϵ�  
	int pointnum;
	int temp1, temp2;
	int map1[cities];
	int map2[cities];
	double jiaopeip[num];//Ⱦɫ��Ľ���ĸ���  
	int jiaopeiflag[num];//Ⱦɫ��Ŀɽ�������  
	for (i = 0; i<num; i++)
		jiaopeiflag[i] = -1;
	srand(time(NULL));
	for (i = 0; i<num; i++)
	{
		jiaopeip[i] = rand() % 100;
		jiaopeip[i] /= 100;
	}
	t = 0;//ͳ���ܽ���ĸ���  
	for (i = 0; i<num; i++)
		if (jiaopeip[i]<pc)
		{
			jiaopeiflag[t] = i;
			t++;
		}
	t = t / 2 * 2;//��֤tΪż��,�������������Ȼ��8�ˣ���Ϊpc��0.8  
	srand(time(NULL));
	temp1 = 0;
	c = 0;
	d = 1;
	for (i = 0; i<t / 2; i++)
	{
		point1 = rand() % cities;
		point2 = rand() % cities;
		if (point1>point2)
		{
			temp = point1;
			point1 = point2;
			point2 = temp;
		}
		temp1 = jiaopeiflag[c];
		temp2 = jiaopeiflag[d];
		c = c + 2;
		d = d + 2;
		memset(map1, -1, sizeof(map1));
		memset(map2, -1, sizeof(map2));
		for (k = point1; k <= point2; k++)
		{
			map1[group[temp1].city[k]] = group[temp2].city[k];//����map1��¼��һ��Ⱦɫ���ĳ�������Ӧ�ڶ���Ⱦɫ���ĳ�����򣨹ؼ���)  
			map2[group[temp2].city[k]] = group[temp1].city[k];//����map2��¼�ڶ���Ⱦɫ���ĳ�������Ӧ�ڶ���Ⱦɫ���ĳ������  
		}
		for (k = 0; k<point1; k++)
		{
			temp = group[temp1].city[k];
			group[temp1].city[k] = group[temp2].city[k];
			group[temp2].city[k] = temp;
		}
		for (k = point2 + 1; k<cities; k++)
		{
			temp = group[temp1].city[k];
			group[temp1].city[k] = group[temp2].city[k];
			group[temp2].city[k] = temp;
		}
		printf("�����ͻ.........\n");//���Ƚ����ָ�����ߵĻ���Ƭ�Σ�Ȼ���ж��µ���ߣ��µ��ұ��Ƿ����м�Ƭ�����ظ�����ΪҪ����ȫ���У�  
		//������ظ�����ߵ��ظ�Ԫ�ر�Ϊ�м��Ԫ������Ӧ����һ��Ⱦɫ���ϵĻ���  
		//�����Ϊ������β��������ߵ��ظ�Ԫ�ؿ��������м������Ԫ���ظ������Ի��ô�ͷɨһ��  
		for (k = 0; k<point1; k++)//�ȴ����һ��Ⱦɫ��  
			for (kk = point1; kk <= point2; kk++)
				if (group[temp1].city[k] == group[temp1].city[kk])
				{
					group[temp1].city[k] = map1[group[temp1].city[k]];
					kk = point1 - 1;
				}
		for (k = point2 + 1; k<cities; k++)
			for (kk = point1; kk <= point2; kk++)
				if (group[temp1].city[k] == group[temp1].city[kk])
				{
					group[temp1].city[k] = map1[group[temp1].city[k]];
					kk = point1 - 1;

				}
		for (i = 0; i<num; i++)
		{
			for (j = 0; j<cities; j++)
				printf("%4d", group[i].city[j]);//���10���Ҵ��·��  
			printf("\n");
		}
		//����ڶ���Ⱦɫ��  
		for (k = 0; k<point1; k++)
			for (kk = point1; kk <= point2; kk++)
				if (group[temp2].city[k] == group[temp2].city[kk])
				{
					group[temp2].city[k] = map2[group[temp2].city[k]];
					kk = point1 - 1;
				}
		for (k = point2 + 1; k<cities; k++)
			for (kk = point1; kk <= point2; kk++)
				if (group[temp2].city[k] == group[temp2].city[kk])
				{
					group[temp2].city[k] = map2[group[temp2].city[k]];
					kk = point1 - 1;
				}
	}
}
void bianyi()//���죨������ĳһ������ͻ�䣬���ǵ��������Ҫȫ���У����ǽ��������ڵ㡣  
{
	int i, j;
	int temp1, temp2, temp;
	double bianyip[num];
	int bianyiflag[num];
	for (i = 0; i<num; i++)
		bianyiflag[i] = 0;
	srand(time(NULL));
	for (i = 0; i<num; i++)
	{
		bianyip[i] = rand() % 100;
		bianyip[i] /= 100;
	}
	for (i = 0; i<num; i++)
	{
		if (bianyip[i]<pm)
		{
			bianyiflag[i] = 1;//�����Ҫ����Ļ���  
		}
	}
	srand(time(NULL));
	//��ʼ���죬�ҵ���Ҫ�����Ⱦɫ�壬����Ⱦɫ��������ڵ�  
	for (i = 0; i<num; i++)
		if (bianyiflag[i] == 1)
		{
			temp1 = rand() % 10;
			temp2 = rand() % 10;
			temp = group[i].city[temp1];
			group[i].city[temp1] = group[i].city[temp2];
			group[i].city[temp2] = temp;
		}
}
void shuaixuan()
{
	int i, j;
	double max;
	max = group[0].p;
	j = 0;
	for (i = 1; i<num; i++)
		if (max<group[i].p)
		{
			max = group[i].p;//����������  
			j = i;
		}
	printf("���·��Ϊ:\n");
	for (i = 0; i<cities; i++)
		printf("%d ", group[j].city[i]);
	printf("\n");
	printf("���tsp·��Ϊ:%d\n", group[j].adapt);
}
int main()
{
	int i, j, t, m;
	init();
	groupproduce();
	t = 0;
	while (t<MAX)
	{
		pingjia();
		xuanze();
		jiaopei();
		bianyi();
		t++;
	}
	printf("��ǰ�Ҵ�·��Ϊ��\n");
	for (i = 0; i<num; i++)
	{
		for (j = 0; j<cities; j++)
			printf("%4d", group[i].city[j]);//���10���Ҵ��·��  
		printf("\n");
	}
	shuaixuan();//�ڵ�ǰ10���������ҳ����Ž�  
	return 0;
}