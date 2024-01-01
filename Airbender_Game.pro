TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        airstage.cpp \
        avatar.cpp \
        boss.cpp \
        bossstage.cpp \
        dummy.cpp \
        earthstage.cpp \
        enemy.cpp \
        entity.cpp \
        firecircle.cpp \
        firestage.cpp \
        game.cpp \
        golem.cpp \
        landscape.cpp \
        main.cpp \
        menu.cpp \
        projectile.cpp \
        slime.cpp \
        soldier.cpp \
        state.cpp \
        story.cpp \
        waterstage.cpp \
        worm.cpp

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
    airstage.h \
    avatar.h \
    boss.h \
    bossstage.h \
    dummy.h \
    earthstage.h \
    enemy.h \
    entity.h \
    firecircle.h \
    firestage.h \
    game.h \
    golem.h \
    landscape.h \
    menu.h \
    projectile.h \
    slime.h \
    soldier.h \
    state.h \
    story.h \
    waterstage.h \
    worm.h
