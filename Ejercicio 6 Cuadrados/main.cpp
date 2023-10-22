#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    // Crear la ventana
    RenderWindow App(VideoMode(400, 400), "Ejercicio 6 cuadrado");

    // Cargar las imágenes (reemplaza las rutas con tus propias imágenes)
    Texture texture1, texture2, texture3, texture4;
    texture1.loadFromFile("cuad_red.png");
    texture2.loadFromFile("cuad_yellow.png");
    texture3.loadFromFile("cuad_blue.png");
    texture4.loadFromFile("cuad_grey.png");

    // Crear los sprites y escalarlos al mismo tamaño
    Sprite sprite1, sprite2, sprite3, sprite4;
    sprite1.setTexture(texture1);
    sprite2.setTexture(texture2);
    sprite3.setTexture(texture3);
    sprite4.setTexture(texture4);

    // Tamaño del cuadrado
    float cuadradoSize = 200.0f;

    // Escalar los sprites al tamaño del cuadrado
    sprite1.setScale(cuadradoSize / texture1.getSize().x, cuadradoSize / texture1.getSize().y);
    sprite2.setScale(cuadradoSize / texture2.getSize().x, cuadradoSize / texture2.getSize().y);
    sprite3.setScale(cuadradoSize / texture3.getSize().x, cuadradoSize / texture3.getSize().y);
    sprite4.setScale(cuadradoSize / texture4.getSize().x, cuadradoSize / texture4.getSize().y);

    // Posiciones de los sprites para formar un cuadrado
    sprite1.setPosition(0, 0);
    sprite2.setPosition(cuadradoSize, 0);
    sprite3.setPosition(0, cuadradoSize);
    sprite4.setPosition(cuadradoSize, cuadradoSize);

    // Loop principal
    while (App.isOpen()) {
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed) {
                App.close();
            }
        }

        // Limpiar la ventana
        App.clear();

        // Dibujar los sprites
        App.draw(sprite1);
        App.draw(sprite2);
        App.draw(sprite3);
        App.draw(sprite4);

        // Mostrar la ventana
        App.display();
    }

    return 0;
}

