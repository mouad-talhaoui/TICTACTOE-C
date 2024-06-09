#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "functions.h"


int main(int argc, char *args[])
{
    int running = 1;

    const SDL_MessageBoxButtonData buttons[] = {
        {/* .flags, .buttonid, .text */ 0, 0, "Play"},
        {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Exit"}};
    const SDL_MessageBoxColorScheme colorScheme = {
        {/* .colors (.r, .g, .b) */
         /* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
         {239, 156, 114},
         /* [SDL_MESSAGEBOX_COLOR_TEXT] */
         {0, 0, 0},
         /* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
         {253, 206, 138},
         /* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
         {253, 206, 138},
         /* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
         {255, 0, 255}}};
    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION, /* .flags */
        NULL,                       /* .window */
        "TICTACTOE",              /* .title */
        "        Welcome",          /* .message */
        SDL_arraysize(buttons),     /* .numbuttons */
        buttons,                    /* .buttons */
        &colorScheme                /* .colorScheme */
    };
    int OpenGame = 0;
    int turn = 1;
    int buttonid;
    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0)
    {
        SDL_Log("error displaying message box");
        return 1;
    }
    if (buttonid == -1)
    {
        SDL_Log("no selection");
    }
    else
    {
        SDL_Log("selection was %s", buttons[buttonid].text);
        const *ng = "Play";
        if (strcmp(buttons[buttonid].text, ng) == 0)
        {
            OpenGame = 1;
        }
    }
    SDL_Init(SDL_INIT_VIDEO);

    // declaration des defferentes variables
    int widthOfWindow = 900;
    int heightOfWindow = 900;
    int board[3][3] = {
                {0, 0, 0},
                {0, 0, 0},
                {0, 0, 0}};

    SDL_Window *Window = SDL_CreateWindow("TIC TAC TOE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, widthOfWindow, heightOfWindow, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    
    

    SDL_Renderer *renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_Event event;
    while (running && OpenGame)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = 0;
            } else if(event.window.event == SDL_WINDOWEVENT_RESIZED){
                widthOfWindow = event.window.data1;
                heightOfWindow = event.window.data2;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                x = event.button.x;
                y = event.button.y;
                if(0 <= y && y <= widthOfWindow/3){
                    if(0 <= x && x <= heightOfWindow/3) {
                        if(board[0][0] == 0){
                            board[0][0] = turn;
                            if(turn == 1){ 
                            turn = -1;
                            }else {
                                turn = 1;
                            }
                        }
                        
                    }else if(heightOfWindow/3 <= x && x <= 2*heightOfWindow/3){
                        if(board[0][1] == 0){
                            board[0][1] = turn;
                            if(turn == 1){ 
                            turn = -1;
                            }else {
                                turn = 1;
                            }
                        }
                    }else if(2*heightOfWindow/3 <= x && x <= 3*heightOfWindow/3){
                        if(board[0][2] == 0){
                            board[0][2] = turn;
                            if(turn == 1){ 
                            turn = -1;
                            }else {
                                turn = 1;
                            }
                        }
                    }
                }else /**/
                if(widthOfWindow/3 <= y && y <= 2*widthOfWindow/3){
                    if(0 <= x && x <= heightOfWindow/3) {
                        if(board[1][0] == 0){
                            board[1][0] = turn;
                            if(turn == 1){ 
                            turn = -1;
                            }else {
                                turn = 1;
                            }
                        }
                        
                    }else if(heightOfWindow/3 <= x && x <= 2*heightOfWindow/3){
                        if(board[1][1] == 0){
                            board[1][1] = turn;
                            if(turn == 1){ 
                            turn = -1;
                            }else {
                                turn = 1;
                            }
                        }
                    }else if(2*heightOfWindow/3 <= x && x <= 3*heightOfWindow/3){
                        if(board[1][2] == 0){
                            board[1][2] = turn;
                            if(turn == 1){ 
                            turn = -1;
                            }else {
                                turn = 1;
                            }
                        }
                    }
                }/**/
                 if(2*widthOfWindow/3 <= y && y <= 3*widthOfWindow/3){
                    if(0 <= x && x <= heightOfWindow/3) {
                        if(board[2][0] == 0){
                            board[2][0] = turn;
                            if(turn == 1){ 
                            turn = -1;
                            }else {
                                turn = 1;
                            }
                        }
                        
                    }else if(heightOfWindow/3 <= x && x <= 2*heightOfWindow/3){
                        if(board[2][1] == 0){
                            board[2][1] = turn;
                            if(turn == 1){ 
                            turn = -1;
                            }else {
                                turn = 1;
                            }
                        }
                    }else if(2*heightOfWindow/3 <= x && x <= 3*heightOfWindow/3){
                        if(board[2][2] == 0){
                            board[2][2] = turn;
                            if(turn == 1){ 
                            turn = -1;
                            }else {
                                turn = 1;
                            }
                        }
                    }
                }
                
            }
        }
        // Drawing the board
        SDL_SetRenderDrawColor(renderer, 239, 156, 114, 255);
        SDL_RenderClear(renderer);

        SDL_Rect rect1;
        rect1.x = 0;
        rect1.y = 0;
        rect1.w = widthOfWindow/3;
        rect1.h = heightOfWindow/3;
        if(board[0][0] == 0 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(renderer, &rect1);
        }
        else if(board[0][0] == 1 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect1);
        }
        else if(board[0][0] == -1 ){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect1);
        }
        
        

        SDL_Rect rect2;
        rect2.x = widthOfWindow/3;
        rect2.y = 0;
        rect2.w = widthOfWindow/3;
        rect2.h = heightOfWindow/3;
        if(board[0][1] == 0 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(renderer, &rect2);
        }
        else if(board[0][1] == 1 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect2);
        }
        else if(board[0][1] == -1 ){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect2);
        }

        SDL_Rect rect3;
        rect3.x = 2*widthOfWindow/3;
        rect3.y = 0;
        rect3.w = widthOfWindow/3;
        rect3.h = heightOfWindow/3;

        if(board[0][2] == 0 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(renderer, &rect3);
        }
        else if(board[0][2] == 1 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect3);
        }
        else if(board[0][2] == -1 ){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect3);
        }


        
        SDL_Rect rect4;
        rect4.x = 0;
        rect4.y = heightOfWindow/3;
        rect4.w = widthOfWindow/3;
        rect4.h = heightOfWindow/3;
        if(board[1][0] == 0 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(renderer, &rect4);
        }
        else if(board[1][0] == 1 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect4);
        }
        else if(board[1][0] == -1 ){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect4);
        }

        SDL_Rect rect5;
        rect5.x = widthOfWindow/3;
        rect5.y = heightOfWindow/3;
        rect5.w = widthOfWindow/3;
        rect5.h = heightOfWindow/3;
        if(board[1][1] == 0 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(renderer, &rect5);
        }
        else if(board[1][1] == 1 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect5);
        }
        else if(board[1][1] == -1 ){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect5);
        }

        SDL_Rect rect6;
        rect6.x = 2*widthOfWindow/3;
        rect6.y = heightOfWindow/3;
        rect6.w = widthOfWindow/3;
        rect6.h = heightOfWindow/3;
        if(board[1][2] == 0 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(renderer, &rect6);
        }
        else if(board[1][2] == 1 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect6);
        }
        else if(board[1][2] == -1 ){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect6);
        }

        SDL_Rect rect7;
        rect7.x = 0;
        rect7.y = 2*heightOfWindow/3;
        rect7.w = widthOfWindow/3;
        rect7.h = heightOfWindow/3;

        if(board[2][0] == 0 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(renderer, &rect7);
        }
        else if(board[2][0] == 1 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect7);
        }
        else if(board[2][0] == -1 ){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect7);
        }

        SDL_Rect rect8;
        rect8.x = widthOfWindow/3;
        rect8.y = 2*heightOfWindow/3;
        rect8.w = widthOfWindow/3;
        rect8.h = heightOfWindow/3;
        if(board[2][1] == 0 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(renderer, &rect8);
        }
        else if(board[2][1] == 1 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect8);
        }
        else if(board[2][1] == -1 ){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect8);
        }

        SDL_Rect rect9;
        rect9.x = 2*widthOfWindow/3;
        rect9.y = 2*heightOfWindow/3;
        rect9.w = widthOfWindow/3;
        rect9.h = heightOfWindow/3;

        if(board[2][2] == 0 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderDrawRect(renderer, &rect9);
        }
        else if(board[2][2] == 1 ){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect9);
        }
        else if(board[2][2] == -1 ){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(renderer, &rect9);
        }

        if(checkWinner(board)==1){
            const SDL_MessageBoxButtonData  buttons[] ={
                    {0,0,"no"},
                    {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT,1,"yes"}
                };
                
                const SDL_MessageBoxData messageboxdata = {
                    SDL_MESSAGEBOX_INFORMATION,
                    NULL,
                    "payer one won",
                    "payer one won, do you want to replay?",
                    SDL_arraysize(buttons),
                    buttons,
                    &colorScheme
                };
                int buttonid;
                if(SDL_ShowMessageBox(&messageboxdata,&buttonid)<0){
                    SDL_Log("error");
                }
                if(buttonid == -1){
                    SDL_Log("no selection");
                }else if(buttonid == 0) {
                    running = 0;
                }else if(buttonid == 1) {
                    board[0][0]=0;
                    board[0][1]=0;
                    board[0][2]=0;
                    
                    board[1][0]=0;
                    board[1][1]=0;
                    board[1][2]=0;
                    
                    board[2][0]=0;
                    board[2][1]=0;
                    board[2][2]=0;

                }
        }else if(checkWinner(board)==-1){
            SDL_Log("minus -1");
            const SDL_MessageBoxButtonData  buttons[] ={
                    {0,0,"no"},
                    {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT,1,"yes"}
                };
                
                const SDL_MessageBoxData messageboxdata = {
                    SDL_MESSAGEBOX_INFORMATION,
                    NULL,
                    "player two won",
                    "player two won, do you want to replay?",
                    SDL_arraysize(buttons),
                    buttons,
                    &colorScheme
                };
                int buttonid;
                if(SDL_ShowMessageBox(&messageboxdata,&buttonid)<0){
                    SDL_Log("error");
                }
                if(buttonid == -1){
                    SDL_Log("no selection");
                }else if(buttonid == 0) {
                    running = 0;
                }else if(buttonid == 1) {
                    board[0][0]=0;
                    board[0][1]=0;
                    board[0][2]=0;
                    
                    board[1][0]=0;
                    board[1][1]=0;
                    board[1][2]=0;
                    
                    board[2][0]=0;
                    board[2][1]=0;
                    board[2][2]=0;

                }
        }else if(checkWinner(board) == 2) {
            SDL_Log("minus -1");
            const SDL_MessageBoxButtonData  buttons[] ={
                    {0,0,"no"},
                    {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT,1,"yes"}
                };
                
                const SDL_MessageBoxData messageboxdata = {
                    SDL_MESSAGEBOX_INFORMATION,
                    NULL,
                    "egalite",
                    "egalite, do you want to replay?",
                    SDL_arraysize(buttons),
                    buttons,
                    &colorScheme
                };
                int buttonid;
                if(SDL_ShowMessageBox(&messageboxdata,&buttonid)<0){
                    SDL_Log("error");
                }
                if(buttonid == -1){
                    SDL_Log("no selection");
                }else if(buttonid == 0) {
                    running = 0;
                }else if(buttonid == 1) {
                    board[0][0]=0;
                    board[0][1]=0;
                    board[0][2]=0;
                    
                    board[1][0]=0;
                    board[1][1]=0;
                    board[1][2]=0;
                    
                    board[2][0]=0;
                    board[2][1]=0;
                    board[2][2]=0;

                }
        }






        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        SDL_RenderPresent(renderer);
        
        
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
