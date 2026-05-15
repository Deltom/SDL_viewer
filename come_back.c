#include <SDL2/SDL.h>

// Ширина и высота
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main (int argc, char ** args) {
    // Создание указателей на объекты
    //
    // 1. Что-то типа слоя, поверхности для взаимодействия
    // 2. Окно
    // 3. Обработчик событий
    SDL_Surface* screen_surface = NULL;
    SDL_Window* window = NULL;
    SDL_Event event;

    // Передаём нашему окну параметры
    window = SDL_CreateWindow("Hello, SDL 2!",
        0, 0,
        SCREEN_WIDTH, SCREEN_HEIGHT,
    SDL_WINDOW_SHOWN);

    // Позволяет рисовать всякое, типа линий и т.д.
    SDL_Renderer *ren = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Проверка на ошибки
    if (ren == NULL || window == NULL){ return 1; }

    // Инициализируем все модули что есть у SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) ) { return 1; }


    //Цикл не позволяющий окну сразу закрыться, обробатывает событие - нажатие
    //на крестик на окне
    _Bool flag = 1;
    while (flag) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                flag = 0;
        }
    }

    // Полное закрытие окна и подсистем
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
