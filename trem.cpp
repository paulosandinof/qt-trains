#include "trem.h"
#include "locks.h"
#include <QtCore>

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = 100;
    this->parado = false;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        if (!parado) {
            switch(ID){
            case 1:     //Trem 1
                if (x == 310 && y == 30) {
                    if (Locks::sem_abc->available() > 0 && Locks::sem_ab->available() > 0 && Locks::sem_a->available() > 0 && Locks::sem_0->available() > 0) {
                        Locks::sem_abc->acquire(1);
                        Locks::sem_ab->acquire(1);
                        Locks::sem_a->acquire(1);
                        Locks::sem_0->acquire(1);
                        x+=10;
                    }
                } else if(x == 330 && y == 130) {
                    if (Locks::sem_2->available() > 0) {
                        Locks::sem_2->acquire(1);
                        y+=10;
                    }
                } else if(x == 310 && y == 150) {
                    if (Locks::sem_0->available() < 1)
                        Locks::sem_0->release(1);
                    x-=10;
                } else if (x == 180 && y == 150) {
                    if (Locks::sem_2->available() < 1)
                        Locks::sem_2->release(1);
                    if (Locks::sem_a->available() < 2)
                        Locks::sem_a->release(1);
                    if (Locks::sem_ab->available() < 3)
                        Locks::sem_ab->release(1);
                    if (Locks::sem_abc->available() < 4)
                        Locks::sem_abc->release(1);
                    x-=10;
                } else if (y == 30 && x < 330) {
                    x+=10;
                } else if (x == 330 && y < 150) {
                    y+=10;
                } else if (x > 60 && y == 150) {
                    x-=10;
                } else {
                    y-=10;
                }
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            case 2:     //Trem 2
                if (x == 580 && y == 30) {
                    if (Locks::sem_abc->available() > 0 && Locks::sem_bc->available() > 0 && Locks::sem_c->available() > 0 && Locks::sem_1->available() > 0) {
                        Locks::sem_abc->acquire(1);
                        Locks::sem_bc->acquire(1);
                        Locks::sem_c->acquire(1);
                        Locks::sem_1->acquire(1);
                        x+=10;
                    }
                } else if (x == 600 && y == 130) {
                    if (Locks::sem_ab->available() > 0 && Locks::sem_b->available() > 0 && Locks::sem_4->available() > 0) {
                        Locks::sem_ab->acquire(1);
                        Locks::sem_b->acquire(1);
                        Locks::sem_4->acquire(1);
                        y+=10;
                    }
                } else if (x == 580 && y == 150) {
                    if (Locks::sem_1->available() < 1)
                        Locks::sem_1->release(1);
                    x-=10;
                } else if (x == 490 && y == 150) {
                    if (Locks::sem_a->available() > 0 && Locks::sem_3->available() > 0) {
                        Locks::sem_a->acquire(1);
                        Locks::sem_3->acquire(1);
                        x-=10;
                    }
                } else if (x == 450 && y == 150) {
                    if (Locks::sem_4->available() < 1)
                        Locks::sem_4->release(1);
                    if (Locks::sem_c->available() < 2)
                        Locks::sem_c->release(1);
                    x-=10;
                } else if (x == 350 && y == 150) {
                    if (Locks::sem_0->available() > 0) {
                        Locks::sem_0->acquire(1);
                        x-=10;
                    }
                } else if (x == 330 && y == 130) {
                    if (Locks::sem_3->available() < 1)
                        Locks::sem_3->release(1);
                    if (Locks::sem_b->available() < 2)
                        Locks::sem_b->release(1);
                    if (Locks::sem_bc->available() < 3)
                        Locks::sem_bc->release(1);
                    y-=10;
                } else if (x == 350 && y == 30) {
                    if (Locks::sem_0->available() < 1)
                        Locks::sem_0->release(1);
                    if (Locks::sem_a->available() < 2)
                        Locks::sem_a->release(1);
                    if (Locks::sem_ab->available() < 3)
                        Locks::sem_ab->release(1);
                    if (Locks::sem_abc->available() < 4)
                        Locks::sem_abc->release(1);
                    x+=10;
                } else if (y == 30 && x < 600) {
                    x+=10;
                } else if (x == 600 && y < 150) {
                    y+=10;
                } else if (x > 330 && y == 150) {
                    x-=10;
                } else {
                    y-=10;
                }
                emit updateGUI(ID, x,y);    //Emite um sinal
                break;
            case 3:
                if (x == 760 && y == 150) {
                    if (Locks::sem_abc->available() > 0 && Locks::sem_bc->available() > 0 && Locks::sem_c->available() > 0 && Locks::sem_5->available() > 0) {
                        Locks::sem_abc->acquire(1);
                        Locks::sem_bc->acquire(1);
                        Locks::sem_c->acquire(1);
                        Locks::sem_5->acquire(1);
                        x-=10;
                    }
                } else if (x == 620 && y == 150) {
                    if (Locks::sem_1->available() > 0) {
                        Locks::sem_1->acquire(1);
                        x-=10;
                    }
                } else if (x == 600 && y == 130) {
                    if (Locks::sem_5->available() < 1)
                        Locks::sem_5->release(1);
                    y-=10;
                } else if (x == 620 && y == 30) {
                    if (Locks::sem_1->available() < 1)
                        Locks::sem_1->release(1);
                    if (Locks::sem_c->available() < 2)
                        Locks::sem_c->release(1);
                    if (Locks::sem_bc->available() < 3)
                        Locks::sem_bc->release(1);
                    if (Locks::sem_abc->available() < 4)
                        Locks::sem_abc->release(1);
                    x+=10;
                } else if (y == 30 && x < 870) {
                    x+=10;
                } else if (x == 870 && y < 150) {
                    y+=10;
                } else if (x > 600 && y == 150) {
                    x-=10;
                } else {
                    y-=10;
                }
                emit updateGUI(ID, x,y);
                break;
            case 4:
                if (x == 490 && y == 280) {
                    if (Locks::sem_abc->available() > 0 && Locks::sem_bc->available() > 0 && Locks::sem_ab->available() > 0 && Locks::sem_b->available() > 0 && Locks::sem_6->available() > 0) {
                        Locks::sem_abc->acquire(1);
                        Locks::sem_bc->acquire(1);
                        Locks::sem_ab->acquire(1);
                        Locks::sem_b->acquire(1);
                        Locks::sem_6->acquire(1);
                        x-=10;
                    }
                } else if (x == 470 && y == 170) {
                    if (Locks::sem_c->available() > 0 && Locks::sem_4->available() > 0) {
                        Locks::sem_c->acquire(1);
                        Locks::sem_4->acquire(1);
                        y-=10;
                    }
                } else if (x == 490 && y == 150) {
                    if (Locks::sem_6->available() < 1)
                        Locks::sem_6->release(1);
                    x+=10;
                } else if (x == 580 && y == 150) {
                    if (Locks::sem_5->available() > 0) {
                        Locks::sem_5->acquire(1);
                        x+=10;
                    }
                } else if (x == 620 && y == 150) {
                    if (Locks::sem_4->available() < 1)
                        Locks::sem_4->release(1);
                    if (Locks::sem_b->available() < 2)
                        Locks::sem_b->release(1);
                    if (Locks::sem_ab->available() < 3)
                        Locks::sem_ab->release(1);
                    x+=10;
                } else if (x == 740 && y == 170) {
                    if (Locks::sem_5->available() < 1)
                        Locks::sem_5->release(1);
                    if (Locks::sem_c->available() < 2)
                        Locks::sem_c->release(1);
                    if (Locks::sem_bc->available() < 3)
                        Locks::sem_bc->release(1);
                    if (Locks::sem_abc->available() < 4)
                        Locks::sem_abc->release(1);
                    y+=10;
                } else if (y == 280 && x > 470) {
                    x-=10;
                } else if (x == 470 && y > 150) {
                    y-=10;
                } else if (y == 150 && x < 740) {
                    x+=10;
                } else {
                    y+=10;
                }
                emit updateGUI(ID, x,y);
                break;
            case 5:
                if (x == 200 && y == 170) {
                    if (Locks::sem_abc->available() > 0 && Locks::sem_ab->available() > 0 && Locks::sem_a->available() > 0 && Locks::sem_2->available() > 0) {
                        Locks::sem_abc->acquire(1);
                        Locks::sem_ab->acquire(1);
                        Locks::sem_a->acquire(1);
                        Locks::sem_2->acquire(1);
                        y-=10;
                    }
                } else if (x == 310 && y == 150) {
                    if (Locks::sem_bc->available() > 0 && Locks::sem_b->available() > 0 && Locks::sem_3->available() > 0) {
                        Locks::sem_bc->acquire(1);
                        Locks::sem_b->acquire(1);
                        Locks::sem_3->acquire(1);
                        x+=10;
                    }
                } else if (x == 350 && y == 150) {
                    if (Locks::sem_2->available() < 1)
                        Locks::sem_2->release(1);
                    x+=10;
                } else if (x == 450 && y == 150) {
                    if (Locks::sem_6->available() > 0) {
                        Locks::sem_6->acquire(1);
                        x+=10;
                    }
                } else if (x == 470 && y == 170) {
                    if (Locks::sem_3->available() < 1)
                        Locks::sem_3->release(1);
                    if (Locks::sem_a->available() < 2)
                        Locks::sem_a->release(1);
                    y+=10;
                } else if (x == 450 && y == 280) {
                    if (Locks::sem_6->available() < 1)
                        Locks::sem_6->release(1);
                    if (Locks::sem_b->available() < 2)
                        Locks::sem_b->release(1);
                    if (Locks::sem_ab->available() < 3)
                        Locks::sem_ab->release(1);
                    if (Locks::sem_bc->available() < 3)
                        Locks::sem_bc->release(1);
                    if (Locks::sem_abc->available() < 4)
                        Locks::sem_abc->release(1);
                    x-=10;
                } else if (y == 280 && x > 200) {
                    x-=10;
                } else if (x == 200 && y > 150) {
                    y-=10;
                } else if (y == 150 && x < 470) {
                    x+=10;
                } else {
                    y+=10;
                }
                emit updateGUI(ID, x,y);
                break;
            default:
                break;
            }
            if (velocidade == 200) {
                parado = true;
            }
            msleep(velocidade);
        } else {
            if (velocidade != 200)
                parado = false;
        }
    }
}

void Trem::set_velocidade(int valor_slider){
    int velocidade = 200 - valor_slider;
    this->velocidade = velocidade;
}
