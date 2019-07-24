
#include <nds.h>
#include <stdio.h>
#include "Vector3.h"
#include "RGBColor.h"
#include "HitRecord.h"
#include "Ray.h"
#include "Sphere.h"
#include "Camera.h"
#include "utils.h"

#define BACKGROUND_RED 6
#define BACKGROUND_GREEN 6
#define BACKGROUND_BLUE 6

using namespace std;

// determines if r intersects sphere, if so returns the color of the sphere, otherwise the background
RGBColor* colr( Ray* r, Sphere* sphere ) {

	RGBColor* ret;
	HitRecord* hr = new HitRecord();
	if ( sphere->hit( r, 0.0, 99999.0, hr ) ) {
		ret = new RGBColor( (uint8) (0.5*(hr->n->x+1.0)*31.0),
							(uint8) (0.5*(hr->n->y+1.0)*31.0),
							(uint8) (0.5*(hr->n->z+1.0)*31.0) );
	} else {
		ret = new RGBColor(BACKGROUND_RED, BACKGROUND_GREEN, BACKGROUND_BLUE);
	}

	delete hr;
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

	// creating the sphere centered in (0,0,-1) with radius 0.5
	Vector3* sphere_center = new Vector3(0.0,0.2,-1.0);
	Sphere* sphere = new Sphere( sphere_center, 0.5);
	delete sphere_center;

	// creating the camera
	float32 aspect = (SCREEN_WIDTH*1.0) / (SCREEN_HEIGHT*1.0);
    Camera* camera = new Camera( 90.0*M_PI/180.0, aspect );

	// counter for the rendering passes
	int16 count = 0;

	// put data inside vram
	while(1) {
		for (u16 j=0; j < SCREEN_HEIGHT; j++) {
			for (u16 i=0; i < SCREEN_WIDTH; i++) {
				float32 u = (i * 1.0) / SCREEN_WIDTH;
				float32 v = (j * 1.0) / SCREEN_HEIGHT;

				// get ray from the pixel through the camera
				Ray* r = camera->getRay( u, v );

				// determine the color of the pixel based on the intersection between the ray and the sphere
				RGBColor* col = colr( r, sphere );

				delete r;

				// set the computed color in the vram
				VRAM_A[(SCREEN_HEIGHT - j) * SCREEN_WIDTH + i] = RGB5(col->r, col->g, col->b);

				delete col;
			}
		}
		count++;
		iprintf("pass: %d\n", count);
		swiWaitForVBlank();
	}

	delete camera;
	delete sphere;
	
}
