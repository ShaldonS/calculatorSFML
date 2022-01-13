#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

float sfString_to_num(sf::String str) {
	float num = 0.0f;

	return num;
}

std::string calculate_expr(std::string str) {
	std::string answer(""), tmp_str, signs;
	int answer_int = 0;
	std::vector<int> nums;
	for (char ch : str) {
		if (int(ch) <= 47 && int(ch) >= 40) {
			nums.push_back(stoi(tmp_str));
			tmp_str = "";
			signs += ch;
		}
		else {
			tmp_str += ch;
		}
	}
	nums.push_back(stoi(tmp_str));
	for (int i(0); i < signs.size(); ++i) {
		if (signs[i] == '/') {
			answer_int += (nums[i] / nums[i + 1]);
		}
		if (signs[i] == '*') {
			answer_int += (nums[i] * nums[i + 1]);
		}
		if (signs[i] == '-') {
			answer_int += (nums[i] - nums[i + 1]);
		}
		if (signs[i] == '+') {
			answer_int += (nums[i] + nums[i + 1]);
		}
	}
	answer = std::to_string(answer_int);

	return answer;
}

int main(int argc, char** argv) {
	sf::RenderWindow window;

	window.create(sf::VideoMode(300, 450), "Calculator", sf::Style::Default);

	RectangleShape buttons_field(Vector2f(300.0f, 400.0f));
	buttons_field.setFillColor(Color(0, 0, 0, 200));
	buttons_field.setPosition(0.0f, 50.0f);

	sf::Font font;
	font.loadFromFile("C:/WINDOWS/Fonts/arial.ttf");
	const int size_buttons = 19;
	sf::Text buttons_text[size_buttons];
	buttons_text[0].setString("7");
	buttons_text[1].setString("8");
	buttons_text[2].setString("9");
	buttons_text[3].setString("/");
	buttons_text[4].setString("4");
	buttons_text[5].setString("5");
	buttons_text[6].setString("6");
	buttons_text[7].setString("*");
	buttons_text[8].setString("1");
	buttons_text[9].setString("2");
	buttons_text[10].setString("3");
	buttons_text[11].setString("-");
	buttons_text[12].setString("+-");
	buttons_text[13].setString("0");
	buttons_text[14].setString(".");
	buttons_text[15].setString("+");
	buttons_text[16].setString("(");
	buttons_text[17].setString(")");
	buttons_text[18].setString("=");
	for (int i(0); i < size_buttons; ++i) {
		buttons_text[i].setFont(font);
		buttons_text[i].setCharacterSize(24);
		buttons_text[i].setFillColor(sf::Color::Black);
		buttons_text[i].setStyle(sf::Text::Bold);
	}
	RectangleShape buttons[size_buttons];
	int x = 10.0f, y = 60.0f;
	for(int i(0); i < size_buttons; ++i) {
		buttons[i].setSize(Vector2f(40.0f, 40.0f));
		buttons[i].setFillColor(Color(255, 255, 255));
		buttons[i].setPosition(x, y);
		buttons_text[i].setPosition(x+10.0f, y+5.0f);
		x += 60.0f;
		if ((i+1) % 4 == 0) {
			x = 10.0f;
			y += 50.0f;
		}
	}

	sf::Text text;
	text.setString("Input expression here");
	text.setFont(font);
	text.setCharacterSize(24); 
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	window.clear(Color(72, 0, 255));

	sf::String input;
	int pos_button = 0;
	std::vector<sf::String> nums_to_calc;
	std::vector<char> sign_to_calc;
	while (window.isOpen()) {
		sf::Event event;
		
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			for (int i(0); i < size_buttons; ++i) {
				Vector2i pos;
				pos.x = buttons[i].getPosition().x;
				pos.y = buttons[i].getPosition().y;
				if (Mouse::getPosition(window).x <= pos.x + 40.0f && Mouse::getPosition(window).y <= pos.y + 40.0f && event.type == sf::Event::MouseButtonPressed) {
					input += buttons_text[i].getString();
					text.setString(input);
					std::cout << input.getSize();

					sf::String tmp_str;
					int input_size = input.getSize();
					if ((i + 1) % 4 == 0) { //when sign is not a num 
						/*for (int j(0); j < input_size-1; ++j) {//for (auto ch : input){
							tmp_str += input[j];
						}
						sign_to_calc.push_back(input[input_size - 1]);
						std::string str = static_cast<std::string>(tmp_str); //tmp_str.operator std::string();
						nums_to_calc.push_back(str);
						*/
						
						//input.clear();
					}
					/*std::cout << "\nVECTOR OF NUMS: ";
					for (std::string st : nums_to_calc) {
						cout << st << " ";
					}
					std::cout << "\nVECTOR OF SIGNS: ";
					for (char ch : sign_to_calc) {
						cout << ch << " ";
					}
					std::cout << "\n";*/
					buttons_text[i].setFillColor(Color::Red);
					pos_button = i;
					if (i == size_buttons - 1) {
						std::string str = static_cast<std::string>(input);
						str.pop_back();
						std::string s("");
						s = calculate_expr(str);
						sf::String answer(s);
						text.setString(answer);
						input.clear();
					}
					break;
				}
			}
			if (event.type == sf::Event::TextEntered)
			{
				input += event.text.unicode;
				text.setString(input);
			}
			//if (event.key.code == sf::Keyboard::)
		}
		window.draw(buttons_field);
		window.draw(text);
		for (int i(0); i < size_buttons; ++i) {
			window.draw(buttons[i]);
			window.draw(buttons_text[i]);
		}
		window.display();
		window.clear(Color(72, 0, 255));
	}
	return 0;
}























/*#include "engine.h"

int main() {
	Engine engine;

	engine.start();

	return 0;
}*/

