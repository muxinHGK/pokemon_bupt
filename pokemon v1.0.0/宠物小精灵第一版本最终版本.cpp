#include<iostream>
#include<cmath>
#include<stdlib.h> 
#include<process.h>
#include<time.h> 
using namespace std;

void initfunc();//���Ӿ���ĺ��� 
void printfunc();//��ѯ����ĺ��� 
void fightfunc();//ģ���ս�ĺ��� 
void depokemon();//ɾ������ĺ��� 

class Pokemon
{
 	public:
 		string name;
		string type;//�����֣������ͣ������ͣ�������ֵ�ͣ������� 
		int level;
		int attack;//������ 
		int defense;//������ 
		int life;//����ֵ 
		int attacktime;//������� 
		int exp;//���鵱ǰ�ľ��� 
		int expforlevelup;//����������Ҫ�ľ���		
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
		void show();//��ӡ�������Ϣ 
		virtual	void levelup(); //������������� 
		virtual void attacktype();//����Ĺ�����ʽ 
};

void Pokemon::show() 
{
	cout<<"���֣�"<<name<<endl; 
    cout<<"���ͣ�"<<type<<endl;
	cout<<"�ȼ���"<<level<<endl;
	cout<<"��������"<<attack<<endl;
	cout<<"��������"<<defense<<endl;
	cout<<"����ֵ��"<<life<<endl;
	cout<<"���������"<<attacktime<<endl;
	cout<<"��ǰ���飺"<<exp<<endl;
	cout<<"�������飺"<<expforlevelup<<endl<<endl;
}

void Pokemon::levelup(){};
void Pokemon::attacktype(){};

