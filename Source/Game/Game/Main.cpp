#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include <vector>
#include <iostream>
#include <chrono>
#include "Renderer/Model.h"
#include <thread>

using namespace std;
using vec2 = bunny::Vector2;

class Star {
public:
	Star(const vec2& pos, const bunny::Vector2& vel) :
		m_pos{ pos },
		m_vel{ vel }
	{}

	void Update(int width, int height) {
		m_pos += m_vel * kiko::g_time.GetDelta();

		if (m_pos.x >= width) {
			m_pos.x = 0;
		}

		if (m_pos.y >= height) {
			m_pos.y = 0;
		}
	}

	void Draw(bunny::Renderer& r) {
		r.DrawPoint(m_pos.x, m_pos.y);
	}
public:
	bunny::vec2 m_pos;
	bunny::vec2 m_vel;
};

int main(int argc, char* argv[]) {
	bunny::seedRandom((unsigned int)time(nullptr));
	bunny::setFilePath("Assets");
	bunny::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	bunny::InputSystem is;
	is.Initialize();

	//std::vector<bunny::vec2> points{ {-10,5}, {10, 5}, {0, -5}, {-10, 5} };
	bunny::Model model;
	model.Load("ship.txt");

	bunny::vec2 v{ 5,5 };
	v.Normalize();

	vector<Star> stars;
	for (int i = 0; i < 1000; i++) {
		bunny::Vector2 pos(bunny::Vector2(bunny::random(renderer.GetWidth()), bunny::random(renderer.GetHeight())));
		bunny::Vector2 vel(bunny::randomf(1, 4), 0.0f);
		stars.push_back(Star(pos, vel));
	}

	bunny::Transform transform{ {400, 300}, 0, 3 };
	bunny::vec2 position{ 400, 300 };
	float speed = 200;
	float turnRate = bunny::DegreesToRadians(180);

	//game loop
	bool quit = false;
	while (!quit) {
		kiko::g_time.Tick();
		is.Update();

		float rotate = 0;
		if (is.GetKeyDown(SDL_SCANCODE_A)) {
			rotate = -1;
		}

		if (is.GetKeyDown(SDL_SCANCODE_D)) {
			rotate = 1;
		}
		transform.rotation += rotate * turnRate * kiko::g_time.GetDelta();

		float thrust = 0;
		if (is.GetKeyDown(SDL_SCANCODE_W)) {
			thrust = 1;
		}

		if (is.GetKeyDown(SDL_SCANCODE_S)) {
			thrust = -1;
		}

		bunny::vec2 forward = bunny::vec2{ 0, -1 }.Rotate(transform.rotation);
		transform.position += forward * speed * thrust * kiko::g_time.GetDelta();
		//transform.position.x = bunny::Wrap(transform.position.x, renderer.GetWidth());
		//transform.position.y = bunny::Wrap(transform.position.y, renderer.GetHeight());

		//bunny::vec2 direction;
		//if (is.GetKeyDown(SDL_SCANCODE_ESCAPE)) {
		//	quit = true;
		//}

		//if (is.GetKeyDown(SDL_SCANCODE_W)) {
		//	direction.y = -1;
		//}

		//if (is.GetKeyDown(SDL_SCANCODE_S)) {
		//	direction.y = 1;
		//}

		//if (is.GetKeyDown(SDL_SCANCODE_A)) {
		//	direction.x = -1;
		//}

		//if (is.GetKeyDown(SDL_SCANCODE_D)) {
		//	direction.x = 1;
		//}

		//position += direction * speed * kiko::g_time.GetDelta();

		if (is.GetMouseButtonDown(0)) {
			cout << "left" << endl;
			cout << is.GetMousePosition().x << " " << is.GetMousePosition().y << endl;
		}

		if (is.GetMouseButtonDown(1)) {
			cout << "middle" << endl;
		}

		if (is.GetMouseButtonDown(2)) {
			cout << "right" << endl;
		}

		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();
		// draw

		for (auto& star : stars) {
			star.Update(renderer.GetWidth(), renderer.GetHeight());

			renderer.SetColor(bunny::random(256), bunny::random(256), bunny::random(256), 255);
			star.Draw(renderer);
		}

		model.Draw(renderer, transform.position, transform.rotation, transform.scale);

		renderer.EndFrame();

		//this_thread::sleep_for(chrono::milliseconds(100));
	}

	//bunny::g_memoryTracker.DisplayInfo();
	//int* p = new int;
	//bunny::g_memoryTracker.DisplayInfo();
	//delete p;
	//bunny::g_memoryTracker.DisplayInfo();

	//kiko::Time timer;
	//for (int i = 0; i < 1000000; i++) {}
	//cout << timer.GetElapsedSeconds() << endl;

	/*auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < 10000000; i++) {}
	
	auto end = std::chrono::high_resolution_clock::now();

	cout << (end - start).count() << endl;*/

	/*cout << bunny::getFilePath() << endl;
	bunny::setFilePath("Assets");
	cout << bunny::getFilePath() << endl;
	size_t size;
	bunny::getFileSize("why.txt", size);
	cout << size << endl;

	string s;
	bunny::readFile("why.txt", s);
	cout << s << endl;

	bunny::seedRandom((unsigned int)time(nullptr));
	for (int i = 0; i < 10; i++) {
		cout << bunny::random(1, 9) << endl;
	}*/

	return 0;
}