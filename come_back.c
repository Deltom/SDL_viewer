#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>

// Ширина и высота
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main (int argc, char ** args) {
    // Инициализируем все модули что есть у SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) ) { return 1; }

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

    // Слой для работы
    screen_surface = SDL_GetWindowSurface(window);

    // Позволяет рисовать всякое, типа линий и т.д.
    // SDL_Renderer *ren = SDL_CreateRenderer(window, -1,
    //     SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Проверка на ошибки
    // if (ren == NULL) { printf("%s", "Render RIP"); return 1; }
    if (window == NULL) { printf("%s", "Window RIP"); return 1; }
    if (screen_surface == NULL) { printf("%s", "Surface RIP"); return 1; }



    //Цикл не позволяющий окну сразу закрыться, обробатывает событие - нажатие
    //на крестик на окне
    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0, 255, 0));
    SDL_UpdateWindowSurface(window);

    _Bool flag = 1;
    while (flag) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                flag = 0;
        }
    }
    SDL_Delay(3000);
    printf("%s", "huila");
    // Полное закрытие окна и подсистем
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
