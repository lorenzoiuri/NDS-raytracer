// note: touch.py and touch.py are [0,255]

#include <nds.h>
#include <stdio.h>
#include "utils.h"
#include "Vector3.h"

using namespace std;

int main(void) {
	
	// main engine has direct access to video memory
	videoSetMode(MODE_FB0);
	vramSetBankA(VRAM_A_LCD);
	
	// sub engine used for printing debug info
	videoSetModeSub(MODE_0_2D);
	
	// main engine works on top lcd
	lcdMainOnTop();
	
	// put some text on bottom screen
	consoleDemoInit();
	iprintf("--------------------------------\n");
	iprintf("\n debug text initialized \n");

	Vector3 v(33,2,15);
	iprintf("\n %d %d\n", v.x, v.getX());
	iprintf("\n %d\n", map(5, 1, 10, 100, 160) );
	
	// put data inside vram
	while(1) {
		for (int j=0; j < SCREEN_HEIGHT; j++) {
			int y = map(j, 0, SCREEN_HEIGHT, 0, 31);
			for (int i=0; i < SCREEN_WIDTH; i++) {
				int x = map(i, 0, SCREEN_WIDTH, 0, 31);
				VRAM_A[j * SCREEN_WIDTH + i] = RGB5(x,y,15);
			}
		}
		swiWaitForVBlank();
	}
	
}
