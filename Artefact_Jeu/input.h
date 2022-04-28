#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

using namespace sf;


class Input {
	struct Button { bool left, right, up, down, attack, escape, shift, clicG, moletteH, molletteB, inventaire; };


public:
	//Proto du contructeur
	Input();
	//Proto du GetButton()
	Button GetButton(void) const;

	//Proto de la fonction InputHandler (en gros c'est pour dire que la fonction existe)
	void InputHandler(Event event, RenderWindow& window);
	void resetButtonMollette();

private:
	//On crée une variable "button" qui est un attribut de la classe input, respectant la structure Button juste au dessus
	Button button;


};
#endif

