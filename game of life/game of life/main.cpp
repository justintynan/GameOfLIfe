#include <iostream>
#include <stdlib.h>  
#include <time.h>
#include <math.h>
#include <windows.h>
using namespace std;

	const int res_x = 110;
	const int res_y = 29;
	const int max_units = 1000;
	const int frame_delay = 500;

	struct stats
	{
		bool alive;
		char symbol;
		int speed;
		int health;
		int age;
		int lifetime;
		POINT start_pos;
		POINT pos;
	};
stats new_citizen(stats);
int main()
{
	bool game = true;

	stats *citizen;
	int check; //free variable for testing
	bool citizen_space[max_units+1];
	int citizen_id = 0;
	int direction;
	int y = 0;
	int x = 0;
	int founder_count = 1;
	int founder_max = 2;
	bool partner[9];
	char display[res_x+1][res_y+1];
	citizen = new stats[max_units+1];

	//mark citizen_space as empty
	for (int i = 0; i <= max_units; i++)
	{
		citizen_space[i] = true;
	}
	while (game = 1)//start of game loop
	{
		//clear screen
		for (int y = 0; y <= res_y; y++)
		{
			for (int x = 0; x <= res_x; x++)
			{
				display[x][y] = ' ';
			}

		}
		srand(time(NULL));
		//optimize use of citizen array
		
		//founders
		if (founder_count <= founder_max)
		{
			//new citizen
			//get new id
			for (int i = 0; i <= max_units && citizen_space[i] == false;)
			{
				i++;
				citizen_id = i;
			}
			citizen[citizen_id] = new_citizen(citizen[citizen_id]);//fill citizen with new stats
			citizen[citizen_id].pos.x = citizen[citizen_id].start_pos.x;
			citizen[citizen_id].pos.y = citizen[citizen_id].start_pos.y;
			citizen_space[citizen_id] = false;
			founder_count++;
		}
		

		
		for (int i = 0; i <= max_units; i++)//update each citizen
		{
			if (citizen[i].age <= citizen[i].lifetime)//check if alive 
			{
				citizen[i].age++;//if alive add age
				citizen[i].alive = true;
			}
			else
			{
				citizen[i].alive = false;
				citizen[i].symbol = ' ';
				citizen_space[i] = true;
			}
			//decide direction
			direction = (rand() % 8)+1;
			switch (direction)
			{
				case 1:
					if (citizen[i].pos.x - citizen[i].speed >= 0 && citizen[i].pos.x - citizen[i].speed <= res_x)
					{
						if (citizen[i].pos.y + citizen[i].speed >= 0 && citizen[i].pos.y + citizen[i].speed <= res_y)
						{
							citizen[i].pos.x = citizen[i].pos.x - citizen[i].speed;
							citizen[i].pos.y = citizen[i].pos.y + citizen[i].speed;
						}
					}
					break;
				case 2:
					if (citizen[i].pos.x >= 0 && citizen[i].pos.x <= res_x)
					{
						if (citizen[i].pos.y + citizen[i].speed >= 0 && citizen[i].pos.y + citizen[i].speed <= res_y)
						{
							citizen[i].pos.x = citizen[i].pos.x;
							citizen[i].pos.y = citizen[i].pos.y + citizen[i].speed;
						}
					}
					break;
				case 3:
					if (citizen[i].pos.x + citizen[i].speed >= 0 && citizen[i].pos.x + citizen[i].speed <= res_x)
					{
						if (citizen[i].pos.y + citizen[i].speed >= 0 && citizen[i].pos.y + citizen[i].speed <= res_y)
						{
							citizen[i].pos.x = citizen[i].pos.x + citizen[i].speed;
							citizen[i].pos.y = citizen[i].pos.y + citizen[i].speed;
						}
					}
					break;
				case 4:
					if (citizen[i].pos.x - citizen[i].speed >= 0 && citizen[i].pos.x - citizen[i].speed <= res_x)
					{
						if (citizen[i].pos.y >= 0 && citizen[i].pos.y <= res_y)
						{
							citizen[i].pos.x = citizen[i].pos.x - citizen[i].speed;
							citizen[i].pos.y = citizen[i].pos.y;
						}
					}
					break;
				case 5:
					if (citizen[i].pos.x >= 0 && citizen[i].pos.x <= res_x)
					{
						if (citizen[i].pos.y >= 0 && citizen[i].pos.y <= res_y)
						{
							citizen[i].pos.x = citizen[i].pos.x;
							citizen[i].pos.y = citizen[i].pos.y;
						}
					}
					break;
				case 6:
					if (citizen[i].pos.x + citizen[i].speed >= 0 && citizen[i].pos.x + citizen[i].speed <= res_x)
					{
						if (citizen[i].pos.y >= 0 && citizen[i].pos.y <= res_y)
						{
							citizen[i].pos.x = citizen[i].pos.x + citizen[i].speed;
							citizen[i].pos.y = citizen[i].pos.y;
						}
					}
					break;
				case 7:
					if (citizen[i].pos.x - citizen[i].speed >= 0 && citizen[i].pos.x - citizen[i].speed <= res_x)
					{
						if (citizen[i].pos.y - citizen[i].speed >= 0 && citizen[i].pos.y - citizen[i].speed <= res_y)
						{
							citizen[i].pos.x = citizen[i].pos.x - citizen[i].speed;
							citizen[i].pos.y = citizen[i].pos.y - citizen[i].speed;
						}
					}
					break;
				case 8:
					if (citizen[i].pos.x >= 0 && citizen[i].pos.x <= res_x)
					{
						if (citizen[i].pos.y - citizen[i].speed >= 0 && citizen[i].pos.y - citizen[i].speed <= res_y)
						{
							citizen[i].pos.x = citizen[i].pos.x;
							citizen[i].pos.y = citizen[i].pos.y - citizen[i].speed;
						}
					}
					break;
				case 9:
					if (citizen[i].pos.x + citizen[i].speed >= 0 && citizen[i].pos.x + citizen[i].speed <= res_x)
					{
						if (citizen[i].pos.y - citizen[i].speed >= 0 && citizen[i].pos.y - citizen[i].speed <= res_y)
						{
							citizen[i].pos.x = citizen[i].pos.x + citizen[i].speed;
							citizen[i].pos.y = citizen[i].pos.y - citizen[i].speed;
						}
					}
					break;
			}
			if (citizen[i].pos.x >= 0 && citizen[i].pos.x <= res_x)
			{
				if (citizen[i].pos.y >= 0 && citizen[i].pos.y <= res_y)
				{
					if (citizen[i].alive = true)
					{
					display[citizen[i].pos.x][citizen[i].pos.y] = citizen[i].symbol;//fill display with units
					}
			
					/*
					direction id
					[1][2][3]
					[4][5][6]
					[7][8][9]
					*/
					//check surrounding tiles 

			
					for (y = (citizen[i].pos.y); y <= ((citizen[i].pos.y) + 1); y++)
					{
						for (x = (citizen[i].pos.x), check =1; x <= ((citizen[i].pos.x) + 1); x++, check++)
						{

							if (display[x][y] == '*' && (x + y) != 0)
							{
									partner[check] = true;
							}
							else
							{
									partner[check] = false;
							}
						}

					}
				

				}
			}
			
			
		}// end of unit updates
		
		//display
		for (int y = 0; y <= res_y; y++)
		{
			for (int x = 0; x <= res_x; x++)
			{
				cout<<display[x][y];
			}
			cout << endl;
		}

		Sleep(frame_delay);
		system("cls");
	}//end of game loop
	delete citizen;
	cin.get();
	return 0;
}// end of main

stats new_citizen(stats citizen)
{
	citizen.age = 0;
	citizen.symbol = '*';
	citizen.alive = 1;
	citizen.speed = 1;
	citizen.health = 3;
	citizen.lifetime = 10;
	citizen.start_pos.x = 50;
	citizen.start_pos.y = 20;
	return citizen;
}


