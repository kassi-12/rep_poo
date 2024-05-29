#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>

class FenetreSDL {
private:
    SDL_Window* fenetre;
    SDL_Renderer* rendu;

public:
    FenetreSDL(const char* titre, int largeur, int hauteur) {
        SDL_Init(SDL_INIT_VIDEO);
        fenetre = SDL_CreateWindow(titre, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, largeur, hauteur, SDL_WINDOW_SHOWN);
        rendu = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    }

    ~FenetreSDL() {
        SDL_DestroyRenderer(rendu);
        SDL_DestroyWindow(fenetre);
        SDL_Quit();
    }

    void gererEvenements() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                SDL_Quit();
                exit(0);
            }
        }
    }

    void rafraichir() {
        SDL_RenderPresent(rendu);
    }

    void nettoyer() {
        SDL_RenderClear(rendu);
    }

    SDL_Renderer* getRendu() const {
        return rendu;
    }
};

class TextureSDL {
private:
    SDL_Texture* texture;
    SDL_Renderer* rendu;

public:
    TextureSDL(const char* chemin, SDL_Renderer* rendu) : rendu(rendu) {
        SDL_Surface* surface = SDL_LoadBMP(chemin);
        if (surface == nullptr) {
            std::cerr << "Erreur chargement de l'image : " << SDL_GetError() << std::endl;
            SDL_Quit();
            exit(-1);
        }
        texture = SDL_CreateTextureFromSurface(rendu, surface);
        SDL_FreeSurface(surface);
    }

    ~TextureSDL() {
        SDL_DestroyTexture(texture);
    }

    void afficher(int x, int y) {
        SDL_Rect dstRect = {x, y, 0, 0};
        SDL_QueryTexture(texture, NULL, NULL, &dstRect.w, &dstRect.h);
        SDL_RenderCopy(rendu, texture, NULL, &dstRect);
    }
};

int main(int argc, char* argv[]) {
    FenetreSDL fenetre("Ma fenêtre SDL", 800, 600);
    TextureSDL texture("image0.Bmp", fenetre.getRendu()); // Change the image name here

    bool running = true;
    while (running) {
        fenetre.gererEvenements();
        fenetre.nettoyer();
        texture.afficher(0, 0);
        fenetre.rafraichir();
    }

    return 0;
}
