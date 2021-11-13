#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
class BaseRunner : private sf::NonCopyable
{
public:
	static const sf::Time	TIME_PER_FRAME;
	static const int WINDOW_WIDTH = 1920;
	static const int WINDOW_HEIGHT = 1080;

	static BaseRunner* getInstance();
	BaseRunner();
	void run();
	float GetFPS();
	static BaseRunner* sharedInstance;
private:
	float fps;
	sf::RenderWindow		window;
	void render();
	void processEvents();
	void update(sf::Time elapsedTime);
};


