// note: touch.py and touch.py are [0,255]

#include <nds.h>
#include <stdio.h>
//#include "Vector3.h"
#include "Ray.h"
#include "utils.h"

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

	Vector3* origin = new Vector3(0.0,0.0,0.0);
	Vector3* dir = new Vector3(1.0,0.8,0.0);
	Ray* r = new Ray( origin, dir );

	delete origin; delete dir;

	Vector3* pt = r->pointAtParameter(2.0);
	iprintf("point: %d, %d\n", (int32)(pt->x * 100), (int32)(pt->y * 100) );

	delete pt;
	delete r;

	// put data inside vram
	while(1) {
		for (u16 j=0; j < SCREEN_HEIGHT; j++) {
			u16 y = map(j, 0, SCREEN_HEIGHT, 0, 31);
			for (u16 i=0; i < SCREEN_WIDTH; i++) {
				u16 x = map(i, 0, SCREEN_WIDTH, 0, 31);
				VRAM_A[j * SCREEN_WIDTH + i] = RGB5(x,y,15);
			}
		}
		swiWaitForVBlank();
	}
	
}
