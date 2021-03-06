#include "Player.h"
#include "Bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // set graphic
    setPixmap(QPixmap(":/images/ship1.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    //moving the player

    int step_size = 20;

    //checking if player is outside of scene boundary
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0){
        setPos(x()-step_size,y());
        }
    }

    else if (event->key() == Qt::Key_Right){
        if (pos().x()+100 < 800){
        setPos(x()+step_size,y());
        }
    }

    else if (event->key() == Qt::Key_Up){
        if (pos().y() > 0){
        setPos(x(),y()-step_size); //y axis is oriented downward
        }
    }

    else if (event->key() == Qt::Key_Down){
        if (pos().y()+100 < 600){
        setPos(x(),y()+step_size);
        }
    }

    //shooting bullets
    else if (event->key() == Qt::Key_Space){
        //create a bullet object
        Bullet* bullet = new Bullet();
        bullet->setPos(x()+32.5,y()); // adjusting bullet position
        scene()->addItem(bullet);// add bullet to the scene

    }

    // 2 keys pressed
    else if (event->key() == Qt::Key_Left && event->key() == Qt::Key_Space){
        if (pos().x() > 0){
        setPos(x()-step_size,y());

        Bullet* bullet = new Bullet();
        bullet->setPos(x()+32.5,y());
        scene()->addItem(bullet);

        }

    }

    else if (event->key() == Qt::Key_Right && event->key() == Qt::Key_Space){
        if (pos().x()+100 < 800){
        setPos(x()+step_size,y());

        Bullet* bullet = new Bullet();
        bullet->setPos(x()+32.5,y());
        scene()->addItem(bullet);

        }
    }

    else if (event->key() == Qt::Key_Up && event->key() == Qt::Key_Space){
        if (pos().y() > 0){
        setPos(x(),y()-step_size); //y axis is oriented downward

        Bullet* bullet = new Bullet();
        bullet->setPos(x()+32.5,y());
        scene()->addItem(bullet);

        }
    }

    else if (event->key() == Qt::Key_Down && event->key() == Qt::Key_Space){
        if (pos().y()+100 < 600){
        setPos(x(),y()+step_size);

        Bullet* bullet = new Bullet();
        bullet->setPos(x()+32.5,y());
        scene()->addItem(bullet);

        }
    }
}

void Player::spawn(){
    //create an enemy
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);//adds enemy object to the scene of the player object
}

