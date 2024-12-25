#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define DECK_SIZE 52
#define CARD_WIDTH 7
#define CARD_HEIGHT 5
#define SLEEP_TIME 50

long long final = 0; //紀錄最後輸贏的錢
const char* face[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "t", "J", "Q", "K" }; //定義牌的數值
const char* suit[] = { "H", "B", "C", "D" }; //定義牌的花色
const char* card_back[] = { //定義牌的背面
	"┌─────┐",
	"│─────│",
	"│─────│",
	"│─────│",
	"└─────┘" };

void clear_screen() {
	system("cls");
}

struct card {
	const char* face;
	const char* suit;
	int value;
};
typedef struct card Card;

Card drawCard(Card deck[], int* deckIndex) { 
	if (*deckIndex >= DECK_SIZE) {
		printf("\n牌已經抽完了！\n");
		exit(1);
	}
	return deck[(*deckIndex)++];
}

void display_two_card(const char* face1, const char* suit1, const char* face2, const char* suit2) {
	
}

void card_front(const char* face, const char* suit, int show) {
	
}

void draw_card(const char* card[], int y, const char* face1, const char* suit1, const char* face2, const char* suit2) {   // 顯示撲克牌在指定位置
	
}

void card_fly_and_flip(int start_y, const char* face, const char* suit, const char* face1, const char* suit1, const char* face2, const char* suit2) {
	
}

void initializeDeck(Card deck[]) { // 初始化撲克牌
	int index = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			deck[index].face = (char*)face[j];
			deck[index].suit = (char*)suit[i];
			deck[index].value = j + 1;
			index++;
		}
	}
}

void shuffle(Card* const wDeck) { // 洗牌
	int i;
	int j;
	Card temp;

	for (i = 0; i < DECK_SIZE; i++) {
		j = rand() % DECK_SIZE;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}

int rull() {
	return 1;
}

int main() {
	
	system("pause");
	return 0;
}