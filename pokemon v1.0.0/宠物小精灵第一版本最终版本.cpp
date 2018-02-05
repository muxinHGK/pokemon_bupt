#include<iostream>
#include<cmath>
#include<stdlib.h> 
#include<process.h>
#include<time.h> 
using namespace std;

void initfunc();//增加精灵的函数 
void printfunc();//查询精灵的函数 
void fightfunc();//模拟对战的函数 
void depokemon();//删除精灵的函数 

class Pokemon
{
 	public:
 		string name;
		string type;//共四种：力量型，防御型，高生命值型，敏捷型 
		int level;
		int attack;//攻击力 
		int defense;//防御力 
		int life;//生命值 
		int attacktime;//攻击间隔 
		int exp;//精灵当前的经验 
		int expforlevelup;//精灵升级需要的经验		
		Pokemon()
		{
			name="undefined";
			type="undefined";
			level=0;
			attack=0;
			defense=0;
			life=0;
			attacktime=0;
			exp=0;
			expforlevelup=0;
		}
		void show();//打印精灵的信息 
		virtual	void levelup(); //精灵的升级函数 
		virtual void attacktype();//精灵的攻击方式 
};

void Pokemon::show() 
{
	cout<<"名字："<<name<<endl; 
    cout<<"类型："<<type<<endl;
	cout<<"等级："<<level<<endl;
	cout<<"攻击力："<<attack<<endl;
	cout<<"防御力："<<defense<<endl;
	cout<<"生命值："<<life<<endl;
	cout<<"攻击间隔："<<attacktime<<endl;
	cout<<"当前经验："<<exp<<endl;
	cout<<"升级经验："<<expforlevelup<<endl<<endl;
}

void Pokemon::levelup(){};
void Pokemon::attacktype(){};

class Pokemon11:public Pokemon   //力量型皮卡丘子类 
{
 	public:	
		Pokemon11()
		{
			name="皮卡丘";
			type="攻击型";
			level=1;
			attack=60;
			defense=50;
			life=500;
			attacktime=50;
			exp=0;
			expforlevelup=10;
		}
		void levelup(); 
		void attacktype();
};


void Pokemon11::levelup()  //力量型精灵升级时各属性的变化 
{
	level++;
	attack+=20;  //力量型的精灵攻击力增加比其他类型的多 
	defense+=10;
	life+=100;
	attacktime-=1;
	exp=exp-expforlevelup;
	expforlevelup=level*10;
} 

void Pokemon11::attacktype()
{
	cout<<"十万伏特！"<<endl; 
}

class Pokemon12:public Pokemon   //力量型小火龙子类 
{
 	public:	
		Pokemon12()
		{
			name="小火龙";
			type="攻击型";
			level=1;
			attack=60;
			defense=50;
			life=500;
			attacktime=50;
			exp=0;
			expforlevelup=10;
		}
		void levelup(); 
		void attacktype();
};


void Pokemon12::levelup()  //力量型精灵升级时各属性的变化 
{
	level++;
	attack+=20;  //力量型的精灵攻击力增加比其他类型的多 
	defense+=10;
	life+=100;
	attacktime-=1;
	exp=exp-expforlevelup;
	expforlevelup=level*10;
} 

void Pokemon12::attacktype()
{
	cout<<"神龙烈焰！"<<endl; 
}


class Pokemon21:public Pokemon   //防御型铁甲蛹子类 
{
 	public:	
		Pokemon21()
		{
			name="铁甲蛹";
			type="防御型";
			level=1;
			attack=50;
			defense=60;
			life=500;
			attacktime=52;
			exp=0;
			expforlevelup=10;
		}
		void levelup(); 
		void attacktype();
};

void Pokemon21::levelup()  //防御型精灵升级时各属性的变化 
{
	level++;
	attack+=10;   
	defense+=20; //防御型精灵升级时防御属性的增加比其他类型的多 
	life+=100;
	attacktime-=1;
	exp=exp-expforlevelup;
	expforlevelup=level*10;
} 

void Pokemon21::attacktype()
{
	cout<<"护盾冲击！"<<endl; 
}

class Pokemon22:public Pokemon   //防御型臭泥子类 
{
 	public:	
		Pokemon22()
		{
			name="臭泥";
			type="防御型";
			level=1;
			attack=50;
			defense=60;
			life=500;
			attacktime=52;
			exp=0;
			expforlevelup=10;
		}
		void levelup(); 
		void attacktype();
};

void Pokemon22::levelup()  //防御型精灵升级时各属性的变化 
{
	level++;
	attack+=10;   
	defense+=20; //防御型精灵升级时防御属性的增加比其他类型的多 
	life+=100;
	attacktime-=1;
	exp=exp-expforlevelup;
	expforlevelup=level*10;
} 

