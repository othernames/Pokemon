#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "func.h"

//�÷��̾� ��������
Player *make_player(Player *player) {
	player = malloc(sizeof(Player) * PLAYER_NUM);
	if (player == NULL) {
		printf("�Ҵ����");
	}
	else {
		printf("�÷��̾���� �Ҵ缺��\n");
		memset(player, 0x0, sizeof(Player)*PLAYER_NUM);
	}
	player->name = (char*)malloc(sizeof(char) * MAX_NAME);
	if (player->name == NULL) {
		printf("�̸����� �Ҵ� ����\n");
	}
	else {
		printf("�̸����� �Ҵ缺��\n");
		memset(player->name, 0x0, sizeof(char) * MAX_NAME);
	}
	return player;
}

//���ϸ� ���� ����
Pokemon* make_pokemon(Pokemon* pokemon) {
	pokemon = (Pokemon*) malloc(sizeof(Pokemon) * 1);
	if (pokemon == NULL) {
		printf("���ϸ���� �Ҵ����");
	}
	else {
		printf("���ϸ� ���� �Ҵ缺��\n");
		memset(pokemon, 0x0, sizeof(Pokemon) * 1);
	}
	return pokemon;
}

//�κ��丮 ���� ����
Inventory* make_inventory(Inventory* inventory) {
	inventory = (Inventory*) malloc(sizeof(Inventory) * 1);
	if (inventory == NULL) {
		printf("�κ��丮���� �Ҵ����");
	}
	else {
		printf("�κ��丮���� �Ҵ缺��\n");
		memset(inventory, 0x0, sizeof(Inventory) * 1);
	}
	return inventory;
}

//�÷��̾� ���� ����
Player *set_player_info(Player *player) {
	Pokemon* pokemon = { 0 };
	Inventory* inventory = { 0 };

	printf("(���ڻ�) �ڳ��� �̸��� �����ΰ�? ");
	scanf("%s", player->name);
	printf("(���ڻ�) �ݰ���, %s! �� ������ �Բ��� ���ϸ��� �����ϰ� ���ְڳ�\n", player->name);
	Sleep(200);

	//���ϸ� ���� ����
	pokemon = make_pokemon(player->pokemon);

	//���ϸ� ������ �÷��̾� ������ ����
	player->pokemon = pokemon;

	//���ϸ� ���� ����
	set_pokemon_info(player);

	printf("(���ڻ�) ���� ������ �ʿ��� ĳ�ÿ� ���ͺ��� �ְڳ�\n");
	player->cash = CASH;
	printf("ĳ�� %d���� ȹ���Ͽ����ϴ�.\n", player->cash);
	Sleep(200);

	//�κ��丮 ���� ����
	inventory = make_inventory(inventory);
	//�κ��丮 ������ �÷��̾� ������ ����
	player->inventory = inventory;

	//�κ��丮 ���� ����
	set_inventory_info(player);

	printf("(���ڻ�) ��ſ� ����Ǳ⸦ �ٶ�� �̸� ������߰ھ�!\n");
	return player;
}

//���ϸ� ���� ����
void set_pokemon_info(Player* player) {
	printf("1. ���α�, 2. ����, 3. ���̸�\n");
	Sleep(200);
	printf("���ϸ��� �����Ͻÿ� : ");
	scanf("%d", &(player->pokemon->attribute));

	//���Ͽ��� �о���� ������ ���α�, ����, ���̸��� ������ ����
	switch (player->pokemon->attribute) {
	case ggobugi:
		//�ƽ�Ű��Ʈ �ϼ��Ǹ� ���ϸ� ������ ���ϸ� �ƽ�Ű��Ʈ ���


		//attribute

		//name

		//hp

		//max_hp (�ʱ� hp�� ����)

		//power

		//skill

		break;
	case pichu:
		break;
	case fire:
		break;
	}

	// �������� �ϼ��Ǹ� �Ӽ����� �ƴ� �̸��� ����ϵ��� ��������
	printf("���ϸ� �Ӽ��� : %d\n", player->pokemon->attribute);
	Sleep(200);

}

//�κ��丮 ���� ����
void set_inventory_info(Player *player) {
	player->inventory->monster_ball = MONSTER_BALL;
	Sleep(200);
	printf("���Ϻ� %d���� ȹ���Ͽ����ϴ�.\n", player->inventory->monster_ball);
	Sleep(200);
	
}

//�÷��̾� ���� ���� ���
void print_player(Player *player) {
	//�÷��̾� ����
	printf("===================�÷��̾� ����===================\n");
	Sleep(200);
	printf("�÷��̾� �̸� : %s, �÷��̾� ĳ�� : %d\n", player->name, player->cash);
	Sleep(200);
	printf("���� ���� : %d, ���ͺ� ���� : %d\n", player->badge, player->inventory->monster_ball);
	Sleep(200);
	printf("��ȭ�� �� ���� : %d, HP���� ���� : %d\n", player->inventory->evolution_stone, player->inventory->medicine);
	Sleep(200);
	if (player->pokemon_bag == NULL) {
		printf("���ϰ��濡�� ���� ���ϸ��� �����ϴ�.\n");
	}
	else {
		printf("���ϰ��濡�� ()������ ���ϸ��� �ֽ��ϴ�\n");
	}
	Sleep(200);
	printf("Level : %d\n", player->pres_level);
	Sleep(200);

	//���ϸ� ����
	printf("===================���� ���ϸ� ����===================\n");
	Sleep(200);
	printf("�̸� : %s\n", player->pokemon->name);
	Sleep(200);
	printf("HP : %d, POWER : %d,", player->pokemon->hp, player->pokemon->power);
	Sleep(200);
	printf("EXP : %d\n", player->pokemon->exp);
	Sleep(200);
}
//
//Pokemon **make_pokemon_bag_row(Pokemon ***bag_addr) {
//	//bag_addr = malloc(sizeof)
//}
//
//Pokemon **make_pokemon_bag_col(Pokemon ***bag_addr) {
//
//}

