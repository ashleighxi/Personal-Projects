#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "windows.h"
using namespace std;


const int x_size = 41; //make these odd numbers
const int y_size = 41;
char fate(int, int); //decide if cells live or die
char boardArray [x_size][y_size]; //board that is displayed on screen
char tempArray [x_size][y_size]; //board used to transfer results without affecting future ones


int main() {
	
	int iterations = 0; // avoid infinite loop
	srand (time(NULL));

	for (int x = 0; x < x_size; x++) { //initializing the boards
		for (int y = 0; y < y_size; y++) {
			boardArray[x][y] = ' ';
			tempArray[x][y] = ' ';
		}
	}
	for (int i = 1; i < x_size-1; i++) {
		for (int j = 1; j < y_size-1; j++) {
			float random = rand() % 10 + 1;
			if (random >= 8) {
				boardArray[i][j] = 'O';
			}
		}
	}
	system("PAUSE");
	// boardArray[((x_size-1)/2)-1][y_size/2] = 'O'; //creating the initial shape
	// boardArray[((x_size-1)/2)][(y_size/2)-1] = 'O';
	// boardArray[((x_size-1)/2)][(y_size/2)+1] = 'O';
	// for (int j = ((y_size-1)/2)-5; j < ((y_size-1)/2)+5; j++) {
	// 	boardArray[((x_size-1)/2)+1][j] = 'O';
	// 	boardArray[((x_size-1)/2)+1][j+12] = 'O';
	// }
	// boardArray[((x_size-1)/2)+3][y_size/2] = 'O';
	// boardArray[((x_size-1)/2)+2][(y_size/2)-1] = 'O';
	// boardArray[((x_size-1)/2)+2][(y_size/2)+1] = 'O';


	for (int i = 0; i < x_size; i++) {
			for (int j = 0; j < y_size; j++) {
				cout << boardArray[i][j] << " ";
			}
			cout << endl;
		}

	do {
		for (int i = 1; i < x_size-1; i++) {
			for (int j = 1; j < y_size-1; j++) {
				tempArray[i][j] = fate(i,j);
			}
		}
		for (int i = 0; i < x_size; i++) {
			for (int j = 0; j < y_size; j++) {
				boardArray[i][j] = tempArray[i][j];
				cout << boardArray[i][j] << " ";
			}
			cout << endl;
		}
		// for (int i = 0; i < x_size; i++) {
		// 	//cout << "                ";
		// 	for (int j = 0; j < y_size; j++) {
		// 		//if (boardArray[i][j] == 'O') {
		// 			cout << boardArray[i][j] << " ";
		// 		//}
		// 	}
		// 	cout << endl;
		// }
		
		iterations++;
		
		system("CLS");
		
	} while(iterations < 5000);

	return 0;
}

char fate(int x, int y) {
	int count = 0;
	switch (boardArray[x][y]) {
		case ' ':
			for (int i = x-1; i < x+2; i++) {
				for (int j = y-1; j < y+2; j++) {
					if(boardArray[i][j] == 'O'){
						count++;
					} 					
				}
			}
			if (count == 3) {
				return 'O';
			} else {
				return ' ';
			}
			break;
		case 'O':
			for (int i = x-1; i < x+2; i++) {
				for (int j = y-1; j < y+2; j++) {
					if(boardArray[i][j] == 'O') {
						count++;
					}					
				}
			}
			count -= 1;
			if(count > 1 && count < 4) {
				return 'O';
			} else {
				return ' ';
			}
			break;
	}
}
