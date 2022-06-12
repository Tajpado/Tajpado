#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

int main(int argc, char** argv) {
	SDL_Window* window;
	SDL_Event exit;
	// SDL2�̏�����
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		SDL_Quit();
		return 1;
	}
	// Window�̍쐬�ATTF�̏������Ɏ��s�����Ƃ�
	if ((window = SDL_CreateWindow("Tajpado", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_RESIZABLE)) == NULL || TTF_Init() == -1) {
		SDL_Quit();
		return 1;
	}
	TTF_Font* font;

	SDL_SetWindowTitle(window, "Tajpado");
	//�����_���[
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	//�w�i�����ɂ���
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//�w�i���N���A
	SDL_RenderClear(renderer);

	while (1)
	{
		//����{�^���ŕ����悤�ɂ���
		SDL_PollEvent(&exit);
		if (exit.type == SDL_QUIT) {
			break;
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}