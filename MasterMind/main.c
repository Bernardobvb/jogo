#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5\allegro_color.h"


const int SCREEN_W = 1024;
const int SCREEN_H = 768;

void must_init(bool test, const char *description)
{
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

int main()
{

    ALLEGRO_COLOR black;

    ALLEGRO_COLOR green;
    ALLEGRO_COLOR yellow;



    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
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
    /*ALLEGRO_BITMAP* mysha = al_load_bitmap("imagens/mysha.png");
    must_init(mysha, "mysha");*/

    must_init(al_init_primitives_addon(),"primitives");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    float r = 1;
    float g = 1;
    float b = 1;
    float a = 1;
    ALLEGRO_COLOR red  = al_map_rgba_f(r, g, b, a);
    black = al_map_rgb_f(0, 0, 0);
    green = al_map_rgb(0, 255, 0);
    yellow = al_map_rgb_f(255, 255, 128);

    al_start_timer(timer);
    while(1)
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                // game logic goes here.
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


            //al_draw_bitmap(mysha, 100, 100, 0);
            //Primeiraa Fileira
            al_draw_filled_rectangle(600,50,700,100, al_map_rgba_f(0,1,0,1));
            al_draw_filled_circle(100, 75, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(230, 75, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(360, 75, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(490, 75, 40, al_map_rgba_f(r, g, b, a));
            //Segunda Fileira
            al_draw_filled_rectangle(600,150,700,200, al_map_rgba_f(0,1,0,1));
            al_draw_filled_circle(100, 175, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(230, 175, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(360, 175, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(490, 175, 40, al_map_rgba_f(r, g, b, a));
            //Terceira Fileira
            al_draw_filled_rectangle(600,250,700,300, al_map_rgba_f(0,1,0,1));
            al_draw_filled_circle(100, 275, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(230, 275, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(360, 275, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(490, 275, 40, al_map_rgba_f(r, g, b, a));
            //Quarta Fileira
            al_draw_filled_rectangle(600,350,700,400, al_map_rgba_f(0,1,0,1));
            al_draw_filled_circle(100, 375, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(230, 375, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(360, 375, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(490, 375, 40, al_map_rgba_f(r, g, b, a));
             //Quinta Fileira
            al_draw_filled_rectangle(600,450,700,500, al_map_rgba_f(0,1,0,1));
            al_draw_filled_circle(100, 475, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(230, 475, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(360, 475, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(490, 475, 40, al_map_rgba_f(r, g, b, a));
            //Sexta Fileira
            al_draw_filled_rectangle(600,550,700,600, al_map_rgba_f(0,1,0,1));
            al_draw_filled_circle(100, 575, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(230, 575, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(360, 575, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(490, 575, 40, al_map_rgba_f(r, g, b, a));
            //Sétima Fileira
            al_draw_filled_rectangle(600,650,700,700, al_map_rgba_f(0,1,0,1));
            al_draw_filled_circle(100, 675, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(230, 675, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(360, 675, 40, al_map_rgba_f(r, g, b, a));
            al_draw_filled_circle(490, 675, 40, al_map_rgba_f(r, g, b, a));

            //Respostas Bolas brancas e vermelhas

            al_draw_filled_circle(750,55,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(790,55,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(750,95,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(790,95,15, al_map_rgba_f(1,1,1,1));

            al_draw_filled_circle(750,155,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(790,155,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(750,195,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(790,195,15, al_map_rgba_f(1,1,1,1));

            al_draw_filled_circle(750,255,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(790,255,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(750,295,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(790,295,15, al_map_rgba_f(1,1,1,1));

            al_draw_filled_circle(750,355,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(790,355,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(750,395,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(790,395,15, al_map_rgba_f(1,1,1,1));

            al_draw_filled_circle(750,455,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(790,455,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(750,495,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(790,495,15, al_map_rgba_f(1,1,1,1));

            al_draw_filled_circle(750,555,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(790,555,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(750,595,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(790,595,15, al_map_rgba_f(1,1,1,1));

            al_draw_filled_circle(750,655,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(790,655,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(750,695,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(790,695,15, al_map_rgba_f(1,1,1,1));

            //COLUNA LATERAL

            al_draw_filled_circle(935,100,40, al_map_rgba_f(1,0,0,1));
            al_draw_filled_circle(935,200,40, al_map_rgba_f(0,1,0,1));
            al_draw_filled_circle(935,300,40, al_map_rgba_f(0,0,1,1));
            al_draw_filled_circle(935,400,40, al_map_rgba_f(0,1,1,1));

            al_draw_filled_circle(880,590,15, al_map_rgba_f(1,1,1,1));
            al_draw_filled_circle(880,650,15, al_map_rgba_f(1,0,0,1));

            //Linha
            al_draw_line(850, 10, 850, SCREEN_H-10, al_map_rgb_f(1, 0, 0), 3);

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


            al_flip_display();


            redraw = false;
        }
    }

//    al_destroy_bitmap(mysha);
    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}

