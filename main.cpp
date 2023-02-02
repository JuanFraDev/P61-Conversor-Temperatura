#include "conversor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator traducion;
        // Solicitando al usuario que seleccione un idioma
        QStringList idiomas;
        idiomas << "Español" << "Chino" << "Ingles";
        QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                   "Idioma",
                                   "Seleccione un idioma",
                                   idiomas);
        // Dependiendo del idioma seleccionado, carga el archivo de rtaducción
        if (idiomaSeleccionado == "Chino"){
            traducion.load(":/Conversor-Temperatura_ch.qm");
        }else if (idiomaSeleccionado == "Ingles"){
            traducion.load(":/Conversor-Temperatura_en.qm");
        }
        // Si es diferente de español, se instala la traducción en TODA la aplicación
        if (idiomaSeleccionado != "Español"){
            a.installTranslator(&traducion);
        }
    Conversor w;
    w.show();
    return a.exec();
}
