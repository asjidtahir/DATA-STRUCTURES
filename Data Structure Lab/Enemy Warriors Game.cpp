#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<stdlib.h>

using namespace std;

void my_init();
int get_random(int, int);

struct height
{
	int feet;
	int inches;
};

class character
{
protected:
	height height; 
	int weight;

public:
	character(int f = 0, int i = 0, int w = 0)
	{
		height.feet = f;
		height.inches = i;
		weight = w;
	}
};

class Enemy: public character
{
protected:
	string colour;
	int hitpoints, identifier;

public:
	static int EnemyCount;

	Enemy(string c = " ", int f = 0, int i = 0, int w = 0, int p = 1)
	{
		colour = c;
		height.feet = f;
		height.inches = i;
		weight = w;
		hitpoints = p;
		EnemyCount++;
	}

	virtual void Attack() = 0;
	
	void destory()
	{
		cout<<"The enemy launched an attack on the defenders' base base"<<endl;
		cout<<endl;
	}

	void capture()
	{
		cout<<"The enemy has captured one of the defenders' civilians"<<endl;
		cout<<endl;
	}

	int getCount()
	{
		return EnemyCount;
	}

	virtual void Showstats() = 0;

};

class Alien: public Enemy
{
public:
	static int AlienCount;

	Alien()
	{
		hitpoints = 1;
		identifier = 1;
		colour = "green";
		height.feet = get_random(2,3);
		height.inches = get_random(12, 0);
		weight = get_random(20, 60);
		AlienCount++;
	}

	void Showstats()
	{
		cout<<"Height      : "<<height.feet<<"' "<<height.inches<<"\""<<endl;
		cout<<"Weight      : "<<weight<<"kgs"<<endl;
		cout<<"Colour      : "<<colour<<endl;
		cout<<"Hitpoints   : "<<hitpoints<<endl;
	}

	void Damage()
	{
		--hitpoints;
		cout<<"Damage was done to an Alien"<<endl;
		cout<<endl;
	}

	int getHP()
	{
		return hitpoints;
	}

	int getID()
	{
		return identifier;
	}

	int getACount()
	{
		return AlienCount;
	}

	void Attack()
	{
		cout<<"An alien has attacked your airforce"<<endl;
		cout<<endl;
	}

	void kill()
	{
		--AlienCount;
		--EnemyCount;
		cout<<"An alien was killed"<<endl;
		cout<<endl;
	}
};

class Monster: public Enemy
{
public:
	static int MonsterCount;

	Monster()
	{
		hitpoints = 5;
		identifier = 2;
		colour = "purple";
		height.feet = get_random(2,5);
		height.inches = get_random(12,0);
		weight = get_random(50,150);
		MonsterCount++;
	}

	void Showstats()
	{
		cout<<"Height      : "<<height.feet<<"' "<<height.inches<<"\""<<endl;
		cout<<"Weight      : "<<weight<<"kgs"<<endl;
		cout<<"Colour      : "<<colour<<endl;
		cout<<"Hitpoints   : "<<hitpoints<<endl;
	}

	void Damage()
	{
		--hitpoints;
		cout<<"Damage was done to a Monster"<<endl;
		cout<<endl;
	}

	int getHP()
	{
		return hitpoints;
	}

	int getID()
	{
		return identifier;
	}

	int getACount()
	{
		return MonsterCount;
	}

	void Attack()
	{
		cout<<"A monster has attacked the army"<<endl;
		cout<<endl;
	}

	void kill()
	{
		--MonsterCount;
		--EnemyCount;
		cout<<"A monster was killed."<<endl;
		cout<<endl;
	}
};

class Defender: public character
{
protected:
	int  hitpoints, identifier;

public:
	static int defenderCount;

	Defender(int f = 0, int i = 0, int w = 0)
	{
		height.feet = f;
		height.inches = i;
		weight = w;
		hitpoints = 3;
		defenderCount++;
	}

	int getDefenderCount()
	{
		return defenderCount;
	}

	virtual void Attack() = 0;

	void destory()
	{
		cout<<"A defender launches an attack on the enemy base"<<endl;
		cout<<endl;
	}

	void capture()
	{
		cout<<"A defender has captured one of the enemy civilians"<<endl;
		cout<<endl;
	}

