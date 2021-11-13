#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Game
{
public:
	Game() ;
	void run();
	float playerSpeed = 300.f;
	const Time TimePerFrame = seconds(1.f / 60.f);

private:
	void processEvents();
	void update(Time);
	void render();
	void rotation(Vector2f);
	void handlePlayerInput(Keyboard::Key, bool);

private:
	RenderWindow window;
	Font font;
	Text FPSText, timePerUpdateText, FPSValue, timePerUpdateValue;
    Sprite player;	
	Texture texture;
	float spriteAngle;
	bool isMovingUp = false;
	bool isMovingDown = false;
	bool isMovingLeft = false;
	bool isMovingRight = false;
	bool isMouseClicking = false;
	Vector2i mousePos;
};