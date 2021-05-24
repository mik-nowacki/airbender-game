TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        avatar.cpp \
        enemy.cpp \
        entity.cpp \
        game.cpp \
        landscape.cpp \
        main.cpp \
        mechanics.cpp \
        projectile.cpp

INCLUDEPATH += "F:/QtCreator/SFML/SFML-2.5.1/include"
LIBS += -L"F:/QtCreator/SFML/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

DISTFILES += \
    Textures/airKingdomGround.png \
    Textures/istockphoto-637036028-1024x1024.jpg

HEADERS += \
    avatar.h \
    enemy.h \
    entity.h \
    game.h \
    landscape.h \
    mechanics.h \
    projectile.h