	virtual void showStats() = 0;
	virtual void kill() = 0;

};

class groundArmy: public Defender
{
public:
	static int groundArmyCount;

	groundArmy()
	{
		identifier = 2;
		groundArmyCount++;
		height.feet = get_random(3,5);
		height.inches = get_random(12,0);
		weight = get_random(80,70);
	}

	void Damage()
	{
		--hitpoints;
		cout<<"Damage was done to an Army unit."<<endl;
		cout<<endl;
	}

	void Attack()
	{
		cout<<"An army has attacked a Monster"<<endl;
		cout<<endl;
	}

	int getGroundCount()
	{
		return groundArmyCount;
	}

	int getID()
	{
		return identifier;
	}

	int getHP()
	{
		return hitpoints;
	}

	void showStats()
	{
		cout<<"Height      : "<<height.feet<<"' "<<height.inches<<"\""<<endl;
		cout<<"Weight      : "<<weight<<"kgs"<<endl;
		cout<<"Evasion     : 10%"<<endl;
		cout<<"Hitpoints   : "<<hitpoints<<endl;
	}

	void kill()
	{
		--groundArmyCount;
		--defenderCount;
		cout<<"An army unit was killed"<<endl;
		cout<<endl;
	}

};

class airArmy: public Defender
{
	public:
	static int airArmyCount;

	airArmy()
	{
		identifier = 1;
		height.feet = get_random(3,5);
		height.inches = get_random(12,0);
		weight = get_random(80,70);
		airArmyCount++;
	}

	void Damage()
	{
		--hitpoints;
		cout<<"Damage was done to an Airforce unit"<<endl;
		cout<<endl;
	}

	void Attack()
	{
		cout<<"An Airforce troop has attacked an Alien"<<endl;
		cout<<endl;
	}

	int getGroundCount()
	{
		return airArmyCount;
	}

	int getID()
	{
		return identifier;
	}

	int getHP()
	{
		return hitpoints;
	}

	void showStats()
	{
		cout<<"Height      : "<<height.feet<<"' "<<height.inches<<"\""<<endl;
		cout<<"Weight      : "<<weight<<"kgs"<<endl;
		cout<<"Evasion     : 20%"<<endl;
		cout<<"Hitpoints   : "<<hitpoints<<endl;
	}

	void kill()
	{
		--airArmyCount;
		--defenderCount;
		cout<<"An Airforce unit was killed"<<endl;
		cout<<endl;
	}
};

int Alien::AlienCount = 0;
int Monster::MonsterCount = 0;
int Enemy::EnemyCount = 0;
int Defender::defenderCount = 0;
int groundArmy::groundArmyCount = 0;
int airArmy::airArmyCount = 0;

void my_init()
{
	srand((unsigned) time(NULL));
}

int get_random(int range, int minValue)
{
	return rand() % range + minValue;
}

inline void WaitEnter() 
{ 
	std::cout << "Press Enter to continue..."; while (std::cin.get()!='\n'); 
}


void instructions()
{
	cout<<"You will be playing the game as the enemy."<<endl;
	cout<<"You can choose your units to be either Ground units (Monsters)"<<endl;
	cout<<"Or Airborne units (Aliens)"<<endl;
	cout<<"The enemy also has ground units (Army) and air units (Airforce)"<<endl;
	cout<<"Beware because the Air units can only be hit by other Air units"<<endl;
	cout<<"and Ground units can only be hit by other Ground units"<<endl;
	cout<<"At the start of every round, you will get the choice to either attack the enemies directly,"<<endl; 
	cout<<"do damage to their base, or capture one of their civilians"<<endl;
	cout<<"The game is won when you either kill all enemies, destroy their base, or capture 20 of their enemies"<<endl;
	cout<<"The game is lost when the enemy is able to complete one of these objectives before you."<<endl;
}