void Pokemon22::attacktype()
{
	cout<<"毒尘放射！"<<endl; 
}

class Pokemon31:public Pokemon   //高生命值型海星星子类 
{
 	public:	
		Pokemon31()
		{
			name="海星星";
			type="肉盾型";
			level=1;
			attack=50;
			defense=50;
			life=600;
			attacktime=48;
			exp=0;
			expforlevelup=10; 
		} 
		void levelup(); 
		void attacktype();
};

void Pokemon31::levelup()  //高生命值型精灵升级时各属性的变化 
{
	level++;
	attack+=10;  
	defense+=10;
	life+=200; //高生命值型的精灵升级时生命值增加的比其他类型的多 
	attacktime-=1;
	exp=exp-expforlevelup;
	expforlevelup=level*10;
} 

void Pokemon31::attacktype()
{
	cout<<"水枪喷射！"<<endl; 
}

class Pokemon32:public Pokemon   //高生命值型呆呆兽子类 
{
 	public:	
		Pokemon32()
		{
			name="呆呆兽";
			type="肉盾型";
			level=1;
			attack=50;
			defense=50;
			life=600;
			attacktime=48;
			exp=0;
			expforlevelup=10; 
		} 
		void levelup(); 
		void attacktype();
};

void Pokemon32::levelup()  //高生命值型精灵升级时各属性的变化 
{
	level++;
	attack+=10;  
	defense+=10;
	life+=200; //高生命值型的精灵升级时生命值增加的比其他类型的多 
	attacktime-=1;
	exp=exp-expforlevelup;
	expforlevelup=level*10;
} 

void Pokemon32::attacktype()
{
	cout<<"精神念力！"<<endl; 
}

class Pokemon41:public Pokemon   //速度型飞天螳螂子类 
{
 	public:	
		Pokemon41()
		{
			name="飞天螳螂";
			type="速度型";
			level=1;
			attack=50;
			defense=50;
			life=500;
			attacktime=42;
			exp=0;
			expforlevelup=10;
		}
		void levelup(); 
		void attacktype();
};

void Pokemon41::levelup()  //速度型精灵升级时各属性的变化 
{
	level++;
	attack+=10;   
	defense+=10;
	life+=100;
	attacktime-=2;//速度型精灵升级时速度属性的增加比其他类型的多 
	exp=exp-expforlevelup;
	expforlevelup=level*10;
} 

void Pokemon41::attacktype()
{
	cout<<"快速打击！"<<endl; 
}

class Pokemon42:public Pokemon   //速度型冰鸟子类 
{
 	public:	
		Pokemon42()
		{
			name="冰鸟";
			type="速度型";
			level=1;
			attack=50;
			defense=50;
			life=500;
			attacktime=42;
			exp=0;
			expforlevelup=10;
		}
		void levelup(); 
		void attacktype();
};

void Pokemon42::levelup()  //防御型精灵升级时各属性的变化 
{
	level++;
	attack+=10;   
	defense+=10;
	life+=100;
	attacktime-=2;//速度型精灵升级时速度属性的增加比其他类型的多 
	exp=exp-expforlevelup;
	expforlevelup=level*10;
} 

void Pokemon42::attacktype()
{
	cout<<"绝对零度！"<<endl; 
}

int temp=0;//用于指示精灵数量及编号的变量 
//Pokemon  *P[100];
Pokemon  *P[100];//总的精灵数目为最多100

int main()
{
	srand(time(0));
	int a=0,b=1;
	cout<<"这是测试函数："<<endl; 
	while(b==1)
	{
		cout<<"请输入要选择的操作：\n"<<"1代表增加精灵\n2代表删除精灵\n3代表进行模拟对战\n4代表查询精灵信息\n5代表退出"<<endl;
		cin>>a;
		switch(a)
		{
			case 1:
				initfunc(); 
				break;
			case 2:
				if(temp>0) 
					depokemon();
				else
					cout<<"目前还没有精灵，请先去增加精灵！"<<endl;
				break;
			case 3:
				if(temp>=2)
					fightfunc();
				else
					cout<<"目前精灵还不足2个，请先去增加精灵！"<<endl;
				break; 
			case 4:
				if(temp>=1)
					printfunc();
				else
					cout<<"目前还没有精灵，请先去增加精灵！"<<endl;
				break;
			case 5:
				cout<<"谢谢使用！"<<endl;
				b=0;
				break;
			default:
				cout<<"错误的输入,请重新输入！"<<endl; 
		}
		system("pause");
		system("cls");
	}
	return 0;
}

