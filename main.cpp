#include"GLgame.h"
#include<QtGui/QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    GLgame a_glGame;
    a_glGame.setGeometry(0,0,1000,800);
    a_glGame.show();

    return app.exec();
}