int main()
{
	my_init();
	int groundChoice, airChoice, action;
	int enemyBase, defenderBase, enemyCivilians, defenderCivilians, roundCount;
	enemyBase = 100;
	defenderBase = 100;
	enemyCivilians = 20;
	defenderCivilians = 20;
	roundCount = 0;
	Alien *alien;
	Monster *monster;
	groundArmy *ground;
	airArmy *air;
	instructions();
	WaitEnter();
	system("CLS");
	
	cout<<"You have chosen to be an enemy"<<endl;
	cout<<"You must now choose your units"<<endl;
	cout<<"To begin with, you will be given 1 of each unit"<<endl;
	cout<<"You can choose the types for the rest three"<<endl;
	cout<<endl;
	cout<<"How many ground units would you like (Maximum 3):"<<endl;
	cin>>groundChoice;
	while(groundChoice > 3 || groundChoice < 0)
	{
		cout<<endl;
		cout<<"You can only choose from 0-3"<<endl;
		cout<<"Please re-enter: "<<endl;
		cin>>groundChoice;
	}
	airChoice = (3-groundChoice);
	cout<<endl;
	cout<<"You have "<<groundChoice+1<<" total ground unit(s)"<<endl;
	cout<<"You have "<<airChoice+1<<" total air unit(s)"<<endl;

	monster = new Monster[groundChoice+1];
	alien = new Alien [airChoice+1];
	air = new airArmy[(get_random(3,0))+1];
	ground = new groundArmy[(3-air->airArmyCount)+2];

	cout<<endl;
	cout<<"The Defenders have "<<ground->groundArmyCount<<" total ground unit(s)"<<endl;
	cout<<"The Defenders have "<<air->airArmyCount<<" total air unit(s)"<<endl;

	cout<<endl;	
	cout<<"Now you must choose what action to take with each unit."<<endl;

		
	do{
		cout<<"Round "<<roundCount+1<<endl;

		for(int i=1; i<=monster->MonsterCount; i++)
		{
			cout<<"Monster units"<<endl;
			cout<<"Unit "<<i<<endl;
			cout<<"1. You can choose to attack an enemy army unit "<<endl;
			cout<<"2. You can choose to damage their base (1 attack does 5 damage)"<<endl;
			cout<<"3. You can choose to capture one of their civillians"<<endl;
			cin>>action;

			switch(action)
			{
			case 1:
				{
					if(ground->groundArmyCount == 0)
						cout<<"There are no more ground units left to attack"<<endl;
					else
					{
						(ground)->Damage();
						if((ground)->getHP() == 0)
						{
							(ground)->kill();
							if(ground->groundArmyCount != 0)
								ground = ground + 1;
						}
					}

					if(air->defenderCount <= 0)
					{
						cout<<"You have killed all the attackers!"<<endl;
						cout<<"You win!"<<endl;
						system("pause");
						return 0;
					}
					cout<<endl;
					break;
				}
			case 2:
				{
					monster->destory();
					defenderBase = defenderBase - 5;
					if(defenderBase <= 0)
					{
						cout<<"The defender base has been destroyed!"<<endl;
						cout<<"You win!"<<endl;
						system("pause");
						return 0;
					}
					else
					cout<<"Remaining HP of the defender base: "<<defenderBase<<endl;
					cout<<endl;
					break;
				}
			case 3:
				{
					monster->capture();
					defenderCivilians = defenderCivilians - 1;
					if(defenderCivilians <= 0)
					{
						cout<<"You have captured all the defender civilians!"<<endl;
						cout<<"You win!"<<endl;
						system("pause");
						return 0;
					}
					else					
					cout<<"Remaining defender civillians: "<<defenderCivilians<<endl;
					break;
					cout<<endl;
				}
			}
		}

		for(int i=1; i<=alien->AlienCount; i++)
		{
			cout<<"Air units"<<endl;
			cout<<"Unit "<<i<<endl;
			cout<<"1. You can choose to attack the airforce"<<endl;
			cout<<"2. You can choose to damage their base (1 attack does 5 damage)"<<endl;
			cout<<"3. You can choose to capture one of their civillians"<<endl;
			cin>>action;

			switch(action)
			{
			case 1:
				{
					if(air->airArmyCount == 0)
						cout<<"There are no more air units left to attack"<<endl;
					else
					{
						air->Damage();
						if(air->getHP() == 0)
						{
							(air+(i-1))->kill();
							if(air->airArmyCount != 0)
								air = air+1;
						}
					}

					if(air->defenderCount <= 0)
					{
						cout<<"You have killed all the attackers!"<<endl;
						cout<<"You win!"<<endl;
						system("pause");
						return 0;
					}
					cout<<endl;
					break;
				}
			case 2:
				{
					alien->destory();
					defenderBase = defenderBase - 5;
					if(defenderBase <= 0)
					{
						cout<<"The defender base has been destroyed!"<<endl;
						cout<<"You win!"<<endl;
						system("pause");
						return 0;
					}
					else
						cout<<"Remaining HP of the defender base: "<<defenderBase<<endl;
					cout<<endl;
					break;
				}
			case 3:
				{
					alien->capture();
					defenderCivilians = defenderCivilians - 1;
					if(defenderCivilians <= 0)
					{
						cout<<"You have captured all the defender civilians!"<<endl;
						cout<<"You win!"<<endl;
						system("pause");
						return 0;
					}
					else					
						cout<<"Remaining defender civillians: "<<defenderCivilians<<endl;
					cout<<endl;
					break;
				}
			}
		}

		for(int i=1; i<=ground->groundArmyCount; i++)
		{
			cout<<"Defenders' turn"<<endl;
			cout<<"Ground units"<<endl;
			cout<<"Unit "<<i<<endl;
			action = get_random(3,1);
			
			switch(action)
			{
			case 1:
				{
					if(monster->MonsterCount == 0)
						cout<<"There are no more ground units left to attack"<<endl;
					else
					{
						(monster)->Damage();
						if((monster)->getHP() == 0)
						{
							(monster)->kill();
							if(monster->MonsterCount!=0)
								monster = monster + 1;
						}
					}

					if(monster->EnemyCount <= 0)
					{
						cout<<"The enemy has killed all your units!"<<endl;
						cout<<"You lose!"<<endl;
						system("pause");
						return 0;
					}
				}
				cout<<endl;
				break;
			case 2:
				{
					ground->destory();
					enemyBase = enemyBase - 5;
					if(enemyBase <= 0)
					{
						cout<<"The enemy base has been destroyed!"<<endl;
						cout<<"You lose!"<<endl;
						system("pause");
						return 0;
					}
					else
						cout<<"Remaining HP of the enemy base: "<<enemyBase<<endl;
					cout<<endl;
					break;
				}
			case 3:
				{
					ground->capture();
					enemyCivilians = enemyCivilians - 1;
					if(enemyCivilians <= 0)
					{
						cout<<"The defenders have captured all the enemy civilians!"<<endl;
						cout<<"You lose!"<<endl;
						system("pause");
						return 0;
					}
					else					
						cout<<"Remaining enemy civillians: "<<enemyCivilians<<endl;
					break;
					cout<<endl;
				}
			}
		}

		for(int i=1; i<=air->airArmyCount; i++)
		{
			cout<<"Air units"<<endl;
			cout<<"Unit "<<i<<endl;
			get_random(3,1);

			switch(action)
			{
			case 1:
				{
					if(alien->AlienCount == 0)
						cout<<"There are no more air units left to attack"<<endl;
					else
					{
						(alien)->Damage();
						if((alien)->getHP() == 0)
						{
							(alien)->kill();
							if(alien->AlienCount!=0)
								alien = alien+1;
						}
					}

					if(monster->EnemyCount <= 0)
					{
						cout<<"The enemy has killed all your units!"<<endl;
						cout<<"You lose!"<<endl;
						system("pause");
						return 0;
					}
				}
				cout<<endl;
				break;
			case 2:
				{
					air->destory();
					enemyBase = enemyBase - 5;
					if(enemyBase <= 0)
					{
						cout<<"The enemy base has been destroyed!"<<endl;
						cout<<"You lose!"<<endl;
						system("pause");
						return 0;
					}
					else
						cout<<"Remaining HP of the enemy base: "<<enemyBase<<endl;
					cout<<endl;
					break;
				}
			case 3:
				{
					air->capture();
					enemyCivilians = enemyCivilians - 1;
					if(enemyCivilians <= 0)
					{
						cout<<"The defenders have captured all the enemy civilians!"<<endl;
						cout<<"You lose!"<<endl;
						system("pause");
						return 0;
					}
					else					
						cout<<"Remaining enemy civillians: "<<enemyCivilians<<endl;
					cout<<endl;
					break;
				}
			}
		}

		roundCount++;
		}while(roundCount >=0);

	system("pause");
	return 0;
}