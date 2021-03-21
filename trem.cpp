#include "trem.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y, QMutex *mutex){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
    this->mutex = mutex;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if(y == 30 && x == 310) {
                bool mutex0 = mutex[0].try_lock();
                bool mutex2 = mutex[2].try_lock();

                if (mutex0 && mutex2) {
                    x+=10;
                } else {
                    if (mutex0)
                        mutex[0].unlock();
                    if (mutex2)
                        mutex[2].unlock();
                }
            } else if (y == 30 && x < 330) {
                x+=10;
            }
            else if (x == 330 && y < 150) {
                y+=10;
            }
            else if (x == 310 && y == 150) {
                mutex[0].unlock();
                x-=10;
            }
            else if (x > 60 && y == 150) {
                x-=10;
            }
            else if (x == 60 && y == 130){
                mutex[2].unlock();
                y-=10;
            }
            else {
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if (y == 30 && x == 350) {
                mutex[0].unlock();
                x+=10;
            } else if (y == 30 && x == 580) {
                bool mutex0 = mutex[0].try_lock();
                bool mutex1 = mutex[1].try_lock();
                bool mutex4 = mutex[4].try_lock();
                bool mutex3 = mutex[3].try_lock();

                if (mutex0 && mutex1 && mutex4 && mutex3) {
                    x+=10;
                } else {
                    if (mutex0)
                        mutex[0].unlock();
                    if (mutex1)
                        mutex[1].unlock();
                    if (mutex4)
                        mutex[4].unlock();
                    if(mutex3)
                        mutex[3].unlock();
                }
            } else if (x == 330 && y == 130){
                mutex[3].unlock();
                y-=10;
            } else if (y == 30 && x < 600) {
                x+=10;
            } else if (x == 600 && y < 150){
                y+=10;
            } else if (x == 580 && y == 150) {
                mutex[1].unlock();
                x-=10;
            } else if (x == 450 && y == 150) {
                mutex[4].unlock();
                x-=10;
            } else if (x > 330 && y == 150){
                x-=10;
            } else if (x == 330 && y == 150) {
                mutex[5].unlock();
                y-=10;
            } else {
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3:
            if (y == 30 && x == 620) {
                mutex[1].unlock();
                x+=10;
            } else if (y == 30 && x < 870)
                x+=10;
            else if (x == 870 && y < 150)
                y+=10;
            else if (x == 760 && y == 150) {
                bool mutex5 = mutex[5].try_lock();
                bool mutex1 = mutex[1].try_lock();
                if (mutex5 && mutex1) {
                    x-=10;
                } else {
                    if (mutex5)
                        mutex[5].unlock();
                    if (mutex1)
                        mutex[1].unlock();
                }
            } else if (x > 600 && y == 150) {
                x-=10;
            } else if (x == 600 && y == 130) {
                mutex[5].unlock();
                y-=10;
            } else {
                y-=10;
            }
            emit updateGUI(ID, x,y);
            break;
        case 4:
            if (y == 280 && x > 470)
                x-=10;
            else if (x == 470 && y > 150)
                y-=10;
            else if (y == 150 && x < 740)
                x+=10;
            else
                y+=10;
            emit updateGUI(ID, x,y);
            break;
        case 5:
            if (y == 280 && x > 200)
                x-=10;
            else if (x == 200 && y > 150)
                y-=10;
            else if (y == 150 && x < 470)
                x+=10;
            else
                y+=10;
            emit updateGUI(ID, x,y);
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}

int Trem::get_velocidade(){
    return this->velocidade;
}

void Trem::set_velocidade(int valor_slider){
    int velocidade = 200 - valor_slider;
    this->velocidade = velocidade;
}


