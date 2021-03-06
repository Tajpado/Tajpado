#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>

int main(int argc, char** argv) {
	SDL_Window* window;
	SDL_Event exit;
	// SDL2の初期化
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Quit();
		return 1;
	}
	// Windowの作成、TTFの初期化に失敗したとき
	if ((window = SDL_CreateWindow("Tajpado", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_RESIZABLE)) == NULL || TTF_Init() == -1) {
		SDL_Quit();
		return 1;
	}
	TTF_Font* font=NULL;

	SDL_Rect time_rect{
		time_rect.x = 520,
		time_rect.y = 260,
		time_rect.w = 200,
		time_rect.h = 100
	};
	SDL_SetWindowTitle(window, "Tajpado");
	//レンダラー
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	//背景を黒にする
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//背景をクリア
	SDL_RenderClear(renderer);
	//フォントを読み込む
	if ((font = TTF_OpenFont("C:/Windows/Fonts/HackGen35Nerd-Bold.ttf", 100)) == NULL) {
		SDL_Quit();
		return 1;
	}
	while (1)
	{
		//閉じるボタンで閉じれるようにする
		SDL_PollEvent(&exit);
		if (exit.type == SDL_QUIT) {
			break;
		}
		SDL_RenderCopy(renderer,
			SDL_CreateTextureFromSurface(renderer,
				TTF_RenderUTF8_Blended(font,"ねこちゃん", SDL_Color{0,120, 120, 120})),
			NULL, &time_rect);
		// 画面に反映させる
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}