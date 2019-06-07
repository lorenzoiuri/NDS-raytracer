// note: touch.py and touch.py are [0,255]

#include <nds.h>
#include <stdio.h>
#include "Vector3.h"
#include "Ray.h"
#include "Sphere.h"
#include "Camera.h"
#include "utils.h"

using namespace std;

Vector3* colr( Ray* r, Sphere* sphere ) {

	Vector3* ret;
	if ( sphere->hit( r ) ) {
		ret = new Vector3(31,0,0);
	}
	ret = new Vector3(31,15,31);
	return ret;
} 

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

	// creating the sphere
	Vector3* sphere_center = new Vector3(0.0,0.0,-1.0);
	Sphere* sphere = new Sphere( sphere_center, 0.5);
	delete sphere_center;

	// creating the camera
	float32 aspect = (SCREEN_WIDTH*1.0) / (SCREEN_HEIGHT*1.0);
    Camera* camera = new Camera( 90.0*(3.141592)/180.0, aspect );

	// put data inside vram
	while(1) {
		for (u16 j=0; j < SCREEN_HEIGHT; j++) {
			for (u16 i=0; i < SCREEN_WIDTH; i++) {
				float32 u = (i * 1.0) / SCREEN_WIDTH;
				float32 v = (j * 1.0) / SCREEN_HEIGHT;

				Ray* r = camera->getRay( u, v );

				Vector3* col = colr( r, sphere );

				VRAM_A[j * SCREEN_WIDTH + i] = RGB5((int)col->x, (int)col->y, (int)col->z);

				delete col;
			}
		}
		swiWaitForVBlank();
	}
	
}
