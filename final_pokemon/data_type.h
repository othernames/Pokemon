#pragma once
#define MAX_NAME 10
#define PLAYER_NUM 1
#define MONSTER_BALL 3
#define CASH 10000

enum start_pokemon {ggobugi=1, pichu, fire}; //���α�, ����, ���̸�. switch������ ������ ���̱� ����

typedef struct pokemon {
	int attribute;
	char *name;
	int hp;
	int max_hp;
	int power;
	int exp;
	int(*skill)(void *, void *); // ���� ���� player struct ������.
}Pokemon;

typedef struct inventory {
	int monster_ball;
	int evolution_stone;
	int medicine;
}Inventory;

typedef struct player {
	char *name;
	int cash;
	int badge;
	Inventory *inventory;
	Pokemon *pokemon;
	Pokemon **pokemon_bag; //������ �ִ� ���ϸ� ����
	int pres_level; // ü���� ����
}Player;
