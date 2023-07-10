#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include <vector>
#include <iostream>
#include <chrono>
using namespace std;
using vec2 = bunny::Vector2;

class Star {
public:
	Star(const vec2& pos, const bunny::Vector2& vel) :
		m_pos{ pos },
		m_vel{ vel }
	{}

	void Update(int width, int height) {
		m_pos += m_vel;

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
	bunny::Vector2 m_pos;
	bunny::Vector2 m_vel;
};

int main(int argc, char* argv[]) {
	bunny::seedRandom((unsigned int)time(nullptr));

	bunny::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	vector<Star> stars;
	for (int i = 0; i < 1000; i++) {
		bunny::Vector2 pos(bunny::Vector2(bunny::random(renderer.GetWidth()), bunny::random(renderer.GetHeight())));
		bunny::Vector2 vel(bunny::randomf(1, 4), 0.0f);
		stars.push_back(Star(pos, vel));
	}

	while (true) {
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();
		// draw

		for (auto& star : stars) {
			star.Update(renderer.GetWidth(), renderer.GetHeight());

			renderer.SetColor(bunny::random(256), bunny::random(256), bunny::random(256), 255);
			star.Draw(renderer);
		}

		/*renderer.SetColor(bunny::random(256), bunny::random(256), bunny::random(256), 255);
		renderer.DrawPoint(bunny::random(renderer.GetWidth()), bunny::random(renderer.GetHeight()));
		renderer.DrawLine(bunny::random(renderer.GetWidth()), bunny::random(renderer.GetHeight()), bunny::random(renderer.GetWidth()), bunny::random(renderer.GetHeight()));

		for (int i = 0; i < 10000; i++) {
			bunny::Vector2 pos(bunny::randomf(renderer.GetWidth(), bunny::random(renderer.GetHeight())));
			renderer.SetColor(bunny::random(256), bunny::random(256), bunny::random(256), 255);
			renderer.DrawPoint(pos.x, pos.y);
		}*/

		renderer.EndFrame();
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