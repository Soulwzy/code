#include <stdio.h>  
#include <string.h>  
#include <math.h>  
#include <stdlib.h>  
#include <time.h>  
#define cities 10//城市的个数  
#define num 10//种群的大小  
#define MAX 100//最大迭代次数  
#define pm  0.05//变异的概率  
#define pc 0.8//交配的概率  
int distance[cities + 1][cities + 1];
typedef struct node//染色体的结构，也就是一组解  
{
	int city[cities];//每一个基因，也就是10座城市  
	int adapt;//该组解的适应性  
	double p;//在种群中幸存的概率  
}node;
node group[num], grouptemp[num];//grouptemp是为了在选择是临时存储group内的数据  
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
	printf("城市的距离矩阵如下:\n");
	for (i = 0; i<cities; i++)
	{
		for (j = 0; j<cities; j++)
			printf("%4d", distance[i][j]);
		printf("\n");
	}

}
void groupproduce()//该函数是随机生成10个n=10的全排列,作为初始种群  
{
	int i, j, k, t, flag;
	for (i = 0; i<num; i++)
		for (j = 0; j<cities; j++)
			group[i].city[j] = -1;
	srand(time(NULL));
	for (i = 0; i<num; i++)//以下方法是求全排列  
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
	printf("初始种群\n");
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
	int sumdistance1, sumdistance2 = 0;//1是计算某个染色体内的路径值和（10个城市加起来），是计算某个种群内所有染色体的路径值和（即是1的和）  
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
	//注意上面group[i].adapt保存的是每一条染色体上的路径长度，但是路径越长，生存概率越小  
	//解决办法是计算每一条染色体   1-group[i].adapt/总的路径长度  
	//这样确实满足路径越短，生存概率高，但是这样算出来所有染色体出现概率之和不为1  
	//所以再把出现概率求和，用每一个概率除以总和（这个是不是归一化？）  
	sump = 0;
	for (i = 0; i<num; i++)
	{
		group[i].p = 1 - (double)group[i].adapt / (double)sumdistance2;
		sump += group[i].p;
	}
	for (i = 0; i<num; i++)
		group[i].p = group[i].p / sump;
	for (i = 0; i<num; i++)
		printf("染色体%d的路径之和与生存概率分别为%4d   %.4f\n", i, group[i].adapt, group[i].p);
}
//这里还是轮盘赌选择，即对于随机生成一个概率，从0开始，依次累加每一个染色体，一旦发现和大于这个概率就认为最后一个加进去是这次选择的胜利者  
//由于要保证种群大小不变，所以选择num次,同时为了避免每一次都累加，则事先将累加结果保存到gradient中.  
void xuanze()
{
	int i, j, temp;
	double gradient[num];
	double t;
	int xuan[num];
	for (i = 0; i<num; i++)
		gradient[i] = 0.0;
	gradient[0] = group[0].p;//先开始累加  
	for (i = 1; i<num; i++)
		gradient[i] = gradient[i - 1] + group[i].p;
	srand(time(NULL));
	for (i = 0; i<num; i++)//为保证种群大小不变  
	{
		t = (rand() % 100);//每一次随机生成1个概率  
		t = t / 100;
		for (j = 0; j<num; j++)
			if (gradient[j]>t)//最后添加进去的存活  
			{
				xuan[i] = j;//第i次选择的是第j条染色体  
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
	int t;//参与交配的染色体的个数  
	int point1, point2, temp, c, d;//交配断点  
	int pointnum;
	int temp1, temp2;
	int map1[cities];
	int map2[cities];
	double jiaopeip[num];//染色体的交配的概率  
	int jiaopeiflag[num];//染色体的可交配的情况  
	for (i = 0; i<num; i++)
		jiaopeiflag[i] = -1;
	srand(time(NULL));
	for (i = 0; i<num; i++)
	{
		jiaopeip[i] = rand() % 100;
		jiaopeip[i] /= 100;
	}
	t = 0;//统计能交配的个数  
	for (i = 0; i<num; i++)
		if (jiaopeip[i]<pc)
		{
			jiaopeiflag[t] = i;
			t++;
		}
	t = t / 2 * 2;//保证t为偶数,这里最理想的自然是8了，因为pc是0.8  
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
			map1[group[temp1].city[k]] = group[temp2].city[k];//对于map1记录第一个染色体的某个基因对应第二个染色体的某个基因（关键！)  
			map2[group[temp2].city[k]] = group[temp1].city[k];//对于map2记录第二个染色体的某个基因对应第二个染色体的某个基因  
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
		printf("处理冲突.........\n");//首先交换分割点两边的基因片段，然后判断新的左边，新的右边是否与中间片段有重复（因为要求是全排列）  
		//如果有重复则左边的重复元素变为中间的元素所对应的另一条染色体上的基因  
		//最后因为担心这次操作完后左边的重复元素可能又与中间的另外元素重复，所以还得从头扫一遍  
		for (k = 0; k<point1; k++)//先处理第一条染色体  
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
				printf("%4d", group[i].city[j]);//输出10条幸存的路径  
			printf("\n");
		}
		//处理第二条染色体  
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
void bianyi()//变异（正常是某一个基因突变，考虑到这里必须要全排列）就是交换两个节点。  
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
			bianyiflag[i] = 1;//标记需要变异的基因  
		}
	}
	srand(time(NULL));
	//开始变异，找到需要变异的染色体，交换染色体的两个节点  
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
			max = group[i].p;//更新最大概率  
			j = i;
		}
	printf("最佳路径为:\n");
	for (i = 0; i<cities; i++)
		printf("%d ", group[j].city[i]);
	printf("\n");
	printf("最短tsp路径为:%d\n", group[j].adapt);
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
	printf("当前幸存路径为：\n");
	for (i = 0; i<num; i++)
	{
		for (j = 0; j<cities; j++)
			printf("%4d", group[i].city[j]);//输出10条幸存的路径  
		printf("\n");
	}
	shuaixuan();//在当前10组数据中找出最优解  
	return 0;
}