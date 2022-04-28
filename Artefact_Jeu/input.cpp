#include "input.h"

//Constructeur
Input::Input() {
    button.left = button.right = button.attack = button.down = button.escape = button.up = button.shift = button.clicG = false;
}
//Fonction qui accède à button (struct) et qui nous donne l'info private
Input::Button Input::GetButton(void) const
{
    return button;
}
//Fonction
//gestion des inputs
void Input::InputHandler(Event event, RenderWindow& window) {
    if (event.type == Event::Closed) {
        window.close();
    }
    if (event.type == Event::KeyPressed) {
        switch (event.key.code)
        {
        case Keyboard::Escape:
            button.escape = true;
            break;
        case Keyboard::Left:
            button.left = true;
            break;
        case Keyboard::Right:
            button.right = true;
            break;
        case Keyboard::Down:
            button.down = true;
            break;
        case Keyboard::Up:
            button.up = true;
            break;
        case Keyboard::LShift:
            button.shift = true;
            break;
        case Keyboard::Z:
            button.up = true;
            break;
        case Keyboard::S:
            button.down = true;
            break;
        case Keyboard::D:
            button.right = true;
            break;
        case Keyboard::Q:
            button.left = true;
            break;
        case Keyboard::I:
            button.inventaire = true;
            break;
        default:
            break;
        }
    }
    if (event.type == Event::KeyReleased) {
        switch (event.key.code)
        {
        case Keyboard::Escape:
            button.escape = false;
            break;
        case Keyboard::Left:
            button.left = false;
            break;
        case Keyboard::Right:
            button.right = false;
            break;
        case Keyboard::Down:
            button.down = false;
            break;
        case Keyboard::Up:
            button.up = false;
            break;
        case Keyboard::LShift:
            button.shift = false;
            break;
        case Keyboard::Z:
            button.up = false;
            break;
        case Keyboard::S:
            button.down = false;
            break;
        case Keyboard::D:
            button.right = false;
            break;
        case Keyboard::Q:
            button.left = false;
            break;
        case Keyboard::I:
            button.inventaire = false;
            break;
        default:
            break;
        }
    }
    if (event.type == Event::MouseButtonPressed) {
        if (event.key.code == Mouse::Left) {
            button.clicG = true;
        }
    }
    if (event.type == Event::MouseButtonReleased) {
        if (event.key.code == Mouse::Left) {
            button.clicG = false;
        }
    }
    if (event.type == Event::MouseWheelMoved) {
        if (event.mouseWheel.delta == 1) {
            button.moletteH = true;
        }
        if (event.mouseWheel.delta == -1) {
            button.molletteB = true;
        }
    }


}

void Input::resetButtonMollette() {
    button.moletteH = button.molletteB = false;
}