#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5\allegro_color.h"
#include <time.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>



const int SCREEN_W = 1024;
const int SCREEN_H = 768;

void winner(){
    al_draw_filled_rectangle(200,200,800,800, al_map_rgb(0,0,0));
}

void fResposta(ALLEGRO_COLOR matrizResposta[7][4], int seq[],int v[4], int a, ALLEGRO_COLOR branco, ALLEGRO_COLOR vermelho, ALLEGRO_COLOR cinza, int mode){
                            int c = a;
                            if (seq[0] == v[0] && seq[1] == v[1] && seq[2] == v[2] && seq[3] == v[3]){
                            matrizResposta[c][0] = matrizResposta[c][1] = matrizResposta[c][2] = matrizResposta[c][3] = branco;
                            mode =1;
                            }else if(seq[0] == v[0] && seq[1] == v[1] && seq[2] == v[2] && seq[3] != v[3]){
                            matrizResposta[c][0] = matrizResposta[c][1] = matrizResposta[c][2] = branco;
                            matrizResposta[c][3] = cinza;
                            }else if (seq[0] == v[0] && seq[1] == v[1] && seq[2] != v[2] && seq[3] == v[3]){
                            matrizResposta[c][0] = matrizResposta[c][1] = matrizResposta[c][2] = branco;
                            matrizResposta[c][3] = cinza;
                            }else if (seq[0] == v[0] && seq[1] != v[1] && seq[2] == v[2] && seq[3] == v[3]){
                            matrizResposta[c][0] = matrizResposta[c][1] = matrizResposta[c][2] = branco;
                            matrizResposta[c][3] = cinza;
                            }else if (seq[0] != v[0] && seq[1] == v[1] && seq[2] == v[2] && seq[3] == v[3]){
                            matrizResposta[c][0] = matrizResposta[c][1] = matrizResposta[c][2] = branco;
                            matrizResposta[c][3] = cinza;
                            }

                            else if(seq[0] != v[0] && seq[1] != v[1] && seq[2] == v[2] && seq[3] == v[3]){
                                matrizResposta[c][0] = matrizResposta[c][1] = branco;
                                int cont = 1;
                                if (seq[0] == v[1]){
                                    matrizResposta[c][2] = vermelho;
                                    cont = 0;
                                 if (seq[1] == v[0]){
                                    matrizResposta[c][3-cont] = vermelho;}}}
                           else if(seq[0] != v[0] && seq[1] == v[1] && seq[2] != v[2] && seq[3] == v[3]){
                                matrizResposta[c][0] = matrizResposta[c][1] = branco;
                                int cont = 1;
                                if (seq[0] == v[2]){
                                    matrizResposta[c][2] = vermelho;
                                    cont = 0;
                                 if (seq[2] == v[0]){
                                    matrizResposta[c][3-cont] = vermelho;}}}
                            else if(seq[0] != v[0] && seq[1] == v[1] && seq[2] == v[2] && seq[3] != v[3]){
                                matrizResposta[c][0] = matrizResposta[c][1] = branco;
                                int cont = 1;
                                if (seq[0] == v[3]){
                                    matrizResposta[c][2] = vermelho;
                                    cont = 0;
                                   if (seq[3] == v[0]){
                                    matrizResposta[c][3-cont] = vermelho;}}}
                            else if(seq[0] == v[0] && seq[1] != v[1] && seq[2] != v[2] && seq[3] == v[3]){
                                matrizResposta[c][0] = matrizResposta[c][1] = branco;
                                int cont =1;
                                if (seq[1] == v[2]){
                                    matrizResposta[c][2] = vermelho;
                                    cont = 0;
                                if (seq[2] == v[1]){
                                    matrizResposta[c][3-cont] = vermelho;}}}
                             else if(seq[0] == v[0] && seq[1] != v[1] && seq[2] == v[2] && seq[3] != v[3]){
                                matrizResposta[c][0] = matrizResposta[c][1] = branco;
                                int cont =1;
                                if (seq[1] == v[3]){
                                    matrizResposta[c][2] = vermelho;
                                    cont = 0;
                                 if (seq[3] == v[1]){
                                    matrizResposta[c][3-cont] = vermelho;}}}
                             else if(seq[0] == v[0] && seq[1] == v[1] && seq[2] != v[2] && seq[3] != v[3]){
                                matrizResposta[c][0] = matrizResposta[c][1] = branco;
                                int cont =1;
                                if (seq[2] == v[3]){
                                    matrizResposta[c][2] = vermelho;
                                    cont = 0;
                                    if (seq[3] == v[2]){
                                    matrizResposta[c][3] = vermelho;}}}

                            else if (seq[0] == v[0] && seq[1] != v[1] && seq[2] != v[2] && seq[3] != v[3]){
                                    matrizResposta [c][0] = branco;
                                    int cont = 2;
                                    if (seq[1] == v[2] || seq[1] == v[3]){
                                        matrizResposta[c][1]=vermelho;
                                        cont = 1;
                                      if(seq[2] == v[1] || seq[2] == v[3]){
                                        matrizResposta[c][3-cont] = vermelho;
                                        cont = 0;
                                       if(seq[3] == v[1] || seq[3] == v[2]){
                                        matrizResposta[c][3-cont] = vermelho;
                                       }}}}
                            else if (seq[0] != v[0] && seq[1] == v[1] && seq[2] != v[2] && seq[3] != v[3]){
                                    matrizResposta [c][0] = branco;
                                    int cont = 2;
                                    if (seq[0] == v[2] || seq[0] == v[3]){
                                        matrizResposta[c][1]=vermelho;
                                        cont = 1;
                                      if(seq[2] == v[0] || seq[2] == v[3]){
                                        matrizResposta[c][3-cont] = vermelho;
                                        cont = 0;
                                       if(seq[3] == v[0] || seq[3] == v[2]){
                                        matrizResposta[c][3-cont] = vermelho;
                                       }}}}
                              else if (seq[0] != v[0] && seq[1] != v[1] && seq[2] == v[2] && seq[3] != v[3]){
                                    matrizResposta [c][0] = branco;
                                    int cont = 2;
                                    if (seq[0] == v[1] || seq[0] == v[3]){
                                        matrizResposta[c][1]=vermelho;
                                        cont = 1;
                                      if(seq[1] == v[0] || seq[1] == v[3]){
                                        matrizResposta[c][3-cont] = vermelho;
                                        cont = 0;
                                       if(seq[3] == v[0] || seq[3] == v[1]){
                                        matrizResposta[c][3-cont] = vermelho;
                                       }}}}
                                else if (seq[0] != v[0] && seq[1] != v[1] && seq[2] != v[2] && seq[3] == v[3]){
                                    matrizResposta [c][0] = branco;
                                    int cont = 2;
                                    if (seq[0] == v[1] || seq[0] == v[2]){
                                        matrizResposta[c][1]=vermelho;
                                        cont = 1;
                                      if(seq[1] == v[0] || seq[1] == v[2]){
                                        matrizResposta[c][3-cont] = vermelho;
                                        cont = 0;
                                       if(seq[2] == v[0] || seq[2] == v[1]){
                                        matrizResposta[c][3-cont] = vermelho;
                                       }}}}
                                else if (seq[0] != v[0] && seq[1] != v[1] && seq[2] != v[2] && seq[3] != v[3]){
                                    matrizResposta[c][0] = matrizResposta[c][1] = matrizResposta[c][2] = matrizResposta[c][3] = vermelho;
                                }

                            return mode;

                        }


