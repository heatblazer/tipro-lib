#ifndef TIPROWIDGET_H
#define TIPROWIDGET_H

// qt headers //
#include <QObject>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSlider>
#include <QLabel>

// tipro lib //
#include "tipro-lib.h"

namespace tipro {

class TiproWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TiproWidget(QWidget* parent=nullptr);
    virtual ~TiproWidget();

private slots:
    int led1();
    int led2();
    int led3();
    int led4();
    int setBrightness(int level);
    void turnOffScreen();
    void turnOnScreen();

private:
    QVBoxLayout m_layout;
    struct {
        QPushButton led1;
        QPushButton led2;
        QPushButton led3;
        QPushButton led4;
        QHBoxLayout layout;
    } m_leds;

    struct {
        QPushButton screen_off;
        QPushButton screen_on;
        QHBoxLayout layout;
    } m_screen;

    struct {
        // screen lights
        QLabel   text;
        QSlider* slider;
        QHBoxLayout layout;
    } m_brightness;


};

} // namespace tipro


#endif // TIPROWIDGET_H
