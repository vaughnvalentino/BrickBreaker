#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
#include <vector>

using namespace std;
using namespace sf;
using namespace sfp;

const float KB_SPEED = 0.1;

int hit = 0;
int points = 0;
int done = 0;

void LoadTex(Texture& tex, string filename) { 
	if (!tex.loadFromFile(filename)) {
		cout << "Could not load " << filename << endl;
	} 
}

int main()
{
	// Render Window
	RenderWindow window(VideoMode(1360, 1000), "Brick Breaker");
	World world(Vector2f(0, 1.5));
	int score(0);

	//PhysicsSprite platform;
	PhysicsSprite& platform = *new PhysicsSprite(); 
	Texture platformTex; 
	LoadTex(platformTex, "images/platform.png"); 
	platform.setTexture(platformTex); 
	Vector2f sz = platform.getSize(); 
	platform.setCenter(Vector2f(680, 
		930 - (sz.y / 2)));
	world.AddPhysicsBody(platform);
	platform.setStatic(true);  

	world.UpdatePhysics(10);

	Text scoreText;
	Font font;
	if (!font.loadFromFile("arial.ttf")) {
		cout << "Couldn't load font arial.ttf" << endl;
		exit(1);
	}
	scoreText.setFont(font);

	// Ball
	PhysicsCircle ball;
	ball.setCenter(Vector2f(640, 600));
	ball.setRadius(20);
	ball.applyImpulse(Vector2f(.15, .91)); 
	world.AddPhysicsBody(ball);
	bool drawingBall(false);

	// Floor, Remove Physics
	PhysicsRectangle floor;
	floor.setSize(Vector2f(1360, 20));
	floor.setCenter(Vector2f(680, 1200));
	floor.setStatic(true);
	world.AddPhysicsBody(floor);  

	// Ceiling
	PhysicsRectangle ceiling;
	ceiling.setSize(Vector2f(1360, 340));
	ceiling.setCenter(Vector2f(680, 10));
	ceiling.setStatic(true);
	world.AddPhysicsBody(ceiling);

	// Right Wall
	PhysicsRectangle rwall;
	rwall.setSize(Vector2f(20, 1000));
	rwall.setCenter(Vector2f(1350, 500));
	rwall.setStatic(true);
	world.AddPhysicsBody(rwall);

	// Left Wall
	PhysicsRectangle lwall;
	lwall.setSize(Vector2f(20, 1000));
	lwall.setCenter(Vector2f(10, 500));
	lwall.setStatic(true);
	world.AddPhysicsBody(lwall);
	
	// Blocks Row
	PhysicsRectangle rect9;
	rect9.setSize(Vector2f(140, 140));
	rect9.setCenter(Vector2f(120, 280));
	rect9.setStatic(true);
	world.AddPhysicsBody(rect9);

	PhysicsRectangle rect10;
	rect10.setSize(Vector2f(140, 140));
	rect10.setCenter(Vector2f(280, 280));
	rect10.setStatic(true);
	world.AddPhysicsBody(rect10);

	PhysicsRectangle rect11;
	rect11.setSize(Vector2f(140, 140));
	rect11.setCenter(Vector2f(440, 280));
	rect11.setStatic(true);
	world.AddPhysicsBody(rect11);

	PhysicsRectangle rect12;
	rect12.setSize(Vector2f(140, 140));
	rect12.setCenter(Vector2f(600, 280));
	rect12.setStatic(true);
	world.AddPhysicsBody(rect12);

	PhysicsRectangle rect13;
	rect13.setSize(Vector2f(140, 140));
	rect13.setCenter(Vector2f(760, 280));
	rect13.setStatic(true);
	world.AddPhysicsBody(rect13);

	PhysicsRectangle rect14;
	rect14.setSize(Vector2f(140, 140));
	rect14.setCenter(Vector2f(920, 280));
	rect14.setStatic(true);
	world.AddPhysicsBody(rect14);

	PhysicsRectangle rect15;
	rect15.setSize(Vector2f(140, 140));
	rect15.setCenter(Vector2f(1080, 280));
	rect15.setStatic(true);
	world.AddPhysicsBody(rect15);

	PhysicsRectangle rect16;
	rect16.setSize(Vector2f(140, 140));
	rect16.setCenter(Vector2f(1240, 280));
	rect16.setStatic(true);
	world.AddPhysicsBody(rect16);

	// Boundary Collision
	int thudCount(0);
	floor.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		cout << "Thud " << thudCount << endl;
		thudCount++;
		done = 1; 
		cout << "Loser " << endl; 
		};
	ceiling.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		cout << "Thud " << thudCount << endl;
		thudCount++;
		};
	rwall.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		cout << "Thud " << thudCount << endl;
		thudCount++;
		};
	lwall.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		cout << "Thud " << thudCount << endl;
		thudCount++;
		};
	platform.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		cout << "Thud " << thudCount << endl;
		thudCount++;
		};

	// Brick Collision
	int bangCount(0);

	rect9.onCollision = [&bangCount](PhysicsBodyCollisionResult result) {
		cout << "Bang " << bangCount << endl;
		bangCount++;
		hit = 9;
		};
	rect10.onCollision = [&bangCount](PhysicsBodyCollisionResult result) {
		cout << "Bang " << bangCount << endl;
		bangCount++;
		hit = 10;
		};
	rect11.onCollision = [&bangCount](PhysicsBodyCollisionResult result) {
		cout << "Bang " << bangCount << endl;
		bangCount++;
		hit = 11;
		};
	rect12.onCollision = [&bangCount](PhysicsBodyCollisionResult result) {
		cout << "Bang " << bangCount << endl;
		bangCount++;
		hit = 12;
		};
	rect13.onCollision = [&bangCount](PhysicsBodyCollisionResult result) {
		cout << "Bang " << bangCount << endl;
		bangCount++;
		hit = 13;
		};
	rect14.onCollision = [&bangCount](PhysicsBodyCollisionResult result) {
		cout << "Bang " << bangCount << endl;
		bangCount++;
		hit = 14;
		};
	rect15.onCollision = [&bangCount](PhysicsBodyCollisionResult result) {
		cout << "Bang " << bangCount << endl;
		bangCount++;
		hit = 15;
		};
	rect16.onCollision = [&bangCount](PhysicsBodyCollisionResult result) {
		cout << "Bang 16" << bangCount << endl;
		bangCount++;
		hit = 16;
		};

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) { 
			if (event.type == Event::Closed) 
				window.close(); 
		}


		Clock clock;
		Time lastTime(clock.getElapsedTime());
		while (bangCount <= 1000000000) {
			Time currentTime(clock.getElapsedTime());
			Time deltaTime(currentTime - lastTime);
			int deltaTimeMS(deltaTime.asMilliseconds());
			if (deltaTimeMS > 0) {
				world.UpdatePhysics(deltaTimeMS);
				lastTime = currentTime;
			}

			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				Vector2f newPos(platform.getCenter());
				newPos.x = newPos.x + (KB_SPEED * clock.getElapsedTime().asSeconds());
				platform.setCenter(newPos);
			}
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				Vector2f newPos(platform.getCenter());
				newPos.x = newPos.x - (KB_SPEED * clock.getElapsedTime().asSeconds());
				platform.setCenter(newPos);
			}

			// Displays Boundaries, Center Square, And Ball
			window.clear(Color(0, 0, 0));
			window.draw(floor);
			window.draw(ceiling);
			window.draw(rwall);
			window.draw(lwall);
			window.draw(platform);
			//Blocks Top Row
			window.draw(rect9);
			window.draw(rect10);
			window.draw(rect11);
			window.draw(rect12);
			window.draw(rect13);
			window.draw(rect14);
			window.draw(rect15);
			window.draw(rect16);

			if (hit == 9)
			{
				world.RemovePhysicsBody(rect9); 
				rect9.setFillColor(Color(0, 0, 0)); 
				points++; 
				hit = 0;
			}

			else if (hit == 10)
			{
				world.RemovePhysicsBody(rect10); 
				rect10.setFillColor(Color(0, 0, 0));
				points++;
				hit = 0;
			}

			else if (hit == 11)
			{
				world.RemovePhysicsBody(rect11); 
				rect11.setFillColor(Color(0, 0, 0));
				points++;
				hit = 0;
			}

			else if (hit == 12)
			{
				world.RemovePhysicsBody(rect12);
				rect12.setFillColor(Color(0, 0, 0));
				points++;
				hit = 0;
			}

			else if (hit == 13)
			{
				world.RemovePhysicsBody(rect13);
				rect13.setFillColor(Color(0, 0, 0));
				points++;
				hit = 0;
			}

			else if (hit == 14)
			{
				world.RemovePhysicsBody(rect14);
				rect14.setFillColor(Color(0, 0, 0));
				points++;
				hit = 0;
			}

			else if (hit == 15)
			{
				world.RemovePhysicsBody(rect15);
				rect15.setFillColor(Color(0, 0, 0));
				points++;
				hit = 0;
			}

			else if (hit == 16)
			{
				world.RemovePhysicsBody(rect16);
				rect16.setFillColor(Color(0,0,0)); 
				points++;
				hit = 0;
			}
			
			scoreText.setString("Score: " + to_string(points));
			FloatRect textBounds = scoreText.getGlobalBounds(); 
			scoreText.setFillColor(Color(256, 256, 256));
			scoreText.setCharacterSize(100);
			scoreText.setPosition(
				Vector2f(850 - textBounds.width, 100 - textBounds.height)); 
			window.draw(scoreText); 

			if (done == 1)
			{
				Text gameOverText;
				gameOverText.setFont(font);
				gameOverText.setString("GAME OVER | Points: " + to_string(points));
				gameOverText.setCharacterSize(100); 
				FloatRect textBounds = gameOverText.getGlobalBounds();
				gameOverText.setPosition(Vector2f(
					680 - (textBounds.width / 2),
					500 - (textBounds.height / 2)
				));
				window.clear(Color(256,256,256)); 
				window.draw(gameOverText);
				window.display();
				while (true);
			}

			if (points == 8)
			{
				Text gameOverText;
				gameOverText.setFont(font);
				gameOverText.setString("YOU WIN");
				gameOverText.setCharacterSize(100);
				FloatRect textBounds = gameOverText.getGlobalBounds();
				gameOverText.setPosition(Vector2f(
					680 - (textBounds.width / 2),
					500 - (textBounds.height / 2)
				));
				window.clear(Color(256, 256, 256));
				window.draw(gameOverText);
				window.display();
				while (true);
			}


			window.draw(ball); 
			window.display();
		}
	}
}