void aniFundo(){
      //quadrado no fundo
    int pos_x;
    int pos_y;
    int i;

    pos_x = rand()%SCREEN_W;
    pos_y = rand()%SCREEN_H;

    for(i =0; i<128; i++){
       al_draw_filled_rectangle(pos_x, pos_y, pos_x + 4, pos_y + 4, al_map_rgb(128,128,128));
    }
}

void must_init(bool test, const char *description)
{
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}
int main()
{
    int mode=0;
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 20.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);

    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);

    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    ALLEGRO_DISPLAY* disp = al_create_display(SCREEN_W, SCREEN_H);
    must_init(disp, "display");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    must_init(al_init_image_addon(), "image addon");

    al_install_mouse();
    must_init(al_install_mouse(), "mouse");


    must_init(al_init_primitives_addon(),"primitives");

    must_init(al_install_audio(), "audio");
    must_init(al_init_acodec_addon(), "audio codecs");
    must_init(al_reserve_samples(16), "reserve samples");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_mouse_event_source());

    bool done = false;
    bool redraw = true;

    ALLEGRO_SAMPLE* deep_Urban = al_load_sample("deep-urban.wav");
    must_init(deep_Urban, "deep-urban");

    ALLEGRO_BITMAP * final = NULL;
    final = al_load_bitmap("imagens/final.png");

    ALLEGRO_COLOR vermelho = al_map_rgb(200, 60, 60);
    ALLEGRO_COLOR azul = al_map_rgb(20, 20, 240);
    ALLEGRO_COLOR branco = al_map_rgb(255, 255, 255);
    ALLEGRO_COLOR amarelo = al_map_rgb(240, 240, 10);
    ALLEGRO_COLOR verde = al_map_rgb(20, 240, 100);
    ALLEGRO_COLOR cinza = al_map_rgb(128, 128, 128);

    ALLEGRO_COLOR matriz[7][4];
    int i;
    int j;
    for(i=0; i<7; i++){
        for(j=0; j<4; j++){
            matriz[i][j] = branco;
        }
    }

    ALLEGRO_COLOR matrizResposta [7][4];
    for(i=0; i<7; i++){
        for(j=0; j<4; j++){
            matrizResposta[i][j] = cinza;
        }
    }
    int cl = 0;
    int cc = 0;
    al_start_timer(timer);

    //SORTEIO BOLAS CORRETAS
    int red = 0;
    int yellow = 1;
    int green = 2;
    int blue = 3;
    int v[4];
    srand((unsigned)time(NULL));
    for(i = 0;  i<4; i++){

        int c = 0;
        c = rand()%4;
        v[i] = c;
    }
        printf("%d -- %d -- %d -- %d ", v[0], v[1], v[2], v[3]);


    while(1)
    {
        ALLEGRO_EVENT event;
        al_play_sample(deep_Urban, 0.1, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        al_wait_for_event(queue, &event);
        //ALLEGRO_EVENT evento;
        switch(event.type)
        {
        int seq[4];
            case ALLEGRO_EVENT_TIMER:

                case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:

                    if (event.mouse.button & 1){

                    if (event.mouse.x >= 895 &&
                event.mouse.x <= 975 && event.mouse.y <= 140 &&
                event.mouse.y >= 60){
                    matriz[cc][cl]= vermelho;
                    seq[cl] = 0;
                    cl = cl+ 1;
                    }
                    else if (event.mouse.x >= 895 &&
                event.mouse.x <= 975 && event.mouse.y <= 240 &&
                event.mouse.y >= 160){
                   matriz[cc][cl]= amarelo;
                    seq[cl]= 1;
                    cl = cl+ 1;
                }
                     else if (event.mouse.x >= 895 &&
                event.mouse.x <= 975 && event.mouse.y <= 340 &&
                event.mouse.y >= 260){
                    matriz[cc][cl]= verde;
                    seq[cl] = 2;
                    cl = cl+ 1;}
                     else if (event.mouse.x >= 895 &&
                event.mouse.x <= 975 && event.mouse.y <= 440 &&
                event.mouse.y >= 360){
                    matriz[cc][cl]= azul;
                    seq[cl] = 3;
                    cl = cl+ 1;}
                    else if (event.mouse.x >= 600 && event.mouse.x <= 700 && event.mouse.y <= 100 && event.mouse.y >= 50 ){
                            if(cc==0){fResposta( matrizResposta, seq, v, 0 , branco,  vermelho, cinza,mode);
                            cl = 0; cc = 1;}
                            }else if(event.mouse.x >= 600 && event.mouse.x <= 700 && event.mouse.y <= 200 && event.mouse.y >= 150 ){
                                 if(cc==1){fResposta( matrizResposta, seq, v, 1 , branco,  vermelho, cinza,mode);
                                  cl = 0; cc = 2;}
                            }else if(event.mouse.x >= 600 && event.mouse.x <= 700 && event.mouse.y <= 300 && event.mouse.y >= 250 ){
                                 if(cc==2){fResposta( matrizResposta, seq, v, 2 , branco,  vermelho, cinza,mode);
                                  cl = 0; cc = 3;}
                            }else if(event.mouse.x >= 600 && event.mouse.x <= 700 && event.mouse.y <= 400 && event.mouse.y >= 350 ){
                                 if(cc==3){fResposta( matrizResposta, seq, v, 3 , branco,  vermelho, cinza,mode);
                                  cl = 0; cc = 4;}
                            }else if(event.mouse.x >= 600 && event.mouse.x <= 700 && event.mouse.y <= 500 && event.mouse.y >= 450 ){
                                if(cc==4){fResposta( matrizResposta, seq, v, 4 , branco,  vermelho, cinza,mode);
                                  cl = 0; cc = 5;}
                            }else if(event.mouse.x >= 600 && event.mouse.x <= 700 && event.mouse.y <= 600 && event.mouse.y >= 550 ){
                                 if(cc==5){fResposta( matrizResposta, seq, v, 5 , branco,  vermelho, cinza,mode);
                                  cl = 0;cc = 6;}
                            }else if(event.mouse.x >= 600 && event.mouse.x <= 700 && event.mouse.y <= 700 && event.mouse.y >= 650 ){
                                 if(cc==6){fResposta( matrizResposta, seq, v, 6 , branco,  vermelho, cinza,mode);
                                 cc=7;}

                            }








                    }

                redraw = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;

        if(redraw && al_is_event_queue_empty(queue))
        {

            al_clear_to_color(al_map_rgb(0, 0, 0));
           for(i=0; i<10; i++){
                aniFundo();
            }


            //Primeiraa Fileira



            al_draw_filled_rectangle(600,50,700,100, verde);
            al_draw_filled_circle(100, 75, 40, matriz[0][0]);
            al_draw_filled_circle(230, 75, 40, matriz[0][1]);
            al_draw_filled_circle(360, 75, 40, matriz[0][2]);
            al_draw_filled_circle(490, 75, 40, matriz[0][3]);
            //Segunda Fileira
            al_draw_filled_rectangle(600,150,700,200, verde);
            al_draw_filled_circle(100, 175, 40, matriz[1][0]);
            al_draw_filled_circle(230, 175, 40, matriz[1][1]);
            al_draw_filled_circle(360, 175, 40, matriz[1][2]);
            al_draw_filled_circle(490, 175, 40, matriz[1][3]);
            //Terceira Fileira
            al_draw_filled_rectangle(600,250,700,300, verde);
            al_draw_filled_circle(100, 275, 40, matriz[2][0]);
            al_draw_filled_circle(230, 275, 40, matriz[2][1]);
            al_draw_filled_circle(360, 275, 40, matriz[2][2]);
            al_draw_filled_circle(490, 275, 40, matriz[2][3]);
            //Quarta Fileira
            al_draw_filled_rectangle(600,350,700,400, verde);
            al_draw_filled_circle(100, 375, 40, matriz[3][0]);
            al_draw_filled_circle(230, 375, 40, matriz[3][1]);
            al_draw_filled_circle(360, 375, 40, matriz[3][2]);
            al_draw_filled_circle(490, 375, 40, matriz[3][3]);
             //Quinta Fileira
            al_draw_filled_rectangle(600,450,700,500, verde);
            al_draw_filled_circle(100, 475, 40, matriz[4][0]);
            al_draw_filled_circle(230, 475, 40, matriz[4][1]);
            al_draw_filled_circle(360, 475, 40, matriz[4][2]);
            al_draw_filled_circle(490, 475, 40, matriz[4][3]);
            //Sexta Fileira
            al_draw_filled_rectangle(600,550,700,600, verde);
            al_draw_filled_circle(100, 575, 40, matriz[5][0]);
            al_draw_filled_circle(230, 575, 40, matriz[5][1]);
            al_draw_filled_circle(360, 575, 40, matriz[5][2]);
            al_draw_filled_circle(490, 575, 40, matriz[5][3]);
            //Sétima Fileira
            al_draw_filled_rectangle(600,650,700,700, verde);
            al_draw_filled_circle(100, 675, 40, matriz[6][0]);
            al_draw_filled_circle(230, 675, 40, matriz[6][1]);
            al_draw_filled_circle(360, 675, 40, matriz[6][2]);
            al_draw_filled_circle(490, 675, 40, matriz[6][3]);

            //Respostas Bolas brancas e vermelhas

            al_draw_filled_circle(750,55,15, matrizResposta[0][0]);
            al_draw_filled_circle(790,55,15, matrizResposta[0][1]);
            al_draw_filled_circle(750,95,15, matrizResposta[0][2]);
            al_draw_filled_circle(790,95,15, matrizResposta[0][3]);

            al_draw_filled_circle(750,155,15, matrizResposta[1][0]);
            al_draw_filled_circle(790,155,15, matrizResposta[1][1]);
            al_draw_filled_circle(750,195,15, matrizResposta[1][2]);
            al_draw_filled_circle(790,195,15, matrizResposta[1][3]);

            al_draw_filled_circle(750,255,15, matrizResposta[2][0]);
            al_draw_filled_circle(790,255,15, matrizResposta[2][1]);
            al_draw_filled_circle(750,295,15, matrizResposta[2][2]);
            al_draw_filled_circle(790,295,15, matrizResposta[2][3]);

            al_draw_filled_circle(750,355,15, matrizResposta[3][0]);
            al_draw_filled_circle(790,355,15, matrizResposta[3][1]);
            al_draw_filled_circle(750,395,15, matrizResposta[3][2]);
            al_draw_filled_circle(790,395,15, matrizResposta[3][3]);

            al_draw_filled_circle(750,455,15, matrizResposta[4][0]);
            al_draw_filled_circle(790,455,15, matrizResposta[4][1]);
            al_draw_filled_circle(750,495,15, matrizResposta[4][2]);
            al_draw_filled_circle(790,495,15, matrizResposta[4][3]);

            al_draw_filled_circle(750,555,15, matrizResposta[5][0]);
            al_draw_filled_circle(790,555,15, matrizResposta[5][1]);
            al_draw_filled_circle(750,595,15, matrizResposta[5][2]);
            al_draw_filled_circle(790,595,15, matrizResposta[5][3]);

            al_draw_filled_circle(750,655,15, matrizResposta[6][0]);
            al_draw_filled_circle(790,655,15, matrizResposta[6][1]);
            al_draw_filled_circle(750,695,15, matrizResposta[6][2]);
            al_draw_filled_circle(790,695,15, matrizResposta[6][3]);

            //COLUNA LATERAL

            al_draw_filled_circle(935,100,40, vermelho);
            al_draw_filled_circle(935,200,40, amarelo);
            al_draw_filled_circle(935,300,40, verde);
            al_draw_filled_circle(935,400,40, azul);

            al_draw_filled_circle(880,590,15, branco);
            al_draw_filled_circle(880,650,15, vermelho);

            //Linha
            al_draw_line(848, 10, 848, SCREEN_H-10, cinza, 5);

            //Textos
            al_draw_text(font, al_map_rgb(0, 0, 0), 640, 72, 0, "VER");
            al_draw_text(font, al_map_rgb(0, 0, 0), 640, 172, 0, "VER");
            al_draw_text(font, al_map_rgb(0, 0, 0), 640, 272, 0, "VER");
            al_draw_text(font, al_map_rgb(0, 0, 0), 640, 372, 0, "VER");
            al_draw_text(font, al_map_rgb(0, 0, 0), 640, 472, 0, "VER");
            al_draw_text(font, al_map_rgb(0, 0, 0), 640, 572, 0, "VER");
            al_draw_text(font, al_map_rgb(0, 0, 0), 640, 672, 0, "VER");
            al_draw_text(font, al_map_rgb(255, 255, 255), 910, 550, 0, "LEGENDA");
            al_draw_text(font, al_map_rgb(255, 255, 255), 920, 580, 0, "POSICAO");
            al_draw_text(font, al_map_rgb(255, 255, 255), 920, 600, 0, "CORRETA");
            al_draw_text(font, al_map_rgb(255, 255, 255), 920, 650, 0, "COR EXISTE");

            if(mode == 1){
                al_draw_filled_rectangle(SCREEN_W/9, SCREEN_H/9, SCREEN_W - SCREEN_W/9 , SCREEN_H - SCREEN_H/9, al_map_rgb(0,0,0));}



            al_flip_display();


            redraw = false;
        }
    }


    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_sample(deep_Urban);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}