void initfunc()
{
	int c;
	cout<<"请选择要增加的精灵类型："<<endl;
	cout<<"(1皮卡丘 2小火龙 3铁甲蛹 4臭泥 5海星星 6呆呆兽 7飞天螳螂 8冰鸟)"<<endl;
	cin>>c;
	switch(c)
	{
		case 1:
			cout<<"增加了1个皮卡丘！"<<endl;
			P[temp]=new Pokemon11;
			temp++;
			break;
		case 2:
			cout<<"增加了1个小火龙！"<<endl;
			P[temp]=new Pokemon12;
			temp++;
			break;
		case 3:
			cout<<"增加了1个铁甲蛹！"<<endl;
			P[temp]=new Pokemon21;
			temp++;
			break;
		case 4:
			cout<<"增加了1个臭泥！"<<endl;
			P[temp]=new Pokemon22;
			temp++;
			break;
		case 5:
			cout<<"增加了1个海星星！"<<endl;
			P[temp]=new Pokemon31;
			temp++;
			break;
		case 6:
			cout<<"增加了1个呆呆兽！"<<endl;
			P[temp]=new Pokemon32;
			temp++;
			break;
		case 7:
			cout<<"增加了1个飞天螳螂！"<<endl;
			P[temp]=new Pokemon41;
			temp++;
			break;
		case 8:
			cout<<"增加了1个冰鸟！"<<endl;
			P[temp]=new Pokemon42;
			temp++;
			break;
		default:
			cout<<"错误的输入"<<endl;
	}
}

void printfunc()
{
	int m=1,k=0,l=0;
	cout<<"当前有"<<temp<<"个精灵"<<"请选择要查询的方式(1按序号查询2显示所有精灵信息)："<<endl;
	cin>>k;
	if(k==1)
	{
		cout<<"当前共有"<<temp<<"个精灵(编号为0~"<<temp-1<<")."<<endl;
		while(m==1)
		{
			cout<<"请输入要查询的编号："<<endl;
			cin>>l;
			if((l>=0)&&(l<temp))
			{
				P[l]->show();
				m=0;
			}	
			else
			{
				cout<<"要查询的精灵编号不存在，请重新输入查询的编号！"<<endl; 
			}
		}
	} 
	else if(k==2)
	{
		for(int a=0;a<temp;a++)
		{
			cout<<a<<"号精灵的属性如下："<<endl;
			P[a]->show();
		} 
	} 
	else 
		cout<<"错误的输入！"<<endl;;
}

