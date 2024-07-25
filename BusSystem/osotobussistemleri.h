#ifndef OSOTOBUSSISTEMLERI_H
#define OSOTOBUSSISTEMLERI_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class OSOtobusSistemleri; }
QT_END_NAMESPACE

class OSOtobusSistemleri : public QMainWindow
{
    Q_OBJECT

public:
    OSOtobusSistemleri(QWidget *parent = nullptr);
    ~OSOtobusSistemleri();

private:
    Ui::OSOtobusSistemleri *ui;
};
#endif // OSOTOBUSSISTEMLERI_H
