TEMPLATE = app
QT = core
QT += widgets
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

HEADERS += ./src/controleur/controleur.h \
            ./src/carte/carte.h \
            ./src/niveau/niveau.h \
            ./src/jeu/jeu.h \
            ./src/type/type.h \
            ./src/pioche/pioche.h \
            ./src/plateau/plateau.h \
            ./src/joueur/joueur.h \
            ./src/partie/vuePartie.h \
            src/partie/setvue.h \
            src/partie/vueCarte.h \
            ./src/menu/vueNumberOfPlayers.h \
            ./src/menu/vuePlayerConfig.h \
            ./src/renduJetons/vueRenduJetons.h \
            src/partie/vuepioche.h


SOURCES += ./test/main.cpp \
        ./src/controleur/controleur.cpp \
        ./src/carte/carte.cpp \
        ./src/niveau/niveau.cpp \
        ./src/jeu/jeu.cpp \
        ./src/type/type.cpp \
        ./src/pioche/pioche.cpp \
        ./src/plateau/plateau.cpp \
        ./src/joueur/joueur.cpp \
        ./src/partie/vuePartie.cpp \
        src/partie/setvue.cpp \
        src/partie/vueCarte.cpp \
        ./src/menu/vueNumberOfPlayers.cpp \
        ./src/menu/vuePlayerConfig.cpp \
        ./src/renduJetons/vueRenduJetons.cpp \
        src/partie/vuepioche.cpp
