
#include <iostream>
#include "raylib.h"
#include "Enemy.h"
#include "tVector.h"
using namespace std;
int main()
{
	// Initialization
	int screenWidth = 800;
	int screenHeight = 450;
	tVector<int> bob;
	InitWindow(screenWidth, screenHeight, " Practice");
	bob.reserve(10);
	bob.push_back(1);
	bob.push_back(2);
	
	cout << bob.size() << endl;
	
	SetTargetFPS(60);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		
		// Update
		// TODO: Update your variables here

		// Draw
		
		BeginDrawing();

		ClearBackground(RAYWHITE);
	

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	CloseWindow();        // Close window and OpenGL context
	

	return 0;
}