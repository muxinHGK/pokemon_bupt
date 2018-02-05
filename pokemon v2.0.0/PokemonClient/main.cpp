#include "pokemonclient2.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PokemonClient w;
    w.show();

    return a.exec();
}
