#include "pokemonserver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PokemonServer w;
    w.show();

    return a.exec();
}
