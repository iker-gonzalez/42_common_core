#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_vars {
	int		size_x;
	int		size_y;
	int     collectables;
	int     walls;
	char	*name;
}			t_map;

void ft_map_generator(t_map *tmap)
{
	int x = tmap->size_x;
	int y = tmap->size_y;
	int coll = tmap->collectables;
	int wall = tmap->walls;
	int play = 1;
	int exit = 1;
	char map[y][x];
	int     i;
	int     j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
				map[i][j] = '1';
			else
			{
				map[i][j] = '0';
			}
			j++;
		}
//		map[i][j] = 0;
		i++;
	}

	srand(time(NULL));
	for (int e = 0; e < wall; e++){
		int c_x = (rand() % (x - 1 - 1) + 1);
		int c_y = (rand() % (y - 1 - 1) + 1);
		if (map[c_y][c_x] == '0')
			map[c_y][c_x] = '1';
		else
			wall++;
	}
	for (int e = 0; e < coll; e++){
		int c_x = (rand() % (x - 1 - 1) + 1);
		int c_y = (rand() % (y - 1 - 1) + 1);
		if (map[c_y][c_x] == '0')
			map[c_y][c_x] = 'C';
		else
			coll++;
	}
	for (int e = 0; e < exit; e++){
		int c_x = (rand() % (x - 1 - 1) + 1);
		int c_y = (rand() % (y - 1 - 1) + 1);
		if (map[c_y][c_x] == '0')
			map[c_y][c_x] = 'E';
		else
			exit++;
	}
	for (int e = 0; e < play; e++){
		int c_x = (rand() % (x - 1 - 1) + 1);
		int c_y = (rand() % (y - 1 - 1) + 1);
		if (map[c_y][c_x] == '0')
			map[c_y][c_x] = 'P';
		else
			play++;
	}


	int		fd;
	int k = 0;
	fd = open(tmap->name, O_WRONLY | O_CREAT | O_TRUNC, 0755);
	while (k < y)
	{
		write(fd, map[k], sizeof(map[k]));
		if ( k != y - 1)
			write(fd, "\n", 1);
		k++;
	}
	close(fd);

	int f = 0;
	int h;
	system("clear");
	printf("---------------------MAPA GENERADO---------------------\n\n");
	while (f < tmap->size_y)
	{
		h = -1;
		while (++h < sizeof (map[f])) {
			printf("%c", map[f][h]);
		}
		printf("\n");
		f++;
	}
	printf("\n--------------------- %s ---------------------\n\n",tmap->name);
}

int main(int argc, char** argv)
{
	t_map map;

	if (argc < 2 || strcmp(argv[1], "-h") == 0)
	{
		system("clear");
		printf("----------------------------INSTRUCCIONES------------------------------\n\n");
		printf(">>>Para generar el mapa ejecuta el programa con los siguientes parámetros:\n");
		printf(">>>./map_generator \"filas\" \"columnas\" \"coleccionables\" \"obstaculos\" \"nombre\"\n");
		printf(">>>Ej: ./map_generator 8 22 6 7 mapa1\n");
		printf("\n-----------------------------------------------------------------------\n\n");
	}else{
		map.size_y = atoi(argv[1]);
		map.size_x = atoi(argv[2]);
		map.collectables = atoi(argv[3]);
		map.walls = atoi(argv[4]);
		map.name = strcat(argv[5],".ber");

		ft_map_generator(&map);
	}

}
