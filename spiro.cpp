#include "iostream"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
//String splitting function
void split2(const std::string& str, std::vector<std::string>& cont, char delim = ' '){
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, delim)){
		cont.push_back(token);
	}
}

int main(int argc, char *argv[]){
	bool	nextPattern = false;
	int		winX=800, winY = 600;
	int 	width, tempx, tempy, counter, red, green, blue;
	float	cX, cY, X, Y, x, y, r, d, R, theta, Theta, dT, temp;
	std::string line, line2, sign;
	std::vector<std::string> vline;

	theta = 0.;
	Theta = 0.;
	dT = M_PI/500.;

	//Create the main window
	sf::RenderWindow window(sf::VideoMode(winX, winY), "Spirograph!");

	sf::Uint8*	pixels = new sf::Uint8[winX*winY*4];
	sf::Texture texture;
	texture.create(winX, winY);
	sf::Sprite sprite(texture);

	//Initialize all pixels to black
	for (int i = 0; i < winX*winY*4; i+=4){
		pixels[i] = 0;
		pixels[i+1] = 0;
		pixels[i+2] = 0;
		pixels[i+3] = 255;
	}

	// Read the first line in the input file
	std::ifstream inp(argv[1]);
	std::getline(inp, line); // Skip the first line
	std::getline(inp, line); // The real first line of the input
	split2(line, vline);
	r = std::stod(vline[0]); d = std::stod(vline[1]); R = std::stod(vline[2]), cX = std::stod(vline[3]), cY = std::stod(vline[4]);
	red = std::stoi(vline[5]); green = std::stoi(vline[6]); blue = std::stoi(vline[7]); sign = vline[8];
	width = std::stoi(vline[9]);

	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed) window.close();

			if (event.type == sf::Event::KeyPressed){
				if (event.key.code == sf::Keyboard::RControl) dT += M_PI/10000.;
			}
			if (event.type == sf::Event::KeyPressed){
				if (event.key.code == sf::Keyboard::LControl) dT -= M_PI/10000.;
				if (dT < 0.) dT = 0.;
			}
			// Go to the next spirograph when the user hits, and then releases the return key.
			if (event.type == sf::Event::KeyPressed){
				if (event.key.code == sf::Keyboard::Return) nextPattern = true;
			}
			if (event.type == sf::Event::KeyReleased and nextPattern){
				if (event.key.code == sf::Keyboard::Return){
					vline.clear();
					std::getline(inp, line);
					split2(line, vline);
					r = std::stod(vline[0]); d = std::stod(vline[1]); R = std::stod(vline[2]), cX = std::stod(vline[3]), cY = std::stod(vline[4]);
					red = std::stoi(vline[5]); green = std::stoi(vline[6]); blue = std::stoi(vline[7]); sign = vline[8];
					width = std::stoi(vline[9]);
					nextPattern = false;
				}
			}
		}
		
		// The "Spiromath" - the engine that controls the updating of the location of the pencil that draws the spirograph
		Theta += dT;

		if (sign == "m") theta -= dT*2*R/d;
		if (sign == "p") theta += dT*2*R/d;

		X = cX + R*cos(Theta);
		Y = cY + R*sin(Theta);

		x = X + r*cos(theta);
		y = Y + r*sin(theta);

		tempx = int(x);
		tempy = int(y);

		counter = 0;
		
		// Change the pixel colors at the pencil location (and nearby locations to accomodate the requested 'stroke width') to the color specified by the user.
		while (counter < width){
			if ((4*tempy*winX+4*(tempx+counter-int(0.5*counter))) < winX*winY*4){
				pixels[4*tempy*winX+4*(tempx+counter-int(0.5*counter))+0] = red;
				pixels[4*tempy*winX+4*(tempx+counter-int(0.5*counter))+1] = green;
				pixels[4*tempy*winX+4*(tempx+counter-int(0.5*counter))+2] = blue;
			}
			counter++;
		}

		window.clear();
		texture.update(pixels);
		window.draw(sprite);
		window.display();
	}
	inp.close();
}