class Pokemon11:public Pokemon   //������Ƥ�������� 
{
 	public:	
		Pokemon11()
		{
			name="Ƥ����";
			type="������";
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


void Pokemon11::levelup()  //�����;�������ʱ�����Եı仯 
{
	level++;
	attack+=20;  //�����͵ľ��鹥�������ӱ��������͵Ķ� 
	defense+=10;
	life+=100;
	attacktime-=1;
	exp=exp-expforlevelup;
	expforlevelup=level*10;
} 

void Pokemon11::attacktype()
{
	cout<<"ʮ����أ�"<<endl; 
}

class Pokemon12:public Pokemon   //������С�������� 
{
 	public:	
		Pokemon12()
		{
			name="С����";
			type="������";
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


void Pokemon12::levelup()  //�����;�������ʱ�����Եı仯 
{
	level++;
	attack+=20;  //�����͵ľ��鹥�������ӱ��������͵Ķ� 
	defense+=10;
	life+=100;
	attacktime-=1;
	exp=exp-expforlevelup;
	expforlevelup=level*10;
} 

void Pokemon12::attacktype()
{
	cout<<"�������棡"<<endl; 
}


class Pokemon21:public Pokemon   //����������Ӽ���� 
{
 	public:	
		Pokemon21()
		{
			name="����Ӽ";
			type="������";
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

void Pokemon21::levelup()  //�����;�������ʱ�����Եı仯 
{
	level++;
	attack+=10;   
	defense+=20; //�����;�������ʱ�������Ե����ӱ��������͵Ķ� 
	life+=100;
	attacktime-=1;
	exp=exp-expforlevelup;
	expforlevelup=level*10;
} 

void Pokemon21::attacktype()
{
	cout<<"���ܳ����"<<endl; 
}

class Pokemon22:public Pokemon   //�����ͳ������� 
{
 	public:	
		Pokemon22()
		{
			name="����";
			type="������";
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

void Pokemon22::levelup()  //�����;�������ʱ�����Եı仯 
{
	level++;
	attack+=10;   
	defense+=20; //�����;�������ʱ�������Ե����ӱ��������͵Ķ� 
	life+=100;
	attacktime-=1;
	exp=exp-expforlevelup;
	expforlevelup=level*10;
} 

void Pokemon22::attacktype()
{
	cout<<"�������䣡"<<endl; 
}

class Pokemon31:public Pokemon   //������ֵ�ͺ��������� 
{
 	public:	
		Pokemon31()
		{
			name="������";
			type="�����";
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

void Pokemon31::levelup()  //������ֵ�;�������ʱ�����Եı仯 
{
	level++;
	attack+=10;  
	defense+=10;
	life+=200; //������ֵ�͵ľ�������ʱ����ֵ���ӵı��������͵Ķ� 
	attacktime-=1;
	exp=exp-expforlevelup;
	expforlevelup=level*10;
} 

void Pokemon31::attacktype()
{
	cout<<"ˮǹ���䣡"<<endl; 
}

class Pokemon32:public Pokemon   //������ֵ�ʹ��������� 
{
 	public:	
		Pokemon32()
		{
			name="������";
			type="�����";
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

void Pokemon32::levelup()  //������ֵ�;�������ʱ�����Եı仯 
{
	level++;
	attack+=10;  
	defense+=10;
	life+=200; //������ֵ�͵ľ�������ʱ����ֵ���ӵı��������͵Ķ� 
	attacktime-=1;
	exp=exp-expforlevelup;
	expforlevelup=level*10;
} 

void Pokemon32::attacktype()
{
	cout<<"����������"<<endl; 
}

class Pokemon41:public Pokemon   //�ٶ��ͷ���������� 
{
 	public:	
		Pokemon41()
		{
			name="�������";
			type="�ٶ���";
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

void Pokemon41::levelup()  //�ٶ��;�������ʱ�����Եı仯 
{
	level++;
	attack+=10;   
	defense+=10;
	life+=100;
	attacktime-=2;//�ٶ��;�������ʱ�ٶ����Ե����ӱ��������͵Ķ� 
	exp=exp-expforlevelup;
	expforlevelup=level*10;
} 

void Pokemon41::attacktype()
{
	cout<<"���ٴ����"<<endl; 
}

class Pokemon42:public Pokemon   //�ٶ��ͱ������� 
{
 	public:	
		Pokemon42()
		{
			name="����";
			type="�ٶ���";
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

void Pokemon42::levelup()  //�����;�������ʱ�����Եı仯 
{
	level++;
	attack+=10;   
	defense+=10;
	life+=100;
	attacktime-=2;//�ٶ��;�������ʱ�ٶ����Ե����ӱ��������͵Ķ� 
	exp=exp-expforlevelup;
	expforlevelup=level*10;
} 

void Pokemon42::attacktype()
{
	cout<<"������ȣ�"<<endl; 
}

int temp=0;//����ָʾ������������ŵı��� 
//Pokemon  *P[100];
Pokemon  *P[100];//�ܵľ�����ĿΪ���100

int main()
{
	srand(time(0));
	int a=0,b=1;
	cout<<"���ǲ��Ժ�����"<<endl; 
	while(b==1)
	{
		cout<<"������Ҫѡ��Ĳ�����\n"<<"1�������Ӿ���\n2����ɾ������\n3�������ģ���ս\n4�����ѯ������Ϣ\n5�����˳�"<<endl;
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
					cout<<"Ŀǰ��û�о��飬����ȥ���Ӿ��飡"<<endl;
				break;
			case 3:
				if(temp>=2)
					fightfunc();
				else
					cout<<"Ŀǰ���黹����2��������ȥ���Ӿ��飡"<<endl;
				break; 
			case 4:
				if(temp>=1)
					printfunc();
				else
					cout<<"Ŀǰ��û�о��飬����ȥ���Ӿ��飡"<<endl;
				break;
			case 5:
				cout<<"ллʹ�ã�"<<endl;
				b=0;
				break;
			default:
				cout<<"���������,���������룡"<<endl; 
		}
		system("pause");
		system("cls");
	}
	return 0;
}

void initfunc()
{
	int c;
	cout<<"��ѡ��Ҫ���ӵľ������ͣ�"<<endl;
	cout<<"(1Ƥ���� 2С���� 3����Ӽ 4���� 5������ 6������ 7������� 8����)"<<endl;
	cin>>c;
	switch(c)
	{
		case 1:
			cout<<"������1��Ƥ����"<<endl;
			P[temp]=new Pokemon11;
			temp++;
			break;
		case 2:
			cout<<"������1��С������"<<endl;
			P[temp]=new Pokemon12;
			temp++;
			break;
		case 3:
			cout<<"������1������Ӽ��"<<endl;
			P[temp]=new Pokemon21;
			temp++;
			break;
		case 4:
			cout<<"������1�����࣡"<<endl;
			P[temp]=new Pokemon22;
			temp++;
			break;
		case 5:
			cout<<"������1�������ǣ�"<<endl;
			P[temp]=new Pokemon31;
			temp++;
			break;
		case 6:
			cout<<"������1�������ޣ�"<<endl;
			P[temp]=new Pokemon32;
			temp++;
			break;
		case 7:
			cout<<"������1��������룡"<<endl;
			P[temp]=new Pokemon41;
			temp++;
			break;
		case 8:
			cout<<"������1������"<<endl;
			P[temp]=new Pokemon42;
			temp++;
			break;
		default:
			cout<<"���������"<<endl;
	}
}

void printfunc()
{
	int m=1,k=0,l=0;
	cout<<"��ǰ��"<<temp<<"������"<<"��ѡ��Ҫ��ѯ�ķ�ʽ(1����Ų�ѯ2��ʾ���о�����Ϣ)��"<<endl;
	cin>>k;
	if(k==1)
	{
		cout<<"��ǰ����"<<temp<<"������(���Ϊ0~"<<temp-1<<")."<<endl;
		while(m==1)
		{
			cout<<"������Ҫ��ѯ�ı�ţ�"<<endl;
			cin>>l;
			if((l>=0)&&(l<temp))
			{
				P[l]->show();
				m=0;
			}	
			else
			{
				cout<<"Ҫ��ѯ�ľ����Ų����ڣ������������ѯ�ı�ţ�"<<endl; 
			}
		}
	} 
	else if(k==2)
	{
		for(int a=0;a<temp;a++)
		{
			cout<<a<<"�ž�����������£�"<<endl;
			P[a]->show();
		} 
	} 
	else 
		cout<<"��������룡"<<endl;;
}

void fightfunc()
{
	int a=0,b=0;//�洢������ս���������ֵ 
	int m=0,n=0;//������ս����ı�� 
	int k=1,l=1;//�����ж�ѡ��ľ����Ƿ����Ҫ�� 
	int j=1;//ģ��غ�ʹ�õı��� 
	int run=0;//����ģ�⹥������ı��� 
	int attvalue=0;//���ڼ����˺�ֵ 
	while(k==1)
	{
		cout<<"��ǰ��"<<temp<<"�������ѡ����ѡ��Ҫ��ս�ĵ�һ������(���Ϊ0~"<<temp-1<<")."<<endl;
		cin>>m;
		if((m>=0)&&(m<temp))
		{
			k=0;
		}
		else
			cout<<"ѡ��ľ��鲻���ڣ�������ѡ��"<<endl; 
	}
	while(l==1)
	{
		cout<<"��ǰ��"<<temp-1<<"�������ѡ����ѡ��Ҫ��ս�ĵڶ�������(���Ϊ0~"<<temp-1;
		cout<<",���Ϊ"<<m<<"�ľ����Ѿ���ѡ����"<<endl;
		cin>>n;
		if((n>=0)&&(n<temp)&&(n!=m))
		{
			l=0;
		}
		else
			cout<<"ѡ��ľ��鲻���ڻ����Ѿ���ѡ��������ѡ��"<<endl; 
	}
	a=P[m]->life;
	b=P[n]->life;
    while((a>0)&&(b>0))
    {
    	run++;
    	if(run%P[m]->attacktime==0)
    	{
    		cout<<"��"<<j<<"�غ�:"<<endl; 
    		attvalue=P[m]->attack-0.5*P[n]->defense;
    		int r=(rand() %4+1);//����1��4֮��������
			if(r==1)
			{
				attvalue=0;
    			cout<<"("<<P[m]->name<<"����:"<<a<<"	"<<P[n]->name<<"����:"<<b<<")"<<"\n"<<P[m]->name<<"ʹ�ã�";
    			P[m]->attacktype();	
    			cout<<P[n]->name<<"���ܣ�"<<endl;
    			b=b-attvalue;
			}
			else if(r==2)
			{
				attvalue=2*attvalue;
    			cout<<"("<<P[m]->name<<"����:"<<a<<"	"<<P[n]->name<<"����:"<<b<<")"<<"\n"<<P[m]->name<<"ʹ�ã�";
    			P[m]->attacktype();	
				cout<<P[m]->name<<"������"<<endl;
				cout<<P[m]->name<<"�ܵ�"<<attvalue<<"���˺���"<<endl;
				b=b-attvalue;
			}
			else 
			{
				cout<<"("<<P[m]->name<<"����:"<<a<<"	"<<P[n]->name<<"����:"<<b<<")"<<"\n"<<P[m]->name<<"ʹ�ã�";
    			P[m]->attacktype();	
				cout<<P[n]->name<<"�ܵ�"<<attvalue<<"���˺���"<<endl;
				b=b-attvalue;
			}
			j++;
			cout<<"\n";
		}
		else ;
		if((run%P[n]->attacktime==0)&&(b>0))//������ͬ�ٶ������£����ܻ�ʹ���ž�������ֵΪ���Թ���������b>0���� 
		{
			cout<<"��"<<j<<"�غ�:"<<endl; 
			attvalue=P[n]->attack-0.5*P[m]->defense;
			int t=(rand() %4+1);//����1��4֮��������
			if(t==1)
			{
				attvalue=0;
    			cout<<"("<<P[m]->name<<"����:"<<a<<"	"<<P[n]->name<<"����:"<<b<<")"<<"\n"<<P[n]->name<<"ʹ�ã�";
    			P[n]->attacktype();	
    			cout<<P[m]->name<<"���ܣ�"<<endl;
    			a=a-attvalue;
			}
			else if(t==2)
			{
				attvalue=2*attvalue;
    			cout<<"("<<P[m]->name<<"����:"<<a<<"	"<<P[n]->name<<"����:"<<b<<")"<<"\n"<<P[n]->name<<"ʹ�ã�";
    			P[n]->attacktype();	
				cout<<P[n]->name<<"������"<<endl;
				cout<<P[m]->name<<"�ܵ�"<<attvalue<<"���˺���"<<endl;
				a=a-attvalue;
			}
			else 
			{
				cout<<"("<<P[m]->name<<"����:"<<a<<"	"<<P[n]->name<<"����:"<<b<<")"<<"\n"<<P[n]->name<<"ʹ�ã�";
    			P[n]->attacktype();	
				cout<<P[m]->name<<"�ܵ�"<<attvalue<<"���˺���"<<endl;
				a=a-attvalue;
			}
			j++;
			cout<<"\n";
		}
		else ;
	}
	if(a>0)
	{
		cout<<P[m]->name<<"��ʤ��"<<P[m]->name<<"�����10����㣬"<<P[n]->name<<"�����5����㡣"<<endl<<endl; 
		P[m]->exp+=10;
		if((P[m]->exp>=P[m]->expforlevelup)&&(P[m]->level<=15))
		{
			cout<<P[m]->name<<"����"<<P[m]->level+1<<"������"<<endl; 
			P[m]->levelup();
			cout<<endl; 
		}
		P[n]->exp+=5;
		if((P[n]->exp>=P[n]->expforlevelup)&&(P[n]->level<=15))
		{
			cout<<P[n]->name<<"����"<<P[n]->level+1<<"������"<<endl; 
			P[n]->levelup();
			cout<<endl; 
		}
	}
	else	
	{
		cout<<P[n]->name<<"��ʤ��"<<P[n]->name<<"�����10����㣬"<<P[m]->name<<"�����5����㡣"<<endl<<endl;;
		P[n]->exp+=10;
		if((P[n]->exp>=P[n]->expforlevelup)&&(P[n]->level<=15))
		{
			cout<<P[n]->name<<"����"<<P[n]->level+1<<"������"<<endl; 
			P[n]->levelup();
			cout<<endl; 
		}
		P[m]->exp+=5;
		if((P[m]->exp>=P[m]->expforlevelup)&&(P[m]->level<=15))
		{
			cout<<P[m]->name<<"����"<<P[m]->level+1<<"������"<<endl; 
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
		cout<<"������Ҫɾ���ľ�����(��ǰ��"<<temp<<"�����飬���Ϊ0~"<<temp-1<<")."<<endl; 
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
			cout<<"��������룬������ѡ��"<<endl;
	}
		cout<<"ɾ���ɹ���"<<endl;
		P[temp]=NULL;
		temp--;
}
                               