void fightfunc()
{
	int a=0,b=0;//存储两个出战精灵的生命值 
	int m=0,n=0;//两个出战精灵的编号 
	int k=1,l=1;//用于判断选择的精灵是否符合要求 
	int j=1;//模拟回合使用的变量 
	int run=0;//用于模拟攻击间隔的变量 
	int attvalue=0;//用于计算伤害值 
	while(k==1)
	{
		cout<<"当前有"<<temp<<"个精灵可选，请选择要出战的第一个精灵(编号为0~"<<temp-1<<")."<<endl;
		cin>>m;
		if((m>=0)&&(m<temp))
		{
			k=0;
		}
		else
			cout<<"选择的精灵不存在，请重新选择！"<<endl; 
	}
	while(l==1)
	{
		cout<<"当前有"<<temp-1<<"个精灵可选，请选择要出战的第二个精灵(编号为0~"<<temp-1;
		cout<<",编号为"<<m<<"的精灵已经被选）："<<endl;
		cin>>n;
		if((n>=0)&&(n<temp)&&(n!=m))
		{
			l=0;
		}
		else
			cout<<"选择的精灵不存在或者已经被选择，请重新选择！"<<endl; 
	}
	a=P[m]->life;
	b=P[n]->life;
    while((a>0)&&(b>0))
    {
    	run++;
    	if(run%P[m]->attacktime==0)
    	{
    		cout<<"第"<<j<<"回合:"<<endl; 
    		attvalue=P[m]->attack-0.5*P[n]->defense;
    		int r=(rand() %4+1);//产生1到4之间的随机数
			if(r==1)
			{
				attvalue=0;
    			cout<<"("<<P[m]->name<<"生命:"<<a<<"	"<<P[n]->name<<"生命:"<<b<<")"<<"\n"<<P[m]->name<<"使用：";
    			P[m]->attacktype();	
    			cout<<P[n]->name<<"闪避！"<<endl;
    			b=b-attvalue;
			}
			else if(r==2)
			{
				attvalue=2*attvalue;
    			cout<<"("<<P[m]->name<<"生命:"<<a<<"	"<<P[n]->name<<"生命:"<<b<<")"<<"\n"<<P[m]->name<<"使用：";
    			P[m]->attacktype();	
				cout<<P[m]->name<<"暴击！"<<endl;
				cout<<P[m]->name<<"受到"<<attvalue<<"点伤害。"<<endl;
				b=b-attvalue;
			}
			else 
			{
				cout<<"("<<P[m]->name<<"生命:"<<a<<"	"<<P[n]->name<<"生命:"<<b<<")"<<"\n"<<P[m]->name<<"使用：";
    			P[m]->attacktype();	
				cout<<P[n]->name<<"受到"<<attvalue<<"点伤害。"<<endl;
				b=b-attvalue;
			}
			j++;
			cout<<"\n";
		}
		else ;
		if((run%P[n]->attacktime==0)&&(b>0))//考虑相同速度条件下，可能会使二号精灵生命值为负仍攻击，增加b>0条件 
		{
			cout<<"第"<<j<<"回合:"<<endl; 
			attvalue=P[n]->attack-0.5*P[m]->defense;
			int t=(rand() %4+1);//产生1到4之间的随机数
			if(t==1)
			{
				attvalue=0;
    			cout<<"("<<P[m]->name<<"生命:"<<a<<"	"<<P[n]->name<<"生命:"<<b<<")"<<"\n"<<P[n]->name<<"使用：";
    			P[n]->attacktype();	
    			cout<<P[m]->name<<"闪避！"<<endl;
    			a=a-attvalue;
			}
			else if(t==2)
			{
				attvalue=2*attvalue;
    			cout<<"("<<P[m]->name<<"生命:"<<a<<"	"<<P[n]->name<<"生命:"<<b<<")"<<"\n"<<P[n]->name<<"使用：";
    			P[n]->attacktype();	
				cout<<P[n]->name<<"暴击！"<<endl;
				cout<<P[m]->name<<"受到"<<attvalue<<"点伤害。"<<endl;
				a=a-attvalue;
			}
			else 
			{
				cout<<"("<<P[m]->name<<"生命:"<<a<<"	"<<P[n]->name<<"生命:"<<b<<")"<<"\n"<<P[n]->name<<"使用：";
    			P[n]->attacktype();	
				cout<<P[m]->name<<"受到"<<attvalue<<"点伤害。"<<endl;
				a=a-attvalue;
			}
			j++;
			cout<<"\n";
		}
		else ;
	}
	if(a>0)
	{
		cout<<P[m]->name<<"获胜。"<<P[m]->name<<"获得了10经验点，"<<P[n]->name<<"获得了5经验点。"<<endl<<endl; 
		P[m]->exp+=10;
		if((P[m]->exp>=P[m]->expforlevelup)&&(P[m]->level<=15))
		{
			cout<<P[m]->name<<"升到"<<P[m]->level+1<<"级啦！"<<endl; 
			P[m]->levelup();
			cout<<endl; 
		}
		P[n]->exp+=5;
		if((P[n]->exp>=P[n]->expforlevelup)&&(P[n]->level<=15))
		{
			cout<<P[n]->name<<"升到"<<P[n]->level+1<<"级啦！"<<endl; 
			P[n]->levelup();
			cout<<endl; 
		}
	}
	else	
	{
		cout<<P[n]->name<<"获胜。"<<P[n]->name<<"获得了10经验点，"<<P[m]->name<<"获得了5经验点。"<<endl<<endl;;
		P[n]->exp+=10;
		if((P[n]->exp>=P[n]->expforlevelup)&&(P[n]->level<=15))
		{
			cout<<P[n]->name<<"升到"<<P[n]->level+1<<"级啦！"<<endl; 
			P[n]->levelup();
			cout<<endl; 
		}
		P[m]->exp+=5;
		if((P[m]->exp>=P[m]->expforlevelup)&&(P[m]->level<=15))
		{
			cout<<P[m]->name<<"升到"<<P[m]->level+1<<"级啦！"<<endl; 
			P[m]->levelup();
			cout<<endl; 
		}
	}
}

void depokemon()
{
	int i=0,j=0,k=1;
	while(k==1)
	{
		cout<<"请输入要删除的精灵编号(当前有"<<temp<<"个精灵，编号为0~"<<temp-1<<")."<<endl; 
		cin>>i;
		if((i>=0)&&(i<temp))
		{
			for(j=i;j<temp;j++)
			{
				P[j]=P[j+1];	
			}
			k=0;
		}
		else 
			cout<<"错误的输入，请重新选择！"<<endl;
	}
		cout<<"删除成功！"<<endl;
		P[temp]=NULL;
		temp--;
}
                               
