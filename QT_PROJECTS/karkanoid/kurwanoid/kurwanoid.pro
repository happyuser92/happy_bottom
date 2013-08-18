QT += core gui opengl

LIBS += -L/usr/local/lib -lBox2D

HEADERS += ball.h \
           box.h \
           brick.h \
           game.h \
           graphicalobject.h \
           panel.h \
           wall.h

SOURCES += ball.cpp \
           box.cpp \
           brick.cpp \
           game.cpp \
           graphicalobject.cpp \
           main.cpp \
           panel.cpp \
           wall.cpp
