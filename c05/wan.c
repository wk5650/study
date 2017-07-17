#include<stdio.h>
int main(){
	int year=1900,month=1,sum=0;
	while(1)
	{
		printf("请输入你想查询的年月：");
		scanf("%d%d",&year,&month);
		getchar();
		if(year<1900||month<1||month>12){
			printf("输入有误!");
		}else{
			break;
		}
	}
	for(int i=1900;i<year;i++)
	{
		if(i%4==0&&i%100!=0||i%400==0)
		{
			sum+=366;
		}
		else{
			sum+=365;
		}
	}
	int day=0;
	for(int j=1;j<=month;j++){
			switch(j){
				case 4:
				case 6:
		 		case 9:
				case 11:
					sum+=30;
					day=30;
					break;
				case 2:
					if(year%4==0&&year%100!=0||year%400==0)
					{
						sum+=29;
						day=29;
					}else{
						sum+=28;
						day=28;
					}
					break;
				default:
						sum+=31;
						day=31;
					}
	}
	sum-=day;
	int week=0;
	week=sum%7+1;
	printf("sun\tmon\ttue\twes\ttus\tfri\tsat\n");
	for(int i=1;i<=week;i++){
		printf("\t");
	}
	for(int j=1;j<=day;j++)
	{
		printf("%d\t",j);
		if((j+week)%7==0)
			printf("\n");
	}
	printf("\n");
}

